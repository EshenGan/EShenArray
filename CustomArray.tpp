#include "CustomArray.h"

template <typename T>
EShenArray<T>::EShenArray(int inSize, int inCapacity)
{
     size = inSize;
     capacity = inCapacity;
     data = new T[inCapacity];
     if (data == nullptr)
     {
         std::cout << "fail to init array" << std::endl;
     }
}

template <typename T>
EShenArray<T>::EShenArray(int inSize, int inCapacity, const std::initializer_list<T>& inList)
{
     size = inSize;
    if (inList.size() != size)
    {
        std::cout << "initializer list size does not match given array size" << std::endl;
        size = 0;
        return;
    }
    
     capacity = inCapacity;
     data = new T[inCapacity];
     if (data == nullptr)
     {
         std::cout << "fail to init array" << std::endl;
         return;
     }
    
     for (int i = 0; i < size; ++i )
     {
         std::copy_n(inList.begin(),size,data);
     }
}

template <typename T>
EShenArray<T>::~EShenArray()
{
    Empty();
}

template <typename T>
EShenArray<T>& EShenArray<T>::operator=(const std::initializer_list<T>& inList)
{
    if (inList.size() == size)
    {
        for (int i = 0; i < size; ++i )
        {
            std::copy_n(inList.begin(),size,data);
        }
    }
    
    return *this;
}

template <typename T>
T EShenArray<T>::operator[](int index)
{
     if (data == nullptr || index >= size)
     {
         std::cout << "out of bound" << std::endl;
         exit(0);
     }
     return data[index];
}

template <typename T>
void EShenArray<T>::Add(T&& inData)
{
    if (size < 0)
    {
        std::cout << "size cannot be lesser than 0" << std::endl;
        return;
    }
    
    if (size < capacity)
    {
        data[size] = std::forward<T>(inData);
    }
    else if (size == capacity)
    {
        T* temp = new T[size + 1];
        for (int i = 0; i < size; ++i )
        {
            temp[i] = std::move(data[i]);
        }
        temp[size] = std::forward<T>(inData);
        capacity = size;
        delete[] data;
        data = temp;
        temp = nullptr;
    }
    size++;
}

template <typename T>
void EShenArray<T>::Remove()
{
     if (size < 0)
     {
         std::cout << "nothing more to remove" << std::endl;
         return;
     }
     
     --size;
}

template <typename T>
void EShenArray<T>::RemoveAt(int index)
{
    if (size < 0)
    {
        std::cout << "nothing more to remove" << std::endl;
        return;
    }
    
    T* temp = new T[size - 1];
    for (int i = 0; i < size - 1; ++i )
    {
        if (i >= index )
        {
            temp[i] = std::move(data[i+1]);
            continue;
        }
        
        temp[i] = std::move(data[i]);
    }
    
    size--;
    delete[] data;
    data = temp;
    temp = nullptr;
}

template <typename T>
void EShenArray<T>::Empty()
{
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template <typename T>
int EShenArray<T>::Find(T&& inKey)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == std::forward<T>(inKey))
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
T* EShenArray<T>::begin() const
{
    return &(data[0]); 
}

template <typename T>
T* EShenArray<T>::end() const
{
    return &(data[size]);
}

template <typename T>
void EShenArray<T>::Reserve(int inCapacity)
{
    if (inCapacity < size)
    {
        size = inCapacity;
    }
    
    T* temp = new T[inCapacity];
    for (int i = 0; i < size; ++i )
    {
        temp[i] = std::move(data[i]);
    }
    delete[] data;
    data = temp;
    temp = nullptr;
    capacity = inCapacity;
}

template <typename T>
void EShenArray<T>::Resize(int inSize)
{
    if (inSize == size)
    {
        return;
    }
    if (inSize > capacity)
    {
        std::cout << "size cant be larger than capacity" << std::endl;
        return;
    }
    
    size = inSize;
}

template <typename T>
int EShenArray<T>::Size() const
{
    return size;
}

template <typename T>
int EShenArray<T>::Capacity() const
{
    return capacity;
}
