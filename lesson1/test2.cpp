#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include <vector>

using namespace std;

/*
typedef vector<vector<int>> Matrix;

int Cofactor(const Matrix& matrix, int x, int y) {
    int size = matrix.size();
    Matrix cofactor_matrix(size - 1, vector<int>(size - 1));

    int cofactor_sign = (x + y) % 2 == 0 ? 1 : -1;
    int cofactor_row = 0;
    for (int i = 0; i < size; i++) {
        if (i == x) continue;

        int cofactor_col = 0;
        for (int j = 0; j < size; j++) {
            if (j == y) continue;

            cofactor_matrix[cofactor_row][cofactor_col] = matrix[i][j];
            cofactor_col++;
        }
        cofactor_row++;
    }

    int cofactor_value = 0;
    if (size - 1 == 1) {
        cofactor_value = cofactor_matrix[0][0];
    } else {
        for (int j = 0; j < size - 1; j++) {
            cofactor_value += cofactor_sign * cofactor_matrix[0][j] * Cofactor(cofactor_matrix, 0, j);
            cofactor_sign *= -1;
        }
    }

    return cofactor_value;
}

Matrix Adjugate_Matrix(const Matrix& matrix) {
    int size = matrix.size();
    Matrix adjugate(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int cofactor = Cofactor(matrix, i, j);
            adjugate[j][i] = cofactor;
        }
    }

    return adjugate;
}

int Determinant(const Matrix& matrix) {
    int size = matrix.size();
    int determinant = 0;

    if (size == 1) {
        determinant = matrix[0][0];
    } else {
        int sign = 1;
        for (int j = 0; j < size; j++) {
            int cofactor = Cofactor(matrix, 0, j);
            determinant += sign * matrix[0][j] * cofactor;
            sign *= -1;
        }
    }

    return determinant;
}

Matrix Inverse_Matrix(const Matrix& matrix) {
    int size = matrix.size();
    Matrix adjugate = Adjugate_Matrix(matrix);
    int determinant = Determinant(matrix);

    Matrix inverse(size, vector<int>(size));

    if (determinant != 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                inverse[i][j] = adjugate[i][j] / determinant;
            }
        }
    }

    return inverse;
}

bool Identity_Matrix(const Matrix& matrix) {
    int size = matrix.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j && matrix[i][j] != 1) {
                return false;
            }
            if (i != j && matrix[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // 示例用法
    Matrix matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix adjugate = Adjugate_Matrix(matrix);
    Matrix inverse = Inverse_Matrix(matrix);
    bool is_identity = Identity_Matrix(matrix);

    // 输出伴随矩阵
    cout << "Adjugate Matrix:" << endl;
    for (int i = 0; i < adjugate.size(); i++) {
        for (int j = 0; j < adjugate.size(); j++) {
            cout << adjugate[i][j] << " ";
        }
        cout << endl;
    }

    // 输出逆矩阵
    cout << "Inverse Matrix:" << endl;
    for (int i = 0; i < inverse.size(); i++) {
        for (int j = 0; j < inverse.size(); j++) {
            cout << inverse[i][j] << " ";
        }
        cout << endl;
    }

    // 判断是否为单位矩阵
    cout << "Is Identity Matrix? " << (is_identity ? "true" : "false") << endl;

    return 0;
}
*/
using namespace std;

#define eps 1e-8
inline int sig(double x)
{
    return (x > eps) - (x < -eps);
}

