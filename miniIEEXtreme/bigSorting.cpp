//Consider an array of numeric strings where each string is a positive number with anywhere from  to  digits. Sort the array's elements in non-decreasing, or ascending order of their integer values and return the sorted array

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace  std;

int main(){
    
   // input numeric string 
    int n;
    cin >> n;
    vector<string> strArr(n);
    string x;

    for(int i=0;i<n;i++){
        cin >> x;
        strArr[i] = x;
    }
    // sort the string array
    sort(strArr.begin(),strArr.end(),[](const string &a, const string &b){
        if(a.size() == b.size()){
            return a<b;
        }
        return a.size() < b.size();
    });

    // print the sorted array
    for(int i=0;i<n;i++){
        cout << strArr[i] << endl;
    }
    

    



    return 0;
}
