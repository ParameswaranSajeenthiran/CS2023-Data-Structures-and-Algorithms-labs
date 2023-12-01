#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
    int largest = root; 
    int l = 2*root + 1; 
    int r = 2*root + 2; 
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    if (largest != root)
    {
        swap(arr[root], arr[largest]);
  
        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }






  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    

   // extracting elements from heap one by one
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
  
        heapify(arr, i, 0);
    }
    
    
   
  
   // extracting elements from heap one by one
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
// read input with dynamic size  array from user w
    
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int heap_arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> heap_arr[i];
    }


   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}