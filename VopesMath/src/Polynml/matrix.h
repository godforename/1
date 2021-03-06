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



Matrix::Matrix()
{
	this->n_rows = 0;
	this->n_cols = 0;
	this->data = NULL;
}

Matrix::Matrix(int rows, int cols)
{
	this->n_rows = rows;
	this->n_cols = cols;
	this->data = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		this->data[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			this->data[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& A)
{
	int rows = A.n_rows;
	int cols = A.n_cols;

	this->n_rows = rows;
	this->n_cols = cols;

	this->data = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		this->data[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			this->data[i][j] = A.data[i][j];
		}
	}
}

Matrix Matrix::input()
{
	int rows, cols;
	cout << "Input the rows of your matrix:";
	cin >> rows;
	cout << "Input the cols of your matrix:";
	cin >> cols;

	*this = Matrix(rows, cols);
	cout << "Input the data of your matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> this->data[i][j];
		}
	}
	cout << "Input end!" << endl;

	return *this;
}

Matrix& Matrix::operator =(const Matrix& A)
{
	this->clear();

	int rows = A.n_rows;
	int cols = A.n_cols;

	this->n_rows = rows;
	this->n_cols = cols;

	this->data = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		this->data[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			this->data[i][j] = A.data[i][j];
		}
	}
	return *this;
}

void Matrix::clear()
{
	int rows = this->n_rows;

	for (int i = 0; i < rows; i++)
	{
		delete this->data[i];
	}
	delete this->data;

	this->data = NULL;
	this->n_rows = 0;
	this->n_cols = 0;
}

Matrix Matrix::operator -()const
{
	int rows = this->n_rows;
	int cols = this->n_cols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->data[i][j] = -this->data[i][j];
		}
	}

	return *this;
}

Matrix operator +(const Matrix& A, const Matrix& B)
{
	int rows_A = A.n_rows;
	int cols_A = A.n_cols;

	int rows_B = B.n_rows;
	int cols_B = B.n_cols;

	if (rows_A != rows_B || cols_A != cols_B)
	{
		cout << "[ Error in \"Matrix A + Matrix B\":" << endl
			<< "  A.n_rows != B.n_rows || A.n_cols != B.n_cols is not permitted! ]" << endl;
		exit(-1);
	}

	Matrix C(rows_A, cols_A);
	for (int i = 0; i < rows_A; i++)
	{
		for (int j = 0; j < cols_A; j++)
		{
			C.data[i][j] = A.data[i][j] + B.data[i][j];
		}
	}

	return C;
}

Matrix operator -(const Matrix& A, const Matrix& B)
{
	return A + (-B);
}

Matrix operator *(const Matrix& A, const Matrix& B)
{
	int rows_A = A.n_rows;
	int cols_A = A.n_cols;

	int rows_B = B.n_rows;
	int cols_B = B.n_cols;

	if (cols_A != rows_B)
	{
		cout << "[ Error in \"Matrix A * Matrix B\":" << endl
			<< "  A.n_cols != B.n_rows is not permitted!" << endl;
		exit(-1);
	}

	int n = cols_A;

	Matrix C(rows_A, cols_B);
	for (int i = 0; i < rows_A; i++)
	{
		for (int j = 0; j < cols_B; j++)
		{
			double S = 0;
			for (int k = 0; k < n; k++)
			{
				S += A.data[i][k] * B.data[k][j];
			}
			C.data[i][j] = S;
		}
	}

	return C;
}

Matrix operator *(double scale, const Matrix& A)
{
	int rows = A.n_rows;
	int cols = A.n_cols;
	Matrix B(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			B.data[i][j] = scale * A.data[i][j];
		}
	}

	return B;
}

Matrix operator *(const Matrix& A, double scale)
{
	return scale * A;
}

Matrix operator /(const Matrix& A, double scale)
{
	return 1.0 / scale * A;
}

