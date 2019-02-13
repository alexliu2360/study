#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include <ctime>
#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

namespace SortTestHelper{
    int *generateRandomArray(int n, int rangeL, int rangeR){
        assert(rangeL <= rangeR);

        int *arr = new int[n];

        srand(time(NULL));
        for(int i=0;i<n;i++){
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    template<typename T>    
    void printArray(T arr[], int n){
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        return;
    }
    
    int *copyIntArray(int a[], int n){

        int *arr = new int[n];
        //* 在VS中, copy函数被认为是不安全的, 请大家手动写一遍for循环:)
        copy(a, a+n, arr);
        return arr;
    }

    int *generateNearlyOrderedArray(int n, int swapTimes){
       int * arr = new int[n];
       for(int i = 0;i < n;i++){
           arr[i] = i;
       }
       srand(time(NULL));
       for(int i = 0;i < swapTimes;i++){
           int posx = rand()%n;
           int posy = rand()%n;
           swap(arr[posx], arr[posy]);
       }
       return arr;
    }

    template<typename T>
    bool isSorted(T arr[], int n){
        for(int i = 0; i < n-1; i++){
            if(arr[i] > arr[i+1]){
                cout<<"not sorted!"<<endl;
                return false;
            }
        }
        cout<<"sorted!"<<endl;
        return true;
    }

    template<typename T>
    void testSort(const string &sortName, void(*sort)(T [], int), T arr[], int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout<< sortName <<" : " <<double(endTime-startTime)<<"ms"<<endl;
    }

}
#endif
