/* preprocessor directive
*  ensure .h file included only once in a single compilation
*  serves the same purpose as #include guards, but with several advantages
*  including less code, avoidance of name clashes, and sometimes improvement in compilation speed
*/
#pragma once

#include <iostream>

template<typename T>
class EShenArray
{
    
    T* data = nullptr;
    int size = 0;
    int capacity = 0;
    

public:

    EShenArray(int inSize, int inCapacity);

    EShenArray(int inSize, int inCapacity, const std::initializer_list<T>& inList);

    ~EShenArray();

    EShenArray& operator=(const std::initializer_list<T>& inList);
    
    T operator[](int index);

    void Add(T&& inData); // cv-unqualified template parameter(https://en.cppreference.com/w/cpp/language/cv) , universal/forwarding reference
    
    void Remove();

    void RemoveAt(int index);
    
    void Empty();
    
    int Find(T&& inKey);

    T* begin() const;

    T* end() const;
    
    void Reserve(int inCapacity);
    
    void Resize(int inSize);
    
    int Size() const;

    int Capacity() const;
    
};