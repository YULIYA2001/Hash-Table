#ifndef MyTask6H
#define MyTask6H

#include "Hash.h"

class MyTask : public Hash
{
	public:
	int Amount(int, Node**);             // ���-�� ������, ����������� ������� ��������
	private:
	double AverageValue(int, Node**);    // ������� �������� ���� ������
};

#endif
