/**************************************************************************//**
 * @file     rtl8710c_crypto_ctrl.h
 * @brief    This file defines adapter,rom stubs structure and other related common MACRO_VARs for CRYPTO.
 * @version  v1.00
 * @date     2022/04/11
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

/**
 * @addtogroup hs_hal_crypto CRYPTO
 * @ingroup 8710c_hal
 * @{
 */

#ifdef CONFIG_BUILD_LIB
#error ERROR, only for application
#endif

#ifndef RTL8710C_CRYPTO_CTRL_H
#define RTL8710C_CRYPTO_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rtl8735b_crypto.h"

/* Macros for hp crypto module general configuration */
#define CRYPTO_MAX_DIGEST_LENGTH    32  // SHA256 Digest length : 32
#define CRYPTO_MAX_KEY_LENGTH       32  // MAX  is  AES-256 : 32 byte,  3DES : 24 byte
#define CRYPTO_AUTH_PADDING         64  // HMAC key maximum size is 64 bytes
#define CRYPTO_PADSIZE              64
#define CRYPTO_PADSIZE_SHA512       128


// Mode Select
#define CRYPTO_MS_TYPE_CIPHER       (0)
#define CRYPTO_MS_TYPE_AUTH         (1)
#define CRYPTO_MS_TYPE_MIX          (2)

//HASH Type
/* Macros for hp crypto module hash type configuration */

// HASH General
/* Macros for hp crypto module hash type general configuration */
#define AUTH_TYPE_NO_AUTH           ((u32)-1)

#define AUTH_TYPE_MASK_FUNC         0x3 // bit 0, bit 1
#define AUTH_TYPE_MD5               0x2
#define AUTH_TYPE_SHA1              0x0
#define AUTH_TYPE_SHA2              0x1

#define AUTH_TYPE_MASK_HMAC         0x4 // bit 2
#define AUTH_TYPE_HMAC_MD5          (AUTH_TYPE_MD5 | AUTH_TYPE_MASK_HMAC)
#define AUTH_TYPE_HMAC_SHA1         (AUTH_TYPE_SHA1 | AUTH_TYPE_MASK_HMAC)
#define AUTH_TYPE_HMAC_SHA2         (AUTH_TYPE_SHA2 | AUTH_TYPE_MASK_HMAC)

#define AUTH_TYPE_MASK_FUNC_ALL     (AUTH_TYPE_MASK_FUNC| AUTH_TYPE_MASK_HMAC)

#define CRYPTO_MD5_DIGEST_LENGTH    16
#define CRYPTO_SHA1_DIGEST_LENGTH   20
#define CRYPTO_SHA2_DIGEST_LENGTH   32

// SHA2
/* Macros for hp crypto module general hash type sha2 configuration */
#define AUTH_TYPE_MASK_SHA2         0x70 // bit 3,4
#define AUTH_TYPE_SHA2_224          0x10
#define AUTH_TYPE_SHA2_256          0x20
#define AUTH_TYPE_SHA2_384          0x30
#define AUTH_TYPE_SHA2_512          0x40


#define AUTH_TYPE_SHA2_224_ALL      (AUTH_TYPE_SHA2_224|AUTH_TYPE_SHA2)
#define AUTH_TYPE_SHA2_256_ALL      (AUTH_TYPE_SHA2_256|AUTH_TYPE_SHA2)
#define AUTH_TYPE_SHA2_384_ALL      (AUTH_TYPE_SHA2_384|AUTH_TYPE_SHA2)
#define AUTH_TYPE_SHA2_512_ALL      (AUTH_TYPE_SHA2_512|AUTH_TYPE_SHA2)


#define AUTH_TYPE_HMAC_SHA2_224_ALL (AUTH_TYPE_SHA2_224|AUTH_TYPE_HMAC_SHA2)
#define AUTH_TYPE_HMAC_SHA2_256_ALL (AUTH_TYPE_SHA2_256|AUTH_TYPE_HMAC_SHA2)
#define AUTH_TYPE_HMAC_SHA2_384_ALL (AUTH_TYPE_SHA2_384|AUTH_TYPE_HMAC_SHA2)
#define AUTH_TYPE_HMAC_SHA2_512_ALL (AUTH_TYPE_SHA2_512|AUTH_TYPE_HMAC_SHA2)


#define SHA2_NONE                   0
#define SHA2_224                    (224/8)
#define SHA2_256                    (256/8)
#define SHA2_384                    (384/8)
#define SHA2_512                    (512/8)

