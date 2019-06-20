#pragma once
#include "MyVirust.h"
#include<iostream>
using namespace std;
class Dengue : public MyVirust
{
private:
	char m_protein;
public:
	Dengue();
	Dengue(char);
	~Dengue();
	Dengue(const Dengue &p);
	void setM_protein(char m_protein);
	char getM_protein();
	void DoBorn();
	list<MyVirust*> DoClone();
	void DoDie();
	void InitResistance();
};
