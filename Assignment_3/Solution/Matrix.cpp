#include"Matrix.h"
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

/*
* @Author Himanshu Kohli
* Student ID: 40070839
*/



/*
* Default Constructor of the class 
* Assigns the 4 values to 0 and restricts the values to 4
*/

Matrix::Matrix()
{
	matrix.assign(4, 0);
	matrix.reserve(4);
}

/*
* Constructor of the class
* Assigns the 4 values to given parameters and restricts the values to 4
* @param a(const): 0th index value
* @param b(const): 1th index value
* @param c(const): 2th index value
* @param d(const): 3th index value
*/
Matrix::Matrix(const double a,const double b,const double c ,const double d)
{
	matrix.reserve(4);
	matrix.push_back(a);
	matrix.push_back(b);
	matrix.push_back(c);
	matrix.push_back(d);
}

/*
* Copy Constructor of the class
* Assigns value of one Matrix object to another Matrix object
* @param source(const): Matrix from where data is to be copied
*/
Matrix::Matrix(const Matrix& source)
{
	this->matrix.reserve(4);
	this->matrix = source.matrix;
}

/*
* Initializer list of the class
* Assigns list value to Matrix object
* @param list(const): contains list of values
*/
Matrix::Matrix(initializer_list<double> list)
{
	if (list.size() != 4)
		throw invalid_argument("elements in the list must be 4");

	this->matrix.reserve(4);
	for (double i : list)
	{
		matrix.push_back(i);
	}
}

/*
* Assignment operator of the class
* Assigns value of one matrix to another matrix
* @param source: Matrix from where data is to be copied
* @return : returns the Matrix value
*/
Matrix& Matrix::operator=(const Matrix& source)
{
	if (this == &source)
		return *this;
	this->matrix.reserve(4);
	this->matrix = source.matrix;
	return *this;
}

/*
* Destructor of the class
*	prints an endng message 
*/
Matrix::~Matrix(){}

// Member functions

/*
* Returns back the determinant for calling Matrix object
* performs ad - bc (according to assignment)
* @return double : returns ad - bc
* where a is first index value and d is the last index value
*/
double Matrix::determinant() const
{
	// ad - bc
	return ((matrix[0] * matrix[3]) - (matrix[1]*matrix[2]));
}

/*
* Calculates the trace of the matrix
* which is the addition of first and thrid value of vector
* @return (double)a + c 
*/
double Matrix::trace() const
{
	return (matrix[0] + matrix[3]);	// a + c
}

/*
* Finds whether a give matrix is symmetric or not
* @return (bool) true or false {second index value}
*/
bool Matrix::isSymmetric() const
{
	return (matrix[1] == matrix[2]);	// b == c
}

/*
* Checks whether the matrix is similar or not
* by checking trace and determinant of each matrix 
* invoker and argument
* @param rhs: Matrix with which data is to be compared
* @return :(bool) if matrix are equal -> true
*	else -> false
*/
bool Matrix::isSimilar(const Matrix& rhs) const
{
	return ((this->determinant() == rhs.determinant())
				&&
				this->trace() == rhs.trace());	// det and trace
}

/*
* Perform the transpose of the matrix
* @return transposed Matrix object
*/
Matrix Matrix::transpose() const
{
	Matrix m(*this);
	double temp = m.matrix[1];
	m.matrix[1] = m.matrix[2];
	m.matrix[2] = temp;

	return m;
}

/*
* Performs inversion of the matrix
* @returns inversed matrix of the invoking Matrix object
* (1/det)[d  -b]
*		 [-c  a]
*/
Matrix Matrix::inverse() const
{
	Matrix m;
	double det = this->determinant();
	if (det != 0.0)
	{
		m.matrix[0] = this->matrix[3] / det;
		m.matrix[1] = (-this->matrix[1]) / det;
		m.matrix[2] = (-this->matrix[2]) / det;
		m.matrix[3] = this->matrix[0] / det;	
	}
	
	return m;
}


// Compound operators

//  M += M'

