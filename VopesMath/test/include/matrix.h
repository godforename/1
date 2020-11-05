#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>
#include <string>
#include <sstream>

#include "complex.h"

using namespace std;

class Matrix
{
	friend ostream & operator <<(ostream &o, const Matrix& A);

public:
	int n_rows;
	int n_cols;
	double **data;

public:
	Matrix exchange_Row(int row1, int row2);
	Matrix scale_Row(double scale, int row);
	Matrix scale_add_Row(int row1, double scale, int row2);
	Matrix col(int it_col);
	Matrix cat(const Matrix& A);

public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& A);
	Matrix input();

	void clear();

	Matrix& operator =(const Matrix& A);
	Matrix  operator -()const;
	Matrix friend operator +(const Matrix& A, const Matrix& B);
	Matrix friend operator -(const Matrix& A, const Matrix& B);
	Matrix friend operator *(const Matrix& A, const Matrix& B);
	Matrix friend operator *(double scale, const Matrix& B);
	Matrix friend operator /(const Matrix& B, double scale);

	bool friend operator ==(const Matrix& A, const Matrix& B);
	bool friend operator !=(const Matrix& A, const Matrix& B);

	Matrix t()const;
	Matrix inv()const;
	Matrix reduce()const;
	
	double det()const;
	double trac()const;
	int rank()const;
	
	vector<Complex> eigenvalue()const;
	vector<Matrix> QR()const;
};

Matrix pow(Matrix A, int n);
Matrix eye(int n);
Matrix Gram_Schmidt(Matrix A);
Matrix correct(Matrix& A);

#endif