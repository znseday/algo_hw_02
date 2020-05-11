#include <cmath>
#include <iostream>
#include <tuple>

// На двух строчках записаны два целых числа.
// Вывести их наибольший общий делитель.

// Решить задачу разными способами.
// 1. Алгоритм Евклида через вычитание
// 2. Алгоритм Евклида через остаток
// 3. Алгоритм Стейнца через битовые операции

#include "evklid.h"

using namespace std;

tuple<uint64_t, uint64_t> ConvertVectorToTwoUint64(const vector<string> &_data)
{
    uint64_t a, b;
    try
    {
        a = stoull(_data[0]);
        b = stoull(_data[1]);
    }
    catch (exception &e)
    {
        a = b = 1;
        cout << endl << e.what() << ": could not converted to uint64_t" << endl;
    }
    return make_tuple(a, b);
}

string Evklid_minus::Run(const vector<string> &_data)
{
    if (_data.size() < 2)
        return "_data.size() < 2";

    auto [a, b] = ConvertVectorToTwoUint64(_data);

    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return to_string(a);
}


string Evklid_mod::Run(const vector<string> &_data)
{
    if (_data.size() < 2)
        return "_data.size() < 2";

    auto [a, b] = ConvertVectorToTwoUint64(_data);

    while (a && b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }

    return to_string( (a > b) ? a : b );
}


uint64_t gcd(uint64_t u, uint64_t v)
{
    // simple cases (termination)
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);

    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);

    return gcd((v - u) >> 1, u);
}


string Evklid_bits::Run(const vector<string> &_data)
{
    if (_data.size() < 2)
        return "_data.size() < 2";

    auto [a, b] = ConvertVectorToTwoUint64(_data);

    return to_string(gcd(a, b));
}
