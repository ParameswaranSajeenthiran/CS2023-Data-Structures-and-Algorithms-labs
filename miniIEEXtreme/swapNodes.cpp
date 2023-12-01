
// complete solution for hakkerank problem swap nodes
// https://www.hackerrank.com/challenges/swap-nodes-algo/problem
// solution is based on the idea of level order traversal of a binary tree
//c++ code implemnetation
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace  std;

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

void swapNodes(Node *root,int k,int level){
    if(root == NULL){
        return;
    }
    if(level%k == 0){
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    swapNodes(root->left,k,level+1);
    swapNodes(root->right,k,level+1);
}

void inOrder(Node *root ,vector<int> &ans){
    if(root == NULL){
        return;
    }
    inOrder(root->left,ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}

int main() {
    // input number of nodes
    int n;
    cin >> n;
    // input the nodes
    vector<Node*> nodes(n+1);
    for(int i=1;i<=n;i++){
        nodes[i] = new Node(i);
    }
    // input the left and right child of the nodes
    for(int i=1;i<=n;i++){
        int left,right;
        cin >> left >> right;
        if(left != -1){
            nodes[i]->left = nodes[left];
        }
        if(right != -1){
            nodes[i]->right = nodes[right];
        }
    }
    // input number of queries
    int q;
    cin >> q;
    // input the queries
    vector<int> queries(q);
    for(int i=0;i<q;i++){
        cin >> queries[i];
    }
    // swap the nodes and store the inOrder traversal of the tree in a vector
    vector<vector<int>> ans(q);

    for(int i=0;i<q;i++){
        swapNodes(nodes[1],queries[i],1);
        inOrder(nodes[1],ans[i]);
        cout << endl;
    }
    // print the inOrder traversal of the tree
    
    

    return 0;

}