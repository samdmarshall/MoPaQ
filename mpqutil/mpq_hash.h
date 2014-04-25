//
//  mpq_hash.h
//  MoPaQ
//
//  Created by Sam Marshall on 4/14/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef MoPaQ_mpq_hash_h
#define MoPaQ_mpq_hash_h

#include <stdint.h>

struct mpq_hash {
	uint32_t name_a;
	uint32_t name_b;
	uint16_t locale;
	uint16_t platform;
	uint32_t block_index;
};

#endif
