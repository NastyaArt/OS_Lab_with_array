//
// Created by Nastya on 13.11.2017.
//

#include "manager.h"

//сжатие памяти
void compressionMemory(int pos)
{
    size_t delSize=manager[pos].size;
    int i;
    for (i=pos; i<memSize; i++)
    {
        if (!manager[i+1].isEmpty)
        {
            manager[i].address = manager[i+1].address;
            *manager[i].address = manager[i+1].first - delSize;
            manager[i].first = *manager[i].address;
            manager[i].size = manager[i+1].size;
            memcpy(manager[i].first, manager[i+1].first, manager[i+1].size);
        }
        else
        {
            manager[i].isEmpty=true;
            freeMemSize+=delSize;
            return;
        }
    }
    return;
}

/**
 	@func	_malloc
 	@brief	Выделяет блок памяти определенного размера

	@param	[out] ptr		адресс блока
	@param	[in]  szBlock	размер блока

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	-2	нехватка памяти
	@retval	1	неизвестная ошибка
 **/

int _malloc (VA* ptr, size_t szBlock)
{
    if (szBlock>freeMemSize)                                //нехватка свободной памяти
        return LACK_OF_MEMORY;
    for (int i=0; i < memSize; i++)
    {
        if (manager[i].isEmpty)                 //находим пустой блок
        {
            if (i==0)
            {
                manager[i].first=phisMem;
            }
            else
            {
                manager[i].first = manager[i-1].first+manager[i-1].size;
            }
            (*ptr) = manager[i].first;
            manager[i].address = ptr;
            manager[i].size = szBlock;
            manager[i].isEmpty = false;
            freeMemSize -= szBlock;
            return SUCCESS;
        }
    }
    return UNKNOWN_ERROR;
}

/**
 	@func	_free
 	@brief	Удаление блока памяти

	@param	[in] ptr		адресс блока

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	1	неизвестная ошибка
 **/

int _free (VA ptr)
{
    if (ptr==NULL)
        return INCORRECT_PARAMETRS;
    int i;
    for (i= 0; i<memSize; i++)
    {
        if (ptr==manager[i].first)
        {
            compressionMemory(i);
            return SUCCESS;
        }
    }
    return UNKNOWN_ERROR;

}

/**
 	@func	_read
 	@brief	Чтение информации из блока памяти

	@param	[in] ptr		адресс блока
	@param	[in] pBuffer	адресс буфера куда копируется инфомация
	@param	[in] szBuffer	размер буфера

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	-2	доступ за пределы блока
	@retval	1	неизвестная ошибка
 **/

int _read (VA ptr, void* pBuffer, size_t szBuffer)
{
    if (ptr == NULL || pBuffer == NULL)    //проверка является ли адрес, буфер и размер буфера корректными
        return INCORRECT_PARAMETRS;
    for (int i=0; i<memSize; i++)
    {
        if (!manager[i].isEmpty)
        {
            if (ptr>=manager[i].first && ptr<manager[i].first+manager[i].size)
            {
                if  (szBuffer > (manager[i].first+manager[i].size)-ptr)
                    return OUT_OF_BLOCK;
                else
                {
                    memcpy(pBuffer, ptr, szBuffer);
                    return SUCCESS;
                }
            }
        }
        else return UNKNOWN_ERROR;
    }
}

/**
 	@func	_write
 	@brief	Запись информации в блок памяти

	@param	[in] ptr		адресс блока
	@param	[in] pBuffer	адресс буфера куда копируется инфомация
	@param	[in] szBuffer	размер буфера

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	-2	доступ за пределы блока
	@retval	1	неизвестная ошибка
 **/

int _write (VA ptr, void* pBuffer, size_t szBuffer)
{
    if (ptr == NULL || pBuffer == NULL)    //проверка является ли адрес, буфер и размер буфера корректными
        return INCORRECT_PARAMETRS;
    for (int i=0; i<memSize; i++)
    {
        if (!manager[i].isEmpty)
        {
            if (ptr>=manager[i].first && ptr<manager[i].first+manager[i].size)
            {
                if  (szBuffer > (manager[i].first+manager[i].size)-ptr)
                {
                    return OUT_OF_BLOCK;
                }

                else
                {
                    memcpy(ptr, pBuffer, szBuffer);
                    return SUCCESS;
                }
            }
        }
        else return UNKNOWN_ERROR;
    }
}

/**
 	@func	_init
 	@brief	Инициализация модели менеджера памяти

	@param	[in] n		количество страниц
	@param	[in] szPage	размер страницы

	В варианте 1 и 2 общий объем памяти расчитывается как n*szPage

	@return	код ошибки
	@retval	0	успешное выполнение
	@retval	-1	неверные параметры
	@retval	1	неизвестная ошибка
 **/

int _init (int n, int szPage)
{
    if (n < 1 || szPage < 1 || n*szPage > MAX_MEMORY_SIZE)
        return INCORRECT_PARAMETRS;
    memSize = n*szPage;
    phisMem=(VA)malloc(memSize*sizeof(VA));
    if (phisMem == NULL)
        return UNKNOWN_ERROR;
    manager = malloc(memSize * sizeof(struct Block));
    for (int i = 0; i <= memSize; i++)
        manager[i].isEmpty = true;
    freeMemSize = memSize;
    return SUCCESS;
}

int _free_memory()
{
    free(manager);
    free(phisMem);
}

