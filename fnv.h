#pragma once

#include <stdint.h>

#define force_inline  inline __attribute__((always_inline))

// public domain, see https://creativecommons.org/publicdomain/zero/1.0

/**
 * original: http://www.isthe.com/chongo/tech/comp/fnv
 */

/**
 * FNV-1a alternate algorithm
 *
 * hash = OFFSET_BASIS
 * for each octet_of_data to be hashed
 *     hash = hash XOR octet_of_data
 *     hash = hash * FNV_PRIME
 * endfor
 * return hash
 */

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

/**
 * 32 bit FNV Hash
 *
 * OFFSET_BASIS = 0x811c9dc5
 * FNV_PRIME    = 0x1000193
 */
force_inline uint32_t fnv_hash32(uint8_t *data, size_t l)
{
	uint64_t hash = 0x811c9dc5UL;
	for (size_t i = 0; i < l; i++) {
		hash ^= data[i];
		hash *= 0x1000193UL;
	}
	return hash;
}

/**
 * 64 bit FNV Hash
 *
 * OFFSET_BASIS = 0xcbf29ce484222325
 * FNV_PRIME    = 0x100000001b3
 */
force_inline uint64_t fnv_hash64(uint8_t *data, size_t l)
{
	uint64_t hash = 0xcbf29ce484222325ULL;
	for (size_t i = 0; i < l; i++) {
		hash ^= data[i];
		hash *= 0x100000001b3ULL;
	}
	return hash;
}
