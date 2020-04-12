//Min Heap

#include <iostream>
using namespace std;

void swap(long int arr[], long int index, long int parent) {
    long int temp;
    temp = arr[index];
    arr[index] = arr[parent];
    arr[parent] = temp;
}

void rising(long int arr[], long int index) {
    while (index > 1) {
        if (arr[index] < arr[index/2]) {
            swap(arr, index, index/2);
            index = index /2;
        } else {
        break;
        }
    }
}

long int getSmallestIndex (long int arr[], long int index, long int max) {
    if (2*index == max || arr[2*index] < arr[2*index+1]) {
        return 2*index;
    } else {
        return 2*index +1;
    }
}

void sinking(long int arr[], long int index, long int max) {
    while (2*index <= max) {
        int smallestChild = getSmallestIndex(arr, index, max);
        if (arr[smallestChild] < arr[index]) {
            swap(arr, smallestChild, index);
            index = smallestChild;
        } else {
           break;
        }
    }
}
        
int main(int argc, char** argv) {
    long int arr[100000];
    long int count = 0;
    long int q;
    cin>>q;
    
    while(q--) {
        int ch;
        long int v;
        cin>>ch;
        
        switch(ch) {
            case 1: cin>>v;
            arr[count+1] = v;
            count++;
            rising(arr, count);
            break;
            
            case 2: cin>>v;
            for (int i = 1; i <= count; i++) {
                if (arr[i] == v) {
                    swap(arr, i, count);
                    count--;
                    sinking(arr, i, count);
                    break;
                }
            }
            break;
            
            case 3: cout<<arr[1]<<endl;
            break;
        }
    }
    return 0;
}

