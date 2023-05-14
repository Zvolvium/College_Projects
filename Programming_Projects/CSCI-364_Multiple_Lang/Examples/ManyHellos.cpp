#include <iostream>
#include <thread>
#include <sstream>

int thread_num = 10;

void hello (int tid){
    std::ostringstream oss;
    oss << "Hello from thread " << tid << std::endl;
    std::cout << oss.str();
}

int main (int argc, char* argv[]){
    std::thread t[thread_num];

    for (int i = 0; i < thread_num; i++){
        t[i] = std::thread(hello, i);
    }

    std::cout << "Hello from main" << std::endl;

    for (int i = 0; i < thread_num; i++){
        t[i].join();
    }
}
