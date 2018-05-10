#include "stdafx.h"
#include "ManagerDinosaur.h"

ManagerDinosaur* ManagerDinosaur::self = 0;

using namespace std;

ManagerDinosaur* ManagerDinosaur::Instance()
{
	if (!self)
	{
		self = new ManagerDinosaur();
	}
	return self;
}

bool ManagerDinosaur::DeleteInstance()
{
	if (self)
	{
		delete self;
		self = 0;
		return true;
	}
	return false;
}

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
		dnz[i].Save(file);
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
	max = atoi(temp.c_str());

	dnz = new Dinosaur[max];

	for (int i = 0; i < max; ++i) {
		if (!dnz[i].Read(file))
			return false;
	}
	
	file.close();
	return true;
}

bool ManagerDinosaur::ReadAdd(string NameFile) {
	ifstream file(NameFile);
	if (!file.is_open()) return false;

	string temp;

	getline(file, temp);
	int a = atoi(temp.c_str());
	dnz = renew(dnz, max, max + a);

	for (int i = max; i < max + a; ++i)
		if (!dnz[i].Read(file))
			return false;

	max += a;

	file.close();
	return true;
}

void ManagerDinosaur::Show() {

	if (dnz == NULL || max == 0) {
		cout << "No dinosaur\n";
		return;
	}

	for (int i = 0; i < max; ++i) {
		dnz[i].Show();
		cout << "\n";
	}

	return;
}

void ManagerDinosaur::AddDinosaur() {
	dnz = renew(dnz, max, max + 1);
	
	dnz[max].Set();
	++max;

	return;
}
