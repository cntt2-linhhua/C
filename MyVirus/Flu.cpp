#include "Flu.h"

Flu::Flu() {
	DoBorn();
	InitResistance();
}
Flu::Flu(int m_color)
{
	this->m_color = m_color;
}
Flu::Flu(const Flu *flu)
{
	*this = *flu;
}
Flu::~Flu()
{
	//DoDie();
}
void Flu::setM_color(int m_color)
{
	this->m_color = m_color;
}
int Flu::GetM_color()
{
	return this->m_color;
}
void Flu::DoBorn()
{
	this->m_color = rand() % (2 - 1 + 1) + 1;
}
std::list<MyVirust*> Flu::DoClone()
{
	cout << "Flu was clone " << endl;
	std::list<MyVirust*> vr;
	Flu *flu = new Flu();
	flu->m_resistance = this->m_resistance;
	this->m_color = this->m_color;
	std::string str = this->m_dna;
	for (int i = 0; i < str.size(); i++)
	{
		flu[i] = str[i];
	}
	vr.push_back(flu);
	return vr;
}
void Flu::DoDie()
{
	cout << endl << "Flu was die" << endl;
}
void Flu::InitResistance()
{
	if (m_color == FLU_BLUE)
	{
		this->m_resistance = 10 + rand() % (5 + 1);
		cout << "Flu blue was born: " << m_resistance << "\n";
	}
	else
	{
		this->m_resistance = 10 + rand() % (10 + 1);
		cout << "Flu red was born: " << m_resistance << "\n";
	}
}
