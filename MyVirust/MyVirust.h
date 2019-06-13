#pragma once
class MyVirust{
	private:
		char*m_dna;
		int m_resistance;
	public:
		MyVirust();
		~MyVirust();
		MyVirust(char*,int);
		void SetM_dna(char*);
		char* GetM_dna();
		void SetM_resistance(int);
		int GetM_resistance();		
		MyVirust(const MyVirust &p);
		void LoadADNInfomation();
		int ReduceResistance();
		
};
