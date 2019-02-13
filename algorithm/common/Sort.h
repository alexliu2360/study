#ifndef SORT_H
#define SORT_H

#include <iostream>

template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void insertionSort(T arr[], int n){
    for(int i=0;i<n;i++){
        // 写法1
        // for(int j = i + 1; j > 0; j--){
        //     if (arr[j] < arr[j-1]){
        //         swap(arr[j], arr[j-1]);
        //     }else{
        //         break;
        //     }
        // }

        // 写法2
        // for(int j = i + 1; j > 0 && arr[j] < arr[j-1]; j--){
        //     swap(arr[j], arr[j-1]);
        // }

        // 写法3
        T e = arr[i];
        int j;// j保存元素e应该插入的位置
        for (j = i + 1; j > 0 && arr[j] <arr[j-1]; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

template<typename T>
void bubblelSort(T arr[], int n){
    for(int i = n;i > 0;i--){
        for(int j = 0;j + 1 < i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

template<typename T>
void shellSort(T arr[], int n){
    int h = 1;
    while(h < n/3){
        h = 3 * h + 1;
    }

    while(h >= 1){
        
    }
}

#endif
