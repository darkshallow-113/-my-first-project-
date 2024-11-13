#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}HP;

void HeapInit(HP* php);
// 堆的销毁
void HeapDestory(HP* hp);
// 堆的插入
void HeapPush(HP* hp, HPDataType x);
// 堆的删除
void HeapPop(HP* hp);
// 取堆顶的数据
HPDataType HeapTop(HP* hp);
// 堆的数据个数
int HeapSize(HP* hp);
// 堆的判空
int HeapEmpty(HP* hp);

void Swap(HPDataType* p1, HPDataType* p2);
void AdjustUp(HPDataType* a, int child);
void Adjustdown(HPDataType* a, int n, int parent);


