#include <iostream>
using namespace std;

struct Node {
  int key;
  struct  Node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct Node *root) {

}



struct Node * createNewNode( int key){
  // cout<<  key;
   Node* node = new Node();
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    return node;
}
// Insert a node
struct Node *insertNode(struct Node *node, int key) {
  // cout<<key;
  if(node==NULL){
   node = new Node();
		node->key = key;
		node->left = node->right = NULL;
    
  }else if ( node->key>key){
    insertNode  (node->left,key);
  }
  else {
    insertNode(node->right, key);
    }
  return node ; 

}

// finding minimum in the node ;
struct Node *   findMin (struct Node* root ){
  if(root==NULL){
    cout << " tree is empty ";
  }else if ( root->left =NULL ){
    return root;

  }
  return findMin( root->left);

}


// Deleting a node
struct Node *deleteNode(struct Node *root, int key) {
  if(root==NULL){
    return root;
  }else if ( root->key > key){
    deleteNode(root->left,key);

  }
  else  if ( root->key < key)  {
    deleteNode(root->right,key);
  }else{
    //no childe
    if(root->right==NULL && root->left ==NULL){
      delete root;
      root =NULL ;
      return root;
      }
      else if( root->right==NULL){
        Node* temp = root;
        root= root->left;
        delete temp;
        return root;
      }
      else if ( root->left ==NULL){
         Node* temp = root;
        root= root->right;
        delete temp;
        return root;
      }
      else {
        Node * temp =  findMin( root-> right );
        root->key=temp->key;
        root->right =deleteNode(root->right, temp->key);

      }
  }
 
}

// Driver code
int main() {

cout<< "HI"<<endl;
struct Node * root =NULL;
int test=8;
cout<< "HI"<<endl;

  root= insertNode(root,test);
 cout << root->key;
 root= insertNode(root, 6);
 root=insertNode(root,10);
 cout<< root->right->key;
 cout<< root->left->key;
 cout<< "tet";
 deleteNode(root,10);
cout<< root->right->key;

  // struct Node *root = NULL;

  // int operation;
  // int operand;
  // cin >> operation;

  // while (operation != -1) {
  //   switch(operation) {
  //     case 1: // insert
  //       cin >> operand;
  //       root = insertNode(root, operand);
  //       cin >> operation;
  //       break;
  //     case 2: // delete
  //       cin >> operand;
  //       root = deleteNode(root, operand);
  //       cin >> operation;
  //       break;
  //     default:
  //       cout << "Invalid Operator!\n";
  //       return 0;
  //   }
  // }
  
  // traverseInOrder(root);
}