// Cipher Type
/* Macros for hp crypto module cipher type configuration */
#define CIPHER_TYPE_NO_CIPHER       ((u32)-1)

#define CIPHER_TYPE_MODE_ENCRYPT    0x80

#define CIPHER_TYPE_MASK_ALL        0x3F
#define CIPHER_TYPE_MASK_FUNC       0x30    // 0x00 : DES, 0x10: 3DES, 0x20: AES
#define CIPHER_TYPE_FUNC_DES        0x00
#define CIPHER_TYPE_FUNC_3DES       0x10
#define CIPHER_TYPE_FUNC_AES        0x20
#define CIPHER_TYPE_FUNC_CHACHA     0x30    //Including(chaha_poly1305,chacha20,poly1305)

#define CIPHER_TYPE_FUNC_CHACHA_POLY1305    0x30
#define CIPHER_TYPE_FUNC_CHACHA20           0x31

#define CIPHER_TYPE_MASK_BLOCK      0xF   // 0x0:ECB, 0x1:CBC, 0x2:CFB , 0x3:OFB , 0x4:CTR, 0x5:GCTR, 0x6:GMAC, 0x7:GHASH, 0x8:GCM
#define CIPHER_TYPE_BLOCK_ECB       0x0
#define CIPHER_TYPE_BLOCK_CBC       0x1
#define CIPHER_TYPE_BLOCK_CFB       0x2
#define CIPHER_TYPE_BLOCK_OFB       0x3
#define CIPHER_TYPE_BLOCK_CTR       0x4
#define CIPHER_TYPE_BLOCK_GCTR      0x5
#define CIPHER_TYPE_BLOCK_GMAC      0x6
#define CIPHER_TYPE_BLOCK_GHASH     0x7
#define CIPHER_TYPE_BLOCK_GCM       0x8

#define CIPHER_TYPE_BLOCK_CHACHA    0x1
#define CIPHER_TYPE_BLOCK_CHACHA_POLY1305   0x0

/// Crypto cipher encrypt self-define index
#define TYPE_ENCRYPT 1
/// Crypto cipher decrypt self-define index
#define TYPE_DECRYPT 0
/// Cipher type none for Crypto ROM Code self-define index.
#define CIPHER_TYPE_NONE            0xFF
/// DES_ECB for Crypto ROM Code self-define index.
#define CIPHER_TYPE_DES_ECB         0x0
/// DES_CBC for Crypto ROM Code self-define index.
#define CIPHER_TYPE_DES_CBC         0x1
/// 3DES_ECB for Crypto ROM Code self-define index.
#define CIPHER_TYPE_3DES_ECB        0x10
/// 3DES_CBC for Crypto ROM Code self-define index.
#define CIPHER_TYPE_3DES_CBC        0x11
/// AES_ECB for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_ECB         0x20
/// AES_CBC for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_CBC         0x21
/// AES_CFB for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_CFB         0x22
/// AES_OFB for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_OFB         0x23
/// AES_CTR for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_CTR         0x24  // 0x29
/// AES_GCTR for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_GCTR        0x25
/// AES_GMAC for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_GMAC        0x26
/// AES_GHASH for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_GHASH       0x27
/// AES_GCM for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_GCM         0x28

/// Chacha20_Poly1305 for Crypto ROM Code self-define index.
#define CIPHER_TYPE_CHACHA_POLY1305 0x30 // chacha+poly1305
/// Chacha20 for Crypto ROM Code self-define index.
#define CIPHER_TYPE_CHACHA          0x31
/// Poly1305_mode2 for Crypto ROM Code self-define index.
#define CIPHER_TYPE_POLY1305        0x33 // poly1305 - mode 2


#define CRYPTO_ENGINE_SET_MIX_MODE_SSH_ENC_ESP_DEC     0x2
#define CRYPTO_ENGINE_SET_MIX_MODE_SSH_DEC_ESP_ENC     0x3
#define CRYPTO_ENGINE_SET_MIX_MODE_SSL_TLS_ENC         0x4

#define CRYPTO_MIX_MODE_SSH_ENC             0x12
#define CRYPTO_MIX_MODE_SSH_DEC             0x03
#define CRYPTO_MIX_MODE_ESP_ENC             0x13
#define CRYPTO_MIX_MODE_ESP_DEC             0x02
#define CRYPTO_MIX_MODE_SSL_TLS_ENC         0x14
#define CRYPTO_MIX_MODE_MASK_TYPE           0x07    //SSH/ESP/SSL
#define CRYPTO_MIX_MODE_MASK_FUNC           0x10

