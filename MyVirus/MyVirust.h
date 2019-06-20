#pragma once
#include<iostream>
#include<list>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include <string>
#define FLU_BLUE 0
#define FLU_RED 1
#define NS3_VIRUS 0
#define NS5_VIRUS 1
#define E_VIRUS 2
using namespace std;

class MyVirust
{
protected:
	char*m_dna;
	int m_resistance;
public:
	MyVirust();
	virtual ~MyVirust();
	MyVirust(char*, int);
	void SetM_dna(char*);
	char* GetM_dna();
	void SetM_resistance(int);
	int GetM_resistance();
	MyVirust(const MyVirust &p);
	void LoadADNInfomation();
	void ReduceResistance(int);
	virtual void DoBorn() = 0;
	virtual list<MyVirust*> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
};

