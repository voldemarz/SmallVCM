#pragma once
#include <cstdarg>
#include <stdio.h>

#define DEBUG_OUTPUT 0
#define DEBUG_X 0
#define DEBUG_Y 250
#define DEBUG_RES_X 512
#define DEBUG_RES_Y 512
#define DEBUG_IDX DEBUG_X + (DEBUG_RES_Y - DEBUG_Y) * DEBUG_RES_X
#define DEBUG_THREAD_ID 0

#define DEBUG_PIX 0
#define DEBUG_PIX_X 400
#define DEBUG_PIX_Y 460

#define DEBUG_EMIT_DIR_FIXED 0
#define DEBUG_EMIT_DIR Normalize(Vec3f(-0.5f, 0.f, -1.f))
#define DEBUG_SCATTER_MIRROR_REFLECT 0


#define IS_DEBUG_IDX(idx) (idx && (*idx == DEBUG_IDX))
#define IS_DEBUG_PIX(pixelPos) (int(pixelPos.x) == DEBUG_PIX_X && int(pixelPos.y) == (DEBUG_RES_Y - DEBUG_PIX_Y))
#define IDX_X(idx) (idx % DEBUG_RES_X)
#define IDX_Y(idx) (DEBUG_RES_Y - (idx / DEBUG_RES_X))

#if DEBUG_OUTPUT

void dbgPrintf(const char * format, ... ) 
{ 
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    fflush(stdout);
};

#define DBG_PRINTFI(idx, format, ...) \
    if (idx && (*idx == DEBUG_IDX) && (DEBUG_THREAD_ID == omp_get_thread_num())) \
    { \
        dbgPrintf(format, __VA_ARGS__); \
    }

#define DBG_PRINTFC(cond, format, ...) \
    if ((cond) && (DEBUG_THREAD_ID == omp_get_thread_num())) \
{ \
    dbgPrintf(format, __VA_ARGS__); \
}

#else
inline void dbgPrintf(const char * format, ... ) { };
#define DBG_PRINTFI(idx, format, ...)
#define DBG_PRINTFC(cond, format, ...) 
#endif






