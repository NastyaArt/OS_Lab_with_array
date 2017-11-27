#include "tests.h"

void run_init_tests()
{
    printf("\nInit tests...\n");

    init_test_incorrect_data();
    init_test_out_of_size();
    init_test_success();

    printf("\nInit tests passed successfully!\n");
}

void init_test_incorrect_data()          //некорректные данные
{
    assert(_init(1, -5)==-1);
}

void init_test_out_of_size()          //попытка выделить память больше допустимого
{
    assert(_init(1, 110000)==-1);
}

void init_test_success()          //успешная инициализация
{
    assert(_init(1, 180)==0);
}

void run_malloc_tests()
{
    printf("\nMalloc tests...\n");

    malloc_test_memory_lack();
    malloc_test_out_of_memory();
    malloc_test_success();

    printf("\nMalloc tests passed successfully!\n");
}

void malloc_test_memory_lack()          //нехватка памяти
{
    _init(1, 10);
    VA ptr1;
    VA ptr2;
    VA ptr3;
    _malloc(&ptr1, 4);
    _malloc(&ptr2, 4);

    assert(_malloc(&ptr3, 4)==-2);

    _free(ptr1);
    _free(ptr2);
}

void malloc_test_out_of_memory()        //нехватка памяти
{
    _init(1, 10);
    VA ptr;

    assert(_malloc(&ptr, 11)==-2);
}

void malloc_test_success()              //успешное добавление блока
{
    _init(1, 10);
    VA ptr;

    assert(_malloc(&ptr, 1)==0);

    _free(ptr);
}

void run_free_tests()
{
    printf("\nFree tests...\n");

    free_test_incorrect_address();
    free_test_success();

    printf("\nFree tests passed successfully!\n");
}

void free_test_incorrect_address()          //некорректный адрес
{
    _init(1, 100);
    VA ptr;
    VA ptr1=NULL;
    _malloc(&ptr, 40);

    assert(_free(ptr1)==-1);

    _free(ptr);
}

void free_test_success()                    //успешное удаление блока
{
    _init(1, 100);
    VA ptr;
    _malloc(&ptr, 40);

    assert(_free(ptr)==0);
}


void run_write_tests()
{
    printf("\nWrite tests...\n");

    write_test_incorrect_address_of_block();
    write_test_incorrect_address_of_buffer();
    write_test_out_of_block();
    write_test_out_of_block2();
    write_test_success();
    write_test_with_shift_success();

    printf("\nWrite tests passed successfully!\n");
}

void write_test_incorrect_address_of_block()          //некорректный адрес блока
{
    _init(1, 6);
    VA ptr;
    VA ptr1=NULL;
    _malloc(&ptr, 6);

    VA pBuffer = "string";

    assert(_write(ptr1, pBuffer, 6)==-1);

    _free(ptr);
}

void write_test_incorrect_address_of_buffer()          //некорректный адрес буфера
{
    _init(1, 6);
    VA ptr;
    _malloc(&ptr, 6);

    VA pBuffer = NULL;

    assert(_write(ptr, pBuffer, 6)==-1);

    _free(ptr);
}

void write_test_out_of_block()          //размер буфера больше размера участка блока для записи
{
    _init(1, 10);
    VA pBuffer = "string";
    VA ptr;
    _malloc(&ptr, 3);

    assert(_write(ptr, pBuffer, 6)==-2);

    _free(ptr);
}

void write_test_out_of_block2()          //размер буфера больше размера блока
{
    _init(1, 15);
    VA pBuffer = "string";
    VA ptr;
    _malloc(&ptr, 10);

    assert(_write(ptr+6, pBuffer, 5)==-2);

    _free(ptr);
}

void write_test_success()          //успешная запись информации в блок
{
    _init(1, 10);
    VA ptr;
    _malloc(&ptr, 4);


    VA pBuffer = "qwer";
    assert(_write(ptr, pBuffer, 4)==0);

    VA pBuffer2=(VA)malloc(4 * sizeof(VA));

    _read(ptr, pBuffer2, 4);

    assert(strcmp (pBuffer, pBuffer2)==0);

    _free(ptr);
}

void write_test_with_shift_success() //успешная запись в середину блока
{
    _init(1, 10);
    VA ptr;
    _malloc(&ptr, 8);

    VA pBuffer = "qwer";
    assert(_write(ptr+2, pBuffer, 4)==0);

    VA pBuffer2=(VA)malloc(4 * sizeof(VA));

    assert(_read(ptr+2, pBuffer2, 4)==0);

    assert(strcmp (pBuffer, pBuffer2)==0);

    _free(ptr);
}

void run_read_tests()
{
    printf("\nRead tests...\n");

    read_test_incorrect_address_of_block();
    read_test_incorrect_address_of_buffer();
    read_test_out_of_block();
    read_test_out_of_block2();
    read_test_success();
    read_test_with_shift_success();
    read_test_with_shift_from_center_success();
    read_test_with_shift_from_center_success2();

    printf("\nRead tests passed successfully!\n");
}

void read_test_incorrect_address_of_buffer()          //некорректный адрес
{
    _init(1, 15);
    VA ptr;
    _malloc(&ptr, 5);
    _write(ptr, "first", 5);

    VA pBuffer = NULL;

    assert(_read(ptr, pBuffer, 5)==-1);

    _free(ptr);
}

void read_test_incorrect_address_of_block()          //некорректный адрес
{
    _init(1, 15);
    VA ptr;
    VA ptr1=NULL;
    _malloc(&ptr, 5);
    _write(ptr, "first", 5);

    VA pBuffer=(VA)malloc(3 * sizeof(VA));

    assert(_read(ptr1, pBuffer, 5)==-1);

    _free(ptr);
}

