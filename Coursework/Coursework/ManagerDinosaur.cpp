#include "stdafx.h"
#include "ManagerDinosaur.h"

using namespace std;

Dinosaur* renew(Dinosaur *Mas, int Max, int NewMax) {
	Dinosaur *temp = Mas;

	Mas = new Dinosaur[NewMax];
	int max = (Max > NewMax) ? NewMax : Max;

	for (int i = 0; i < max; ++i)
		Mas[i] = temp[i];

	return Mas;
}

void ManagerDinosaur::DeleteDinosaur() {
	if (dnz != NULL) {
		delete[] dnz;
		dnz = NULL;
	}
	max = 0;
}

ManagerDinosaur::~ManagerDinosaur()
{
	DeleteDinosaur();
}

ManagerDinosaur::ManagerDinosaur() {
	max = 0;
	dnz = NULL;
}

bool ManagerDinosaur::Save(string NameFile) {
	ofstream file(NameFile);
	if (!file.is_open()) return false;
	if (dnz == NULL || max == 0) return false;

	file << max << "\n";

	for (int i = 0; i < max; ++i) {
		dnz->Save(file);
	}

	file.close();
	return true;
}

bool ManagerDinosaur::Read(string NameFile) {
	ifstream file(NameFile);
	if (!file.is_open()) return false;
	DeleteDinosaur();

	string temp;

	getline(file, temp);
	max = atoi(temp.c_str);

	dnz = new Dinosaur[max];

	for (int i = 0; i < max; ++i) {
		dnz->Read(file);
	}
	
	file.close();
	return true;
}

bool ManagerDinosaur::ReadAdd(string NameFile) {
	ifstream file(NameFile);
	if (!file.is_open()) return false;

	string temp;

	getline(file, temp);
	int a = atoi(temp.c_str);
	renew(dnz, max, max + a);

	for (int i = max; i < max + a; ++i)
		dnz->Read(file);

	max += a;

	file.close();
	return true;
}

void ManagerDinosaur::Show() {

	for (int i = 0; i < max; ++i) {
		dnz->Show();
	}

	return;
}

