#pragma once

#include "Singleton.h"
#include "Dinosaur.h"

class ManagerDinosaur : Singleton
{
protected:
	~ManagerDinosaur();
private:
	Dinosaur * dns; // Динозавр
	int max; // Кол-во динозавров
public:
	void Save(); // Сохраняет в файл
	void Read(); // Читает из файла
	void ReadAdd(); // Читает из файла динозавра и добавляет к уже существующим
	void Show(); // Показывает всех динозавров
	void AddDinosaur(); // Добавляет нового динозавра
	void DeleteDinosaur(); // Удоляет всех динозавров

};

ManagerDinosaur* ManagerDinosaur::_self = 0;