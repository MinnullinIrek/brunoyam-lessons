#include <iostream>
#include <thread>
#include <chrono>
#include <array>
#include <stdio.h> 
#include <time.h> 
#include <mutex>

//1 состояние гонки std::mutex;
//2 взаимоблокировка потоков -  std::scoped_lock lock(mutex1, mutex2);

//синхронизация
//1. мьютекс std::mutex m; m.lock(); ... m.unlock();
// std::lock_guard<std::mutex> lc(m);
//2. атомики std::atomic<int> var;
//3. std::condition_variable



const int count = 10000000;

std::mutex mutex;
int global = 0;
std::atomic_int atmic_global;


std::array<double, count> numbers;
double sum = 0;

void fn() {
    std::chrono::milliseconds timespan(100);
    std::this_thread::sleep_for(timespan);
}

void init() {
    for (int i = 0; i < count; ++i) {
        numbers[i] = 1;
    }
}

void sumElements() {
    for (int i = 0; i < count; ++i) {
        sum += numbers[i];
    }
}

void sumElementsFromTo(int start, int finish, double& sum ) {
    for (int i = start; i < finish; ++i) {
        sum += numbers[i];
    }
}


void thread_func(int delta) {

    try {
        for (int i = 0; i < 1000.000; ++i) {


            std::cout << "cicle body start " << std::this_thread::get_id() << "\n";
            std::cout << "this thread id = " << std::this_thread::get_id() << "\n";
            //fn();
             //throw std::exception("random exc");
            //mutex.lock();
            {
                std::lock_guard<std::mutex> lock(mutex);
                global += delta;
            }
            //throw std::exception("random exc");

            //mutex.unlock();

            std::cout << "cicle body end" << std::this_thread::get_id() << "\n";
        }
    }
    catch (...) {
        
    
    }
}

void thread_func_atomic(int delta) {
    for (int i = 0; i < 1000000; ++i) {
        atmic_global += delta;
    }
}

std::mutex mutex1;
int global1;

std::mutex mutex2;
int global2;


int main()
{
    /*
    //std::cout <<  std::this_thread::get_id();
    std::thread th(thread_func_atomic, -1);
    thread_func_atomic(1);
   
    th.join();
    std::cout << "\ngloabal = " << global;
    */

    /*
    init();

    clock_t start = clock();
    double threadSum = 0;
    std::thread th(sumElementsFromTo, 0, count/2, std::ref(threadSum));
    
    double threadSum2 = 0;
    sumElementsFromTo(count / 2, count, threadSum2);

    th.join();
    clock_t end = clock();
    auto sum = threadSum + threadSum2;
    int ms = (end - start) ;



    std::cout << "sum = " << sum << "\ntime = " << ms;
    */
    /*
    std::thread thr1(
        [&]() {
            for (int i = 0; i < 1000; ++i) {
                
                std::scoped_lock lock(mutex1, mutex2);
                global1 += 1;
                std::cout << "thr1 " << i << std::endl;
                global2 += global1;
            }
        }
    );

    std::thread thr2(
        [&]() {
            for (int i = 0; i < 1000; ++i) {
                std::scoped_lock lock(mutex2, mutex1);
                std::cout << "thr2 " << i << std::endl;
                global1 -= 1;
                global2 -= global1;
            }
        }
    );


    thr1.join();
    thr2.join();

    std::cout << global1 << ":" << global2;
    */
    std::cout << std::thread::hardware_concurrency();
    return 0;

}
