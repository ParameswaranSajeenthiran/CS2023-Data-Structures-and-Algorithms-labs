#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}


void quickSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int pivot = v[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (v[j] < pivot)
            {
                i++;
                int temp=v[i];
                v[i]=v[j];
                v[j]=temp;


                
            }
        }

        int temp=v[i + 1];
                v[i + 1]=v[high];
               v[high]=temp;
               
        int p = i + 1;
        quickSort(v, low, p - 1);
        quickSort(v, p + 1, high);
    
}
}




int lilysHomework(vector<int> &arr) {
     vector<int>originalArray(arr);
         vector<int>originalArray2(arr);

     map<int ,int> indexofElementInOriginalArry;
          map<int ,int> indexofElementInOriginalArry2;


    int n=arr.size();
    int swapCount1=0;
    int swapCount2=0;
    sort(arr.begin(),arr.end());

    for (int i=0; i<n;i++){
        indexofElementInOriginalArry[originalArray[i]]=i;

    }


    for (int j=0;j <n; j++ ){
       

        if(originalArray[j]!=arr[j]){

            swapCount1++;
            int index_swapped=indexofElementInOriginalArry[arr[j]];
            indexofElementInOriginalArry[originalArray[j]]=index_swapped;
            int temp=originalArray[index_swapped];
            originalArray[index_swapped]=originalArray[j];
            originalArray[j]=temp;
            // indexofElementInOriginalArry[temp]=j;
            // indexofElementInOriginalArry[originalArray[j]]=indexofElementInOriginalArry[arr[j]];



        }
    }




        reverse(arr.begin(),arr.end());
  
 for (int i=0; i<n;i++){
        indexofElementInOriginalArry2[originalArray2[i]]=i;

    }
    
    for (int j=0;j <n; j++ ){
        

        if(originalArray2[j]!=arr[j]){
           swapCount2++;
            int index_swapped=indexofElementInOriginalArry2[arr[j]];
            indexofElementInOriginalArry2[originalArray2[j]]=index_swapped;
            int temp=originalArray2[index_swapped];
            originalArray2[index_swapped]=originalArray2[j];
            originalArray2[j]=temp;

        }
    }


    


    int minimum=min(swapCount1,swapCount2);
    cout<< minimum;
    return minimum;


    
    
}
int main(){

    vector<int> test={3 ,4 ,2 ,5 ,1};
    vector<int> test2={2 ,5, 3 ,1 };
    cout<<lilysHomework(test);

}