#include "MyPoints.h"
#include<iostream>




MyPoints::MyPoints()
{
	
	this->mPosX = 0;
	this->mPosY = 0;
	

}

MyPoints::MyPoints(int x, int y)
{
	this->mPosX = x;
	this->mPosY = y;
}
void MyPoints::Display()
{
	std::cout << "The coordinates of X : " <<this->mPosX<<std::endl;
	std::cout << "The coordinates of Y : " << this->mPosY << std::endl;
}
void MyPoints::SetX(int)
{
	this->mPosX = mPosX;
	this->mPosY = mPosY;
}
int MyPoints::GetX()
{
	return this->mPosX;
}
void MyPoints::SetY(int)
{
	this->mPosY = mPosY;
}
int MyPoints::GetY()
{
	return this->mPosY = mPosY;
}
double MyPoints::Distance(MyPoints *p)
{
	return sqrt((p->mPosX-this->mPosX)*(p->mPosX - this->mPosX)+(p->mPosY-this->mPosY)*(p->mPosY-this->mPosY));
}

MyPoints::~MyPoints()
{
}
