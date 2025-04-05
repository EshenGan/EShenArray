#include "CustomArray.h"

template <typename T>
EShenArray<T>::EShenArray(int inSize)
{
    size = inSize;
    capacity = size;
    data = new T[size];
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
T& EShenArray<T>::operator[](int index)
{
     if (index >= size)
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
        delete[] data;
        data = temp;
        temp = nullptr;
        capacity++;
    }
    
    ++size;
}

template <typename T>
void EShenArray<T>::RemoveAt(int index)
{
    if (size <= 0)
    {
        std::cout << "nothing more to remove" << "\n";
        return;
    }
    
    for (int i = 0; i < size - 1; ++i )
    {
        if (i >= index )
        {
            data[i] = data[i + 1];
        }
    }

    data[size - 1].~T();
    size--;
}

template <typename T>
void EShenArray<T>::Remove()
{
    RemoveAt(size - 1);
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
int EShenArray<T>::Find(const T& inKey)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == inKey)
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
    if (inCapacity <= size)
    {
        return;
    }
    
    T* temp = reinterpret_cast<T*>(new char[sizeof(T) * inCapacity]);
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
    
    if (inSize > capacity) // reallocate if more than the space reserved
    {
       T* temp = new T[inSize];
        for (int i = 0; i < size; ++i )
        {
            temp[i] = std::move(data[i]);
        }
        delete[] data;
        data = temp;
        temp = nullptr;
        size = inSize;
        capacity = size;
    }
    else if (inSize > size) // if the same or lesser than the available reserved space means no reallocate but still need to check against old size
    {
        for (int i = size; i < inSize; i++)
        {
            new (&data[i]) T;
        }

        size = inSize;
    }
    else
    {
        for (int i = size - 1; i >= inSize; i--)
        {
            Remove();
        }
    }
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
