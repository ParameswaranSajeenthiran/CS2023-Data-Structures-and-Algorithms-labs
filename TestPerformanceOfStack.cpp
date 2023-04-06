#include<iostream>
#include <climits>
using namespace std;
 
class Stack {
    
  
public:
    int a[MAX]; // Maximum size of Stack
    int top;
  
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void display();
};
  
bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        // cout << x << " pushed into stack\n";
        return true;
    }
}

  
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
  
bool Stack::isEmpty()
{
    return (top < 0);
}

void PrintStack(Stack s)
{
    // If stack is empty then return
    if (s.isEmpty())
        return;
     
 
    int x = s.peek();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}
  
void test(Stack s){
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    //print all elements in stack :

    // s.display()/


    cout <<"Elements present in stack : ";
        PrintStack(s);

    
    for (int i=0; i<5;i++){
        s.pop();
    }
   cout <<"Elements present in stack : ";
        PrintStack(s);

    

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

   cout <<"Elements present in stack : ";
        PrintStack(s);

    
}










class Node {
public:
    int data;
    Node* link;
    
    // Constructor
    Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};


class LinkedListStack {
    Node* top;
  
public:
    LinkedListStack() { top = NULL; }
  
    void push(int data)
    {
  
        // Create new node temp and allocate memory in heap
        Node* temp = new Node(data);
  
        // Check if stack (heap) is full.
        // Then inserting an element would
        // lead to stack overflow
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }
  
        // Initialize data into temp data field
        temp->data = data;
  
        // Put top pointer reference into temp link
        temp->link = top;
  
        // Make temp as top of Stack
        top = temp;
    }
  
    // Utility function to check if
    // the stack is empty or not
    bool isEmpty()
    {
        // If top is NULL it means that
        // there are no elements are in stack
        return top == NULL;
    }
  
    // Utility function to return top element in a stack
    int peek()
    {
        // If stack is not empty , return the top element
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }
  
    // Function to remove
    // a key from given queue q
    void pop()
    {
        Node* temp;
  
        // Check for stack underflow
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
  
            // Assign top to temp
            temp = top;
  
            // Assign second node to top
            top = top->link;
  
            // This will automatically destroy
            // the link between first node and second node
  
            // Release memory of top node
            // i.e delete the node
            free(temp);
        }
    }
  
    // Function to print all the
    // elements of the stack
    void display()
    {
        Node* temp;
  
        // Check for stack underflow
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {
  
                // Print node data
                cout << temp->data;
  
                // Assign temp link to temp
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

// Driven Program
int main()
{
    // Creating a stack
    LinkedListStack ls;
    // test(s)
  
    // Push the elements of stack
    ls.push(11);
    ls.push(22);
    ls.push(33);
    ls.push(44);
  
    // Display stack elements
    ls.display();
  
    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;
  
    // Delete top elements of stack
    ls.pop();
    ls.pop();
  
    // Display stack elements
    ls.display();
  
    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;
  
    return 0;
}