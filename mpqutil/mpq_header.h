//
//  mpq_header.h
//  MoPaQ
//
//  Created by Sam Marshall on 4/14/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef MoPaQ_mpq_header_h
#define MoPaQ_mpq_header_h

#include <stdint.h>

struct mpq_header {
	char magic[3];
	uint8_t header_offset;
	uint32_t header_size;
	uint32_t archive_size;
	uint16_t version;
	uint16_t block_size;
	uint32_t hash_table_offset;
	uint32_t block_table_offset;
	uint32_t hash_table_entries;
	uint32_t block_table_entries;
};

struct mpq_header_ext_v2 {
	uint64_t ext_block_table_offset;
	uint16_t hash_table_offset_high;
	uint16_t block_table_offset_high;
};

struct mpq_header_ext_v3 {
	uint64_t archive_size_64;
	uint64_t bet_table_offset;
	uint64_t het_table_offset;
};

struct mpq_header_ext_v4 {
	uint64_t hash_table_size_64;
	uint64_t block_table_size_64;
	uint64_t block_table_size_64_high;
	uint64_t het_table_size;
	uint64_t bet_table_size;
	uint32_t data_chunk_size;
};

/*
// Array of MD5's
unsigned char MD5_BlockTable[MD5_DIGEST_SIZE];      // MD5 of the block table before decryption
unsigned char MD5_HashTable[MD5_DIGEST_SIZE];       // MD5 of the hash table before decryption
unsigned char MD5_HiBlockTable[MD5_DIGEST_SIZE];    // MD5 of the hi-block table
unsigned char MD5_BetTable[MD5_DIGEST_SIZE];        // MD5 of the BET table before decryption
unsigned char MD5_HetTable[MD5_DIGEST_SIZE];        // MD5 of the HET table before decryption
unsigned char MD5_MpqHeader[MD5_DIGEST_SIZE];       // MD5 of the MPQ header from signature to (including) MD5_HetTable
*/


struct mpq_v0 {
	struct mpq_header header;
};

struct mpq_v1 {
	struct mpq_header header;
};

struct mpq_v2 {
	struct mpq_header header;
	struct mpq_header_ext_v2;
};

struct mpq_v3 {
	struct mpq_header header;
	struct mpq_header_ext_v2;
	struct mpq_header_ext_v3;
};

struct mpq_v4 {
	struct mpq_header header;
	struct mpq_header_ext_v2;
	struct mpq_header_ext_v3;
	struct mpq_header_ext_v4;
};

#endif
