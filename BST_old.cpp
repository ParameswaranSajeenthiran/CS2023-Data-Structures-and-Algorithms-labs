#include <iostream>
using namespace std;

struct node {
  int key;
  struct  node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {

if( root == NULL){
  return;
}
traverseInOrder(root->left);
cout << root->key << " ";
traverseInOrder(root->right);

}




// Insert a node
struct node *insertNode(struct node *node, int key) {
  // cout<<key;
if(node == NULL) {
		node = new struct node;
		node->key = key;
		node->left = node->right = NULL;
	}
	else if(key <= node->key)
		node->left = insertNode(node->left,key);
	else 
		node->right = insertNode(node->right,key);
	return node;

}

// finding minimum in the node ;
struct node *   findMin (struct node* root ){
  if(root==NULL){
    cout << " tree is empty ";
  }else if ( root->left =NULL ){
    return root;

  }
  return findMin( root->left);

}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
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
        node* temp = root;
        root= root->left;
        delete temp;
        return root;
      }
      else if ( root->left ==NULL){
         node* temp = root;
        root= root->right;
        delete temp;
        return root;
      }
      else {
        node * temp =  findMin( root-> right );
        root->key=temp->key;
        root->right =deleteNode(root->right, temp->key);

      }
  }
 
}

// Driver code
int main() {


  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}