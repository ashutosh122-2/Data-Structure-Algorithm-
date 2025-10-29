#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int start , int end , int mid ){
        vector<int> temp(end - start + 1);
        int left = start , right = mid + 1 , index = 0;

        while(left <= mid && right <= end){
            if(arr[left] <= arr[right]){
                temp[index] = arr[left];
                index++; left++;
            } else {
                temp[index] = arr[right];
                index++; right++;
            }
        }

        while(left <= mid){
            temp[index] = arr[left];
            index++; left++;
        }
        while(right <= end){
            temp[index] = arr[right];
            index++; right++;
        }

        index = 0;
        while(start <= end){
            arr[start] = temp[index];
            start++; index++;
        }
    }

    void mergeSort(vector<int>& arr , int start , int end )  {
        if(start >= end)
            return;

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end, mid);
    }

    vector<int> sortArray(vector<int>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
        return arr;
    }
};
