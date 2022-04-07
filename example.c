#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "fnv.h"

int main(int argc, char **argv)
{
	for (int i = 2; i < argc; i++) {
		const char *s = argv[i];
		size_t l = strlen(s);
		if (!strcmp(argv[1], "-64")) {
			uint64_t hash = fnv_hash64((uint8_t *)s, l);
			printf("[64] %016lx\t%s\n", hash, s);
		} else if (!strcmp(argv[1], "-32")) {
			uint32_t hash = fnv_hash32((uint8_t *)s, l);
			printf("[32] %08x\t%s\n", hash, s);
		}
	}

	return 0;
}
