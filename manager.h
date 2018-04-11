//
// Created by Nastya on 13.11.2017.
//

#ifndef LAB1_OS_MANAGER_H
#define LAB1_OS_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"
#include "mmemory.h"

#define MAX_MEMORY_SIZE 100000

#define SUCCESS 0
#define INCORRECT_PARAMETRS -1
#define LACK_OF_MEMORY -2
#define UNKNOWN_ERROR 1
#define OUT_OF_BLOCK -2


VA phisMem;  //физическая пам¤ть
int memSize;
int freeMemSize;

struct Block{
    VA* address;
    size_t size;                           //размер блока
    VA first;                           //указатель на первый элемент блока
    bool isEmpty;                       //является ли блок пустым
};

struct Block *manager;      //виртуальные адреса - массив блоков

void compressionMemory(int pos);
int _free_memory();

#endif //LAB1_OS_MANAGER_H
