#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void buildHeap(vector <int > &arr ,int n ){
    for ( int i =(n/2)-1 ;i >=0 ; i-- ){

    }
}

void minHeapify(vector <int > &arr ,int n, int i ){
int l= 2*i +1;
int r= 2* i +2;
int smallest = i;

while ( l<n && arr[smallest]>arr[l]){
    smallest = l;
}
while ( r< n && arr[smallest ]>arr[r]){
    smallest =r;

}

if ( smallest !=i){
    swap(arr[smallest], arr[i]);
    minHeapify(arr, n, smallest);
}
}

int heapPop(vector <int> &arr){
    int result = arr[0];   
    
    arr[0]= arr.back();
    arr.pop_back();
    minHeapify(arr, arr.size()-1 , 0);
    return result;

}

void heapPush(vector<int> &arr ,int n,int x ){
     // //cout<< "beofre pushing " << arr.back();
    arr.push_back(x);
    
    // //cout<< "after pushing " << arr.back();
     for (long i = arr.size() / 2 - 1; i >= 0; i--)
        minHeapify(arr, arr.size(), i);


}

void displayArray(vector <int > &arr, int n)
{
   for (int i=0; i<n; ++i){

   }
   //cout << arr[i] << " ";
   //cout << "\n";
}

int  helper ( priority_queue<int ,vector<int> ,greater<int>> &p_queue,int k,int &count){

if( p_queue.top() >=k || p_queue.size()<2){
    if( count==0)
        return -1;
    return count ;
    }else {
        //cout<< "62"<<endl;


        count ++;
        int a= p_queue.top();
        p_queue.pop();
                //cout<< "68"<< a<<endl;

        // displayArray(arr,arr.size());

        int b = p_queue.top();
        p_queue.pop();
                //cout<< "73"<<endl;

        // displayArray(arr,arr.size());

        int c= a + 2*b;
        //cout<<"a = " << a << " b "<<b<< " c  ="<< c;
        //cout<< "//cout= " <<count;  
        // displayArray(arr,arr.size());


        p_queue.push(c);
        // heapPush( arr,  arr.size(),c);
        // displayArray(arr,arr.size());
        helper( p_queue,k,count);


    }
}

int cookies(int k, vector<int> A) {
    priority_queue<int ,vector<int> ,greater<int>> p_queue;
    for ( int i=0; i< A.size(); i++)
        p_queue.push(A[i]);

    int count =0;
    while ( p_queue.top() <k && p_queue.size()>=2){
    int a= p_queue.top();
        p_queue.pop();
        int b = p_queue.top();
        p_queue.pop();      

        int c= a + 2*b;
       


        p_queue.push(c);    
        count++;
        
        }
if( p_queue.top()<k)
    return -1;

    return count;

    //cout<< "afte buuld heap"<<endl;

    // displayArray(A,A.size());

    //  return helper( p_queue , k,count );
    // cout<< count;
    



}
int main() {

    vector < int >  arr= { 1, 2, 3, 9, 10, 12};
    int k=7;
     cout<< cookies( k, arr);

    return 0;
}