/**
    Copyright (C) 2015-2016 Lymia Aluysia <lymiahugs@gmail.com>

    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
    of the Software, and to permit persons to whom the Software is furnished to do
    so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#ifndef C_RT_H
#define C_RT_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "platform.h"

#ifdef DEBUG
    extern FILE* debug_log_file;
    #define debug_print(format, arg...) \
        fprintf(debug_log_file, "[%lld] %s at %s:%u - " format "\n", \
            (long long) time(NULL), __PRETTY_FUNCTION__, strrchr(__FILE__, '/') + 1, __LINE__, ##arg); \
        fflush(debug_log_file);
#else
    #define debug_print(format, ...)
#endif

#define ASM_ENTRY __attribute__((stdcall, force_align_arg_pointer))

typedef struct UnpatchData {
    void* offset;
    char oldData[5];
} UnpatchData;

UnpatchData* doPatch(int address, void* hookAddress, const char* reason);
void unpatch(UnpatchData* data);

#endif /* C_RT_H */