bool operator ==(const Matrix& A, const Matrix& B)
{
	int rows_A = A.n_rows;
	int cols_A = A.n_cols;

	int rows_B = B.n_rows;
	int cols_B = B.n_cols;

	if (rows_A != rows_B || cols_A != cols_B)
	{
		return false;
	}

	for (int i = 0; i < rows_A; i++)
	{
		for (int j = 0; j < cols_A; j++)
		{
			if (A.data[i][j] != B.data[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

bool operator !=(const Matrix& A, const Matrix& B)
{
	return !(A == B);
}

Matrix Matrix::t()const
{
	int rows_B = this->n_cols;
	int cols_B = this->n_rows;

	Matrix B(rows_B, cols_B);
	for (int i = 0; i < rows_B; i++)
	{
		for (int j = 0; j < cols_B; j++)
		{
			B.data[i][j] = this->data[j][i];
		}
	}

	return B;
}

double Matrix::trac()const
{
	int rows = this->n_rows;
	int cols = this->n_cols;
	if (rows != cols)
	{
		cout << "[ Error in \"double Matrix::trac()\":" << endl
			<< "  rows != cols is not permitted!" << endl;
		exit(-1);
	}

	double T = 0;
	for (int i = 0; i < rows; i++)
	{
		T += this->data[i][i];
	}

	return T;
}

Matrix eye(int n)
{
	Matrix In(n, n);

	for (int i = 0; i < n; i++)
	{
		In.data[i][i] = 1;
	}

	return In;
}

ostream & operator <<(ostream& o, const Matrix& B)
{
	Matrix A = B;
	correct(A);
	int rows = A.n_rows;
	int cols = A.n_cols;
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (A.data[i][j] >= 0)
			{
				o << " " << A.data[i][j] << " ";
			}
			else
			{
				o << A.data[i][j] << " ";
			}
		}
		o << endl;
	}

	return o;
}

Matrix Matrix::exchange_Row(int row1, int row2)
{
	Matrix elementary_exchange_Mat = eye(this->n_rows);

	elementary_exchange_Mat.data[row1][row1] = 0;
	elementary_exchange_Mat.data[row1][row2] = 1;

	elementary_exchange_Mat.data[row2][row2] = 0;
	elementary_exchange_Mat.data[row2][row1] = 1;

	*this = elementary_exchange_Mat * (*this);

	return *this;
}

Matrix Matrix::scale_Row(double scale, int row)
{
	Matrix elementary_scale_Mat = eye(this->n_rows);

	elementary_scale_Mat.data[row][row] = scale;

	*this = elementary_scale_Mat * (*this);

	return *this;
}

Matrix Matrix::scale_add_Row(int row1, double scale, int row2)
{
	Matrix elementary_scaleadd_Mat = eye(this->n_rows);

	elementary_scaleadd_Mat.data[row2][row1] = scale;

	*this = elementary_scaleadd_Mat * (*this);

	return *this;
}

int it_row_max(Matrix A, int it_row, int it_col)
{
	double row_max = A.data[it_row][it_col];
	int it_Row_Max = it_row;
	for (int row = it_row + 1; row < A.n_rows; row++)
	{
		if (abs(A.data[row][it_col]) > abs(row_max))
		{
			row_max = A.data[row][it_col];
			it_Row_Max = row;
		}
	}
	return it_Row_Max;
}

Matrix mirror(const Matrix& A)
{
	int rows = A.n_rows;
	int cols = A.n_cols;

	Matrix B(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			B.data[i][j] = A.data[rows - 1 - i][cols - 1 - j];
		}
	}

	return B;
}

Matrix Matrix::reduce()const
{
	int cols = this->n_cols;
	int rows = this->n_rows;

	Matrix Result = *this;

	for (int it_row = 0; it_row < rows; it_row++)
	{
		int it_col_nonzero = -1;
		for (int it_col = it_row; it_col < cols; it_col++)
		{
			for (int subit_row = it_row; subit_row < rows; subit_row++)
			{
				if (!isZero(Result.data[subit_row][it_col]))
				{
					it_col_nonzero = it_col;
					break;
				}
			}
			if (it_col_nonzero != -1)
			{
				break;
			}
		}

		if (it_col_nonzero == -1)
		{
			break;
		}

		int row_main = it_row_max(Result, it_row, it_col_nonzero);
		if (it_row != row_main)
		{
			Result.exchange_Row(it_row, row_main);
		}

		Result.scale_Row(1.0 / Result.data[it_row][it_col_nonzero], it_row);

		for (int subit_row = 0; subit_row < rows; subit_row++)
		{
			if (subit_row != it_row)
			{
				double scale = -Result.data[subit_row][it_col_nonzero] / Result.data[it_row][it_col_nonzero];
				Result.scale_add_Row(it_row, scale, subit_row);
			}
		}
	}
	return Result;
}

Matrix Matrix::inv()const
{
	int rows = this->n_rows;
	int cols = this->n_cols;

	if (rows != cols)
	{
		cout << "[ Error in \"Matrix Matrix::inv()const\":" << endl
			<< "  rows != cols is not permitted! ]" << endl;
		exit(-1);
	}
	if (this->det() == 0)
	{
		cout << "[ Error in \"Matrix Matrix::inv()const\":" << endl
			<< "  det(A) = 0, then, A has no inverse! ]" << endl;
		exit(-1);
	}

	int n = rows;

	Matrix Temp(n, 2 * n);
	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < n; j++)
		{
			Temp.data[i][j] = this->data[i][j];
		}
		Temp.data[i][n + i] = 1;
	}

	Temp = Temp.reduce();

	Matrix Result(n, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Result.data[i][j] = Temp.data[i][rows + j];
		}
	}

	return Result;
}

