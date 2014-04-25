//
//  mpq.h
//  MoPaQ
//
//  Created by Sam Marshall on 4/25/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef MoPaQ_mpq_h
#define MoPaQ_mpq_h

#include "mpq_header.h"
#include "mpq_hash.h"
#include "mpq_block.h"
#include "mpq_het.h"
#include "mpq_bet.h"

struct mpq_file {
	void * buffer;
	off_t size;
};

struct mpq_file * MPQFileLoadFromPath(char * path);
void MPQFileRelease(struct mpq_file * file);

struct mpq_header * MPQHeaderFromFile(struct mpq_file * file);
void * MPQResolveHeaderVersion(struct mpq_header * header, struct mpq_file * file);
void MPQHeaderRelease(struct mpq_header * header);

struct mpq_het_table * MPQHetTableFromFile(struct mpq_file * file, struct mpq_header * header);
void MPQHetTableRelease(struct mpq_het_table * table);

struct mpq_bet_table * MPQBetTableFromFile(struct mpq_file * file, struct mpq_header * header);
void MPQBetTableRelease(struct mpq_bet_table * table);

#endif
