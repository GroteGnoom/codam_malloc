#include "malloc.h"
#include <stdio.h>
#include <sys/mman.h>
//If addr is
//zero and MAP_FIXED is not specified, then an address will be selected by the system so as not to overlap any exist-
//ing mappings in the address space.  In all cases, the actual starting address of the region is returned.

//PROT_READ | PROT_WRITE means you're allowed to read and write (not that it's protected against it)

//MAP_ANON  Map anonymous memory not associated with any specific file.  The offset argument is ignored.  Mac
//          OS X specific: the file descriptor used for creating MAP_ANON regions can be used to pass some
//          Mach VM flags, and can be specified as -1 if no such flags are associated with the region.  

// MAP_PRIVATE       Modifications are private (copy-on-write).
// Conforming applications must specify either MAP_PRIVATE or MAP_SHARED.

// If offset or len is not a multiple of the pagesize, the
// mapped region may extend past the specified range.  Any extension beyond the end of the mapped object will be zero-
// filled.


void *malloc(size_t size) {
	printf("I am called\n");
	void * map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	printf("map: %p\n", map);
	printf("failed: %p\n", MAP_FAILED);
	if (map == MAP_FAILED)
		return NULL;
	return map;
}

