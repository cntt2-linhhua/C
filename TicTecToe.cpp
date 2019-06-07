#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

void printTable(char arr[3][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j= 0;j<3;j++)
		{
			cout<<arr[i][j]<<" | ";
		}
		cout<<endl;
	}	
}

bool checkRow(char arr[3][3])
{
	for (int i=0;i<3;i++)
	{
		int count=0;
		for (int j=0;j<2;j++)
		{
			if((arr[i][j]==arr[i][j+1]) && (arr[i][j]!=' '))
				count++;
		}
		if(count == 2) {
			return 1;
		}
	}
	return 0;
}

bool checkColumn(char arr[3][3])
{
	for (int i=0;i<3;i++)
	{
		int count =0;
		for (int j=0;j<3;j++)
		{
			if((arr[j][i]==arr[j+1][i]) && arr[j][i]!=' ')
				count ++;			
		}
		if(count == 3-1) {
			return 1;
		}
	}
	return 0;
}

bool checkDiagonalRight(char arr[3][3])
{
	for (int i=0;i<2;i++)
	{
		if((arr[i][2-i]!=arr[i+1][2-1-i]) || arr[i][2-i]==' ')
			return 0;
	}
	return 1;
}

bool checkDiagonalLeft(char arr[3][3])
{
	for (int i=0;i<2;i++)
	{
		if((arr[i][i]!=arr[i+1][i+1]) || arr[i][i]==' ')
			return 0;	
	}
	return 1;
}


bool win(char arr[3][3])
{
	if(checkRow(arr)==1 || checkColumn(arr)==1 || checkDiagonalRight(arr)==1 || checkDiagonalLeft(arr)==1)
		return 1;
	else return 0;
}
void init(char arr[3][3]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			arr[i][j]=' ';
		}
	}
}
bool draw(char arr[3][3])
{
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(arr[i][j]==' '){
				return 0 ;
			}
		}
		return 1;
}

void play(char arr[3][3], string a, string b)
{
	int k=0,h=0,x=0,y=0;
	
	for(int i=0;i<9;i++)
	{
		cout<<"Your Turn Fly - 0 of "<<a<< " : " ; turn : cin>>k;
		x=k /10;
		y=k%10;
		if(x>=3 || y>=3)
		{
			cout<<"The cell you enter is not in the board"<<endl;
			cout<<"Please re-enter:";
			goto turn;
		}
		else if(arr[x][y] != ' ')
		{
			cout<<"The cell you entered already exists!!!"<<endl;
			cout<<"HIHI...Please retype !!! "<<endl;
			goto turn;
		}
		else
		{
			arr[x][y]='X';
			cout<<"row "<<checkRow(arr);
			cout<<"column "<<checkColumn(arr);
			cout<<"left "<<checkDiagonalLeft(arr);
			cout<<"right "<<checkDiagonalRight(arr)<<endl;
			printTable(arr);
		}
		if(win(arr)==1)
		{
			cout<<"Le Joueur " << a << " a gagne partie "<<endl;
			break;
		}else if(draw(arr)==1) 
		{
			cout<<"La partie s'est termine a egalite !"<<endl;
			break;
		}else
		{
			cout<<"Your Turn Fly - 0 of "<< b << " : " ;
			cin>>h;
			x=h /10;
			y=h%10;
			if(x>=3 || y>=3)
		{
			cout<<"The cell you enter is not in the board"<<endl;
			cout<<"Please re-enter:";
			goto turn;
		}
		else if(arr[x][y] != ' ')
		{
			cout<<"The cell you entered already exists!!!"<<endl;
			cout<<"HIHI...Please retype !!! "<<endl;
			goto turn;
		}
		else
		{
			arr[x][y]='O';
		}
		printTable(arr);
		if(win(arr)==1)
		{
			cout<<"Le Joueur " << b << " a gagne partie "<<endl;
			break;
		}else continue;
		}
		
	}
}

int main()
{
	int x;
	string a,b;
	char arr[3][3];
	cout<<"Welcome To Tic-tac-toe game! Play withyour way!" <<endl;;
	cout<<"If you find any problem, please contact john.nguyen@gameloft.com"<<endl;
	cout<<"SELECT YOUR MORE (1 - PLAY GAME, OTHERS - EXIT GAME)"<<endl;cin>>x;
	init(arr);
	switch(x) 
		{
			case 1:
			{
				cin.ignore();
				cout<<"Enter Player 1 Name: ";
				getline(cin,a);
				cout<<"Enter Player 2 Name: ";
				getline(cin,b);
				cout<<" Start !!! "<<endl;
				printTable(arr);
				play(arr,a,b);
				break;
			}
			default :
			{
					cout<<"Exit game"<<endl;
			}
		}
			
	
	return 0;
}
