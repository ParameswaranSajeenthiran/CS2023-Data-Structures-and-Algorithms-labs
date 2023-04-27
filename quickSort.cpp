// #include <iostream>
// #include <vector>
// #include <chrono>
// #include <algorithm>
// using namespace std;

// /// sort array using quick sort recursively
// void printVector(vector <int> v){
//     for(int i = 0; i < v.size(); i++){
//         cout << v[i] << " ";
//     }
// }

// void quickSort(vector<int> &v, int low, int high)
// {
//     if (low < high)
//     {
//         int pivot = v[high];
//         int i = low - 1;
//         for (int j = low; j < high; j++)
//         {
//             if (v[j] < pivot)
//             {
//                 i++;
//                 swap(v[i], v[j]);
//             }
//         }
//         swap(v[i + 1], v[high]);
//         int p = i + 1;
//         printVector(v);
//         quickSort(v, low, p - 1);
//         quickSort(v, p + 1, high);
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     //generate a random vector
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//         v[i] = rand() % 100;
//     //sort using quick sort
//     auto start = chrono::high_resolution_clock::now();
//     quickSort(v, 0, n - 1);
//     auto end = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//     cout << "Time taken by quick sort: " << duration.count() << " nanoseconds" << endl;
//     //sort using inbuilt sort
//     start = chrono::high_resolution_clock::now();
//     sort(v.begin(), v.end());
//     end = chrono::high_resolution_clock::now();
//     duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//     cout << "Time taken by inbuilt sort: " << duration.count() << " nanoseconds" << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

// int partition (vector<int> &v ,int start ,int end){
//     int pivot =v[end];
//     int  i=start-1;
//     cout<<pivot<<end;

//     for (int j=start; j<end;j++){
//         if(pivot>v[j]){
//              i++;
//             int temp =v[j];
//             v[j]=v[i];
//             v[i]=temp;

//         }

//         int temp =v[j+1];
//         v[j+1]= v[end];
//         v[end]=v[j+1];
//         return i+1;

//     }
// }

// void quickSort(  vector<int> &v, int start,int end){
//     if(start<end){
//         int pivot =partition(v,start,end);
//         quickSort(v,start,pivot-1);
//         quickSort(v,pivot+1,end);

//     }
// };

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> quickSort(vector<int> &arr)
{

    int pivot = arr[0];
    cout << "pivot" << pivot;
    int low = 1;
    int i = 0;
    int high = arr.size();
    for (int j = low; j < high; j++)
    {
        cout << " j= " << j << " i= " << i << endl;
        cout << " arrr[j] " << arr[j] << "pivot" << pivot << endl;

        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        printVector(arr);
    }
    int temp = arr[0];
    arr[0] = arr[i ];
    arr[i ] = temp;
    return arr;
}

int main()
{
    vector<int> array = {4, 3, 2, 6, 5,10,3,2,3,5,8};
    printVector(array);
    quickSort(array);
    printVector(array);
}