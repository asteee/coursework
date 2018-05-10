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
	Dinosaur * dnz; // Динозавр
	int max; // Кол-во динозавров
public:
	static ManagerDinosaur* Instance();
	static bool DeleteInstance();

	bool Save(std::string NameFile); // Сохраняет в файл
	bool Read(std::string NameFile); // Читает из файла
	bool ReadAdd(std::string NameFile); // Читает из файла динозавра и добавляет к уже существующим
	void Show(); // Показывает всех динозавров
	void AddDinosaur(); // Добавляет нового динозавра
	void DeleteDinosaur(); // Удоляет всех динозавров

};
