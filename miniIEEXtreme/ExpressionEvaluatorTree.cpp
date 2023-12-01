#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

// function to append node to a parent node 
void appendNode(Node *parent,Node *child,int isLeft){
    if(isLeft){
        parent->left = child;
    }else{
        parent->right = child;
    }
}
// generate tree from the given evalution expression 
Node *generateTree(string s){
    Node *root = NULL;
    Node *curr = NULL;
    Node *prev = NULL;
    int i=0;
    while(i<s.length()){
        cout<< s.length();
        if(s[i] == '('){

            i++;
            int num = 0;
            while(s[i] != '(' && s[i] != ')'){
                num = num*10 + (s[i]-'0');
                i++;
            }
            Node *temp = new Node(num);
            if(root == NULL){
                root = temp;
            }else{
                appendNode(curr,temp,prev->data == '*' || prev->data == '+' || prev->data =='-');
            }
            curr = temp;
        }else if(s[i] == ')'){
            curr = curr->right;
        }else{
            prev = curr;
            curr = curr->left;
        }
    }
    return root;
}


// function to evaluate the expression tree
int evaluate(Node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    int left = evaluate(root->left);
    int right = evaluate(root->right);
    if(root->data == '+'){
        return left+right;
    }else if(root->data == '-'){
        return left-right;
    }else if(root->data == '*'){
        return left*right;
    }else{
        return left/right;
    }
}
void postOrdertravesal(Node *root){
    if(root == NULL){
        return;
    }
    postOrdertravesal(root->left);
    postOrdertravesal(root->right);
    cout << root->data << " ";
}

int main() {
    string s;
    cin >> s;
    Node *root = generateTree(s);
    // cout << evaluate(root) << endl;
    postOrdertravesal(root);
    return 0;
}




