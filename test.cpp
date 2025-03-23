#pragma once

#include "CustomArray.tpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int size = 5;
    int capacity = 10;
    EShenArray<int> array1(size,capacity);
    array1 = {0,1,2,3,4};
    
    array1.Add(5);
    cout << "array1: " << array1[5] << endl;
    
    array1.Remove();
    cout <<"array1: ";
    
    for (auto element : array1)
    {
        cout << element;
    }
    std::printf("\n");
    
    int index = array1.Find(4);
    cout << "array1: " << index << endl;

    EShenArray<float>array2(size,capacity,{0.1, 0.2, 0.3, 0.4, 0.5});
    cout << "array2: " << array2[4] << endl;

    array2.Empty();
    //cout << "array2: " << array2[0] << endl; //expect error

    array2.Resize(5); // expect error, must resever before resize
    array2.Reserve(10);
    array2.Resize(5);
    cout << "array2 size:" << array2.Size() << endl;
    cout << "array2 capacity: " << array2.Capacity() << endl;

    array2 = {0.0,1.0,2.0,3.0,4.0};
    cout << "array2: " << array2[4] << endl; // expect error

    array2.Add(5.0);
    cout << "array2: ";
    for (auto element : array2)
    {
        cout << element;
    }
    std::printf("\n");
    
    array2.RemoveAt(3);
    cout << "array2:" << array2[3] << endl;
    
    return 0;
}