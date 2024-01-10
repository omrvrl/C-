#pragma once
#include<iostream>
using namespace std;

class TransRot
{
public:
	TransRot();
	//
	string opType;
	//
	void setXYZ(double, double, double);
	//
	void setX(double);
	//
	void setY(double);
	//
	void setZ(double);
	//
	double getX();
	//
	double getY();
	//
	double getZ();
	//
	void translateAlongX(double value);
	//
	void translateAlongY(double value);
	//
	void translateAlongZ(double value);
	//
	void rotateAroundX(double value);
	//
	void rotateAroundY(double value);
	////
	void rotateAroundZ(double value);
	//
	void printResult();
	//
	string getOperationType();
	//
	double getRadianFromDegree(double);
	//
	void updateCoordinates(void);


private:
	double x;
	double y;
	double z;
	double newX;
	double newY;
	double newZ;

};