double Matrix::det()const
{
	int rows = this->n_rows;
	int cols = this->n_cols;

	if (rows != cols)
	{
		cout << "[ Error in \"double Matrix::det()const\":" << endl
			<< "  n_rows != n_cols is not permitted!" << endl;
		exit(-1);
	}

	int n = rows;

	Matrix Result = *this;
	int times_change = 0;
	for (int it_row = 0; it_row < n - 1; it_row++)
	{
		int it_col_nonzero = -1;
		for (int it_col = it_row; it_col < n; it_col++)
		{
			for (int subit_row = it_row; subit_row < n; subit_row++)
			{
				if (Result.data[subit_row][it_col] != 0)
				{
					it_col_nonzero = it_col;
					break;
				}
			}
			if (it_col_nonzero >= 0)
			{
				break;
			}
		}

		int row_main = it_row_max(Result, it_row, it_col_nonzero);
		if (it_row != row_main)
		{
			times_change++;
			Result.exchange_Row(it_row, row_main);
		}

		for (int subit_row = it_row + 1; subit_row < rows; subit_row++)
		{
			double scale = -Result.data[subit_row][it_col_nonzero] / Result.data[it_row][it_col_nonzero];
			Result.scale_add_Row(it_row, scale, subit_row);
		}
	}

	double Det = 1;
	for (int i = 0; i < n; i++)
	{
		Det *= Result.data[i][i];
	}

	int sgn = 1;
	for (int i = 1; i <= times_change; i++)
	{
		sgn = -sgn;
	}

	return sgn * Det;
}

Matrix correct(Matrix& A)
{
	int rows = A.n_rows;
	int cols = A.n_cols;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (A.data[i][j] > -1E-6 && A.data[i][j] < 1E-6)
			{
				A.data[i][j] = 0;
			}
		}
	}
	return A;
}

