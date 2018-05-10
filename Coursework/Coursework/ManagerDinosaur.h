#pragma once

#include "Singleton.h"
#include "Dinosaur.h"

class ManagerDinosaur : Singleton
{
protected:
	~ManagerDinosaur();
	ManagerDinosaur();
private:
	Dinosaur * dnz; // ��������
	int max; // ���-�� ����������
public:
	bool Save(std::string NameFile); // ��������� � ����
	bool Read(std::string NameFile); // ������ �� �����
	bool ReadAdd(std::string NameFile); // ������ �� ����� ��������� � ��������� � ��� ������������
	void Show(); // ���������� ���� ����������
	void AddDinosaur(); // ��������� ������ ���������
	void DeleteDinosaur(); // ������� ���� ����������

};

ManagerDinosaur* ManagerDinosaur::_self = 0;