#include "binary_search.h"


int *binary_search(int value, const int *arr, size_t length) {
    
    if (length == 0) {
        return NULL;
    }

    int start = 0;
    int end = length -1;

    //return (int *) &arr[0];

    while (start <= end) {
        int mid = (end + start) / 2;
        if (arr[mid] == value)
            return (int *) &arr[mid];
        
        if (arr[mid] < value){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return NULL;
}
