#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "itask.h"
#include <iostream>

// На первой строчке записано целое число N >= 0.
// Найти и вывести на экран точное значение N-ого числа Фибоначчи.

// Решить задачу разными способами.
// 1. Через рекурсию.
// 2. Через итерацию.
// 3. Через формулу золотого сечения.
// 4. Через возведение матрицы в степень.


class Matrix2D
{
public:
//    uint64_t a[2][2];
    int a[2][2];
    Matrix2D();
    void SetIdentity();
    void InitFibo();
    Matrix2D operator*(const Matrix2D &m);

    friend std::ostream & operator<<(std::ostream &s, const Matrix2D &m)
    {
        std::cout << m.a[0][0] << "\t" << m.a[0][1] << std::endl;
        std::cout << m.a[1][0] << "\t" << m.a[1][1] << std::endl;
        return s;
    }
};


class Fibonacci_rec : public ITask
{
public:
    virtual std::string Run(const std::vector<std::string> &_data) override;
};

class Fibonacci_iter : public ITask
{
public:
    virtual std::string Run(const std::vector<std::string> &_data) override;
};

class Fibonacci_gold : public ITask
{
public:
    virtual std::string Run(const std::vector<std::string> &_data) override;
};

class Fibonacci_matrix : public ITask
{
public:
    virtual std::string Run(const std::vector<std::string> &_data) override;
};



#endif // FIBONACCI_H
