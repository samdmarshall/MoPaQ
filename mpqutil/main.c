//
//  main.c
//  mpqutil
//
//  Created by Sam Marshall on 4/14/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#include <stdio.h>
#include "mpq.h"

int main(int argc, const char * argv[]) {
	struct mpq_file * file = MPQFileLoadFromPath("/Users/sam/Projects/MoPaQ/enUS_Text.mpq");
	struct mpq_header * header = MPQHeaderFromFile(file);
	void * test = MPQResolveHeaderVersion(header, file);
	struct mpq_het_table * het_table = MPQHetTableFromFile(file, test);
	MPQHeaderRelease(test);
	MPQFileRelease(file);
	return 0;
}

