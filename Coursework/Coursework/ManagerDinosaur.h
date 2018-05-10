#pragma once

#include "Dinosaur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class ManagerDinosaur
{
protected:
	static ManagerDinosaur* self;
	ManagerDinosaur();
	~ManagerDinosaur();
private:
	Dinosaur * dnz; // ��������
	int max; // ���-�� ����������
public:
	static ManagerDinosaur* Instance();
	static bool DeleteInstance();

	bool Save(std::string NameFile); // ��������� � ����
	bool Read(std::string NameFile); // ������ �� �����
	bool ReadAdd(std::string NameFile); // ������ �� ����� ��������� � ��������� � ��� ������������
	void Show(); // ���������� ���� ����������
	void AddDinosaur(); // ��������� ������ ���������
	void DeleteDinosaur(); // ������� ���� ����������

};
