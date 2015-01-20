/*
vect_main.cc

Eric Yablunosky

Testing vect object
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "vect.h"

using namespace std;

void nl( int numLines){ for( int loop = 0; loop < numLines; loop++ ) cout << endl; }
//void printVect( Vect aVect){
//	cout << "< ";
//	 for( int dim = 0; dim < aVect.numDims(); dim++ ){
// 	 	  cout << aVect.cmp( dim );
// 	 	  if( dim != ( aVect.numDims() - 1) )
// 	 	  	  cout << ", ";
//      }
// 	 cout << " > ";	
// }

int main(void){
	//double variable = 0;
	double twoVector[3] = {5.0, 1.0};
	double zeroVector[3] = {0.0,0.0,0.0};
	double threeVector[3] = {2.0, 2.0, 2.0};
	double threeVector1[3] = {(-5.0), 3.0, 0.1};
	double threeVector2[3] = {1.0, 2.0, 1.5};
	cout << "Vectors\n\n";
	//cin >>	variable;
	
	Vect vector1(2, twoVector);
	Vect vector2(3, threeVector2);
	Vect vector3(3, threeVector);
	Vect vector4(3, threeVector1);
	Vect vector5(3, zeroVector);

	cout << "v1: " << vector1;
	nl(2);
	vector5 = vector3;
	cout << "vector2: ";
	vector2.print();
	nl(2);

	cout << "v1 + v2 = " << vector1 + vector2;
	nl(2);
	
	cout << "vector3: ";
	vector3.print();
	nl(2);

	cout << "vector4: ";
	vector4.print();
	nl(2);

	cout << "vector5: ";
	vector5.print();
	nl(2);

	/*cout << "vector3 = vector3 + vector2" << endl;
	vector3.print(); cout << " + "; vector2.print(); cout << " = ";
	vector2+=vector3;
	vector2.print();
*/
	//vector5 = vector3.add(vector2);
	//vector5.print();
	nl(2);

	cout << "vector2: ";
	vector2.print();
	nl(2);
	
	cout << "vector3: ";

	vector3.print();
	nl(3);

	cout << "vector2: ";
	vector2.print();
	nl(2);

	cout << "vector4: ";
	vector4.print();
	nl(2);
	cout << "|vector4|^2 = " << vector4.magSq() << endl;
	cout << "vector4 + vector2" << endl;
	vector4.print(); cout << " + "; vector2.print(); cout << " = ";
	(vector4+vector2).print();
	//printVect(vector4.add(vector2));
	//Vect newVect = vector4.add(vector2);
	//newVect.print();
	nl(2);

	cout << "vector2: ";
	vector2.print();
	nl(2);

	cout << "vector4: ";
	vector4.print();
	nl(2);

	cout << "v2 dot v4:" << endl;	
	cout << vector4*vector2;
	nl(2);

	cout << "v5 = v3 times 5:" << endl;	
	cout << vector3 << "* 5 = " <<	(vector3*5) << endl;
	vector5 = (5*vector3);
	cout << "v5: <" << vector5[0] << ", " << vector5[1] << ", " << vector5[2] << ">";
	nl(2);


	//system("PAUSE");
 	return 0;   
}
