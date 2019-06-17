#include <stdio.h>
#include <cstdlib>
#include "Patient.h"
#include <iostream>
using namespace std;
int main()
{
 Patient p;
 //p.Patient();
 int t = 0;
 while (p.GetState() == 1)
 {
	printf("Take Medicine (0 = NO, 1 = YES): ");
	cin >> t;
	if (t == 1)
	{
		int min = 1;
		int max = 60;
		int medicine_resistance = min + (rand() % (int)(max - min + 1));
		p.TakeMedicine(medicine_resistance);
	}
 }
 return 0;
}
