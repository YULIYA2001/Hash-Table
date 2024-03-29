#pragma hdrstop

#include "Hash.h"

Hash :: Hash(int tableSize)
{
	hashTableSize = tableSize;
	hashTable = new Node*[hashTableSize];
	for (int i = 0; i < hashTableSize; i++)
		hashTable[i] = NULL;
}

// ���-������� ���������� �������
int Hash :: Index(T data)
{
	return (data % hashTableSize);
}

// ������� ������ ������� �� ��������� data
Node* Hash :: FindNode(T data)
{
	Node *p;
	p = hashTable[Index(data)];
	while (p && !compEQ(p->data, data))
		p = p->next;
	return p;
}

Node* Hash :: InsertNode(T data)
{
	Node *p, *p0;
	int index = Index(data);
	if ((p = new Node) == 0)
	{
		Application->Title = "ERROR";
		ShowMessage("�������� ������");
		exit(1);
	}
	p0 = hashTable[index];
	hashTable[index] = p;
	p->next = p0;
	p->data = data;
	return p;
}

void Hash :: DeleteNode(T data)
{
	Node *p0, *p;
	int index = Index(data);
	p0 = 0;
	p = hashTable[index];
	while(p && !compEQ(p->data, data))
	{
		p0 = p;
		p = p->next;
	}
	if (!p)
		return;
	if (p0)
		p0->next = p->next;
	else
		hashTable[index] = p->next;
	delete p;
 }

#pragma package(smart_init)
