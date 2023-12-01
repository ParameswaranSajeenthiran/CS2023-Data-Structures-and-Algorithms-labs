#include <iostream>
using namespace std;

void printArray ( int * array , int n ){
     for ( int i =0 ; i<n ; i++){
        printf(" %d",   array[i]);
     }
}
void heapify(int array[], int n,int i ){ // int* A is same as int A[] -- it's the same  always passes the pointer of the arrray
int l= 2*i+1;
int r= 2*i +2;
int largest = i;
while ( l<= n && array[l]>array[largest]){
    largest =l;
}

while ( r<= n && array[r] > array[largest]){
    largest=r;
}

if( largest != i){
     int temp =array[largest];
        array[largest]=array[i];
        array[i]=temp; 
    heapify( array, n, largest);
    }
    cout<< " after one heapify"<< endl;
    printArray(array,n);
//  for ( int i =0; i <n;i++){
//     printf("%d ",array[i]);
//  }
}

void heapSort( int array[] , int n  ){
    // build heap 
    for ( int i =n/2;i>0; i--){
        cout<< "whne building heap";
        heapify(array, n ,i);

    }

    // delete max and heapify 
    for ( int i = n; i>0; i--){
        int temp =array[0];
        array[0]=array[i];
        array[i]=temp;        
        heapify(array, n, i);
    }
}


void swap ( int * array , int i ,int j){
     int temp =array[i];
    array[i]=array[j];
    array[j]=array[i];
}



int main () {
    int arr[] = {9,2,4,2,43,1,3,444,21,2};
    int n = sizeof(arr)/sizeof(int);
    printArray(arr, n );
    // for ( int i=0; i< n ; i++){
    //     printf("%d ",arr[i]);
    // }
    // A can be used for  &A[0]
    heapSort(arr,n);
    printArray(arr,n);
    return 0;
}