#define CRYPTO_KEY_STG_INPUT_SK_DIS         0xFF
#define CRYPTO_KEY_STG_ROLE_KEYCFG          0x1
#define CRYPTO_KEY_STG_ROLE_WBCFG           0x2

#define CRYPTO_KEY_STG_LD_SK_EN             0x1
#define CRYPTO_KEY_STG_LD_SK_DIS            0x0
#define KEY_STG_SK_IDX_MASK                 0xF
#define KEY_STG_SK_IDX_NONE                 0xFF
#define KEY_STG_SKTYPE_LD_NOKEY             0x0
#define KEY_STG_SKTYPE_LD_SK                0x1
#define KEY_STG_SKTYPE_LD_KEYBUF            0x2

#define CRYPTO_KEY_STG_WB_SK_EN             0x1
#define CRYPTO_KEY_STG_WB_SK_DIS            0x0

enum {
	CRYPTO_TYPE_CRC32          = 0x50,
	CRYPTO_TYPE_CRC16          = 0x51,
	CRYPTO_TYPE_CRC_CCITT      = 0x52,
	CRYPTO_TYPE_CRC_XMODEM     = 0x53,
	CRYPTO_TYPE_CRC12          = 0x54,
	CRYPTO_TYPE_CRC10          = 0x55,
	CRYPTO_TYPE_CRC8           = 0x56
};

enum {
	KEY_STG_WBTYPE_WB_ONLY_BUF =    0x0,
	KEY_STG_WBTYPE_WB_ONLY_STG =    0x1,
	KEY_STG_WBTYPE_WB_STG_BUF  =    0x2
};

enum {
	KEY_STG_IDX0     = 0x0,
	KEY_STG_IDX1     = 0x1,
	KEY_STG_IDX2     = 0x2,
	KEY_STG_IDX3     = 0x3,
	KEY_STG_IDX4     = 0x4,
	KEY_STG_IDX5     = 0x5,
	KEY_STG_IDX6     = 0x6,
	KEY_STG_IDX7     = 0x7,
	KEY_STG_HUK1     = 0xC,
	KEY_STG_HUK2     = 0xD,
	KEY_STG_SK1      = 0xE,
	KEY_STG_SK2      = 0xF
};

typedef union {
	struct {
		uint8_t idx: 4;         //!<  [3..0] sk_idx
		uint8_t sel: 4;         //!<  [7..4] sk_sel
	} b;
	uint8_t w;
} hal_crypto_key_cfg_t;

typedef union {
	struct {
		uint8_t idx: 4;         //!<  [3..0] wb_idx
		uint8_t sel: 4;         //!<  [7..4] wb_sel
	} b;
	uint8_t w;
} hal_crypto_wb_cfg_t;


/* Data Struct for hp crypto adapter */
/**
 *  \brief Define data struct for hp crypto adapter.
 */
