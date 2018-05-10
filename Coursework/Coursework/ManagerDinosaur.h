#pragma once

#include "Singleton.h"
#include "Dinosaur.h"

class ManagerDinosaur : Singleton
{
protected:
	~ManagerDinosaur();
	ManagerDinosaur();
private:
	Dinosaur * dnz; // Динозавр
	int max; // Кол-во динозавров
public:
	bool Save(std::string NameFile); // Сохраняет в файл
	bool Read(std::string NameFile); // Читает из файла
	bool ReadAdd(std::string NameFile); // Читает из файла динозавра и добавляет к уже существующим
	void Show(); // Показывает всех динозавров
	void AddDinosaur(); // Добавляет нового динозавра
	void DeleteDinosaur(); // Удоляет всех динозавров

};

ManagerDinosaur* ManagerDinosaur::_self = 0;