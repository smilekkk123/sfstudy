#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1;
std::mutex mutex2;

void function1() {
    mutex1.lock();
    std::cout << "Thread 1: Locked mutex1\n";
    
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟一些耗时操作
    
    mutex2.lock();
    std::cout << "Thread 1: Locked mutex2\n";
    
    mutex1.unlock();
    mutex2.unlock();
}

void function2() {
    mutex2.lock();
    std::cout << "Thread 2: Locked mutex2\n";
    
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟一些耗时操作
    
    mutex1.lock();
    std::cout << "Thread 2: Locked mutex1\n";
    
    mutex2.unlock();
    mutex1.unlock();
}

int main() {
    std::thread thread1(function1);
    std::thread thread2(function2);
    
    thread1.join();
    thread2.join();
    
    return 0;
}