typedef struct hal_crypto_adapter_s {
	CRYPTO_Type *base_addr;     //!< The Crypto register base address
	uint8_t     isInit;         //!< Crypto engine init state: 1=Init, 0=Not init
	uint8_t     isIntMode;      //!< Crypto engine interrupt mode state: 1=Active, 0=Inactive
	uint8_t     isMemDump;      //!< Crypto memory dump control state: 1=Enable, 0=Disable. related \ref __dbg_mem_dump
	uint8_t     initmap;

	//uint8_t dma_burst_num; // 0 ~ 32
	//uint8_t desc_num;  // total number of source/destination description
	//uint8_t mode_select;

	uint32_t    cipher_type;    //!<  Cipher_type ID
	uint8_t     des;            //!<  DES state: 1=Active, 0=Inactive
	uint8_t     trides;         //!<  3DES state: 1=Active, 0=Inactive
	uint8_t     aes;            //!<  AES state: 1=Active, 0=Inactive
	uint8_t     chacha;         //!<  Chacha(including poly1305) state: 1=Active, 0=Inactive
	uint8_t     isDecrypt;      //!<  Decryption state: 1=Enable, 0=Disable
	uint8_t     reserved1[3];   //!<  Reserve

	uint32_t    auth_type;      //!<  Hash_type ID
	uint8_t     isHMAC;         //!<  HMAC state: 1=Active, 0=Inactive
	uint8_t     isMD5;          //!<  MD5 state: 1=Active, 0=Inactive
	uint8_t     isSHA1;         //!<  SHA1 state: 1=Active, 0=Inactive
	uint8_t     isSHA2;         //!<  SHA2 state: 1=Active, 0=Inactive

	/**
	 * Sha2_type ID: 0=None of this mode of sha2, 28=sha2_224 mode(output size is 28bytes),
	 * 32=sha2_256 mode(output size is 32bytes)
	 */
	uint8_t     sha2type;       //!< Sha2_type ID
	uint8_t     reserved2[3];   //!<  Reserve

	uint8_t     mix_mode_type;  //!< Mix mode type: SSH/ESP/SSL
	uint8_t     reserved3[3];   //!<  Reserve

	// hash
	uint32_t    enc_last_data_size;     //!<  Encrypted message of last data size
	uint32_t    aad_last_data_size;     //!<  Additional authenticated data of last data size
	uint32_t    hashpad_last_data_size; //!<  Mix mode Hash padding of last data size
	uint32_t    encpad_last_data_size;  //!<  Mix mode Encryption padding of last data size

	uint32_t    lenAuthKey;     //!<  Key length of authenticated hash
	const uint8_t *pAuthKey;    //!<  Pointer to variable that points the key address of authenticated hash
	uint32_t    digestlen;      //!<  Digest length of hash

	// sequential hash
	uint8_t     hmac_seq_hash_first;    //!<  Sequential hash first one state:  1=Active, 0=Inactive
	uint8_t     hmac_seq_hash_last;     //!<  Sequential hash last one state: 1=Active, 0=Inactive
	uint8_t     hmac_seq_is_recorded;   //!<  Recording a sequential hash: 1=Active, 0=Inactive
	uint8_t     hmac_seq_buf_is_used_bytes;     //!<  Recorded data size in sequential hash buffer
	uint32_t    hmac_seq_hash_total_len;        //!<  Total data length of sequential hash
	uint32_t    hmac_seq_last_msglen;   //!<  Last message length of sequential hash
	uint8_t     *hmac_seq_last_message; //!<  Pointer to variable that points the last message address of sequential hash

	uint32_t    lenCipherKey;   //!<  Key length of Cipher
	const uint8_t *pCipherKey;  //!<  Pointer to variable that points the key address of cipher

	uint32_t    a2eo;           //!<  Additional authenticated data length
	uint32_t    apl_aad;        //!<  Padding length of additional authenticated data
	uint32_t    enl;            //!<  Crypto message length
	uint32_t    apl;            //!<  Padding length of crypto message
	uint32_t    hash_padlen;    //!<  Mix mode hash padding length
	uint32_t    hashpad_pad;    //!<  Mix mode padding length of hash padding
	uint32_t    enc_padlen;     //!<  Mix mode encryption padding length
	uint32_t    encpad_pad;     //!<  Mix mode padding length of encryption padding

	uint8_t     *ipad;          //!<  Pointer to variable that points the inner padding data address of HMAC
	uint8_t     *opad;          //!<  Pointer to variable that points the outer padding data address of HMAC
	// crc
	int32_t     crc_order;      //!<  Cyclic redundancy check order

	//read_crc_setting used
	uint32_t    crc_sel;        //!<  Register value of cyclic redundancy check order
	uint32_t    crc_oswap;      //!<  Register value of cyclic redundancy check refout
	uint32_t    crc_iswap;      //!<  Register value of cyclic redundancy check refin
	uint32_t    crc_oxor;       //!<  Register value of cyclic redundancy check xor
	uint32_t    crc_init;       //!<  Register value of cyclic redundancy check init
	uint32_t    crc_poly;       //!<  Register value of cyclic redundancy check polynomial

	// cache
	uint8_t     is_dst_first_cache_used;    //!<  Destination descriptor that used first cache line: 1=Active, 0=Inactive
	uint8_t     is_dst_last_cache_used;     //!<  Destination descriptor that used last cache line: 1=Active, 0=Inactive
	uint8_t     reserved4[2];   //!<  Reserve

	// Key storage
	uint8_t     is_securekey;
	uint8_t     is_writeback;
	uint8_t     index_securekey;
	uint8_t     index_writeback;
#if IS_CUT_TEST(CONFIG_CHIP_VER)
	uint8_t     user_key[8];
	uint8_t     key_buffer;
	uint8_t     key_lock;
#else
	hal_crypto_key_cfg_t ld_key_cfg;
	hal_crypto_wb_cfg_t wb_key_cfg;
	uint8_t     hmac_seq_hash_sk_last;
	uint8_t     reserved5;
	uint8_t     user_key[8];
	uint8_t     key_buffer;
	uint8_t     user_key_lock;
	uint8_t     reserved6[2];
#endif

	// SHIVL
	uint8_t     is_SHIVL;
	uint8_t     is_wb;
	uint8_t     SHIVL_len;
	//uint8_t     SHIVL_buff[32];

	volatile uint8_t SHIVL_buff[32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store inner and outer padding data
	 */
	volatile uint8_t g_IOPAD[CRYPTO_PADSIZE * 2 + 32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store inner and outer padding data
	 */
	volatile uint8_t g_IOPAD_SHA512[CRYPTO_PADSIZE_SHA512 * 2 + 32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store initial vector for AES_GCM/Chacha20/Chacha_poly1305
	 */
	volatile uint8_t  gcm_iv[32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store command register data of source descriptor
	 */
	volatile uint8_t  cl_buffer[32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store digest result of Hash
	 */
	volatile uint8_t  digest_result[32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store digest result of Hash
	 */
	volatile uint8_t  digest_result_SHA512[64] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store temp digest result of Hash
	 */
	volatile uint8_t  temp_digest_result[32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store tag result of HMAC
	 */
	volatile uint8_t  tag_result[32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store first cache line of source descriptor
	 */
	volatile uint8_t  src_first_cache_line[32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store last cache line of source descriptor
	 */
	volatile uint8_t  src_last_cache_line[32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store first cache line of destination descriptor
	 */
	volatile uint8_t  dst_first_cache_line[32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store last cache line of destination descriptor
	 */
	volatile uint8_t  dst_last_cache_line[32] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store 64 bytes sequential buffer data of Hash
	 */
	volatile uint8_t  hmac_seq_buf[64] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store 64 bytes sequential buffer data of Hash
	 */
	volatile uint8_t  hmac_seq_buf_SHA512[128] __attribute__((aligned(32)));

	/**
	 * 32 bytes aligned buffer that store first cache line of crc_dma modeh
	 */
	volatile uint8_t  crc_first_cache_line[32] __attribute__((aligned(32)));

	/**
	 * 64 bytes aligned buffer that store padding value
	 */
	volatile uint8_t  padding[64] __attribute__((aligned(64)));

	/**
	 * Callback function pointer : Clean D-cache.
	 */
	void (*arch_clean_dcache_by_size)(uint32_t start_address, int32_t size);

	/**
	 * Callback function pointer : Invalidate D-cache.
	 */
	void (*arch_invalidate_dcache_by_size)(uint32_t start_address, int32_t size);

	/**
	 * Callback function pointer : Wait available fifo nodes of source descriptor.
	 */
	int (*fifo_wait_func)(void *pIE1);

	/**
	 * Callback function pointer to \ref g_crypto_pre_exec : Initialize the notified mechanism.
	 */
	int (*pre_exec_func)(void *pIE1);

	/**
	 * Callback function pointer to \ref g_crypto_wait_done : Wait to be notified after
	 * interrupt service routine processed over.
	 */
	int (*wait_done_func)(void *pIE1);

#if IS_CUT_TEST(CONFIG_CHIP_VER)
	uint32_t reserved5[8];   //!<  Reserve
#else
	uint32_t reserved7[8];
#endif
} hal_crypto_adapter_t, *phal_crypto_adapter_t ;



//
// stub
//

/**
 *   \brief  The data structure of the stubs functions of the Crypto HAL functions in ROM
 *
 */
typedef struct {
	int (*hal_crypto_engine_init)(phal_crypto_adapter_t pcrypto_adapter);
	int (*hal_crypto_engine_deinit)(phal_crypto_adapter_t pcrypto_adapter);
	void (*hal_crypto_engine_platform_en_ctrl)(int platform_en);

//Auth
	int (*hal_crypto_auth)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 auth_type,
						   IN const u8 *message, IN const u32 msglen,
						   IN const u8 *key, IN const u32 keylen, OUT u8 *pDigest);
	int (*hal_crypto_auth_init)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 auth_type,
								IN const u8 *key, IN const u32 keylen);
	int (*hal_crypto_auth_process)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 auth_type,
								   IN const u8 *message, IN const u32 msglen, OUT u8 *pDigest);
	int (*hal_crypto_auth_update)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 auth_type,
								  IN const u8 *message, IN const u32 msglen);
	int (*hal_crypto_auth_final)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 auth_type, OUT u8 *pDigest);

//Cipher
	int (*hal_crypto_cipher_init)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 cipher_type,
								  IN const u8 *key, IN const u32 keylen);
	int (*hal_crypto_cipher_encrypt)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 cipher_type,
									 IN const u8 *message, IN const u32 msglen,
									 IN const u8 *iv, IN const u32 ivlen,
									 IN const u8 *aad, IN const u32 aadlen,
									 OUT u8 *pResult,  OUT u8 *pTag);
	int (*hal_crypto_cipher_decrypt)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 cipher_type,
									 IN const u8 *message, IN const u32 msglen,
									 IN const u8 *iv, IN const u32 ivlen,
									 IN const u8 *aad, IN const u32 aadlen,
									 OUT u8 *pResult,  OUT u8 *pTag);
//Mix mode
	int (*hal_crypto_mix_mode_init)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 cipher_type, IN const u32 auth_type,
									IN const u8 *cipher_key, IN const u32 cipher_keylen,
									IN const u8 *auth_key, IN const u32 auth_keylen);
	int (*hal_crypto_mix_mode_process)(hal_crypto_adapter_t *pcrypto_adapter, IN const u8 mix_mode_type,
									   IN const u32 cipher_type, IN const u8 *message, IN const u32 msglen,
									   IN const u8 *iv, IN const u32 ivlen,
									   IN const u8 *aad, IN const u32 aadlen,
									   IN const u32 auth_type,
									   IN const u8 *hash_pad, IN const u32 hash_padlen,
									   IN const u8 *enc_pad,  IN const u32 enc_padlen,
									   OUT u8 *pResult, OUT u8 *pTag);

// CHACHA
	int (*hal_crypto_chacha_init)(
		hal_crypto_adapter_t *pcrypto_adapter,
		IN const u8 *key);

	int (*hal_crypto_chacha_encrypt)(
		hal_crypto_adapter_t *pcrypto_adapter,
		IN const u8 *message, IN const u32 msglen,
		IN const u8 *iv, IN const u32 count,
		OUT u8 *pResult);

	int (*hal_crypto_chacha_decrypt)(
		hal_crypto_adapter_t *pcrypto_adapter,
		IN const u8 *message, IN const u32 msglen,
		IN const u8 *iv, IN const u32 count,
		OUT u8 *pResult);

// POLY1305
	int (*hal_crypto_poly1305)(
		hal_crypto_adapter_t *pcrypto_adapter,
		IN const u8 *message, IN const u32 msglen,
		IN const u8 *key,
		OUT u8 *pDigest);

	int (*hal_crypto_poly1305_init)(
		hal_crypto_adapter_t *pcrypto_adapter,
		IN const u8 *key);

	int (*hal_crypto_poly1305_process)(
		hal_crypto_adapter_t *pcrypto_adapter,
		IN const u8 *message, IN const u32 msglen,
		OUT u8 *pDigest);

// CHACHA+POLY1305

	int (*hal_crypto_chacha_poly1305_init)(
		hal_crypto_adapter_t *pcrypto_adapter,
		IN const u8 *key);

	int (*hal_crypto_chacha_poly1305_encrypt)(
		hal_crypto_adapter_t *pcrypto_adapter,
		IN const u8 *message, IN const u32 msglen,
		IN const u8 *nonce,
		IN const u8 *aad, IN const u32 aadlen,
		OUT u8 *pResult, OUT u8 *pTag);

	int (*hal_crypto_chacha_poly1305_decrypt)(
		hal_crypto_adapter_t *pcrypto_adapter,
		IN const u8 *message, IN const u32 msglen,
		IN const u8 *iv,
		IN const u8 *aad, IN const u32 aadlen,
		OUT u8 *pResult, OUT u8 *pTag);

// CRC
	int (*hal_crypto_crc_setting)(hal_crypto_adapter_t *pcrypto_adapter,
								  IN int order, IN uint32_t polynom,
								  IN uint32_t crcinit, IN uint32_t crcxor, IN uint32_t refin, IN uint32_t refout);

	int (*hal_crypto_crc_cmd)(hal_crypto_adapter_t *pcrypto_adapter, IN const u8 *message, IN const uint32_t msglen);

	int (*hal_crypto_crc_dma)(hal_crypto_adapter_t *pcrypto_adapter, IN const u8 *message, IN const uint32_t msglen);

	uint32_t (*hal_crypto_crc_get_result)(hal_crypto_adapter_t *pcrypto_adapter);

	int (*hal_crypto_crc32_cmd)(hal_crypto_adapter_t *pcrypto_adapter, IN const u8 *message, IN const uint32_t msglen);

	int (*hal_crypto_crc32_dma)(hal_crypto_adapter_t *pcrypto_adapter, IN const u8 *message, IN const uint32_t msglen);

// Misc functions for ram code patch
	int (*hal_crypto_engine)(hal_crypto_adapter_t *pcrypto_adapter,
							 IN const u8 *message,     IN const uint32_t msglen,
							 IN const u8 *pIv,         IN const uint32_t ivlen,
							 IN const u8 *paad,     IN const uint32_t aadlen,
							 OUT u8 *pResult, OUT u8 *pTag);

	void (*hal_crypto_engine_get_result)(hal_crypto_adapter_t *pcrypto_adapter, u8 *pDigest, u8 *pResult, uint32_t len, u8 *pTag);

	void (*hal_crypto_set_srcdesc)(hal_crypto_adapter_t *pcrypto_adapter, uint32_t sd1, uint32_t sdpr);

	void (*hal_crypto_set_dstdesc)(hal_crypto_adapter_t *pcrypto_adapter, uint32_t dd1, uint32_t ddpr);

	void (*hal_crypto_engine_setup_cl_buffer)(hal_crypto_adapter_t *pcrypto_adapter);

// Key Storage

	int (*hal_crypto_key_storage_securekey)(hal_crypto_adapter_t *pcrypto_adapter, uint8_t key_num, bool _UseKey);

#if IS_CUT_TEST(CONFIG_CHIP_VER)
	int (*hal_crypto_key_storage_writekey)(hal_crypto_adapter_t *pcrypto_adapter, uint8_t *key, uint8_t Key_number, bool _Lock, uint8_t keylen);

	int (*hal_crypto_key_storage_writeback)(hal_crypto_adapter_t *pcrypto_adapter, uint8_t Key_number, bool _IsWriteback);

	int (*hal_crypto_key_storage_emptyspace)(hal_crypto_adapter_t *pcrypto_adapter, uint8_t index, uint8_t *result);

	int (*hal_crypto_key_storage_lock)(hal_crypto_adapter_t *pcrypto_adapter, uint8_t Key_number, bool _Lock);
#else
	int (*hal_crypto_key_storage_writekey)(hal_crypto_adapter_t *pcrypto_adapter, uint8_t *key, uint8_t keylen, uint8_t key_num);

	int (*hal_crypto_key_storage_writeback)(hal_crypto_adapter_t *pcrypto_adapter, uint8_t key_num, bool _IsWriteback);

	uint32_t func_resv;

	int (*hal_crypto_key_storage_lock)(hal_crypto_adapter_t *pcrypto_adapter, uint8_t key_num);
#endif

	void (*hal_crypto_cache)(IN phal_crypto_adapter_t pcrypto_adapter, IN void *dcache_clean_function, IN void *dcache_invalidate_function);
#if IS_CUT_TEST(CONFIG_CHIP_VER)
	uint32_t reserved[8];
#else
	int (*hal_crypto_auth_sk_init)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 auth_type,
								   IN const u8 *pAuthKey, IN const u32 sk_cfg);
	int (*hal_crypto_auth_sk_final)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 auth_type, OUT u8 *pDigest);
	void (*hal_crypto_set_sk_cfg_info)(IN u32 *psk_cfg, IN const u8 cfg, IN const u8 role);
	void (*hal_crypto_get_sk_cfg_info)(IN const u32 sk_cfg, IN u8 *pcfg, IN const u8 role);
	int (*hal_crypto_cipher_sk_init)(hal_crypto_adapter_t *pcrypto_adapter, IN const u32 cipher_type, IN const u32 sk_cfg, IN const u32 keylen);
	uint32_t reserved[3]; // reserved space for next ROM code version function table extending.
#endif
} hal_crypto_func_stubs_t;



#ifdef __cplusplus
}
#endif

#endif /* RTL8710C_CRYPTO_CTRL_H */

