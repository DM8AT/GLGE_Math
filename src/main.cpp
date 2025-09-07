#include "GLGEMath/GLGEMath.h"
#include <iostream>
#include <chrono>
#include <string>

class ScopeTimer
{
public:
    ScopeTimer(const std::string& name) : m_name(name), m_startTime(std::chrono::high_resolution_clock::now()){}

    ~ScopeTimer()
    {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end_time - m_startTime;
        std::cout << m_name << " took " << elapsed.count() << " seconds\n";
    }

private:
    std::string m_name;
    std::chrono::high_resolution_clock::time_point m_startTime;
};

void testVector()
{
    ScopeTimer s("Vector Test");

    vec4 v(0,1,0,1);
    vec4 u(1,0,1,0);

    for (uint64_t i = 0; i < UINT32_MAX; ++i)
    {
        vec4 a = v + u;
    }
}

int main(void)
{
    testVector();
    return 0;
}