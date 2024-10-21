/*******************************************************************************
 *   XAH Wallet
 *   (c) 2020 Towo Labs
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#ifndef LEDGER_APP_XAH_FIELDS_H
#define LEDGER_APP_XAH_FIELDS_H

#include <stdint.h>
#include <stdbool.h>

#include "limitations.h"

typedef enum {
    // Normal field types
    STI_UINT16 = 0x01,
    STI_UINT32 = 0x02,
    STI_HASH128 = 0x04,
    STI_HASH256 = 0x05,
    STI_AMOUNT = 0x06,
    STI_VL = 0x07,
    STI_ACCOUNT = 0x08,
    STI_OBJECT = 0x0E,
    STI_ARRAY = 0x0F,
    STI_UINT8 = 0x10,
    STI_PATHSET = 0x12,
    STI_VECTOR256 = 0x13,

    // Custom field types
    STI_CURRENCY = 0xF0,
} field_type_t;

// Small collection of used field IDs
// UINT8
// #define XAH_UINT8_CLOSE_RESOLUTION     0x01
// #define XAH_UINT8_METHOD               0x02
// #define XAH_UINT8_TRANSACTION_RESULT   0x03
#define XAH_UINT8_TICK_SIZE 0x10
// #define XAH_UINT8_UNL_MODIFY_DISABLING 0x11
// #define XAH_UINT8_HOOK_RESULT          0x12
// UINT16
// #define XAH_UINT16_LEDGER_ENTRY_TYPE       0x01
#define XAH_UINT16_TRANSACTION_TYPE 0x02
#define XAH_UINT16_SIGNER_WEIGHT    0x03
#define XAH_UINT16_TRANSFER_FEE     0x04
// #define XAH_UINT16_VERSION                 0x10
// #define XAH_UINT16_HOOK_STATE_CHANGE_COUNT 0x11
// #define XAH_UINT16_HOOK_EMIT_COUNT         0x12
// #define XAH_UINT16_HOOK_EXECUTION_INDEX    0x13
#define XAH_UINT16_HOOK_API_VERSION 0x14
// UINT32
#define XAH_UINT32_NETWORK_ID 0x01
#define XAH_UINT32_FLAGS      0x02
#define XAH_UINT32_SOURCE_TAG 0x03
#define XAH_UINT32_SEQUENCE   0x04
// #define XAH_UINT32_PREVIOUS_TXN_LGR_SEQ     0x05
// #define XAH_UINT32_LEDGER_SEQUENCE          0x06
// #define XAH_UINT32_CLOSE_TIME               0x07
// #define XAH_UINT32_PARENT_CLOSE_TIME        0x08
// #define XAH_UINT32_SIGNING_TIME             0x09
#define XAH_UINT32_EXPIRATION    0x0A
#define XAH_UINT32_TRANSFER_RATE 0x0B
#define XAH_UINT32_WALLET_SIZE   0x0C
// #define XAH_UINT32_OWNER_COUNT              0x0D
#define XAH_UINT32_DESTINATION_TAG 0x0E
// #define XAH_UINT32_HIGH_QUALITY_IN          0x10
// #define XAH_UINT32_HIGH_QUALITY_OUT         0x11
// #define XAH_UINT32_LOW_QUALITY_IN           0x12
// #define XAH_UINT32_LOW_QUALITY_OUT          0x13
#define XAH_UINT32_QUALITY_IN  0x14
#define XAH_UINT32_QUALITY_OUT 0x15
// #define XAH_UINT32_STAMP_ESCROW             0x16
// #define XAH_UINT32_BOND_AMOUNT              0x17
// #define XAH_UINT32_LOAD_FEE                 0x18
#define XAH_UINT32_OFFER_SEQUENCE        0x19
#define XAH_UINT32_FIRST_LEDGER_SEQUENCE 0x1A
#define XAH_UINT32_LAST_LEDGER_SEQUENCE  0x1B
// #define XAH_UINT32_TRANSACTION_INDEX        0x1C
#define XAH_UINT32_OPERATION_LIMIT 0x1D
// #define XAH_UINT32_REFERENCE_FEE_UNITS      0x1E
// #define XAH_UINT32_RESERVE_BASE             0x1F
// #define XAH_UINT32_RESERVE_INCREMENT        0x20
#define XAH_UINT32_SET_FLAG      0x21
#define XAH_UINT32_CLEAR_FLAG    0x22
#define XAH_UINT32_SIGNER_QUORUM 0x23
#define XAH_UINT32_CANCEL_AFTER  0x24
#define XAH_UINT32_FINISH_AFTER  0x25
// #define XAH_UINT32_SIGNER_LIST_ID          0x26
#define XAH_UINT32_SETTLE_DELAY    0x27
#define XAH_UINT32_TICKET_COUNT    0x28
#define XAH_UINT32_TICKET_SEQUENCE 0x29
#define XAH_UINT32_NFTOKEN_TAXON   0x2A
// #define XAH_UINT32_MINTED_NFTOKENS         0x2B
// #define XAH_UINT32_BURNED_NFTOKENS         0x2C
// #define XAH_UINT32_HOOK_STATE_COUNT         0x2D
// #define XAH_UINT32_EMIT_GENERATION          0x2E
// #define XAH_UINT32_LOCK_COUNT               0x31
// #define XAH_UINT32_FIRST_NFTOKEN_SEQUENCE  0x32
// #define XAH_UINT32_XAHAU_ACTIVATION_LGR_SEQ 0x60
// #define XAH_UINT32_IMPORT_SEQUENCE          0x61
// #define XAH_UINT32_REWARD_TIME              0x62
// #define XAH_UINT32_REWARD_LGR_FIRST         0x63
// #define XAH_UINT32_REWARD_LGR_LAST          0x64
// UINT64
// #define XAH_UINT64_INDEX_NEXT             0x01
// #define XAH_UINT64_INDEX_PREVIOUS         0x02
// #define XAH_UINT64_BOOK_NODE              0x03
// #define XAH_UINT64_OWNER_NODE             0x04
// #define XAH_UINT64_BASE_FEE               0x05
// #define XAH_UINT64_EXCHANGE_RATE          0x06
// #define XAH_UINT64_LOW_NODE               0x07
// #define XAH_UINT64_HIGH_NODE              0x08
// #define XAH_UINT64_DESTINATION_NODE       0x09
// #define XAH_UINT64_COOKIE                 0x0A
// #define XAH_UINT64_SERVER_VERSION         0x0B
// #define XAH_UINT64_NFTOKEN_OFFER_NODE    0x0C
// #define XAH_UINT64_EMIT_BURDEN            0x0D
// #define XAH_UINT64_HOOK_INSTRUCTION_COUNT 0x11
// #define XAH_UINT64_HOOK_RETURN_CODE       0x12
// #define XAH_UINT64_REFERENCE_COUNT        0x13
// #define XAH_UINT64_ACCOUNT_INDEX          0x62
// #define XAH_UINT64_ACCOUNT_COUNT          0x63
// #define XAH_UINT64_REWARD_ACCUMULATOR     0x64
// HASH128
#define XAH_HASH128_EMAIL_HASH 0x01
// HASH160
// #define XAH_HASH160_TAKER_PAYS_CURRENCY 0x01
// #define XAH_HASH160_TAKER_PAYS_ISSUER   0x02
// #define XAH_HASH160_TAKER_GETS_CURRENCY 0x03
// #define XAH_HASH160_TAKER_GETS_ISSUER   0x04
// HASH256
// #define XAH_HASH256_LEDGER_HASH         0x01
// #define XAH_HASH256_PARENT_HASH         0x02
// #define XAH_HASH256_TRANSACTION_HASH    0x03
// #define XAH_HASH256_ACCOUNT_HASH        0x04
#define XAH_HASH256_PREVIOUS_TXN_ID 0x05
// #define XAH_HASH256_LEDGER_INDEX        0x06
#define XAH_HASH256_WALLET_LOCATOR 0x07
// #define XAH_HASH256_ROOT_INDEX          0x08
#define XAH_HASH256_ACCOUNT_TXN_ID 0x09
#define XAH_HASH256_NFTOKEN_ID     0x0A
// #define XAH_HASH256_EMIT_PARENT_TXN_ID  0x0B
// #define XAH_HASH256_EMIT_NONCE          0x0C
// #define XAH_HASH256_EMIT_HOOK_HASH      0x0D
// #define XAH_HASH256_BOOK_DIRECTORY      0x10
#define XAH_HASH256_INVOICE_ID 0x11
#define XAH_HASH256_NICKNAME   0x12
// #define XAH_HASH256_AMENDMENT           0x13
#define XAH_HASH256_HOOK_ON 0x14
#define XAH_HASH256_DIGEST  0x15
#define XAH_HASH256_CHANNEL 0x16
// #define XAH_HASH256_CONSENSUS_HASH      0x17
#define XAH_HASH256_CHECK_ID 0x18
// #define XAH_HASH256_VALIDATED_HASH      0x19
// #define XAH_HASH256_PREVIOUS_PAGE_MIN   0x1A
// #define XAH_HASH256_NEXT_PAGE_MIN       0x1B
#define XAH_HASH256_NFTOKEN_BUY_OFFER  0x1C
#define XAH_HASH256_NFTOKEN_SELL_OFFER 0x1D
// #define XAH_HASH256_HOOK_STATE_KEY      0x1E
#define XAH_HASH256_HOOK_HASH      0x1F
#define XAH_HASH256_HOOK_NAMESPACE 0x20
// #define XAH_HASH256_HOOK_SET_TXN_ID     0x21
#define XAH_HASH256_OFFER_ID    0x22
#define XAH_HASH256_ESCROW_ID   0x23
#define XAH_HASH256_URITOKEN_ID 0x24
// #define XAH_HASH256_EMITTED_TXN_ID      0x61
#define XAH_HASH256_GOVERNANCE_MARKS 0x62
#define XAH_HASH256_GOVERNANCE_FLAGS 0x63
// AMOUNT
#define XAH_UINT64_AMOUNT       0x01
#define XAH_UINT64_BALANCE      0x02
#define XAH_UINT64_LIMIT_AMOUNT 0x03
#define XAH_UINT64_TAKER_PAYS   0x04
#define XAH_UINT64_TAKER_GETS   0x05
// #define XAH_UINT64_LOW_LIMIT               0x06
// #define XAH_UINT64_HIGH_LIMIT              0x07
#define XAH_UINT64_FEE         0x08
#define XAH_UINT64_SEND_MAX    0x09
#define XAH_UINT64_DELIVER_MIN 0x0A
// #define XAH_UINT64_MINIMUM_OFFER           0x10
// #define XAH_UINT64_RIPPLE_ESCROW           0x11
// #define XAH_UINT64_DELIVERED_AMOUNT        0x12
#define XAH_UINT64_NFTOKEN_BROKER_FEE 0x13
// #define XAH_UINT64_HOOK_CALLBACK_FEE       0x14
// #define XAH_UINT64_LOCKED_BALANCE          0x15
// #define XAH_UINT64_BASE_FEE_DROPS          0x16
// #define XAH_UINT64_RESERVE_BASE_DROPS      0x17
// #define XAH_UINT64_RESERVE_INCREMENT_DROPS 0x18
// BLOB
#define XAH_VL_PUBLIC_KEY      0x01
#define XAH_VL_MESSAGE_KEY     0x02
#define XAH_VL_SIGNING_PUB_KEY 0x03
#define XAH_VL_TXN_SIGNATURE   0x04
#define XAH_VL_URI             0x05
#define XAH_VL_SIGNATURE       0x06
#define XAH_VL_DOMAIN          0x07
// #define XAH_VL_FUND_CODE              0x08
// #define XAH_VL_REMOVE_CODE            0x09
// #define XAH_VL_EXPIRE_CODE            0x0A
#define XAH_VL_CREATE_CODE 0x0B
#define XAH_VL_MEMO_TYPE   0x0C
#define XAH_VL_MEMO_DATA   0x0D
#define XAH_VL_MEMO_FORMAT 0x0E
#define XAH_VL_FULFILLMENT 0x10
#define XAH_VL_CONDITION   0x11
// #define XAH_VL_MASTER_SIGNATURE       0x12
// #define XAH_VL_UNL_MODIFY_VALIDATOR   0x13
// #define XAH_VL_VALIDATOR_TO_DISABLE   0x14
// #define XAH_VL_VALIDATOR_TO_RE_ENABLE 0x15
// #define XAH_VL_HOOK_STATE_DATA        0x16
// #define XAH_VL_HOOK_RETURN_STRING     0x17
#define XAH_VL_HOOK_PARAMETER_NAME  0x18
#define XAH_VL_HOOK_PARAMETER_VALUE 0x19
#define XAH_VL_BLOB                 0x1A
// VECTOR256
// #define XAH_VECTOR256_INDEXES         0x01
// #define XAH_VECTOR256_HASHES          0x02
// #define XAH_VECTOR256_AMENDMENTS      0x03
#define XAH_VECTOR256_NFTOKEN_OFFERS 0x04
// #define XAH_VECTOR256_HOOK_NAMESPACES 0x05
#define XAH_VECTOR256_URITOKEN_IDS 0x63
// ACCOUNTID
#define XAH_ACCOUNT_ACCOUNT        0x01
#define XAH_ACCOUNT_OWNER          0x02
#define XAH_ACCOUNT_DESTINATION    0x03
#define XAH_ACCOUNT_ISSUER         0x04
#define XAH_ACCOUNT_AUTHORIZE      0x05
#define XAH_ACCOUNT_UNAUTHORIZE    0x06
#define XAH_ACCOUNT_REGULAR_KEY    0x08
#define XAH_ACCOUNT_NFTOKEN_MINTER 0x09
// #define XAH_ACCOUNT_EMIT_CALLBACK   0x0A
// #define XAH_ACCOUNT_HOOK_ACCOUNT    0x10
#define XAH_ACCOUNT_INFORM 0x63
// STOBJECT
// #define XAH_STOBJECT_TRANSACTION_META_DATA 0x02
// #define XAH_STOBJECT_CREATED_NODE          0x03
// #define XAH_STOBJECT_DELETED_NODE          0x04
// #define XAH_STOBJECT_MODIFIED_NODE         0x05
// #define XAH_STOBJECT_PREVIOUS_FIELDS       0x06
// #define XAH_STOBJECT_FINAL_FIELDS          0x07
// #define XAH_STOBJECT_NEW_FIELDS            0x08
// #define XAH_STOBJECT_TEMPLATE_ENTRY        0x09
#define XAH_STOBJECT_MEMO         0x0A
#define XAH_STOBJECT_SIGNER_ENTRY 0x0B
#define XAH_STOBJECT_NFTOKEN      0x0C
// #define XAH_STOBJECT_EMIT_DETAILS          0x0D
#define XAH_STOBJECT_HOOK   0x0E
#define XAH_STOBJECT_SIGNER 0x10
// #define XAH_STOBJECT_MAJORITY              0x12
// #define XAH_STOBJECT_DISABLED_VALIDATOR    0x13
// #define XAH_STOBJECT_EMITTED_TXN           0x14
// #define XAH_STOBJECT_HOOK_EXECUTION        0x15
// #define XAH_STOBJECT_HOOK_DEFINITION       0x16
#define XAH_STOBJECT_HOOK_PARAMETER 0x17
#define XAH_STOBJECT_HOOK_GRANT     0x18
#define XAH_STOBJECT_AMOUNT         0x5B
#define XAH_STOBJECT_MINT_URITOKEN  0x5C
// #define XAH_STOBJECT_HOOK_EMISSION         0x5D
// #define XAH_STOBJECT_IMPORT_VL_KEY         0x5E
// #define XAH_STOBJECT_ACTIVE_VALIDATOR      0x5F
// #define XAH_STOBJECT_GENESIS_MINT          0x60
// STARRAY
#define XAH_STARRAY_SIGNERS        0x03
#define XAH_STARRAY_SIGNER_ENTRIES 0x04
// #define XAH_STARRAY_TEMPLATE            0x05
// #define XAH_STARRAY_NECESSARY           0x06
// #define XAH_STARRAY_SUFFICIENT          0x07
// #define XAH_STARRAY_AFFECTED_NODES      0x08
#define XAH_STARRAY_MEMOS    0x09
#define XAH_STARRAY_NFTOKENS 0x0A
#define XAH_STARRAY_HOOKS    0x0B
// #define XAH_STARRAY_MAJORITIES          0x10
// #define XAH_STARRAY_DISABLED_VALIDATORS 0x11
// #define XAH_STARRAY_HOOK_EXECUTIONS     0x12
#define XAH_STARRAY_HOOK_PARAMETERS 0x13
#define XAH_STARRAY_HOOK_GRANTS     0x14
#define XAH_STARRAY_AMOUNTS         0x5C
// #define XAH_STARRAY_HOOK_EMISSIONS      0x5D
// #define XAH_STARRAY_IMPORT_VL_KEYS      0x5E
// #define XAH_STARRAY_ACTIVE_VALIDATORS   0x5F
// #define XAH_STARRAY_GENESIS_MINTS       0x60

#define XAH_CURRENCY_CURRENCY 0x01

// Array of type one is reserved for end-of-array marker so this
// constant cannot possibly collide with anything in the future
#define ARRAY_PATHSET 0x01
#define ARRAY_NONE    0x00

#define PATHSET_NEXT 0xFF
#define PATHSET_END  0x00

#define XAH_ACCOUNT_SIZE   20
#define XAH_CURRENCY_SIZE  20
#define XAH_VECTOR256_SIZE 32

typedef struct {
    uint8_t buf[XAH_ACCOUNT_SIZE];
} xah_account_t;

typedef struct {
    uint8_t buf[XAH_CURRENCY_SIZE];
} xah_currency_t;

typedef struct {
    uint8_t type;
    uint8_t index1;
    uint8_t index2;
} array_info_t;

typedef struct {
    uint8_t buf[16];
} hash128_t;

typedef struct {
    uint8_t buf[32];
} hash256_t;

typedef struct {
    uint8_t id;
    field_type_t data_type;
    uint16_t length;
    union {
        uint8_t u8;
        uint16_t u16;
        uint32_t u32;
        hash128_t *hash128;
        hash256_t *hash256;
        xah_account_t *account;
        xah_currency_t *currency;
        uint8_t *ptr;
    } data;
    array_info_t array_info;
} field_t;

typedef struct {
    char buf[MAX_FIELDNAME_LEN];
} field_name_t;

typedef struct {
    char buf[MAX_FIELD_LEN];
} field_value_t;

bool is_normal_account_field(field_t *field);
const char *resolve_field_name(field_t *field);
bool is_field_hidden(field_t *field);

#endif  // LEDGER_APP_XAH_FIELDS_H
