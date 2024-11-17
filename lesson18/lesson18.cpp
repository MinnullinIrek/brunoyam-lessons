#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <chrono>
#include <fstream>

#include "log.hpp"



void fn() {
    std::chrono::milliseconds timespan(100);
    std::this_thread::sleep_for(timespan);
}






int main() {
    
   

    //int count = 1000;

    //std::function<void(int)> lambda = [](int cnt) {
    //    for (int i = 0; i < cnt; ++i) {
    //        std::cout << "hello " << std::this_thread::get_id() << std::endl;
    //    }
    //};
        //std::thread thr(lambda);
    //thr.join();

    //std::future<void> fut = std::async(std::launch::async, lambda, count);
    //lambda(count);
    //fut.get();
    //....
    //....

    

    Log log;

    while (true) {
        std::cout << "thread id =" << std::this_thread::get_id() << " enter message :\n";
        std::string mess;
        std::cin >> mess;
        log.putMessage(mess);
    }


    return 0;
}

