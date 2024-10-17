#pragma once
#include <mutex>

class Singleton {
public:
    static Singleton* GetInstance();
    Singleton(const Singleton& obj) = delete;
    Singleton& operator=(const Singleton& obj) = delete;
    static int GetNumberOfInstances() { return value; }

private:    
    Singleton() { ++value; }

    static Singleton* instance;
    static std::mutex mutex;
    static std::atomic<int> value;

    std::string m_TestString = "Hello, I am Singleton.";
};
