#pragma once

#include "Singleton.h"
#include "Dinosaur.h"

class ManagerDinosaur : Singleton
{
protected:
	~ManagerDinosaur();
private:
	Dinosaur * dns; // ��������
	int max; // ���-�� ����������
public:
	void Save(); // ��������� � ����
	void Read(); // ������ �� �����
	void ReadAdd(); // ������ �� ����� ��������� � ��������� � ��� ������������
	void Show(); // ���������� ���� ����������
	void AddDinosaur(); // ��������� ������ ���������
	void DeleteDinosaur(); // ������� ���� ����������

};

ManagerDinosaur* ManagerDinosaur::_self = 0;