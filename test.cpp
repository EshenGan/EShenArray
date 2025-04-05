#pragma once

#include "CustomArray.tpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int size = 5;
    EShenArray<int> array1(size);
    array1 = {0,1,2,65,75};
    
    array1.Add(73);
    cout << "array1: " << array1[5] << "\n";
    
    array1.Remove();
    
    cout <<"array1: ";
    for (auto element : array1)
    {
        cout << element;
    }
    std::printf("\n");
    
    int index = array1.Find(75);
    cout << "array1: " << index << "\n";

    EShenArray<float>array2(size);
    array2 = {0.1, 0.2, 0.3, 0.4, 0.5};
    cout << "array2: " << array2[4] << "\n";

    array2.Empty();

    array2.Resize(5);
    array2.Reserve(10);
    array2.Resize(6);
    cout << "array2 size:" << array2.Size() << "\n";
    cout << "array2 capacity: " << array2.Capacity() << "\n";

    array2 = {0.0,1.0,2.0,3.0,4.0,5.0};
    cout << "array2: " << array2[5] << "\n";

    array2.Resize(3);
    
    cout << "array2: ";
    for (auto element : array2)
    {
        cout << element;
    }
    std::printf("\n");
    
    array2.RemoveAt(1);
    cout << "array2:" << array2[1] << "\n"; 
    
    return 0;
}
