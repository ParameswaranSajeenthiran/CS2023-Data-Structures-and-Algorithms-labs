#include <iostream>
#include <string>
using namespace std;


int superDigit(string n,int k){
    if(n.size()==1){
        return stoi(n);
    }

    long parent =0;
    for (char& c : n){

        parent += c-48;
    }

    parent *= k;
    return superDigit(to_string(parent),1);
}


int main (){
   cout<< superDigit("9875 ",4);
}