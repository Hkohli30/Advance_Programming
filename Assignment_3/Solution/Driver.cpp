#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include "Matrix.h"
using namespace std;

/*
* @Author Himanshu Kohli
* Student ID: 40070839
*/


/*
Tests class Matrix. Specifically, tests constructors, compound assignment
operator overloads, basic arithmetic operator overloads, unary +, unary -,
pre/post-increment/decrement, subscripts, function objects, eigenvalues,
input/output operators, isSymetric, isSimilar, determinant, trace, and
equality relational operators.

The test starts with matrix

|2.00 -1.00|
|          |
|1.00  2.00|

with these two complex eigenvalues:
root 1: 2 +1i
root 2: 2 -1i

@return 0 to indicate success.
*/

/*
* Free Function overrided from Matrix.h
* this function prints the eigen values of the of the matrix
* checks the size of vector if size is 2 the roots are complex
* else roots are size is 1 the roots are real
* @param vec(vector<double>): inputs the vector of eigen values
* @return value: (1 or 2) prints the first or second eigen values
*/
void printEigenValues(vector<double> &vec, int value)
{
	
	if (vec.size() == 2)
	{
		if(value == 1)
			cout << "Root : " << vec[0] << " +" << vec[1] << "i" << endl;
		else
			cout << "Root : " << vec[0] <<" "<< vec[1] << "i" << endl;
	}
	else
		cout <<setprecision(2)<< "Root : " << vec.at(0) << endl;
		

}


