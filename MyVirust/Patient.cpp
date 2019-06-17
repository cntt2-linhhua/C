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
 	m_resistance = 1000 + rand() % (8000+1);
 }
 void Patient::DoStart()
 {
 	m_state = 1;
 	int count = 10+rand()%(10+1);
 	for(register int i =0 ; i<count ; i++)
 	{	Sleep(200);
 		int random = rand()%2;
 		if(random==0)
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
 	cout << " Medicine : " <<medicine_resistance;
 	for(list<MyVirust*>::iterator it = m_virusList.begin();it !=m_virusList.end();it++)
 	{
 		cout<<endl<<" Before : "<<(*it)->GetM_resistance();
 		(*it)->ReduceResistance(medicine_resistance);
 		int temp = (*it)->GetM_resistance();
 		cout<<endl<< " Now : "<<temp<<endl;
 		if(temp>0)
 			sum_Viruss_resistance +=temp;
 			
 	}
  	for(list<MyVirust*>::iterator it = m_virusList.begin();it !=m_virusList.end();)
 	{
 		int temp = (*it)->GetM_resistance();
 		if(temp<=0)
 		{
 			(*it)->DoDie();
 			it = m_virusList.erase(it);
 			//delete *it;
 			//if(m_virusList)
 		}
 		else
 		{
 			list<MyVirust*> temp_list = (*it)->DoClone();
 			for(list<MyVirust*>::iterator tmp = temp_list.begin();tmp != temp_list.end();tmp++)
 				m_virusList.push_front(*tmp);
 			++it;
 		}
 	}
 	if (m_virusList.empty())
 	{
 		cout << "Clear Virus In Patient";
 		this->m_state = 0;
 	}
 	cout<<endl<<"Debug m_resistance = "<<m_resistance <<" Virus resistance : "<<sum_Viruss_resistance;
 }
	void Patient::DoDie()
	{
		this->m_state=0;
		this->m_resistance = 0;
		this->m_virusList.clear();
		cout<<endl<<"Patient was die" ;
	}
	 int Patient::GetState()
	 {
	 //	if(m_resistance <= sum_Viruss_resistance)
	 	//	return 0;
	 //	else return 1;
	 	return m_state;
	 }	
