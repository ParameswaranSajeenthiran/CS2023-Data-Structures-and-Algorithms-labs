#include <iostream>
#include<string>
using namespace std;

string concatenate(string p,int k){
    if(k==1){
        return p;
    }
    return p+concatenate(p,k-1);
      
}

double getSum(string number,int n){
    double sum=0;
    for (int i=0; i<n ;i++){
        cout<< "number[i]"<<double(number[i])<<endl;
        sum=sum+ double(number[i])-48;
        cout<<sum<<endl;

    }
    return  sum;
}





string superDigit( string p,int k){
    if(p.size()==1){
        return p;
    }
    cout<< "superDigit p ="<<p<<endl;
     return superDigit(to_string(getSum(p,p.size())),to_string(getSum(p,k)).size()-1);





}
int main(){

    double p=9875987598759875;
    int k=4;
        string p_string=to_string(p);
        cout<<p_string;

        cout << getSum(p_string,p_string.size());
        cout<< superDigit(p_string,4);


    
    

    // cout<< "hi";
    // superDigit(1,6);
}