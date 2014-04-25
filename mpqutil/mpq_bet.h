//
//  mpq_bet.h
//  MoPaQ
//
//  Created by Sam Marshall on 4/25/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef MoPaQ_mpq_bet_h
#define MoPaQ_mpq_bet_h

#include "common.h"

struct mpq_bet_table_bit {
	uint32_t file_position;
	uint32_t file_size;
	uint32_t cmp_size;
	uint32_t flag_index;
	uint32_t unknown;
} PACK;

struct mpq_bet_table {
	struct mpq_common_header header;
	uint32_t table_size;
	uint32_t max_file_count;
	uint32_t unknown;
	uint32_t table_entry_size;
	struct mpq_bet_table_bit bit_index;
	struct mpq_bet_table_bit bit_count;
	struct mpq_common_table hash;
    uint32_t flag_count;
} PACK;

struct mpq_bet_table_contents {
	uint32_t * flag;
	uint32_t flag_count;
};

#endif
