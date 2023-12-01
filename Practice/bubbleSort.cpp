#include <iostream>
using namespace std;



void printArray(int * A,int n ){
    
    cout << "n="<< n<<endl;
    for ( int i=0; i<n; i++){
        cout<< A[i]<<" ";
    }
    cout<<endl;

}

void bubbleSort(int * A, int n){
    for ( int i=n; i>0; i--){
        for ( int j=0; j< i ;j++){
            if( A[j] > A[j+1]){
                int temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }

        }
        printArray(A,n);
    }
    

}
void optimizedBubleSort( int *A , int n ){
    bool swapped =true;
    while (swapped){
        swapped=false ;
        for ( int i=1; i< n ; i++){
             if( A[i] > A[i+1]){
                swapped=true;
                int temp = A[i];
                A[i]=A[i+1];
                A[i+1]=temp;
            }
        }
                printArray(A,n);

    }
}

int main (){
    int A[10] ={2,3,4,6,3,89,11,1,37,6};
    // bubbleSort(A,10);
    optimizedBubleSort(A,10);
    
    return 0;
}