/*
* overloading of the += operator where M += M'
* where M and M' are matrices ==> M.operator+=M'; 
* @param (const)rhs: Matrix that is to be added to the invoking Matrix
* @return :(Matrix) returns the reference of the matrix
*/
Matrix& Matrix::operator+=(const Matrix& rhs)
{
	if (this->size() != rhs.size())
		throw invalid_argument("Cannot add two matrices of different size");

	for (int i = 0; i < rhs.size(); ++i)
		this->matrix[i] += rhs.matrix[i];

	return *this;
}

/*
* overloading of the -= operator where M -= M'
* where M and M' are matrices ==> M.operator-=M';
* @param (const)rhs: Matrix that is to be substract to the invoking Matrix
* @return :(Matrix) returns the reference of the matrix
*/
Matrix& Matrix::operator-=(const Matrix& rhs)
{
	if (this->size() != rhs.size())
		throw invalid_argument("Cannot substract two matrices of different size");

	for (int i = 0; i < rhs.size(); ++i)
		this->matrix[i] -= rhs.matrix[i];

	return *this;
}

/*
* overloading of the *= operator where M *= M'
* where M and M' are matrices ==> M.operator*=M';
* @param (const)rhs: Matrix that is to be product to the invoking Matrix
* @return :(Matrix) returns the reference of the matrix
*/
Matrix& Matrix::operator*=(const Matrix& rhs)
{
	if (this->size() != rhs.size())
		throw invalid_argument("Cannot multiply two matrices of different size");

	Matrix m;
	m.matrix[0] = (this->matrix[0] * rhs.matrix[0]) + (this->matrix[1] * rhs.matrix[2]);
	m.matrix[1] = (this->matrix[0] * rhs.matrix[1]) + (this->matrix[1] * rhs.matrix[3]);
	m.matrix[2] = (this->matrix[2] * rhs.matrix[0]) + (this->matrix[3] * rhs.matrix[2]);
	m.matrix[3] = (this->matrix[2] * rhs.matrix[1]) + (this->matrix[3] * rhs.matrix[3]);

	*this = m;
	return *this;
}

/*
* overloading of the /= operator where M /= M'
* where M and M' are matrices ==> M.operator/=M';
* @param (const)rhs: Matrix that is to be divide to the invoking Matrix
* @return :(Matrix) returns the reference of the matrix
*/
Matrix& Matrix::operator/=(const Matrix& rhs)
{
	if (this->size() != rhs.size())
		throw invalid_argument("Cannot divide two matrices of different size");

	Matrix temp = rhs.inverse();
	for (int i = 0; i < rhs.size(); ++i)
		this->matrix[i] *= temp.matrix[i];

	return *this;
}

// M+=a
/*
* overloading of the += operator where M += a ( a is variable)
* where M is a matrix ==> M.operator+=a;
* @param (const)rhs: double variable
* @return :(Matrix) returns the reference of the matrix
*/
Matrix& Matrix::operator+=(const double rhs)
{

	for (int i = 0; i < this->size(); ++i)
		this->matrix[i] += rhs;

	return *this;
}

/*
* overloading of the -= operator where M -= a ( a is variable)
* where M is a matrix ==> M.operator-=a;
* @param (const)rhs: double variable
* @return :(Matrix) returns the reference of the matrix
*/
Matrix& Matrix::operator-=(const double rhs)
{
	for (int i = 0; i < this->size(); ++i)
		this->matrix[i] -= rhs;

	return *this;
}

/*
* overloading of the *= operator where M *= a ( a is variable)
* where M is a matrix ==> M.operator*=a;
* @param (const)rhs: double variable
* @return :(Matrix) returns the resultant reference of the matrix
*/
Matrix& Matrix::operator*=(const double rhs)
{
	for (int i = 0; i < this->size(); ++i)	
	{
		this->matrix[i] *= rhs;
		if (this->matrix[i] == 0)		// checking for -0
			this->matrix[i] = abs(this->matrix[i]);
	}
	return *this;
}