int main()
{
	Matrix m1(2, -1, 1, 2); // test constructor
	cout << "m1\n" << m1 << endl;    // operator<<, the output operator

	Matrix  m1Inv = m1.inverse();    // inverse
	cout << "m1.invers()\n" << m1Inv << endl;

	Matrix m1Inv_times_m1 = m1Inv * m1;
	cout << "m1 * m1.invers()\n" << m1Inv_times_m1 << endl;
	// the inverse of any 2x2 mutiplied by the 2x2 itself must give the identity 2x2 
	assert(m1Inv_times_m1 == Matrix(1, 0, 0, 1));

	Matrix m1_times_m1Inv = m1 * m1Inv;
	cout << "m1.invers() * m1\n" << m1_times_m1Inv << endl;
	// any 2x2 mutiplied by its inverse must give the identity 2x2 
	assert(m1_times_m1Inv == Matrix(1, 0, 0, 1));

	cout << "det(m1) =   " << m1.determinant() << "\n";
	cout << "trace(m1) = " << m1.trace() << "\n\n";

	// test function object, operator()(int)
	std::vector<double> root1 = m1(1); // real = 2.0, imag = 1
	assert(std::abs(root1[0] - 2) < 1.e-6);
	assert(std::abs(root1[1] - 1) < 1.e-6);
	// implement this free function to print a given eigenvalue (see output)
	printEigenValues(root1,1);    // root 1: 2 +1i	printEigenValues(root1, 1);
								   // test function object, operator()(int)
	std::vector<double> root2(m1(2)); // real = 2.0, imag = -1
	assert(std::abs(root2[0] - 2) < 1.e-6);
	assert(std::abs(root2[1] - (-1)) < 1.e-6);
	// implement this free function to print a given eigenvalue
	printEigenValues(root2, 2);   // root 2: 2 -1i
	cout << "\n";

	Matrix m2 = m1 + 1;  // Mat + int, and assignment op=
	assert(m2 == Matrix(3, 0, 2, 3));
	cout << "m2\n" << m2 << endl;

	m2 = 1 + m1;  // op=, int + Mat
	assert(m2 == Matrix(3, 0, 2, 3));

	Matrix m3 = m2 - 1;  // Mat -int
	assert(m3 == m1);
	cout << "m3\n" << m3 << endl;

	Matrix m4 = 1 - m3; // int - Mat 
	cout << "m4\n" << m4 << endl;
	assert(m4 == Matrix(-1, 2, 0, -1));


	Matrix m5 = m4 * 5; // Mat * int
	cout << "m5\n" << m5 << endl;
	assert(m5 == Matrix(-5, 10, 0, -5));

	Matrix m6 = 10 * m5; // int * Mat
	cout << "m6\n" << m6 << endl;
	assert(m6 == Matrix(-50, 100, 0, -50));
	assert(m6 / 10 == m5);  // Mat / int
	assert(10 / m6 == 10 * m6.inverse());  // int / Mat, inverse
	assert(5 * m4 * 10 == m6);  // int * Mat * int == Mat

	Matrix m7 = m1++;
	cout << "m1\n" << m1 << endl;
	cout << "m7\n" << m7 << endl;
	assert(m7 == m1 - Matrix(1, 1, 1, 1));

	Matrix m8 = --m1;  // --Mat
	cout << "m1\n" << m1 << endl;
	cout << "m8\n" << m8 << endl;
	assert(m8 == m1);
	m8--;  // Mat--
	cout << "m8\n" << m8 << endl;
	assert(m1 == 1 + m8);
	assert(m1 - 1 == m8);
	assert(-m1 + 1 == -m8);
	assert(2 * m1 == m8 + m1 + 1);
	assert(m1 * m1 == m1 * (1 + m8));
	cout << "m8 is " << (m8.isSymmetric() ? "" : "not") << " symmetric\n";
	Matrix m9(123, 6, 6, 4567.89);
	cout << "m9\n" << m9 << endl;
	cout << "m9 is " << (m9.isSymmetric() ? "" : "not") << " symmetric\n";

	// subscripts (non-const)
	m9[0] = 3;
	m9[1] = 1;
	m9[2] = 7;
	m9[3] = 4;
	cout << "m9\n" << m9 << endl;
	assert(m9 == Matrix(3, 1, 7, 4));
	cout << "det(m1) =   " << m1() << "\ntrace(m1) = " << m1.trace() << "\n\n";
	cout << "det(m9) =   " << m9() << "\ntrace(m9) = " << m9.trace() << "\n\n";
	cout << "m9 is " << (m9.isSimilar(m1) ? "" : "not") << " similar to m1\n";

	// subscripts (const version)
	const Matrix cm9{ m9 };
	cout << "cm9\n" << cm9 << endl;

	m9 += m9;
	cout << "m9\n" << m9 << endl;
	assert(m9 == 2 * Matrix(3, 1, 7, 4));

	Matrix m10;
	m10 += (m9 / 2);
	cout << "m10\n" << m10 << endl;
	assert(m10 == Matrix(3, 1, 7, 4));

	m10 *= 2;
	cout << "m10\n" << m10 << endl;
	assert(m10 == m9);

	m10 /= 2;
	cout << "m10\n" << m10 << endl;
	assert(m10 == m9 / 2);

	m10 += 10;
	cout << "m10\n" << m10 << endl;
	assert(m10 == (m9 + 20) / 2);

	m10 -= 10;
	cout << "m10\n" << m10 << endl;
	assert(m10 == 0.5 * m9);

	//--------------------------------------------------
	// revision 1: begin
	//--------------------------------------------------

	// testing transpose()
	Matrix m11 = m10.transpose();
	cout << "m11\n" << m11 << endl;
	assert(m10 == m11.transpose());

	//testing operator>>
	Matrix m12;

	cout << "In response to the following prompt, \n";
	cout << "enter the numbers 10, 20, 30, 40, in that order\n\n";

	cout << "To create the following 2x2 matrix" << endl;
	cout << "|a   b|" << endl;
	cout << "|     |" << endl;
	cout << "|c   d|" << endl;
	cout << "Enter four numbers a, b, c, d in that order" << endl;
	
	
	cin >> m12;
	cout << "\nm12\n" << m12 << endl;
	assert(m12 == Matrix(10, 20, 30, 40));

	// testing unary operators + and -
	Matrix m13 = -m11;
	cout << "m13\n" << m13 << endl;
	assert(+m11 == -m13);

	//--------------------------------------------------
	// revision 1: end
	//--------------------------------------------------

	cout << "\n\n\n";
	Matrix m200 = { 1,2,3,4 };
	vector<double> r1 = m200(1);
	vector<double> r2 = m200(2);

	printEigenValues(r1, 1);
	printEigenValues(r2, 2);

	cout << "Test completed successfully!" << endl;
	return 0;
}

