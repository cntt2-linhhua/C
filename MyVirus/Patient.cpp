#include "Patient.h"

Patient::Patient()
{
	this->InitResistance();
	this->DoStart();
}
Patient::~Patient()
{

}
void Patient::InitResistance()
{
	m_resistance = 1000 + rand() % (8000 + 1);
}
void Patient::DoStart()
{
	m_state = 1;
	int count = 10 + rand() % (10 + 1);
	for (register int i = 0; i<count; i++)
	{
		Sleep(200);
		int random = rand() % 2;
		if (random == 0)
		{
			MyVirust *flu = new Flu();
			m_virusList.push_back(flu);
		}
		else
		{
			MyVirust *dengue = new Dengue();
			m_virusList.push_back(dengue);
		}
	}
}
void Patient::TakeMedicine(int medicine_resistance)
{
	sum_Viruss_resistance = 0;
	cout << " Medicine : " << medicine_resistance;
	for (list<MyVirust*>::iterator it = m_virusList.begin(); it != m_virusList.end();it++ )
	{
		cout << endl << " Before : " << (*it)->GetM_resistance();
		(*it)->ReduceResistance(medicine_resistance);
		cout << endl << " Now : " << (*it)->GetM_resistance() << endl;
		if ((*it)->GetM_resistance() > 0)
		{
			list<MyVirust*> list;
			list = (*it)->DoClone();
			this->m_virusList.insert(it, list.begin(), list.end());
		}
	}
	for (list<MyVirust*>::iterator it = m_virusList.begin(); it != m_virusList.end();)
	{
		if ((*it)->GetM_resistance() <= 0)
		{
			delete (*it);
			it = m_virusList.erase(it);
		}
		else
		{
			sum_Viruss_resistance += (*it)->GetM_resistance();
			++it;
		}
	}
	if (m_virusList.empty())
	{
		cout << "Clear Virus In Patient";
		this->m_state = 0;
	}
	cout << endl << "Patient resistance = " << m_resistance << " Virus resistance : " << sum_Viruss_resistance;
}
void Patient::DoDie()
{
	this->m_state = 0;
	this->m_resistance = 0;
	for (auto v : m_virusList)
	{
		delete v;
	}
	this->m_virusList.clear();
	cout << endl << "Patient was die";
}
int Patient::GetState()
{
	return m_state;
}
