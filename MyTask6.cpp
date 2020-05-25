#pragma hdrstop

#include "MyTask6.h"

double MyTask :: AverageValue(int hashTableSize, Node **hashTable)
{
	Node *p;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < hashTableSize; i++)
	{
		 p = hashTable[i];
		 while(p != NULL)
		 {
			sum += p->data;
			count++;
			p = p->next;
		 }
	}
	return (double)sum / (double)count;
}

int MyTask :: Amount(int hashTableSize, Node **hashTable)
{
	double average = AverageValue(hashTableSize, hashTable);
	int count = 0;
	Node *p;
	for (int i = 0; i < hashTableSize; i++)
	{
		 p = hashTable[i];
		 while(p != NULL)
		 {
			if((double)p->data > average)
				count++;
			p = p->next;
		 }
	}
	return count;
}

#pragma package(smart_init)