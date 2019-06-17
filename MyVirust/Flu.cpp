#include"Flu.h"

	Flu::Flu(){
		DoBorn();
		InitResistance();
	}
	Flu::Flu(int m_color)
	{
		this->m_color=m_color;
	}
	Flu::Flu(const Flu *flu)
	{
		*this=*flu;
	}
	Flu::~Flu()
	{
		DoDie();
	}
	void Flu::setM_color(int m_color)
	{
		this->m_color=m_color;
	}
	int Flu::GetM_color()
	{
		return this->m_color;
	}
	void Flu::DoBorn()
	{
		this->m_color = rand()%(2-1+1) +1;
	}
	std::list<MyVirust*> Flu::DoClone()
	{
		cout<<"Flu was clone "<<endl;
		std::list<MyVirust*> vr;
		MyVirust *flu = this;
		vr.push_back(flu);
		return vr;
	}
	void Flu::DoDie()
	{
		cout<<endl<<"Flu was die"<<endl;
	}
	void Flu::InitResistance()
	{
		if(m_color == FLU_BLUE)
		{
			m_resistance = 10 + rand()%(5+1);
			cout<<"Flu blue was born: "<<m_resistance<<"\n";
		}
		else
		{
			m_resistance = 10 + rand()%(10+1);
			cout<<"Flu red was born: "<<m_resistance<<"\n";
		}
	}	

