//-----------------------------------------------------------------------------
// Copyright (C) 2018 Merlok
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// crypto commands
//-----------------------------------------------------------------------------

#ifndef LIBPCRYPTO_H
#define LIBPCRYPTO_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <mbedtls/pk.h>

void des_encrypt(void *out, const void *in, const void *key);
void des_decrypt(void *out, const void *in, const void *key);
void des_encrypt_ecb(void *out, const void *in, const int length, const void *key);
void des_decrypt_ecb(void *out, const void *in, const int length, const void *key);
void des_encrypt_cbc(void *out, const void *in, const int length, const void *key, uint8_t *iv);
void des_decrypt_cbc(void *out, const void *in, const int length, const void *key, uint8_t *iv);
void des3_encrypt(void *out, const void *in, const void *key, uint8_t keycount);
void des3_decrypt(void *out, const void *in, const void *key, uint8_t keycount);

int aes_encode(uint8_t *iv, uint8_t *key, uint8_t *input, uint8_t *output, int length);
int aes_decode(uint8_t *iv, uint8_t *key, uint8_t *input, uint8_t *output, int length);
int aes_cmac(uint8_t *iv, uint8_t *key, uint8_t *input, uint8_t *mac, int length);
int aes_cmac8(uint8_t *iv, uint8_t *key, uint8_t *input, uint8_t *mac, int length);

int sha1hash(uint8_t *input, int length, uint8_t *hash);
int sha256hash(uint8_t *input, int length, uint8_t *hash);
int sha512hash(uint8_t *input, int length, uint8_t *hash);

int ecdsa_key_create(mbedtls_ecp_group_id curveid, uint8_t *key_d, uint8_t *key_xy);
int ecdsa_public_key_from_pk(mbedtls_pk_context *pk, mbedtls_ecp_group_id curveid, uint8_t *key, size_t keylen);
int ecdsa_signature_create(mbedtls_ecp_group_id curveid, uint8_t *key_d, uint8_t *key_xy, uint8_t *input, int length, uint8_t *signature, size_t *signaturelen, bool hash);
int ecdsa_signature_verify(mbedtls_ecp_group_id curveid, uint8_t *key_xy, uint8_t *input, int length, uint8_t *signature, size_t signaturelen, bool hash);
int ecdsa_signature_r_s_verify(mbedtls_ecp_group_id curveid, uint8_t *key_xy, uint8_t *input, int length, uint8_t *r_s, size_t r_s_len, bool hash);

char *ecdsa_get_error(int ret);

int ecdsa_nist_test(bool verbose);

void bin_xor(uint8_t *d1, uint8_t *d2, size_t len);

#define ISO9797_M2_PAD_BYTE 0x80
void AddISO9797M2Padding(uint8_t *ddata, size_t *ddatalen, uint8_t *sdata, size_t sdatalen, size_t blocklen);
size_t FindISO9797M2PaddingDataLen(uint8_t *data, size_t datalen);


#endif /* libpcrypto.h */
