#include <iostream>
using namespace std;
struct node {
  int freq ;
  char data;;
  
  struct node *left=NULL;
  
   struct node *right=NULL;
};


int tranverse(node * root ,string s , int &i){
//   cout<< " in traverse i = "+ *i<<endl;

  
  if(root->left==NULL && root->right ==NULL){
    char character =root->data;
    cout<<character;
    return 0;
   
  }
  else if( s[i]=='1'){
    i=i+1;

    tranverse(root->right,s, i);
    

  }else {
    i=i+1;
    
    
    tranverse(root->left,s, i);
  }

}




void decode_huff(node * root, string s) {
    int i=0;
    node * node=root;
         while (i< s.length()){
            // cout<< " i in while = "<<i<<endl;
        tranverse(node,s,i);
        // cout<<  tranverse(node,s,&i);
}



}
int main(){
    node *root = new node;
    root->data='D';
    root->freq=5;
    root->left=new node;
    root->left->data='D';
    root->left->freq=2;
    root->right=new node;
    root->right->data='A';
    root->right->freq=3;
    root->left->left=new node;
    root->left->left->data='B';
    root->left->left->freq=1;
    root->left->right=new node;
    root->left->right->data='C';
    root->left->right->freq=1;
    
    string s="1001011";
    decode_huff(root,s);




    return 0;

}