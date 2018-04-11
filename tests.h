#ifndef MEMORY_TESTS_H
#define MEMORY_TESTS_H

#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>
#include "manager.h"

void run_init_tests();
void init_test_incorrect_data();
void init_test_out_of_size();
void init_test_success();

void run_malloc_tests();
void malloc_test_memory_lack();
void malloc_test_out_of_memory();
void malloc_test_success();

void run_free_tests();
void free_test_incorrect_address();
void free_test_success();

void run_write_tests();
void write_test_incorrect_address_of_block();
void write_test_incorrect_address_of_buffer();
void write_test_out_of_block();
void write_test_out_of_block2();
void write_test_success();
void write_test_with_shift_success();


void run_read_tests();
void read_test_incorrect_address_of_block();
void read_test_incorrect_address_of_buffer();
void read_test_out_of_block();
void read_test_out_of_block2();
void read_test_success();
void read_test_with_shift_success();
void read_test_with_shift_from_center_success();
void read_test_with_shift_from_center_success2();


void run_load_tests();
void load_test_1(int size);
void load_test_2(int size);
void load_test_3(int size);

#endif //MEMORY_TESTS_H
