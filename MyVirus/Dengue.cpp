#include "Dengue.h"
#include "MyVirust.h"

Dengue::Dengue()
{
	DoBorn();
	InitResistance();
}
Dengue::Dengue(char m_protein)
{
	this->m_protein = m_protein;
}
Dengue::~Dengue()
{
	//DoDie();
}
Dengue::Dengue(const Dengue &p)
{
	this->m_dna = p.m_dna;
	this->m_resistance = p.m_resistance;
	this->m_protein = p.m_protein;
}
void Dengue::setM_protein(char m_protein)
{
	this->m_protein = m_protein;
}
char Dengue::getM_protein()
{
	return this->m_protein;
}
void Dengue::DoBorn()
{
	if ((rand() % (3 - 1 + 1) + 1) == NS3_VIRUS)
		m_protein = NS3_VIRUS;
	else if (rand() % (3 - 1 + 1) + 1 == NS5_VIRUS)
		m_protein = NS5_VIRUS;
	else m_protein = E_VIRUS;
}
list<MyVirust*> Dengue::DoClone()
{
	std::list<MyVirust*> vr;
	Dengue *dengue1 = new Dengue();
	Dengue *dengue2 = new Dengue();
	dengue1->m_resistance = this->m_resistance;
	dengue2->m_resistance = this->m_resistance;
	dengue1->m_protein = this->m_protein;
	dengue2->m_protein = this->m_protein;
	string str = this->m_dna;
	for (int i = 0; i < str.size(); i++)
	{
		dengue1->m_dna[i] = str[i];
		dengue2->m_dna[i] = str[i];
	}
	vr.push_back(dengue1);
	cout << "Dengue was clone " << endl;
	vr.push_back(dengue2);
	cout << "Dengue was clone " << endl;
	return vr;
}
void Dengue::DoDie()
{
	cout << endl << "Dengue was die " << endl;
}
void Dengue::InitResistance()
{
	string str="";
	if (m_protein == NS3_VIRUS)
	{
		this->m_resistance = 1 + rand() % (9 + 1);
		str = "NS3_VIRUS";
	}
		
	else if (m_protein == NS5_VIRUS)
	{
		this->m_resistance = 11 + rand() % (9 + 1);
		str = "NS5_VIRUS";
	}
	else
	{
		this->m_resistance = 1 + rand() % (9 + 1);
		str = "E_VIRUS";
	}
	cout << " Dengue "<< str <<" was born : " << m_resistance << "\n";
}
