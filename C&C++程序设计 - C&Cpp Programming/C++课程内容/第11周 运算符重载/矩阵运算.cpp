#include <iostream>
#include <string>
using namespace std;

/********* Begin *********/
//矩阵类的声明
class Matrix;
Matrix operator+(Matrix &m1, Matrix &m2);
Matrix operator-(Matrix &m1, Matrix &m2);
Matrix operator*(Matrix &m1, Matrix &m2);

class Matrix
{
    private:
        int row;    // 行
        int column; // 列
        int matrix[10][10];
    public:
        Matrix(int r, int c):row(r), column(c) {}
        void Fill(int value);
        void Set(int i, int j, int value);
        int Get(int i, int j);
        void Print();
        int Row()       {   return row;    }
        int Column()    {   return column; }
        friend Matrix operator+(Matrix &m1, Matrix &m2);
        friend Matrix operator-(Matrix &m1, Matrix &m2);
        friend Matrix operator*(Matrix &m1, Matrix &m2);
};
//矩阵类的定义

void Matrix::Fill(int value)
{
    int i, j;
    for (i=0; i<row; i++)
    {
        for (j=0; j<column; j++)
        {
            matrix[i][j] = value;
        }
    }
}

void Matrix::Set(int i, int j, int value)
{
    matrix[i][j] = value;
}

int Matrix::Get(int i, int j)
{
    return matrix[i][j];
}

void Matrix::Print()
{
    int i, j;
    for (i=0; i<row; i++)
    {
        for (j=0; j<column; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

//实现矩阵加法
Matrix operator+(Matrix &m1, Matrix &m2) 
{
    Matrix temp(m1);
    int i, j;
    for (i=0; i<m1.Row(); i++)
    {
        for (j=0; j<m1.Column(); j++)
        {
            temp.matrix[i][j] += m2.matrix[i][j];
        }
    }
    return temp;
}

//实现矩阵减法
Matrix operator-(Matrix &m1, Matrix &m2)
{
    Matrix temp(m1);
    int i, j;
    for (i=0; i<m1.Row(); i++)
    {
        for (j=0; j<m1.Column(); j++)
        {
            temp.matrix[i][j] -= m2.matrix[i][j];
        }
    }
    return temp;
}

//实现矩阵乘法
Matrix operator*(Matrix &m1, Matrix &m2)
{
    Matrix temp(m1.Row(), m2.Column());
    int i, j, k;
    for (i=0; i<m1.Row(); i++)
    {
        for (j=0; j<m2.Column(); j++)
        {
            int sum=0;
            for (k=0; k<m2.Row(); k++)
            {
                sum += m1.matrix[i][k] * m2.matrix[k][j];
            }
            temp.matrix[i][j] = sum;
        }
    }
    return temp;
}
/********* End *********/

int main(void)
{
	int i, j;
	cin >> i >> j;
	Matrix m1(i, j), m2(i, j), m3(j, i);
	m1.Fill(1);
	m2.Fill(2);
	m3.Fill(0);
	for (int s = 0 ; s < i ; s++) {
		for (int c = 0 ; c < j ; c++) {
			if (s == c)
				m3.Set(s, c, s + 1);
		}
	}
/*
    cout<<"m1 ="<<endl;
    m1.Print();

    cout<<"m2 ="<<endl;
    m2.Print();

    cout<<"m3 ="<<endl;
    m3.Print();
*/
	cout << "m1 + m2 :" << endl ;
	(m1 + m2).Print();
	cout << "m1 - m2 :" << endl ;
	(m1 - m2).Print();
	cout << "m1 * m3 :" << endl ;
	(m1 * m3).Print();

	return 0;
}