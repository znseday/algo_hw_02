#include <cmath>
#include <iostream>

#include "fibonacci.h"
#include "power.h"

// На первой строчке записано целое число N >= 0.
// Найти и вывести на экран точное значение N-ого числа Фибоначчи.

// Решить задачу разными способами.
// 1. Через рекурсию.
// 2. Через итерацию.
// 3. Через формулу золотого сечения.
// 4. Через возведение матрицы в степень.

using namespace std;

uint64_t ConvertVectorToUint64(const vector<string> &_data)
{
    uint64_t N;
    try
    {
        N = stoull(_data[0]);
    }
    catch (exception &e)
    {
        N = 1;
        cout << endl << e.what() << ": could not converted to uint64_t" << endl;
    }
    return N;
}

uint64_t FibonacciRecursive(uint64_t N)
{
    if (N <= 2)
        return 1;

    return FibonacciRecursive(N-1) + FibonacciRecursive(N-2);
}

string Fibonacci_rec::Run(const vector<string> &_data)
{
    if (_data.empty() )
        return "_data.empty()";

    uint64_t N = ConvertVectorToUint64(_data);

    if (N >= 50)  // 53
        return "too big N";
    else
        return to_string(FibonacciRecursive(N));
}

string Fibonacci_iter::Run(const vector<string> &_data)
{
    if (_data.empty() )
        return "_data.empty()";

    uint64_t N = ConvertVectorToUint64(_data);

    uint64_t res;

    if (N <= 2)
        res = 1;
    else
    {
        res = 0;
        uint64_t f1 = 1;
        uint64_t f2 = 1;
        for (uint64_t i = 2; i < N; ++i)
        {
            res = f1 + f2;
            if ( res >= numeric_limits<uint64_t>::max()/2 )
                return "overflow";

            f1 = f2;
            f2 = res;
        }
    }

    return to_string(res);
}


string Fibonacci_gold::Run(const vector<string> &_data)
{
    if (_data.empty() )
        return "_data.empty()";

    uint64_t N = ConvertVectorToUint64(_data);

    long double phi = (1.0l + sqrt(5.0l))/2.0l;

//    uint64_t res = 0.5l + pow(phi, (long double)N) / sqrt(5.0l);
    uint64_t res = 0.5l + Power_2_optim_fast(phi, N) / sqrt(5.0l);

    return to_string(res);
}



Matrix2D::Matrix2D()
{
    a[0][0] = 0;  a[0][1] = 0;
    a[1][0] = 0;  a[1][1] = 0;
}

void Matrix2D::SetIdentity()
{
    a[0][0] = 1;  a[0][1] = 0;
    a[1][0] = 0;  a[1][1] = 1;
}

void Matrix2D:: InitFibo()
{
    a[0][0] = 1;  a[0][1] = 1;
    a[1][0] = 1;  a[1][1] = 0;
}

Matrix2D Matrix2D::operator*(const Matrix2D &m)
{
    Matrix2D res;

    res.a[0][0] = a[0][0]*m.a[0][0] + a[0][1]*m.a[1][0];
    res.a[0][1] = a[0][0]*m.a[0][1] + a[0][1]*m.a[1][1];
    res.a[1][0] = a[1][0]*m.a[0][0] + a[1][1]*m.a[1][0];
    res.a[1][1] = a[1][0]*m.a[0][1] + a[1][1]*m.a[1][1];

    return res; // С включенной оптимизацией копирования и иных накладных расходов не будет
}


string Fibonacci_matrix::Run(const vector<string> &_data)
{
    if (_data.empty() )
        return "_data.empty()";

    uint64_t N = ConvertVectorToUint64(_data);

    Matrix2D res;
    res.SetIdentity();

    Matrix2D base;
    base.InitFibo();

    while (N > 1)
    {
        if ( (N & 1) == 1)
            res = res*base;

        base = base*base;
        N >>= 1;
    }

    res = res*base;

    return to_string(res.a[1][0]);
}




