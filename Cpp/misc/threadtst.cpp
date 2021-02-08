/**
 * threadtst.cpp
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <thread>
using namespace std;

/*
 * sleep for 1 second
 */
void func()
{
    this_thread::sleep_for(chrono::seconds(1));
    cout << "[thread-" << this_thread::get_id() << "] is waking up" << endl;
}

void print_time()
{
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
    cout << "now is: " << ss.str() << endl;
}

int main(int argc, char const *argv[])
{
    print_time();
    /* none threaded code execution */
    auto t0 = chrono::high_resolution_clock::now(); //get start time
    func();
    func();
    func();
    auto t1 = chrono::high_resolution_clock::now(); //get end time
    cout << "Sequential execution time: " << chrono::duration<double, milli>(t1 - t0).count() << " ms" << endl;

    print_time();
    /* threaded code execution */
    auto t2 = chrono::high_resolution_clock::now(); //get start time
    thread th1(func);
    thread th2(func);
    thread th3(func);
    th1.join();
    th2.join();
    th3.join();
    auto t3 = chrono::high_resolution_clock::now(); //get end time
    cout << "Threaded execution time: " << chrono::duration<double, milli>(t3 - t2).count() << " ms" << endl;

    print_time();
    return 0;
}
