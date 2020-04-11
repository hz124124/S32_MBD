/*
 * Copyright (c) 2015 - 2016 , Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * csec_utils.c
 *
 *  Created on: Nov 10, 2016
 *      Author: B50609
 */

#include <stdint.h>
#include <stdbool.h>

#include "csec_utils.h"

/* Constants defined by the SHE spec */
uint8_t key_update_enc_c[16] = {0x01, 0x01, 0x53, 0x48, 0x45, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0};
uint8_t key_update_mac_c[16] = {0x01, 0x02, 0x53, 0x48, 0x45, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0};
uint8_t key_debug_key_c[16] = {0x01, 0x03, 0x53, 0x48, 0x45, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0};

/* Derives a key with a given constant */
status_t CSEC_Utils_deriveKey(const uint8_t *key, uint8_t *constant, uint8_t *derivedKey)
{
    uint8_t concat[32];
    int i;

    for (i = 0; i < 16; i++)
    {
        concat[i] = key[i];
        concat[i+16] = constant[i];
    }

    return CSEC_DRV_MPCompress(concat, 2U, derivedKey, 1U);
}

/* Computes the M1-M3 values */
status_t CSEC_Utils_computeM1M2M3(csec_key_id_t authId, uint8_t *authKey, csec_key_id_t keyId, const uint8_t *key, uint32_t counter,
                                  uint8_t *uid, uint8_t *m1, uint8_t *m2, uint8_t *m3)
{
    status_t stat;
    int i;
    uint8_t iv[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    uint8_t k1[16];
    uint8_t k2[16];

    uint8_t m2Plain[32];

    uint8_t m1m2[48];

    /* Derive K1 and K2 from AuthID */
    CSEC_Utils_deriveKey(authKey, key_update_enc_c, k1);
    CSEC_Utils_deriveKey(authKey, key_update_mac_c, k2);

    /* Compute M1 = UID | ID | AuthID */
    for (i = 0; i < 15; i++)
    {
        m1[i] = uid[i];
    }
    m1[15] = ((keyId & 0xF) << 4) | (authId & 0xF);

    /* Compute M2 (C = counter, F = 0) */
    for(i = 0; i < 16; i++)
    {
        m2Plain[i] = 0;
        m2Plain[16 + i] = key[i];
    }
    m2Plain[0] = (counter & 0xFF00000) >> 20;
    m2Plain[1] = (counter & 0xFF000) >> 12;
    m2Plain[2] = (counter & 0xFF0) >> 4;
    m2Plain[3] = (counter & 0xF) << 4;

    /* Encrypt M2 */
    stat = CSEC_DRV_LoadPlainKey(k1);
    if (stat != STATUS_SUCCESS)
        return stat;

    stat = CSEC_DRV_EncryptCBC(CSEC_RAM_KEY, m2Plain, 32U, iv, m2, 1U);
    if (stat != STATUS_SUCCESS)
        return stat;

    /* Compute M3 as CMAC(key=k2, m1|m2)*/
    for (i = 0; i < 16; i++)
    {
        m1m2[i] = m1[i];
    }
    for(i = 0; i < 32; i++)
    {
        m1m2[16 + i] = m2[i];
    }

    stat = CSEC_DRV_LoadPlainKey(k2);
    if (stat != STATUS_SUCCESS)
        return stat;

    stat = CSEC_DRV_GenerateMAC(CSEC_RAM_KEY, m1m2, 384U, m3, 1U);
    if (stat != STATUS_SUCCESS)
        return stat;

    return STATUS_SUCCESS;
}

/* Computes the M4 and M5 values */
status_t CSEC_Utils_computeM4M5(csec_key_id_t authId, csec_key_id_t keyId, const uint8_t *key, uint32_t counter,
                                uint8_t *uid, uint8_t *m4, uint8_t *m5)
{
    status_t stat;
    int i;

    uint8_t k3[16];
    uint8_t k4[16];

    uint8_t m4StarPlain[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    uint8_t m4StarCipher[16];

    /* Derive K4 and K5 from key ID */
    CSEC_Utils_deriveKey(key, key_update_enc_c, k3);
    CSEC_Utils_deriveKey(key, key_update_mac_c, k4);

    m4StarPlain[0] = (counter & 0xFF00000) >> 20;
    m4StarPlain[1] = (counter & 0xFF000) >> 12;
    m4StarPlain[2] = (counter & 0xFF0) >> 4;
    m4StarPlain[3] = ((counter & 0xF) << 4) | 0x8;

    /* Encrypt M4* */
    stat = CSEC_DRV_LoadPlainKey(k3);
    if (stat != STATUS_SUCCESS)
        return stat;

    stat = CSEC_DRV_EncryptECB(CSEC_RAM_KEY, m4StarPlain, 16U, m4StarCipher, 1U);
    if (stat != STATUS_SUCCESS)
        return stat;

    /* Compute M4 = UID | ID | AuthID | M4* */
    for (i = 0; i < 15; i++)
    {
        m4[i] = uid[i];
    }
    m4[15] = ((keyId & 0xF) << 4) | (authId & 0xF);
    for (i = 0; i < 16; i++)
    {
        m4[16 + i] = m4StarCipher[i];
    }

    stat = CSEC_DRV_LoadPlainKey(k4);
    if (stat != STATUS_SUCCESS)
        return stat;

    stat = CSEC_DRV_GenerateMAC(CSEC_RAM_KEY, m4, 256U, m5, 1U);
    if (stat != STATUS_SUCCESS)
        return stat;

    return STATUS_SUCCESS;
}

/* Extracts the UID. */
bool CSEC_Utils_getUID(const uint8_t *authKey, uint8_t *uid)
{
    status_t stat;
    uint8_t challenge[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    uint8_t sreg;
    uint8_t mac[16];
    uint8_t verif[32];
    bool verifStatus;
    uint8_t i;

    stat = CSEC_DRV_GetID(challenge, uid, &sreg, mac);
    if (stat != STATUS_SUCCESS)
        return false;

    for (i = 0; i < 16; i++) {
        verif[i] = challenge[i];
    }
    for (i = 0; i < 15; i++) {
        verif[16 + i] = uid[i];
    }
    verif[31] = CSEC_DRV_GetStatus() | CSEC_STATUS_BUSY;

    stat = CSEC_DRV_LoadPlainKey(authKey);
    if (stat != STATUS_SUCCESS)
        return false;

    stat = CSEC_DRV_VerifyMAC(CSEC_RAM_KEY, verif, 256U, mac, 128U, &verifStatus, 1U);
    if (stat != STATUS_SUCCESS)
        return false;

    return verifStatus;
}

/* Erases all the keys. */
bool CSEC_Utils_eraseKeys(const uint8_t *authKey)
{
    status_t stat;
    uint8_t challenge[16];
    uint8_t auth[16];
    uint8_t authPlain[31];
    uint8_t k[16];
    uint8_t uid[15];

    uint8_t i;

    CSEC_DRV_InitRNG();
    CSEC_Utils_getUID(authKey, uid);

    CSEC_Utils_deriveKey(authKey, key_debug_key_c, k);

    stat = CSEC_DRV_LoadPlainKey(k);
    if (stat != STATUS_SUCCESS)
        return false;

    stat = CSEC_DRV_DbgChal(challenge);
    if (stat != STATUS_SUCCESS)
        return false;

    for (i = 0; i < 16; i++)
    {
        authPlain[i] = challenge[i];
    }
    for (i = 0; i < 15; i++)
    {
        authPlain[i + 16] = uid[i];
    }

    stat = CSEC_DRV_GenerateMAC(CSEC_RAM_KEY, authPlain, 248U, auth, 1U);
    if (stat != STATUS_SUCCESS)
        return false;

    stat = CSEC_DRV_DbgAuth(auth);
    if (stat != STATUS_SUCCESS)
        return false;

    return true;
}
