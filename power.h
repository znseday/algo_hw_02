#ifndef POWER_H
#define POWER_H

#include "itask.h"

// На первой строчке записано вещественное число A > 0.
// На второй строчке записано целое число N >= 0.

// Вычислить A^N. Результат вывести на экран в стандартном виде.

// Решить задачу разными способами.
// 1. Через обычные итерации.
// 2. Через степень двойки с домножением.
// 3. Через двоичное разложение показателя степени.

long double Power_2_optim_fast(long double base, uint64_t power);

class Power_iter : public ITask
{
public:
    virtual std::string Run(const std::vector<std::string> &_data) override;
};

class Power_2_mult : public ITask
{
public:
    virtual std::string Run(const std::vector<std::string> &_data) override;
};

class Power_2_optim : public ITask
{
public:
    virtual std::string Run(const std::vector<std::string> &_data) override;
};


#endif // POWER_H