void read_test_out_of_block()          //размер буфера больше размера блока
{
    _init(1, 15);
    VA ptr;
    _malloc(&ptr, 5);
    _write(ptr, "first", 5);

    VA ptrBuf=(VA)malloc(6 * sizeof(VA));

    assert(_read(ptr, ptrBuf, 6)==-2);

    _free(ptr);
}

void read_test_out_of_block2()          //размер буфера больше размера блока
{
    _init(1, 15);
    VA ptr;
    _malloc(&ptr, 10);
    _write(ptr+3, "first", 5);

    VA ptrBuf=(VA)malloc(5 * sizeof(VA));

    assert(_read(ptr+6, ptrBuf, 5)==-2);

    _free(ptr);
}

void read_test_success()          //успешное чтение информации всего блока
{
    _init(1, 15);
    VA ptr;
    _malloc(&ptr, 5);
    VA pBuffer2 = "first";
    _write(ptr, pBuffer2, 5);

    VA pBuffer = (VA)malloc(5*sizeof(VA));

    assert(_read(ptr, pBuffer, 5)==0);

    assert(strcmp (pBuffer, pBuffer2)==0);

    _free(ptr);
}

void read_test_with_shift_success()          //успешное чтение части информации части блока блока
{
    _init(1, 15);
    VA ptr;
    _malloc(&ptr, 5);
    VA pBuffer2 = "first";
    _write(ptr, pBuffer2, 5);

    VA pBuffer = (VA)malloc(3*sizeof(VA));

    assert(_read(ptr+2, pBuffer, 3)==0);

    assert(strcmp (pBuffer, pBuffer2+2)==0);

    _free(ptr);
}

void read_test_with_shift_from_center_success()          //успешное чтение части информации из середины блока
{
    _init(1, 15);
    VA ptr;
    _malloc(&ptr, 5);
    VA pBuffer2 = "first";
    _write(ptr, pBuffer2, 5);

    VA pBuffer = (VA)malloc(3*sizeof(VA));

    assert(_read(ptr+2, pBuffer, 3)==0);

    assert(strcmp (pBuffer, pBuffer2+2)==0);

    _free(ptr);
}

void read_test_with_shift_from_center_success2()          //успешное чтение части информации из середины блока
{
    _init(1, 15);
    VA ptr;
    _malloc(&ptr, 10);
    VA pBuffer2 = "first";
    assert(_write(ptr+2, pBuffer2, 5)==0);

    VA pBuffer = (VA)malloc(3*sizeof(VA));

    assert(_read(ptr+3, pBuffer, 3)==0);

    assert(strncmp (pBuffer, pBuffer2+1, 3)==0);

    _free(ptr);
}

void run_load_tests()
{
    int max_size = 60000;
    int size;
    for (size=10000; size<=max_size; size+=10000)
        load_test_1(size);
    for (size=10000; size<=max_size; size+=10000)
        load_test_2(size);
    for (size=10000; size<=max_size; size+=10000)
        load_test_3(size);
}

void load_test_1(int size)
{
    FILE *fp;
    fp = fopen("test1.txt", "w");

    struct timeval ta, te;

    int size_block=1;

    fprintf(fp, "\nTesting compression\nSize - %d \n", size);
   // printf("\nTesting compression\nSize - %d \n", size);
    _init(1, size);

    double time = 0;

    VA ptr[size];
    for (int i=0; i<size; i++)
    {
        _malloc(&ptr[i], size_block);
    }

    for (int i=size-1; i>=0; i--)
    {
        gettimeofday(&ta, NULL);
        _free(ptr[i]);
        gettimeofday(&te, NULL);
        time+=(te.tv_sec - ta.tv_sec)*1000.0 + (te.tv_usec - ta.tv_usec)/1000.0;
    }

    fprintf(fp, "Time: %lf msec\n", time);
   // printf("Time: %lf msec\n", time);

}


void load_test_2(int size)
{
    FILE *fp;
    fp = fopen("test2.txt", "w");

    struct timeval ta, te;

    int size_block=1;

    fprintf(fp, "\nTesting compression\nSize - %d \n", size);
   // printf("\nTesting compression\nSize - %d \n", size);
    _init(1, size);

    double time = 0;

    VA ptr[size];
    for (int i=0; i<size; i++)
    {
        _malloc(&ptr[i], size_block);
    }

    //удаляем с середины по два элемента
  for (int i=size/2, j=size/2+1; i>=0, j<size; i--, j++)
    {
        gettimeofday(&ta, NULL);
        _free(ptr[i]);
        _free(ptr[j]);
        gettimeofday(&te, NULL);
        time+=(te.tv_sec - ta.tv_sec)*1000.0 + (te.tv_usec - ta.tv_usec)/1000.0;
    }

    fprintf(fp, "Time: %lf msec\n", time);
   // printf("Time: %lf msec\n", time);

}


void load_test_3(int size)
{
    FILE *fp;
    fp = fopen("test3.txt", "w");

    struct timeval ta, te;

    int size_block=1;

    fprintf(fp, "\nTesting compression\nSize - %d \n", size);
   // printf("\nTesting compression\nSize - %d \n", size);
    _init(1, size);

    double time = 0;

    VA ptr[size];
    for (int i=0; i<size; i++)
    {
        _malloc(&ptr[i], size_block);
    }

    //удаляем с конца
    for (int i=size-1; i>=0; i--)
    {
        gettimeofday(&ta, NULL);
        _free(ptr[i]);
        gettimeofday(&te, NULL);
        time+=(te.tv_sec - ta.tv_sec)*1000.0 + (te.tv_usec - ta.tv_usec)/1000.0;
    }

    fprintf(fp, "Time: %lf msec\n", time);
   // printf("Time: %lf msec\n", time);

}