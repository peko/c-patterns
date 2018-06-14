#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <stddef.h>
#define container_of(ptr, type, member) \
	((type *)((char *)(ptr) - offsetof(type, member)))
