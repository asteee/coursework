// Coursework.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ManagerDinosaur.h"

#define N 500 // Максимальная длинна названия файла

using namespace std;

string EntryNameFile(string str2) {
	char str[N] = "";
	cout << str2;
	cin >> str;
	return str;
}

int main()
{
	int c = 0;
	
	while (1) {
		system("cls");
		cout << "1.Show \n2.Add dinosaur \n3.Delete all dinosaur \n4.Save in file \n5.Read from a file(new dinosaur)\n6.Read from a file(add dinosaur)  \n0.Exit\n";
		cin >> c;

		switch (c) {
		case 0:
			return 0;
		case 1:
			ManagerDinosaur::Instance()->Show();
			break;
		case 2:
			ManagerDinosaur::Instance()->AddDinosaur();
			break;
		case 3:
			ManagerDinosaur::Instance()->DeleteDinosaur();
			break;
		case 4:
			if(ManagerDinosaur::Instance()->Save(EntryNameFile("Entry name file: ")))
				cout << "Saved successfully\n";
			else cout << "Eror file or missing a creature\n";
			break;
		case 5:
			if (ManagerDinosaur::Instance()->Read(EntryNameFile("Entry name file: ")))
				cout << "Read successfully\n";
			else cout << "Eror file\n";
			break;
		case 6:
			if (ManagerDinosaur::Instance()->ReadAdd(EntryNameFile("Entry name file: ")))
				cout << "Read successfully\n";
			else cout << "Eror file\n";
			break;
		}

		Sleep(1000);
		c = 0;
	}

    return 1;
}

