#include <iostream>
using namespace std;
typedef int *IntPtrType;//d?nh ngh?a ~ define
main()
{
IntPtrType ptr_a, ptr_b, *ptr_c;
ptr_a = new int;//cap phat vung nho cho con tro a
*ptr_a = 3;//gan gia tri tai dia chi ma *prt tro toi  = 3 chinh cai gia tri cua no la a
ptr_b = ptr_a;//con tro b dang tro toi vung nho con tro  a tro toi
cout << *ptr_a << " " << *ptr_b << "\n"; //xuat gia c�i gia tri cua con tro a v� b tro toi 
ptr_b = new int; //cap phat vung nho cho con tro b l� 4 buyt v� kieu int
*ptr_b = 9;//con con tro cua con tro b co nghi la con tro bang tro den chinh no va g�n gia tri cho no l� 9
cout << *ptr_a << " " << *ptr_b << "\n";//xuat ra gia tri cua con tro a , b dang tro toi
*ptr_b = *ptr_a;//g�n gia tri cua con tro p dang tro toi bang gia tri cua con tri cau con tro a dang tro toi
cout << *ptr_a << " " << *ptr_b << "\n";//xuat ra gia tri cua con tro a dang tro toi 
delete ptr_a; //thu hoi vung nho da cap phat cho con tro a truoc do
ptr_a = ptr_b;//con tro a tro toi dua chi con tro b
cout << *ptr_a << " " << *ptr_b << "\n";//xuat ra gia tri cua con tro cua con tro a tro toi
ptr_c = &ptr_a;//con tro cua con tro c tro toi dia chi cua con tro a
cout << *ptr_c << " " << **ptr_c << "\n";//xuat ra cai dia chi cua con tro c dang tro t?i ch�nh l� dia chi cua con tro a
//gia tri cua con tro c dang tro toi
delete ptr_a;//thu h?i vung nho cua con tro b
ptr_a = NULL; //?con tro a ko tro den bat ki phan tu nao
return 0;
}
