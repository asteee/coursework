#include "Dinosaur.h"

using namespace std;

void Dinosaur::Show() {

	cout << "Type: " << Type << endl;
	cout << "Food: " << Food << endl;
	cout << "Size: " << Size << endl;
	cout << "Behavior: " << Behavior << endl;
	cout << "Colour: " << Colour << endl;

	return;
}

bool Dinosaur::Save(ofstream &file) {
	if (!file.is_open())
		return false;

	file << Type << "\n";
	file << Food << "\n";
	file << Size << "\n";
	file << Behavior << "\n";
	file << Colour << "\n";

	return true;
}

bool Dinosaur::Read(ifstream &file) {
	if (!file.is_open())
		return false;

	string temp;

	getline(file, Type);
	getline(file, Food);
	getline(file, temp);
	getline(file, Behavior);
	getline(file, Colour);

	Size = atoi(temp.c_str); // Преобразует строку в число

	return true;
}