struct Matrix
{
    int m, n;
    double **val;
    Matrix() {}
    Matrix(int m_, int n_)
    {
        m = m_;
        n = n_;
        this->val = (double **)malloc(sizeof(double *) * m);
        for (int i = 0; i < m; i++)
        {
            this->val[i] = (double *)malloc(sizeof(double) * n);
        }
    }
    void in()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%lf", &this->val[i][j]);
            }
        }
    }
    void out()
    {
        for (int i = 0; i < m; i++)
        {
            printf("%.4lf", this->val[i][0]);
            for (int j = 1; j < n; j++)
            {
                printf(" %.4lf", this->val[i][j]);
            }
            printf("\n");
        }
    }
    Matrix operator*(const double r) const
    {
        int m_ = this->m;
        int n_ = this->n;
        Matrix A = *this;
        Matrix M(m_, n_);
        for (int i = 0; i < m_; i++)
        {
            for (int j = 0; j < n_; j++)
            {
                M.val[i][j] = A.val[i][j] * r;
            }
        }
        return M;
    }
    Matrix operator*(const Matrix B) const
    {
        Matrix A = *this;
        Matrix M(A.m, B.n);
        if (A.n != B.m)
        {
            printf("error\n");
        }
        for (int i = 0; i < A.m; i++)
        {
            for (int j = 0; j < B.n; j++)
            {
                double sum = 0;
                for (int k = 0; k < A.n; k++)
                {
                    sum += A.val[i][k] * B.val[k][j];
                }
                M.val[i][j] = sum;
            }
        }
        return M;
    }
    int Inverse_Number(int n, int arr[])
    {
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[i])
                {
                    num++;
                }
            }
        }
        return num;
    }
    double Determinant()
    {
        Matrix D = *this;
        double det = 0;
        int *arr;
        arr = (int *)malloc(sizeof(int) * D.n);
        for (int i = 0; i < D.n; i++)
        {
            arr[i] = i;
        }
        do
        {
            int inv = Inverse_Number(D.n, arr);
            double tmp = (inv % 2 == 0) ? 1 : -1;
            for (int i = 0; i < D.n; i++)
            {
                tmp *= D.val[i][arr[i]];
            }
            det += tmp;
        } while (next_permutation(arr, arr + D.n));
        return det;
    }

    double Cofactor(int x, int y);

    Matrix Adjugate_Matrix();

    Matrix Inverse_Matrix();

    bool Identity_Matrix();
};

int main(int argc, const char *argv[])
{

    int n;
    scanf("%d", &n);
    Matrix A(n, n);
    A.in();

    Matrix I(n, n);
    I = A.Inverse_Matrix();
    I.out();

    Matrix E1(n, n);
    Matrix E2(n, n);
    E1 = A * I;
    E2 = I * A;
    if (E1.Identity_Matrix() == false)
    {
        printf("A*I error\n");
        E1.out();
    }
    if (E2.Identity_Matrix() == false)
    {
        printf("I*A error\n");
        E2.out();
    }

    return 0;
}

double Matrix::Cofactor(int x, int y)
{
    Matrix A = *this;
    int sign = (x + y) % 2 == 0 ? 1 : -1;
    int row = 0;

    Matrix cofactor_matrix(A.m - 1, A.n - 1);
    for (int i = 0; i < A.m; i++)
    {
        if (i == x)
            continue;

        int col = 0;
        for (int j = 0; j < A.n; j++)
        {
            if (j == y)
                continue;

            cofactor_matrix.val[row][col] = A.val[i][j];
            col++;
        }
        row++;
    }

    double cofactor_value = cofactor_matrix.Determinant() * sign;
    return cofactor_value;
}

Matrix Matrix::Adjugate_Matrix()
{
    Matrix A = *this;
    Matrix adjugate(A.m, A.n);

    for (int i = 0; i < A.m; i++)
    {
        for (int j = 0; j < A.n; j++)
        {
            adjugate.val[j][i] = A.Cofactor(i, j);
        }
    }

    return adjugate;
}

Matrix Matrix::Inverse_Matrix()
{
    Matrix A = *this;
    Matrix adjugate = A.Adjugate_Matrix();
    double determinant = A.Determinant();

    Matrix inverse(A.m, A.n);

    if (sig(determinant) != 0)
    {
        double inv_det = 1.0 / determinant;
        inverse = adjugate * inv_det;
    }

    return inverse;
}

bool Matrix::Identity_Matrix()
{
    Matrix A = *this;

    for (int i = 0; i < A.m; i++)
    {
        for (int j = 0; j < A.n; j++)
        {
            if (i == j && sig(A.val[i][j] - 1.0) != 0)
            {
                return false;
            }
            if (i != j && sig(A.val[i][j]) != 0)
            {
                return false;
            }
        }
    }

    return true;
}