int Matrix::rank()const
{
	int rows = this->n_rows;
	int cols = this->n_cols;

	Matrix Result = *this;
	int times_change = 0;
	for (int it_row = 0; it_row < rows - 1; it_row++)
	{
		int it_col_nonzero = -1;
		for (int it_col = it_row; it_col < cols; it_col++)
		{
			for (int subit_row = it_row; subit_row < rows; subit_row++)
			{
				if (Result.data[subit_row][it_col] != 0)
				{
					it_col_nonzero = it_col;
					break;
				}
			}
			if (it_col_nonzero >= 0)
			{
				break;
			}
		}

		int row_main = it_row_max(Result, it_row, it_col_nonzero);
		if (it_row != row_main)
		{
			times_change++;
			Result.exchange_Row(it_row, row_main);
		}

		for (int subit_row = it_row + 1; subit_row < rows; subit_row++)
		{
			double scale = -Result.data[subit_row][it_col_nonzero] / Result.data[it_row][it_col_nonzero];
			Result.scale_add_Row(it_row, scale, subit_row);
		}
	}

	Matrix Test(rows + 1, cols + 1);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 1; j < cols + 1; j++)
		{
			Test.data[i][j] = Result.data[i][j - 1];
		}
	}

	correct(Test);

	int Rank = 0;
	for (int col = 1; col < cols + 1; col++)
	{
		for (int row = 0; row < rows; row++)
		{
			if (Test.data[row][col] != 0 && Test.data[row][col - 1] == 0 && Test.data[row + 1][col] == 0)
			{
				Rank++;
			}
		}
	}

	return Rank;
}

Matrix Matrix::col(int n)
{
	int rows = this->n_rows;
	int cols = this->n_cols;
	if (n < 0 || n >= cols)
	{
		cout << "[ Error in \"Matrix Matrix::col(int n)\":" << endl
			<< "  n is not in area! ]" << endl;
		exit(-1);
	}

	Matrix COL_n(rows, 1);
	for (int it_row = 0; it_row < rows; it_row++)
	{
		COL_n.data[it_row][0] = this->data[it_row][n];
	}

	return COL_n;
}

Matrix Matrix::cat(const Matrix& A)
{
	int rows_src = this->n_rows;
	int cols_src = this->n_cols;
	int rows_new = A.n_rows;
	int cols_new = A.n_cols;

	if (rows_src != rows_new)
	{
		cout << "[ Error in \"Matrix Matrix::cat(const Matrix& A)\":" << endl
			<< "  rows must be equal! ]" << endl;
		exit(-1);
	}

	int rows = rows_src;
	int cols = cols_src + cols_new;

	Matrix Result(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols_src; j++)
		{
			Result.data[i][j] = this->data[i][j];
		}
		for (int j = cols_src; j < cols; j++)
		{
			Result.data[i][j] = A.data[i][j - cols_src];
		}
	}

	*this = Result;

	return *this;
}

Matrix Gram_Schmidt(Matrix A)
{
	int rows = A.n_rows;
	int cols = A.n_cols;
	// if(A.rank() != cols)
	// {
	// 	cout << "[ Error in \"Matrix Gram_Schmidt(Matrix A)\":" << endl
	// 		 << "  A.rank() != A.n_cols is not permitted! ]" << endl;
	// 	exit(-1);
	// }

	Matrix v0 = A.col(0);
	Matrix Norm = v0.t() * v0;
	double norm = sqrt(Norm.data[0][0]);
	v0 = v0 / norm;
	Matrix Result = v0;

	for (int it_col = 1; it_col < cols; it_col++)
	{
		Matrix xk = A.col(it_col);

		Matrix S(rows, 1);

		for (int i = 0; i < it_col; i++)
		{
			Matrix vi = Result.col(i);

			Matrix Nume = xk.t() * vi;
			double nume = Nume.data[0][0];

			Matrix Deno = vi.t() * vi;
			double deno = Deno.data[0][0];

			S = S + nume / deno * vi;
		}

		Matrix v = xk - S;

		S.clear();

		Norm = v.t() * v;
		norm = sqrt(Norm.data[0][0]);
		if (!isZero(norm))
		{
			v = v / norm;
		}

		Result.cat(v);
	}

	return Result;
}

