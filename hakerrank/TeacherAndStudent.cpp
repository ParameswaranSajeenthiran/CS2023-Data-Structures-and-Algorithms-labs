#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray( vector<int > arr, int n){
    for ( int i=0; i< n; i++){
        cout<< arr[i] <<" ";
    }
}


int binarySearch(vector <int > arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
void teachAndStudent(){


    int testCases , m,n;
    vector < int > mArr , nArr; 


n=5;
m=6;
nArr={2,3,5,1,6};
mArr={4,5,2,8,1,9};

sort( nArr.begin() ,nArr.end());
printArray(nArr,n);
for ( int i=0; i< m ; i++){
    cout<< mArr[i]<<endl;

    
   int index= binarySearch(nArr,0 , n-1,mArr[i]);
  
}
}

int main(){
    teachAndStudent();
    return 0;
}