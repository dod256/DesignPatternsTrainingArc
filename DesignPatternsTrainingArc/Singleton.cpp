#include "Singleton.h"

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;
std::atomic<int> Singleton::value{0};

Singleton* Singleton::GetInstance() {
    if (!instance) {
        std::lock_guard<std::mutex> lock(mutex);
        if (!instance) {
            instance = new Singleton();
        }
    }
    return instance;
}