vector<Matrix> Matrix::QR()const
{
	int rows = this->n_rows;
	int cols = this->n_cols;
	// if(this->rank() != cols)
	// {
	// 	cout << "[ Error in \"vector<Matrix> Matrix::QR()const\":" << endl
	// 		 << "  this->rank() != cols is not permitted! ]" << endl;
	// 	exit(-1);
	// }

	Matrix Q = Gram_Schmidt(*this);

	Matrix R = Q.t() * (*this);
	correct(R);

	vector<Matrix> Result;
	Result.push_back(Q);
	Result.push_back(R);
	return Result;
}

/*double max(vector<double> X)
{
	vector<double>::iterator it_Max = X.begin();
	for (vector<double>::iterator it = X.begin(); it != X.end(); it++)
	{
		if (*it > *it_Max)
		{
			it_Max = it;
		}
	}
	return *it_Max;
}*/

Matrix extractMat(const Matrix& A, int it_col)
{
	Matrix Result(2, 2);

	Result.data[0][0] = A.data[it_col][it_col];
	Result.data[0][1] = A.data[it_col][it_col + 1];
	Result.data[1][0] = A.data[it_col + 1][it_col];
	Result.data[1][1] = A.data[it_col + 1][it_col + 1];

	return Result;
}

bool conver(const Matrix& A, double epsillon)
{
	int rows = A.n_rows;
	int cols = A.n_cols;
	if (rows != cols)
	{
		cout << "[ Error in \"bool conver(const Matrix& A)\":" << endl
			<< "  A.n_rows != A.n_cols is not permitted! ]" << endl;
		exit(-1);
	}

	int n = rows;

	if (n < 3)
	{
		return true;
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j <= i - 2; j++)
		{
			if (abs(A.data[i][j]) > epsillon)
			{
				return false;
			}
		}
	}

	for (int i = 1; i < n - 1; i++)
	{
		if (abs(A.data[i][i - 1]) > epsillon)
		{
			if (abs(A.data[i + 1][i]) > epsillon)
			{
				return false;
			}
		}

	}

	return true;
}

vector<Complex> Matrix::eigenvalue()const
{
	double epsillon = 1E-7;

	int rows = this->n_rows;
	int cols = this->n_cols;

	if (rows != cols)
	{
		cout << "[ Error in \"vector<Complex> Matrix::eigenvalue()const\":" << endl
			<< "  rows != cols is not permitted! ]" << endl;
		exit(-1);
	}

	vector<Complex> Eigenvalue;

	int n = rows;

	if (n == 2)
	{
		Complex b = -this->trac();
		Complex c = this->det();

		Complex lambda1 = (-b + pow(pow(b, 2) - 4 * c, 0.5)) / 2;
		Complex lambda2 = (-b - pow(pow(b, 2) - 4 * c, 0.5)) / 2;

		Eigenvalue.push_back(lambda1);
		Eigenvalue.push_back(lambda2);

		return Eigenvalue;
	}

	Matrix A = *this;
	vector<double> b;
	b.push_back(1);
	int times = 0;
	int N = n * (n - 1) / 2 - n / 2;

	while (!conver(A, epsillon) && times <= 2000)
	{
		double u = A.data[n - 1][n - 1];
		Matrix B = A - u * eye(n);
		vector<Matrix> qr = B.QR();
		Matrix Q = qr[0];
		Matrix R = qr[1];
		A = R * Q + u * eye(n);

		times++;
	}

	for (int j = 0; j < n - 1; j++)
	{
		if (abs(A.data[j + 1][j]) > epsillon)
		{
			Matrix subMat = extractMat(A, j);
			vector<Complex> Lambda = subMat.eigenvalue();
			Eigenvalue.push_back(Lambda[0]);
			Eigenvalue.push_back(Lambda[1]);
			Lambda.clear();
		}
		else if (abs(A.data[j][j - 1]) <= epsillon)
		{
			Eigenvalue.push_back(R2C(A.data[j][j]));
		}
	}
	if (abs(A.data[n - 1][n - 2]) < epsillon)
	{
		Eigenvalue.push_back(R2C(A.data[n - 1][n - 1]));
	}

	return Eigenvalue;
}
#endif