#pragma once

#include <stddef.h>

/**
 * Get struct pointer from member pointer
 */
#define AStruct_GetParent2(memberPtr, structType) \
    ((structType*) ((char*) memberPtr - offsetof(structType, memberPtr)))


/**
 * Get struct pointer from member pointer with memberName
 */
#define AStruct_GetParent3(memberPtr, structType, memberName) \
    ((structType*) ((char*) memberPtr - offsetof(structType, memberName)))

