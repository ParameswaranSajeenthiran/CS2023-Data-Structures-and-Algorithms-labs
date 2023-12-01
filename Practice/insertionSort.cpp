#include <iostream>
using namespace std;


void printArray(int * A,int n ){
    
    cout << "n="<< n<<endl;
    for ( int i=0; i<n; i++){
        cout<< A[i]<<" ";
    }
    cout<<endl;

}
void insertionSort( int * A ,int n){
    printArray(A,n);

    for ( int i=1 ; i< n ; i++ ){
        int current = A[i];
        int j=i-1;
        while (j >=0 && A[j] >current){
            A[j+1]=A[j];
            j--;

        }
        A[j+1]=current;
            cout<<" after "<<i<<"iteration"<<endl;
                printArray(A,n);


    }



}


int main (){
    int A[10] ={2,3,4,6,3,89,11,1,37,6};
    insertionSort(A,10);
    


}