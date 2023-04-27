#include <iostream>
using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct Node *root) {

if( root == NULL){
  return;
}
traverseInOrder(root->left);
cout << root->key << " ";
traverseInOrder(root->right);

}

// Finding minimum in the node
struct Node *findMin(struct Node *root) {
  if(root==NULL){
    cout << " tree is empty ";
  }else if ( root->left =NULL ){
    return root;

  }
  return findMin( root->left);

}

// Insert a node
struct Node *insertNode(struct Node *node, int key) {
if(node == NULL) {
		node = new Node();
		node->key = key;
		node->left = node->right = NULL;
	}
	else if(key <= node->key)
		node->left = insertNode(node->left,key);
	else 
		node->right = insertNode(node->right,key);
	return node;
}
// Deleting a node
struct Node *deleteNode(struct Node *root, int key) {
  if(root==NULL){
    return root;
  }else if ( root->key > key){
    root->left=deleteNode(root->left,key);
  }else if ( root->key < key){
    root->right=deleteNode(root->right,key);
  }else {
    if(root->left==NULL && root->right==NULL){
      delete root;
      root=NULL;
    }else if (root->left==NULL){
      Node* temp=root;
      root=root->right;
      delete temp;
    }else if (root->right==NULL){
      Node* temp=root;
      root=root->left;
      delete temp;
    }else {
      Node* temp=findMin(root->right);
      root->key=temp->key;
      root->right=deleteNode(root->right,temp->key);
    }
  }
  return root;
 
}

// Driver code
int main() {
  struct Node *root = NULL;

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