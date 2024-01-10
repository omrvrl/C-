#include "TransRot.h"
#include<iostream>
#include<cmath>
using namespace std;

#ifndef m_pi
#define m_pi 3.1415926535
#endif 



TransRot::TransRot()
{
	setXYZ(0.0, 0.0, 0.0);
	newX = 0.0;
	newY = 0.0;
	newZ = 0.0;
}

void TransRot::setXYZ(double a, double b , double c)
{
	setX(a);
	setY(b);
	setZ(c);
}

void TransRot::setX(double a)
{
	x = a;
}
void TransRot::setY(double b)
{
	y = b;
}
void TransRot::setZ(double c)
{
	z = c;
}

double TransRot::getX()
{
	return x;
}

double TransRot::getY()
{
	return y;
}

double TransRot::getZ()
{
	return z;
}

void TransRot::translateAlongX(double value)
{
	newX = x + value;
	newY = y;
	newZ = z;
	opType = "translateAlongX";
}

void TransRot::translateAlongY(double value)
{
	newX = x;
	newY = y + value;
	newZ = z;
	opType = "translateAlongY";
}

void TransRot::translateAlongZ(double value)
{
	newX = x;
	newY = y;
	newZ = z + value;
	opType = "translateAlongZ";
}

void TransRot::rotateAroundX(double value)
{
	value = getRadianFromDegree(value);

	double MatrixX[3][3] = { { 1,0,0 },{ 0, cos(value), -sin(value)},{ 0, sin(value), cos(value)}};


	newX = x * MatrixX[0][0] + y * MatrixX[1][0] + z * MatrixX[2][0];
	newY = x * MatrixX[0][1] + y * MatrixX[1][1] + z * MatrixX[2][1];
	newZ = x * MatrixX[0][2] + y * MatrixX[1][2] + z * MatrixX[2][2];

	opType = "RotateAroundX";
}

void TransRot::rotateAroundY(double value)
{
	value = getRadianFromDegree(value);

	double MatrixY[3][3] = { {cos(value),0,sin(value)}, {0,1,0}, {-sin(value),0,cos(value)} };


	newX = x * MatrixY[0][0] + y * MatrixY[1][0] + z * MatrixY[2][0];
	newY = x * MatrixY[0][1] + y * MatrixY[1][1] + z * MatrixY[2][1];
	newZ = x * MatrixY[0][2] + y * MatrixY[1][2] + z * MatrixY[2][2];

	opType = "RotateAroundY";

}

void TransRot::rotateAroundZ(double value)
{
	value = getRadianFromDegree(value);

	double MatrixZ[3][3] = { {cos(value),-sin(value),0}, {sin(value),cos(value),0}, {0,0,1} };
  
	newX = x * MatrixZ[0][0] + y * MatrixZ[1][0] + z * MatrixZ[2][0];
	newY = x * MatrixZ[0][1] + y * MatrixZ[1][1] + z * MatrixZ[2][1];
	newZ = x * MatrixZ[0][2] + y * MatrixZ[1][2] + z * MatrixZ[2][2];

	opType = "RotateAroundZ";

}

void TransRot::printResult()
{
	cout << "P(" << getX() << "," << getY() << "," << getZ() << ")" << "======" << getOperationType() << "========" << "PNEW(" << newX << "," << newY << "," << newZ << ")" << endl;
}

string TransRot::getOperationType()
{
	return opType;
}

double TransRot::getRadianFromDegree(double angle)
{
	return angle*m_pi/180 ;
}

void TransRot::updateCoordinates(void)
{	
	int x_1, y_1, z_1;

	cout << "Assing new coordinates " << endl;
	cin >> x_1 >> y_1 >> z_1;
	setX(x_1);
	setY(y_1);
	setZ(z_1);
	printResult();

}