/*
* overloading of the /= operator where M /= a ( a is variable)
* where M is a matrix ==> M.operator/=a;
* @param (const)rhs: double variable
* @return :(Matrix) returns the resultant reference of the matrix
*/
Matrix& Matrix::operator/=(const double rhs)
{
	if (rhs == 0)
		throw overflow_error("Cannot divide by zero");

	for (int i = 0; i < this->size(); ++i)
		this->matrix[i] *= (1/rhs);

	return *this;
}

// Binary Arithmetic operator

// M + M'
/*
* overloading of the + operator where M + M' 
* where M and M' are  matrices ==> M.operator+M'
* @param (const)lhs: Matrix operand 1
* @param (const)rhs: Matrix operand 2
* @return :(Matrix) returns the resultant matrix addition operation
*/
Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	Matrix m = lhs;
	m += rhs;
	return m;
}

/*
* overloading of the - operator where M - M'
* where M and M' are  matrices ==> M.operator+M'
* @param (const)lhs: Matrix operand 1
* @param (const)rhs: Matrix operand 2
* @return :(Matrix) returns the resultant matrix substraction operation
*/
Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
	Matrix m = lhs;
	m -= rhs;
	return m;
}

/*
* overloading of the * operator where M + M'
* where M and M' are  matrices ==> M.operator+M'
* @param (const)lhs: Matrix operand 1
* @param (const)rhs: Matrix operand 2
* @return :(Matrix) returns the resultant matrix multiply operation
*/
Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	Matrix m = lhs;
	m *= rhs;
	return m;
}

/*
* overloading of the / operator where M / M'
* where M and M' are  matrices ==> M.operator/M'
* @param (const)lhs: Matrix operand 1
* @param (const)rhs: Matrix operand 2
* @return :(Matrix) returns the resultant matrix division operation
*/
Matrix operator/(const Matrix& lhs, const Matrix& rhs)
{
	Matrix m = lhs;
	m /= rhs;
	return m;
}

// M + a

/*
* overloading of the + operator where M + a
* where M is matrix and a is a double operator ==> M.operator+(a)
* @param (const)lhs: Matrix operand 1
* @param (const)rhs: is a double variable, operand 2
* @return :(Matrix) returns the resultant matrix addition operation
*/
Matrix operator+(const Matrix& lhs, const double rhs)
{
	Matrix m = lhs;
	m += rhs;
	return m;
}

/*
* overloading of the - operator where M - a
* where M is matrix and a is a double operator ==> M.operator-(a)
* @param (const)lhs: Matrix operand 1
* @param (const)rhs: is a double variable, operand 2
* @return :(Matrix) returns the resultant matrix substraction operation
*/
Matrix operator-(const Matrix& lhs, const double rhs)
{
	Matrix m = lhs;
	m -= rhs;
	return m;
}

/*
* overloading of the * operator where M * a
* where M is matrix and a is a double operator ==> M.operator*(a)
* @param (const)lhs: Matrix operand 1
* @param (const)rhs: is a double variable, operand 2
* @return :(Matrix) returns the resultant matrix multiplication operation
*/
Matrix operator*(const Matrix& lhs, const double rhs)
{
	Matrix m = lhs;
	m *= rhs;
	return m;
}

/*
* overloading of the / operator where M / a
* where M is matrix and a is a double operator ==> M.operator/(a)
* @param (const)lhs: Matrix operand 1
* @param (const)rhs: is a double variable, operand 2
* @return :(Matrix) returns the resultant matrix division operation
*/
Matrix operator/(const Matrix& lhs, const double rhs)
{
	Matrix m = lhs;
	m /= rhs;
	return m;
}

// a + M

/*
* overloading of the + operator where a + M
* where M is matrix and a is a double operator
* @param (const)lhs: is a double variable, operand 1
* @param (const)rhs: Matrix operand 2
* @return :(Matrix) returns the resultant matrix addition operation
*/
Matrix operator+(const double lhs, const Matrix& rhs)
{
	return rhs + lhs;
}

