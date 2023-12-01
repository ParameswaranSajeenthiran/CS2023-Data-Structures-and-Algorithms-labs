#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace  std;

int main() {
    // input string 
    string s;
    cin >> s;
    // input number of queries
    int n;
    cin >> n;
    // input queries
    vector<int> queries(n);
    for(int i=0;i<n;i++){
        cin >> queries[i];
    }

    // create a vector to store the weights of the substrings
    vector<int> weights;
    int weight = 0;
    char prev = ' ';
    for(int i=0;i<s.size();i++){
        if(s[i] == prev){
            weight += (s[i]-'a'+1);
        }else{
            weight = (s[i]-'a'+1);
        }
        weights.push_back(weight);
        prev = s[i];
    }

    // sort the weights
    sort(weights.begin(),weights.end());

    // check if the query is present in the weights vector
    for(int i=0;i<n;i++){
        if(find(weights.begin(),weights.end(),queries[i]) != weights.end()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }


    


    return 0;

}