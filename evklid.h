#ifndef EVKLID_H
#define EVKLID_H

// На двух строчках записаны два целых числа.
// Вывести их наибольший общий делитель.

// Решить задачу разными способами.
// 1. Алгоритм Евклида через вычитание
// 2. Алгоритм Евклида через остаток
// 3. Алгоритм Стейнца через битовые операции

#include "itask.h"

class Evklid_minus : public ITask
{
public:
    virtual std::string Run(const std::vector<std::string> &_data) override;
};

class Evklid_mod : public ITask
{
public:
    virtual std::string Run(const std::vector<std::string> &_data) override;
};

class Evklid_bits : public ITask
{
public:
    virtual std::string Run(const std::vector<std::string> &_data) override;
};

#endif // EVKLID_H
