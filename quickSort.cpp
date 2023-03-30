#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

/// sort array using quick sort recursively

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
                swap(v[i], v[j]);
            }
        }
        swap(v[i + 1], v[high]);
        int p = i + 1;
        quickSort(v, low, p - 1);
        quickSort(v, p + 1, high);
    }
}


int main()
{
    int n;
    cin >> n;
    //generate a random vector
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100;
    //sort using quick sort
    auto start = chrono::high_resolution_clock::now();
    quickSort(v, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken by quick sort: " << duration.count() << " nanoseconds" << endl;
    //sort using inbuilt sort
    start = chrono::high_resolution_clock::now();
    sort(v.begin(), v.end());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken by inbuilt sort: " << duration.count() << " nanoseconds" << endl;
    return 0;
}