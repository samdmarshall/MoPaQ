//
//  mpq_het.h
//  MoPaQ
//
//  Created by Sam Marshall on 4/25/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef MoPaQ_mpq_het_h
#define MoPaQ_mpq_het_h

#include "common.h"

struct mpq_het_table {
	struct mpq_common_header header;
	uint32_t table_size;
	uint32_t max_file_count;
	uint32_t hash_table_size;
	uint32_t hash_entry_size;
	struct mpq_common_table block;
} PACK;

struct mpq_het_table_contents {
	uint8_t * hash;
	uint32_t hash_count;
};

#endif
