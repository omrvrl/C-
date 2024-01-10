#include "TransRot.h"
#include <iostream>
using namespace std;



int main() {

	TransRot obj1;
	obj1.setXYZ(3, 4, 5);
	obj1.translateAlongY(10);
	obj1.printResult();
	obj1.rotateAroundZ(90);
	obj1.printResult();

	TransRot obj2;

	obj2.setX(20);
	obj2.setY(15);
	obj2.setZ(50);
	obj2.rotateAroundY(135);
	obj2.printResult();
	obj2.printResult();
	obj2.updateCoordinates();
	obj2.translateAlongZ(-20);
	obj2.printResult();
	

	return 0;
}