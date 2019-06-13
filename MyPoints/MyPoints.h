#pragma once
class MyPoints
{
private:

public:
	int mPosX;
	int mPosY;
public:
	MyPoints();
	MyPoints(int, int);
	~MyPoints();
	void Display();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	double Distance(MyPoints *p);
};

