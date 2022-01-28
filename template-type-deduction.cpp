// Week 04 28 Jan 2022
// Template type deuction
#include <iostream>
#include <utility>
#include <string>

/*
template ko aise dekh sakte hai
ek to T ka type deduce karna hai aur
parameter ka type deduce karna hai

template<typename T>
void fun(ParamType param)
{

}

fun(expr);
Compiler expr jo pass kiya hai usse deduce karta hai 
T aur parameter(s) ka type

3 Cases
1. Passing reference or pointer but not universal reference
2. Passing universal reference
    lvalue ---> ko banna chahiye lvalue
    rvalue --->  rvalue
3. Pass by value
   Isme copy hota hai to constness chali jayegi 
*/

/* Passed by value */
template<typename T>
void fun_byVal(T param)
{
    param +=1;    
}

/* Passed by reference or pointer but not universal reference */
template<typename T>
void fun_byPtr(T* param)
{
    param +=1;
}

template<typename T>
void fun_byRef(T& param)
{
    
}

/* Passed by universal reference */
template<typename T>
void fun_byUniRef(T&& param)
{
    
}


int main()
{
    const int ci = 10;
    const int * p = &ci; // pointer ------> (holds or points to) a const int
    const int * const cp = &ci; // const pointer ---> points to a const int
    int x = 12;

    // by value
    fun_byVal(ci); // void fun_byVal<int>(int) -> T ka deduced type -> int  aur  ParamType -> int
    // kyuki const ka copy banaya hai isliye ab wo const nhi raha
    fun_byVal(p);  // void fun_byVal<int const*>(int const*)
    fun_byVal(cp); // void fun_byVal<int const*>(int const*)  // const pointer cp ki constness chali gayi
    fun_byVal(&x); // void fun_byVal<int*>(int*)

    // by reference or pointer
    fun_byPtr(p); // void fun_byPtr<int const>(int const*)
    // T ---> is deduced to int const
    // ParamType --> is deduced to int const*
    fun_byPtr(cp);

    auto & ref = x;
    const int abc = 15;

    fun_byRef(ref); // void fun_byRef<int>(int&)
    fun_byRef(abc); // void fun_byRef<int const>(int const&)

    // by universal reference
    // passing rvalues
    /* 5 is rvalue, so T is int, param's type is int&& */ 
    fun_byUniRef(5); // void fun_byUniRef<int>(int&&)

    // passing lvalues
    int d = 27;
    const int cd = d;
    const int& rd = d;
    /*template<typename T>
    void fun_byUniRef(T&& param); // can be seen as   (ParamType&& param)

    fun_byUniRef(expr);
    T&& ka matlab hai ye lvalue bhi ho sakta hai aur rvalue bhi
    if expr is lvalue is passed then both T and and ParamType are deudced to be lvalue references
    */

    /* d is lvalue, so T is int& and param's type is also int& */
    fun_byUniRef(d); // void fun_byUniRef<int&>(int&)
    
    fun_byUniRef(cd); // void fun_byUniRef<const int&>(const int&)
    // expr --> const int
    // ParmaType --> const int  + &&  --> const int&
    // T   --> const int&
    fun_byUniRef(rd); // void fun_byUniRef<const int&>(const int&)

    return 0;
}