/*
* overloading of the - operator where a - M
* where M is matrix and a is a double operator
* @param (const)lhs: is a double variable, operand 1
* @param (const)rhs: Matrix operand 2
* @return :(Matrix) returns the resultant matrix substraction operation
*/
Matrix operator-(const double lhs, const Matrix& rhs)
{
	return (rhs - lhs) * (-1);
}

/*
* overloading of the * operator where a + M
* where M is matrix and a is a double operator
* @param (const)lhs: is a double variable, operand 1
* @param (const)rhs: Matrix operand 2
* @return :(Matrix) returns the resultant matrix product operation
*/
Matrix operator*(const double lhs, const Matrix& rhs)
{
	return rhs * lhs;
}

/*
* overloading of the / operator where a / M
* where M is matrix and a is a double operator
* @param (const)lhs: is a double variable, operand 1
* @param (const)rhs: Matrix operand 2
* @return :(Matrix) returns the resultant matrix division operation
*/
Matrix operator/(const double lhs, const Matrix& rhs)
{
	return (rhs.inverse() * lhs);
}

// Relational operators == and !=

/*
* overloading of the == operator where M == M'
* where M and M' are matrices
* @param (const)lhs: Matrix operand 1
* @param (const)rhs: Matrix operand 2
* @return :(bool) true if |every element of matrix1 - every element of matrix2 | < e
*   else return false
*/
bool operator==(const Matrix& lhs,const Matrix &rhs)
{
	static const double e = 1.0E-6;
	if (lhs.size() != rhs.size())
		return false;

	for (int i = 0; i < lhs.size(); ++i)
	{
		if (abs(lhs.matrix[i] - rhs.matrix[i]) >= e)
			return false;
	}
	return true;

}

/*
* overloading of the != operator where M != M'
* where M and M' are matrices
* @param (const)lhs: Matrix operand 1
* @param (const)rhs: Matrix operand 2
* @return :(bool) return the inversion of == operator
*/
bool operator!=(const Matrix& lhs,const Matrix & rhs)
{
	return !(lhs == rhs);
}

// Unary operators

/*
* overloading of the +(unary) operator where +M
* where M is a matrix
* @return :(Matrix) return the matrix as it is,
* beacause var a = 10;
*	+a will be 10 and if a = -10 then +a will be -10
*/
Matrix Matrix::operator+() const
{
	return *this;
}

/*
* overloading of the -(unary) operator where +M
* where M is a matrix
* @return :(Matrix) return the negative matrix values,
* beacause var a = 10
*	-a will be -10 and if a = -10 then -a will be 10
*/
Matrix Matrix::operator-() const
{
	return ((*this) * (-1));
}


// pre increment and decrement

/*
* overloading of the ++(unary) operator where ++M
* where M is a matrix
* @return :(Matrix) return pre-increment values of matrix
* beacause var a = 10;
*	++a will be 11 and returned value will be 11
*/
Matrix& Matrix::operator++()
{
	return (*this += 1);
}

/*
* overloading of the --(unary) operator where --M
* where M is a matrix
* @return :(Matrix) return pre-decremented values of matrix
* beacause var a = 10;
*	--a will be 9 and returned value will be 9
*/
Matrix& Matrix::operator--()
{
	return (*this -= 1);
}

// post increment and decrement

/*
* overloading of the ++(unary) operator where M++
* where M is a matrix
* @return :(Matrix) return pre-increment values of matrix
* beacause var a = 10;
*	a++ will be 11 and returned value will be 10
*/
Matrix Matrix::operator++(int)
{
	Matrix temp = *this;
	*this += 1;
	return temp;
}

/*
* overloading of the ++(unary) operator where M--
* where M is a matrix
* @return :(Matrix) return pre-decrement values of matrix
* beacause var a = 10;
*	a-- will be 9 and returned value will be 10
*/
Matrix Matrix::operator--(int)
{
	Matrix temp = *this;
	*this -= 1;
	return temp;
}

// Subscript operator []

