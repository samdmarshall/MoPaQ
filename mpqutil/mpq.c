//
//  mpq.c
//  MoPaQ
//
//  Created by Sam Marshall on 4/25/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef MoPaQ_mpq_c
#define MoPaQ_mpq_c

#include "mpq.h"
#include <string.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

#define MPQHeaderVersion(version) \
struct mpq_header ## version * MPQHeader ## version ## FromFile(struct mpq_file * file) { \
	struct mpq_header ## version * header = calloc(1, sizeof(struct mpq_header ## version )); \
	memcpy(header, file->buffer, sizeof(struct mpq_header ## version )); \
	return header; \
}

MPQHeaderVersion(_v0);
MPQHeaderVersion(_v1);
MPQHeaderVersion(_v2);
MPQHeaderVersion(_v3);
MPQHeaderVersion(_v4);

struct mpq_file * MPQFileLoadFromPath(char * path) {
	struct mpq_file * file = NULL;
	int fd = open(path, O_RDONLY);
    if (fd < 0) {
        return file;
    }
    
    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        close(fd);
        return file;
    }
    
    file = calloc(1, sizeof(struct mpq_file));
	file->size = statbuf.st_size;
    file->buffer = mmap(0, file->size, PROT_READ, MAP_FILE|MAP_PRIVATE, fd, 0);
    close(fd);
	
	return file;
}

void MPQFileRelease(struct mpq_file * file) {
	if (file) {
		munmap(file->buffer, file->size);
		free(file);
	}
}

struct mpq_header * MPQHeaderFromFile(struct mpq_file * file) {
	struct mpq_header * header = NULL;
	if (file) {
		header = calloc(1, sizeof(struct mpq_header));
		memcpy(header, file->buffer, sizeof(struct mpq_header));
	}
	return header;
}

void * MPQResolveHeaderVersion(struct mpq_header * header, struct mpq_file * file) {
	switch (header->version) {
		case _v0: {
			return MPQHeader_v0FromFile(file);
		}
		case _v1: {
			return MPQHeader_v1FromFile(file);
		}
		case _v2: {
			return MPQHeader_v2FromFile(file);
		}
		case _v3: {
			return MPQHeader_v3FromFile(file);
		}
		case _v4: {
			return MPQHeader_v4FromFile(file);
		}
		default: {
			return MPQHeaderFromFile(file);
		}
	}
}

void MPQHeaderRelease(struct mpq_header * header) {
	if (header) {
		free(header);
	}
}

struct mpq_het_table * MPQHetTableFromFile(struct mpq_file * file, struct mpq_header * header) {
	struct mpq_het_table * het_table = NULL;
	if (file && (header->version == _v3 || header->version == _v4)) {
		uint64_t offset = ((struct mpq_header_v3 *)header)->ext_v3.het_table_offset;
		if (offset != 0) {
			het_table = calloc(1, sizeof(struct mpq_het_table));
			memcpy(het_table, &(file->buffer[offset]), sizeof(struct mpq_het_table));
		}
	}
	return het_table;
}

void MPQHetTableRelease(struct mpq_het_table * table) {
	if (table) {
		free(table);
	}
}

struct mpq_bet_table * MPQBetTableFromFile(struct mpq_file * file, struct mpq_header * header) {
	struct mpq_bet_table * bet_table = NULL;
	if (file && (header->version == _v3 || header->version == _v4)) {
		uint64_t offset = ((struct mpq_header_v3 *)header)->ext_v3.bet_table_offset;
		if (offset != 0) {
			bet_table = calloc(1, sizeof(struct mpq_bet_table));
			memcpy(bet_table, &(file->buffer[offset]), sizeof(struct mpq_bet_table));

		}
	}
	return bet_table;
}

void MPQBetTableRelease(struct mpq_bet_table * table) {
	if (table) {
		free(table);
	}
}

#endif