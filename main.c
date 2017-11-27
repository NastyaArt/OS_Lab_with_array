#include <stdio.h>
#include "manager.h"
#include "tests.h"

int main() {

    run_init_tests();
    run_malloc_tests();
    run_free_tests();
    run_write_tests();
    run_read_tests();

//    run_load_tests();
    return 0;
}