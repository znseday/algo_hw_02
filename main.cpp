#include <iostream>

#include "itask.h"
#include "tester.h"

#include "evklid.h"
#include "power.h"
#include "fibonacci.h"

using namespace std;
namespace fs = std::experimental::filesystem;

int main()
{
//    Evklid_minus evklid_minus;
//    Evklid_mod evklid_mod;
//    Evklid_bits evklid_bits;
//    Tester testerEvklid(&evklid_minus, "Evklid_minus", fs::current_path().string() + "\\2.GCD");
//    testerEvklid.AddTask(&evklid_mod, "Evklid_mod");
//    testerEvklid.AddTask(&evklid_bits, "Evklid_bits");
//    testerEvklid.RunTasks();


//    Power_iter power_iter;
//    Power_2_mult power_2_mult;
//    Power_2_optim power_2_optim;
//    Tester testerPower(&power_iter, "Power_iter", fs::current_path().string() + "\\3.Power");
//    testerPower.AddTask(&power_2_mult, "Power_2_mult");
//    testerPower.AddTask(&power_2_optim, "Power_2_optim");
//    testerPower.RunTasks();

    Fibonacci_rec fibonacci_rec;
    Fibonacci_iter fibonacci_iter;
    Fibonacci_gold fibonacci_gold;
    Fibonacci_matrix fibonacci_matrix;
    Tester testerFibonacci(&fibonacci_rec, "Fibonacci_rec", fs::current_path().string() + "\\4.Fibo");
    testerFibonacci.AddTask(&fibonacci_iter, "Fibonacci_iter");
    testerFibonacci.AddTask(&fibonacci_gold, "Fibonacci_gold");
    testerFibonacci.AddTask(&fibonacci_matrix, "Fibonacci_matrix");
    testerFibonacci.RunTasks();

    return 0;
}
