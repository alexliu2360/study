#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include "Sort.h"
#include "SortTestHelper.h" 
using namespace std;
using namespace SortTestHelper;

int main(int argc, char *args[]){

    /*  
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort( a , 10 );
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;
    */

    int N=100000;
    // int *arr = SortTestHelper::generateRandomArray(N, 0, 100);
    // SortTestHelper::testSort("bubblelSort", bubblelSort, arr, N); 
    // delete[] arr;

    // int *arr = SortTestHelper::generateRandomArray(N, 0, 100);
    // SortTestHelper::testSort("selectionSort", selectionSort, arr, N); 
    // delete[] arr;

    int *arr = SortTestHelper::generateRandomArray(N, 0, 1000000);
    int *arr_ordered = SortTestHelper::generateNearlyOrderedArray(N, 5);
    int *arr_ordered1 = SortTestHelper::generateNearlyOrderedArray(N, 5);
    SortTestHelper::testSort("selectionSort", selectionSort, arr_ordered, N); 
    // SortTestHelper::testSort("insertionSort", insertionSort, arr, N);
    SortTestHelper::testSort("insertionSort", insertionSort, arr_ordered1, N);
    delete[] arr_ordered;
    delete[] arr_ordered1;

    getchar();
    return 0;
}
