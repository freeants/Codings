/**
 * threadtst.cpp
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <thread>
using namespace std;

void print_time()
{
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
    cout << ss.str();
}

/*
 * sleep for 1 second
 */
void func1()
{
    print_time();
    cout << " In func1(), thread-[" << this_thread::get_id() << "] is waking up" << endl;
    this_thread::sleep_for(chrono::seconds(1));
}

/*
 * sleep for 2 second
 */
void func2()
{
    print_time();
    cout << " In func2(), thread-[" << this_thread::get_id() << "] is waking up" << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

/*
 * sleep for 3 second
 */
void func3()
{
    print_time();
    cout << " In func3(), thread-[" << this_thread::get_id() << "] is waking up" << endl;
    this_thread::sleep_for(chrono::seconds(3));
}

int main(int argc, char const *argv[])
{
    /* none threaded code execution */
    auto t0 = chrono::high_resolution_clock::now(); //get start time
    func1();
    func2();
    func3();
    auto t1 = chrono::high_resolution_clock::now(); //get end time
    cout << "Sequential execution time: " << chrono::duration<double, milli>(t1 - t0).count() << " ms" << endl;

    /* threaded code execution */
    auto t2 = chrono::high_resolution_clock::now(); //get start time
    thread th1(func1);
    thread th2(func2);
    thread th3(func3);
    th1.join();
    th2.join();
    th3.join();
    auto t3 = chrono::high_resolution_clock::now(); //get end time
    cout << "Threaded execution time: " << chrono::duration<double, milli>(t3 - t2).count() << " ms" << endl;

    return 0;
}