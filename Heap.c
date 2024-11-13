#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
// �ѵĳ�ʼ��
void HeapInit(HP* php) {
	assert(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}
// �ѵ�����
void HeapDestory(HP* php)
{
	assert(php);
	free(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}
// �ѵĲ���
void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->_size == php->_capacity)
	{
		int newcapacity = php->_capacity == 0 ? 4 : php->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->_a = tmp;
		php->_capacity = newcapacity;
	}
	php->_a[php->_size] = x;
	php->_size++;

	AdjustUp(php->_a, php->_size - 1);
}
// �ѵ�ɾ��
void HeapPop(HP* php)
{
	assert(php);
	assert(php->_size > 0);
	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;

	Adjustdown(php->_a, php->_size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(HP* php) {
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}
// �ѵ����ݸ���
int HeapSize(HP* php) {
	return sizeof(php->_a) / sizeof(HPDataType);
}
// �ѵ��п�
int HeapEmpty(HP* php) {
	assert(php);

	return php->_size == 0;
}
//����
void Swap(HPDataType* p1, HPDataType* p2) {
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//���ϵ���
void AdjustUp(HPDataType* a, int child) {
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//���µ���
void Adjustdown(HPDataType* a, int n, int parent) {
	//�ȼ�������С
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
//������
void HeadSort(int* a,int n)
{
	//���򣬽�С��
	//���򣬽����
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	//������ʼ��
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(a, n, i);
	}
	
	int end = n - 1;
	while (end > 0)
	{// ���Ѷ�Ԫ�������һ��Ԫ�ؽ���
		Swap(&a[0], &a[end]);
		// ����ʣ�ಿ�ֵĶ�
		Adjustdown(a, end, 0);
		--end;
	}
}
