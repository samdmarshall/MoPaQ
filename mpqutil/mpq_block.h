//
//  mpq_block.h
//  MoPaQ
//
//  Created by Sam Marshall on 4/25/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef MoPaQ_mpq_block_h
#define MoPaQ_mpq_block_h

#include "common.h"

enum mpq_block_flag {
	MPQ_FILE_IMPLODE = 0x00000100, 			// File is compressed using PKWARE Data compression library
	MPQ_FILE_COMPRESS = 0x00000200, 		// File is compressed using combination of compression methods
	MPQ_FILE_ENCRYPTED = 0x00010000, 		// The file is encrypted
	MPQ_FILE_FIX_KEY = 0x00020000, 			// The decryption key for the file is altered according to the position of the file in the archive
	MPQ_FILE_PATCH_FILE = 0x00100000, 		// The file contains incremental patch for an existing file in base MPQ
	MPQ_FILE_SINGLE_UNIT = 0x01000000, 		// Instead of being divided to 0x1000-bytes blocks, the file is stored as single unit
	MPQ_FILE_DELETE_MARKER = 0x02000000, 	// File is a deletion marker, indicating that the file no longer exists. This is used to allow patch archives to delete files present in lower-priority archives in the search chain. The file usually has length of 0 or 1 byte and its name is a hash
	MPQ_FILE_SECTOR_CRC = 0x04000000, 		// File has checksums for each sector (explained in the File Data section). Ignored if file is not compressed or imploded.
	MPQ_FILE_EXISTS = 0x80000000 			// Set if file exists, reset when the file was deleted
};

struct mpq_block {
	uint32_t position;
	uint32_t block_size;
	uint32_t file_size;
	uint32_t flags;
} PACK;

#endif
