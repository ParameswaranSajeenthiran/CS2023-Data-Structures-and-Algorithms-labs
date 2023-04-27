#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int twoStacks(int maxSum, vector<int> a, vector<int> b,int currentSum) {
        cout<< "test "<< currentSum<<" "<< maxSum << " " << a.front() << " " << b.front() << endl;
        // printVector(a);
        // printVector(b);
if(a.empty() && b.empty()){
        return 0;
    }
        

    if(currentSum>maxSum){
        return 0;
    }


    int x=0;
    if(a.empty()){
        x=b.front();
        // delete b.front();
        b.erase(b.begin());
       
        return 1+twoStacks( maxSum, a,  b, currentSum+x);
    }

    if(b.empty()){
        x=a.front();
        // delete a.front();
        a.erase(a.begin());
        return 1+twoStacks( maxSum, a,  b, currentSum+x);
    }
       if(a.front()<b.front() ){
        x=a.front();
        // delete a.front();
        a.erase(a.begin());
    } else{
        x=b.front();
        // delete b.front();
        b.erase(b.begin());
    }
    return  (1+twoStacks( maxSum, a,  b, currentSum+x)) ;


}

int main(){
    int maxSum=100;
    
    int currentSum=0;

    //randomly genreate array of length n for a and b
    int n=10000;
    vector<int> a;
    for(int i=0;i<n;i++){
        a.push_back(rand()%10);
    }
    vector<int> b;
    for(int i=0;i<n;i++){
        b.push_back(rand()%10);
    }
    printVector(a);
    printVector(b);
    cout<<twoStacks(maxSum,a,b,currentSum);

    

    

    



    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}