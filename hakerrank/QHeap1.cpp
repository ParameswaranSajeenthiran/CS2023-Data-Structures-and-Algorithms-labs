#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

void heapify ( vector<long> &arr, long n, long i ){
    long l = 2*i +1;
    long r= 2* i +2;
    long smallest = i;

    while ( l< n  && arr[smallest]>arr[l]){
        smallest=l;
    }
    while ( r< n && arr[smallest]>arr[r]){
        smallest =r;
    }
    if( smallest !=i){
        swap(arr[smallest], arr[i]);
        heapify(arr,n,smallest);

    };

} 





void deleteNode(vector<long> &arr, long node) //function for deleting node
{
    long size =arr.size();
  long i=0;
  for (i = 0; i < size; i++)
  {
    if (node == arr[i]) //finding selected node
      break;
  }

  swap(arr[i], arr[size - 1]); //swapping with last node
  size -= 1; //decrementing size after deleting node 
  
  for (long i = size / 2 - 1; i >= 0; i--)
  {
    heapify(arr,size, i); //heapifying 
  }
}

void insertElement( vector<long> &arr ,long n,long x ){
    
    // cout<< "beofre pushing " << arr.back();
    arr.push_back(x);
    
    // cout<< "after pushing " << arr.back();
     for (long i = arr.size() / 2 - 1; i >= 0; i--)
        heapify(arr, arr.size(), i);
    


}

void deleteElement( vector <long> &arr , long n , long x){

}

void printMin( vector<long> arr){
    printf("%d", arr[0]);
}



int main() {
    int n;
    cin >> n;
        priority_queue<int ,vector<int> ,greater<int>> p_queue;
             priority_queue<int ,vector<int> ,greater<int>> pq_new;

    
    set<int> S;
    
    for (int i = 0; i < n; i++) {
        int t, v;
        cin >> t;
        
        switch (t) {
        case 1:
            cin >> v;
            p_queue.push(v);
            break;
        case 2:
            cin >> v;
            while (!pq_new.empty()) {
            pq_new.pop();
            }


            while (!p_queue.empty()) {
                if (p_queue.top() != v) {
                    pq_new.push(p_queue.top());
                };
                p_queue.pop();
                
            };
            p_queue=pq_new;
            
            break;
        case 3:
            cout << p_queue.top();
            break;
        }
    }
    
    return 0;
}

// int main (){
//     vector < long > arr;

//       priority_queue<int ,vector<int> ,greater<int>> p_queue;

//   long n ;
//   cin>> n;
// // cout<< "number of queries ="<< n<<endl;

//   long operation;
//   long operand;
//   cin >> operation;
//   long i=0;

//   while (i <n) {
//     i++;
//     // cout<< "opertaion ="<< operation<<endl;
//     switch(operation) {
//       case 1: // insert
//         cin >> operand;
//         // cout<< "new operand "<< operand<<endl;
//         cout<<endl;
//         //  insertElement(arr,  arr.size(), operand);
//         p_queue.push(operand);
//         cin >> operation;

//         break;
//       case 2: // delete
//         cin >> operand;
//          deleteNode(arr, operand);
//          p_queue.swap
//         cin >> operation;
//         break;
//     case 3: // print
//         // cin >> operand;
//         cout<< arr[0];
//         cin >> operation;
//         break;
//       default:
//         cout << "Invalid Operator!\n";
//         return 0;
//     }
//   }

//     return 0;
// }