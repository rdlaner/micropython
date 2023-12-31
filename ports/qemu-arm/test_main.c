#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <setjmp.h>

#include "py/compile.h"
#include "py/runtime.h"
#include "py/stackctrl.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "shared/runtime/gchelper.h"
#include "lib/tinytest/tinytest.h"
#include "lib/tinytest/tinytest_macros.h"

#define HEAP_SIZE (100 * 1024)

#include "genhdr/tests.h"

int main() {
    mp_stack_ctrl_init();
    mp_stack_set_limit(10240);
    static uint32_t heap[HEAP_SIZE / sizeof(uint32_t)];
    upytest_set_heap(heap, (char *)heap + HEAP_SIZE);
    int r = tinytest_main(0, NULL, groups);
    printf("status: %d\n", r);
    return r;
}

void gc_collect(void) {
    gc_collect_start();
    gc_helper_collect_regs_and_stack();
    gc_collect_end();
}

mp_lexer_t *mp_lexer_new_from_file(qstr filename) {
    mp_raise_OSError(MP_ENOENT);
}

void nlr_jump_fail(void *val) {
    printf("uncaught NLR\n");
    exit(1);
}
