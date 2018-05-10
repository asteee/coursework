#pragma once

#include "stdafx.h"

class Dinosaur
{
private:
	std::string Type; // ��� ���������
	std::string Food; // ��� �������
	float Size; // ������
	std::string Behavior; // ���������
	std::string Colour; // �����
public:
	Dinosaur() { Type = " "; Food = " "; Size = 0; Behavior = " "; Colour = " "; }
	Dinosaur(std::string type, std::string food, float size, std::string behavior, std::string colour) { Type = type; Food = food; Size = size; Behavior = behavior; Colour = colour; }
	~Dinosaur() {}

	void SetType(std::string type) { Type = type; }
	void SetFood(std::string food) { Food = food; }
	void SetSize(float size) { Size = size; }
	void SetBehavior(std::string behavior) { Behavior = behavior; }
	void SetColour(std::string colour) { Colour = colour; }
	void SetDinosaur(std::string type, std::string food, float size, std::string behavior, std::string colour) { Type = type; Food = food; Size = size; Behavior = behavior; Colour = colour; }

	void Show(); // �������� ���������
	bool Save(ofstream &file);
	bool Read(ifstream &file);
};