
#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<vector>


/*
* @Author Himanshu Kohli
* Student ID: 40070839
*/


using namespace std;
class Matrix
{
private:

	// matrix holder
	vector<double> matrix;

public:
	// Constructor
	Matrix();	// default constructor
	Matrix(const double, const double, const double, const double);
	Matrix(const Matrix&);	// copy constructor
	Matrix(initializer_list<double> list);

	// Assignment Operator and Destructor
	Matrix& operator=(const Matrix&);	
	~Matrix();

	// Member functions
	double determinant() const;
	double trace() const;
	bool isSymmetric() const;
	bool isSimilar(const Matrix& rhs) const;
	Matrix transpose() const;
	Matrix inverse() const;

	// Compound operators 
	// M' += M
	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
	Matrix& operator*=(const Matrix& rhs);
	Matrix& operator/=(const Matrix& rhs);

	// M' += a
	Matrix& operator+=(const double rhs);
	Matrix& operator-=(const double rhs);
	Matrix& operator*=(const double rhs);
	Matrix& operator/=(const double rhs);
	
	
	//Basic Arithmetic Operators (Binary)
	friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator/(const Matrix& lhs, const Matrix& rhs);

	// M + a
	friend Matrix operator+(const Matrix& lhs, const double rhs);
	friend Matrix operator-(const Matrix& lhs, const double rhs);
	friend Matrix operator*(const Matrix& lhs, const double rhs);
	friend Matrix operator/(const Matrix& lhs, const double rhs);

	// a + M
	friend Matrix operator+(const double lhs, const Matrix& rhs);
	friend Matrix operator-(const double lhs, const Matrix& rhs);
	friend Matrix operator*(const double lhs, const Matrix& rhs);
	friend Matrix operator/(const double lhs, const Matrix& rhs);

	// Relational operators M == M' and M!=M

	friend bool operator==(const Matrix& lhs, const Matrix& rhs);
	friend bool operator!=(const Matrix& lhs, const Matrix& rhs);

	// Unary Operators ++,-- , +, -

	// +M or - M
	Matrix operator+() const;
	Matrix operator-() const;

	// pre increment and post decrement
	Matrix& operator++();
	Matrix& operator--();

	// post increment and post decrement
	Matrix operator++(int);
	Matrix operator--(int);

	// Subscripts operators []

	double& operator[](const int value);	// Read and write
	
	const double& operator[](const int value) const; // read only

	// function objects M(1) or M() returns det(M)
	double operator()();
	vector<double> operator()(const int value);
		
	// Stream functions cin >> M1
	friend istream& operator>>(istream &in, Matrix &m);
	friend ostream& operator<<(ostream &os, const Matrix &m);

	// Helper methods
	int size() const;
	vector<double> calculateEigenValues();
	double calculateDelta();
	friend void printEigenValues(const vector<double> &vec,int type);

};


#endif