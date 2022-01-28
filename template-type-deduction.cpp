// Week 02 14 Jan 2022
// Template type deuction
#include <iostream>
#include <utility>

template<typename T>
void fun(T param)
{
    param +=1;    
}

template<typename T>
void fun1(T* param)
{
    param +=1;
}

int main()
{
    const int ci = 10;
    const int * p = &ci;
    const int * const cp = &ci; 

    fun(ci);
    //fun(p);
    fun(cp);

    fun1(p);
    fun1(cp);

    return 0;
}