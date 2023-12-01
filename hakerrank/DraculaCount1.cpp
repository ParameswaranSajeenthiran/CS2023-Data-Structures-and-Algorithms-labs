#include <iostream >
#include <vector>
using namespace std;

void printArray( vector<int > arr, int n){
    for ( int i=0; i< n; i++){
        cout<< arr[i];
    }
}



void bubbleSort( vector<int> arr, int n){
    for ( int i=n; i>0 ; i--){
        for ( int j =0 ; j<i; j++){
            if( arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=arr[j];
            }
           
        }
    }
    printArray( arr,n);
}

int main() {
    vector <int> arr={3,2,5,3,1,};
    bubbleSort(arr,arr.size());
    
    return 0;
}       