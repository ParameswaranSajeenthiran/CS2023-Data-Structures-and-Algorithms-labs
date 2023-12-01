#include <iostream>
using namespace std;

void printArray ( int * arr, int n ){
    for ( int i =0; i<n; i++){
        printf("%d ",arr[i]);
    }
}
void heapify ( int * arr, int n , int i ){
                cout<<endl;

    int l =2*i;
    int r =2*i +1;
    int largest =i;
    while ( l<=n && arr[l]>arr[largest]){
        largest =l;
    }
    while ( r<=n && arr[r]>arr[largest]){
        largest =r;
    }
    if ( largest !=i){
        int temp =arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(arr,n,largest);
    }
}

void heapSort ( int * arr, int n ){
    // build heap 
    for ( int i =n/2; i>0; i--){
        heapify(arr,n,i);
    }
    // delete max and heapify 
    for ( int i =n; i>0; i--){
        int temp =arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,n,i);
    }
                    printArray(arr,n);

}



int main () {
    cout<< " HI ";

    int arr[]={0,4,1,3,2,16,9,10,14,8,7};
    int n =sizeof(arr)/sizeof(int);
            printArray(arr,n);

    heapSort(arr,n);
    printArray(arr,n);

    return 0;
}
//     int n = sizeof(arr)/sizeof(arr[0]);