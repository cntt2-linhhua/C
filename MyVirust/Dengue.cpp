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
		DoDie();
	}
	Dengue::Dengue(const Dengue &p)
	{
		this->m_dna=p.m_dna;
		this->m_resistance=p.m_resistance;
		this->m_protein=p.m_protein;
	}
	void Dengue::setM_protein(char m_protein)
	{
		this->m_protein=m_protein;
	}
	char Dengue::getM_protein()
	{
		return this->m_protein;
	}
	void Dengue::DoBorn()
	{
		if((rand()%(3-1+1)+1)==NS3_VIRUS)
			m_protein=NS3_VIRUS;
		else if(rand()%(3-1+1)+1==NS5_VIRUS)
				m_protein = NS5_VIRUS;
			else m_protein=E_VIRUS;
	}
	list<MyVirust*> Dengue::DoClone()
	{
		std::list<MyVirust*> vr;
		MyVirust *dengue = this;
		vr.push_back(dengue);
		
		cout<<"Dengue was clone "<<endl;
		return vr;
	}
	void Dengue::DoDie()
	{
		cout<<endl<<"Dengue was die "<<endl;
	}
	void Dengue::InitResistance()
	{
		if(m_protein == NS3_VIRUS)
			m_protein = 1 + rand()%(9+1);
		else if(m_protein == NS5_VIRUS)
				m_protein = 11 + rand()%(9+1);
			else 
				m_protein = 21 + rand()%(9+1);
		cout<< " Dengue was born : " <<m_resistance <<"\n";
	}
