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

void testVec4(void* p_iters)
{
    uint64_t iters = *((uint64_t*)p_iters);
    ScopeTimer s("Vec4 Test");
    vec4 v(0,1,0,1);
    vec4 u(1,0,1,0);

    for (uint64_t i = 0; i < iters; ++i)
    {
        u + v;
    }
}

void testVec3(void* p_iters)
{
    uint64_t iters = *((uint64_t*)p_iters);
    ScopeTimer s("Vec3 Test");
    vec3 v(0,1,0);
    vec3 u(1,0,1);

    for (uint64_t i = 0; i < iters; ++i)
    {
        u + v;
    }
}

void testVec2(void* p_iters)
{
    uint64_t iters = *((uint64_t*)p_iters);
    ScopeTimer s("Vec2 Test");
    vec2 v(0,1);
    vec2 u(1,0);

    for (uint64_t i = 0; i < iters; ++i)
    {
        u + v;
    }
}

void testVec1(void* p_iters)
{
    uint64_t iters = *((uint64_t*)p_iters);
    ScopeTimer s("Vec1 Test");
    float v = 0;
    float u = 1;

    for (uint64_t i = 0; i < iters; ++i)
    {
        u + v;
    }
}

void testVec0(void* p_iters)
{
    uint64_t iters = *((uint64_t*)p_iters);
    ScopeTimer s("Vec0 Test");

    for (uint64_t i = 0; i < iters; ++i)
    {
        
    }
}

void testVec_1(void* p_iters)
{
    ScopeTimer ("Vec-1 Test");
}

int main(void)
{
    uint64_t iters = UINT32_MAX>>4;
    testVec_1(&iters);
    testVec0(&iters);
    testVec1(&iters);
    testVec2(&iters);
    testVec3(&iters);
    testVec4(&iters);
    return 0;
}