/*
* overloading of the [] operator where M[]
* where M is a matrix
* @param index(const): is the index value  
* @return :(double&) returns the double value at specified index
* e.g. M[1] will return the second element in the vector
* or the first column and second row element
* for both read and write values
*/
double& Matrix::operator[](const int index)
{
	if (index < 0 || index > 4)
		throw out_of_range("Matrix is out of range");

	return matrix.at(index);
}

/*
* overloading of the [] operator where M[]
* where M is a matrix
* @param index(const): is the index value
* @return :(double&) returns the double value at specified index
* e.g. M[1] will return the second element in the vector
* or the first column and second row element
* for reading values
*/
const double& Matrix::operator[](const int index) const
{
	if (index < 0 || index > 4)
		throw out_of_range("Matrix is out of range");

	return matrix.at(index);
		
}

// function objects

/*
* overloading of the () operator where M()
* where M is a matrix
* @return :(double) return the determinant value of the matrix
*/
double Matrix::operator()()
{
	return this->determinant();
}

/*
* overloading of the () operator where M(1) or M(2)
* where M is a matrix
* @param value(const): to return 1 or 2 eigen value
* @return :(vector) which contains eigen values
*/
vector<double> Matrix::operator()(const int value)
{
	vector<double> vec = calculateEigenValues();
	vector<double> vec2;
	if (value == 1)
	{
		if (vec.size() == 2)
		{
			vec2.push_back(vec[0]);
		}
		else
		{
			vec2.push_back(vec[0]);
			vec2.push_back(vec[1]);
		}
	}
	else if (value == 2)
	{
		if (vec.size() == 2)
		{
			vec2.push_back(vec[1]);
		}
		else
		{
			vec2.push_back(vec[0]);
			vec2.push_back(vec[2]);
		}
	}
	else
		throw invalid_argument("value can only be 1 or 2");
	return vec2;
}

// Streaming methods

/*
* overloading of the >> operator where cin>>M
* where M is a matrix
* @param in: input stream which has console input stream double values
* @param m: Matrix in which values are to be stored
* @return :the input stream to facilitate chain operation
* eg cin>>a>>b>>c>>d;
*/
istream& operator>>(istream& in, Matrix &m)
{
	for (int i = 0; i<4; i++)
	{
		in >> m.matrix[i];
	}
	return in;
}

/*
* overloading of the << operator where cout<<M
* where M is a matrix
* @param out: output stream which prints double values to console
* @param m: Matrix values that are to be printed
* @return : ouput stream of matrix values
* eg cin<<a<<b<<c<<d;
*/
ostream& operator<<(ostream& out,const Matrix& m)
{
	out << fixed<<setprecision(2);
	out << "|" << setw(8) << left << m[0] << setw(8) << right << m[1] << "|" << endl;
	out << setw(8) << left << "| " << setw(10) << right << " |" << endl;
	out << "|" << setw(8) << left << m[2] << setw(8) << right << m[3] << "|" << endl;
	//out << fixed <<setprecision(0);
	return out;
}


// Helper methods

/*
* Matrix object which returns the size of the vector 
* @return : the size of the matrix
*/
int Matrix::size() const
{
	return matrix.size();
}

/*
* Function to calculate the eigen values of for the Matrix object
* @return :vector which contains the eigen values of the matrix
*/
vector<double> Matrix::calculateEigenValues()
{
	vector<double> vec;
	double delta = calculateDelta();
	if (delta >= 0)
	{
		vec.push_back((trace() + sqrt(delta))/2);
		vec.push_back((trace() - sqrt(delta))/2);
	}
	else
	{
		vec.push_back(trace() / 2);
		vec.push_back(sqrt((abs(delta))) / 2);
		vec.push_back((sqrt((abs(delta))) / 2) * (-1));
	}
	return vec;
}


/*
* function to calculate delta value of the matrix 
* @return :double delta value
*/
double Matrix::calculateDelta()
{
	return ((trace() * trace()) - (4 * determinant()));
}

