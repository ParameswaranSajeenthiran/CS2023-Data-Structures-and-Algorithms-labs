#include <iostream>
using namespace std;
#define MAX 100
int s[MAX];
int top =-1;

void display(){
    
}

void push (int x){

    if(top==MAX){
        cout<< "Stack Overflow";
    }else{
top=top+1;
    s[top]=x;
    }
    


}

int main(){
    
    push(10);
    push(11);
    cout<< s[0];
    



}