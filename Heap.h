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
// �ѵ�����
void HeapDestory(HP* hp);
// �ѵĲ���
void HeapPush(HP* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(HP* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(HP* hp);
// �ѵ����ݸ���
int HeapSize(HP* hp);
// �ѵ��п�
int HeapEmpty(HP* hp);

void Swap(HPDataType* p1, HPDataType* p2);
void AdjustUp(HPDataType* a, int child);
void Adjustdown(HPDataType* a, int n, int parent);


