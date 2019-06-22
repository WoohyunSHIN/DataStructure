//
//  main.c
//  9_sort
//
//  Created by WoohyunSHIN on 13/02/2019.
//  Copyright © 2019 Woo. All rights reserved.
//
/*
 정렬을 하는 이유 -> 보기가 편하다 -> 찾기가 편하다
 
 선택정렬과 버블정렬은 비효율 적이다.
 그에 비해서, 비교적 삽입 정렬은 효율 적이다.
 
 merge sort
 쪼갠다음에 1:1 이후에, 승자를 위로 보내서 또 대결 시킨다
 
 heap sort
 
 */

#include <stdio.h>

void QuickSort(int* parr, int left, int right){
    int i = left;
    int j = right;
    int pivot = parr[i];
    
    do{
        while(parr[i]<pivot) i++;
        while(parr[j]>pivot) j--;
        if(i<=j){
            int imsi = parr[i];
            parr[i] = parr[j];
            parr[j] = imsi;
            i++;
            j--;
        }
    }
    
    while(i<j);
    if(left<j) QuickSort(parr, left, j);
    if(right>i) QuickSort(parr, i, right);
    
}

int main() {
    int arr[8] = {77, 55, 11, 33, 66, 99, 22, 44 };
    int i,j;
    
    /*
    // Buble Sort
    for(i=7;i>1;i--){
        for(j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j]=tmp;
            }
        }
    }
    
    for(i=0;i<8;i++){
        printf("%d-",arr[i]);
    }
    return 0;
    */
    
    /*
    // Insert Sort
    int t;
    for(i=1;i<8;++i){
        t = arr[i];
        j = i;

        while(arr[--j] > t){
            arr[j + i] = arr[j];
            if(j-1<0){
                j--;
                break;
            }
        }
        
        arr[++j] = t;
    }
    
    for(i=0;i<8;i++){
        printf("%d-",arr[i]);
    }
    return 0;
    */
    
    // QuickSort
    
    QuickSort(arr, 0, 7);
    
    for(i=0;i<8;i++){
        printf("%d-",arr[i]);
    }
    return 0;
}



