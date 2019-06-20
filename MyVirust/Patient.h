#pragma once
#include<iostream>
#include<list>
#include<cstdlib>
#include <Windows.h>
#include "MyVirust.h"
#include "Flu.h"
#include "Dengue.h"
#define DIE 0
#define ALIVE 1
class Patient
{
	private :
		int m_resistance;
		list<MyVirust*> m_virusList;
		int m_state;
		int sum_Viruss_resistance;
	public :
		Patient();
		~Patient();
		void InitResistance();
		void DoStart();
		void TakeMedicine(int medicine_resistance);
		void DoDie();
		int GetState();	
};
