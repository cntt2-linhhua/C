#pragma once
#include<iostream>
#include<list>
#include "MyVirust.h"
using namespace std;
class Flu : public MyVirust
{
	private:
		int m_color;
	public:
		Flu();
		Flu(int m_color);
		Flu(const Flu *flu);
		~Flu();
		void setM_color(int);
		int GetM_color();
		void DoBorn();
		list<MyVirust*> DoClone();
		void DoDie();
		void InitResistance();		
};
