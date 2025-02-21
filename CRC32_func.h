// CRC32_func.h
#ifndef CRC32_FUNC_H
#define CRC32_FUNC_H

#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include "stddef.h"

uint32_t crc32(const void *buf, size_t size);

#endif 
