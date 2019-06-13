#include<iostream>
#include<fstream>
#include "MyVirust.h"

MyVirust::MyVirust()
{
	this->m_dna=NULL;
	this->m_resistance=0;
}

MyVirust::MyVirust(char*,int)
{
	this->m_dna=m_dna;
	this->m_resistance=m_resistance;
}

void MyVirust::SetM_dna(char*)
{
	this->m_dna=m_dna;
}

char* MyVirust::GetM_dna()
{
	return this->m_dna;
}

void MyVirust::SetM_resistance(int m_resistance)
{
	this->m_resistance=m_resistance;
}

int MyVirust::GetM_resistance()
{
	return this->m_resistance;
}		
MyVirust::MyVirust(const MyVirust &p)
{
	this->m_dna=m_dna;
	this->m_resistance=m_resistance;	
}

void MyVirust::LoadADNInfomation()
{
	FILE *fv = fopen("ATGX.bin", "r");
	if (fv == NULL){
		printf("Cannot open file save.bin");
	}
	int count = 0;
	int c;
	while (1) {
		c = fgetc(fv);

		if (feof(fv)) {
			break;
		}
		printf("%c",c);
	}
	printf("\n");
}

int MyVirust::ReduceResistance()
{
	return 0;
}
MyVirust::~MyVirust()
{
	
}
