#include <tuple>
#include <cmath>
#include <iostream>
#include "power.h"

// На первой строчке записано вещественное число A > 0.
// На второй строчке записано целое число N >= 0.

// Вычислить A^N. Результат вывести на экран в стандартном виде.

// Решить задачу разными способами.
// 1. Через обычные итерации.
// 2. Через степень двойки с домножением.
// 3. Через двоичное разложение показателя степени.

using namespace std;

tuple<long double, uint64_t> ConvertVectorToLDoubleAndUint64(const vector<string> &_data)
{
    long double base;
    uint64_t power;

    try
    {
        base = stold(_data[0]);
        power = stoull(_data[1]);
    }
    catch (exception &e)
    {
        base = power = 1;
        cout << endl << e.what() << ": could not converted to numerics" << endl;
    }
    return make_tuple(base, power);
}

string Power_iter::Run(const vector<string> &_data)
{
    if (_data.size() < 2)
        return "_data.size() < 2";

    auto [base, power] = ConvertVectorToLDoubleAndUint64(_data);

    long double res = 1.0l;
    //cout << endl << "!!!!!!   sizeof(res) = " << sizeof(res) << "   !!!" << endl;

    for (uint64_t i = 0; i < power; ++i)
        res *= base;

    char buf[32];
    sprintf(buf, "%.11Lf", res);

    return buf;
}

string Power_2_mult::Run(const vector<string> &_data)
{
    if (_data.size() < 2)
        return "_data.size() < 2";

    auto [base, power] = ConvertVectorToLDoubleAndUint64(_data);

    long double res = 1.0l;

    if (power == 0)
         return to_string(1.0l);

    uint64_t t = 2, old_t = 1;
    res = base;

    while (t < power)
    {
        old_t = t;
        t *= 2;
        res *= res;
    }

    for (uint64_t i = old_t; i < power; ++i )
        res *= base;

    char buf[32];
    sprintf(buf, "%.11Lf", res);

    return buf;
}

long double Power_2_optim_fast(long double base, uint64_t power)
{
    long double res = 1.0l;

    if (power == 0)
         return 1.0l;

    while (power > 1)
    {
        if ( (power & 1) == 1 )
            res *= base;
        base *= base;
        power >>= 1;
    }

    return res*base;
}

string Power_2_optim::Run(const vector<string> &_data)
{
    if (_data.size() < 2)
        return "_data.size() < 2";

    auto [base, power] = ConvertVectorToLDoubleAndUint64(_data);

//    long double res = 1.0l;

//    if (power == 0)
//         return to_string(1.0l);

//    while (power > 1)
//    {
//        if ( (power & 1) == 1 )
//            res *= base;
//        base *= base;
//        power >>= 1;
//    }
    long double res = Power_2_optim_fast(base, power);

    char buf[32];
    sprintf(buf, "%.11Lf", res);

    return buf;
}

