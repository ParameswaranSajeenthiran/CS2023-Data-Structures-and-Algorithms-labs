#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
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
                swap(v[i], v[j]);
            }
        }
        swap(v[i + 1], v[high]);
        int p = i + 1;
        quickSort(v, low, p - 1);
        quickSort(v, p + 1, high);
    }
}

vector<int> closestNumbers(vector<int> arr)
{
    quickSort(arr, 0, arr.size()-1);
        printVector(arr);

    vector<int> result;
    int n = arr.size();
    int min = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        cout<< " minimum " <<min << " difference "<< abs(arr[i] - arr[i + 1]);
        if (min > abs(arr[i] - arr[i + 1]))

        {
            min =abs(arr[i] - arr[i + 1]);
            result.clear();
            result.push_back(arr[i]);
            result.push_back(arr[i + 1]);
        }
        else if (abs(arr[i] - arr[i + 1]) == min)
        {
            result.push_back(arr[i]);
            result.push_back(arr[i + 1]);
        }
        cout<<" result ";
         printVector(result);
    }

    cout <<endl;
    printVector(arr);
   
    // cout<<min;
}
int main()
{
    vector<int> test = {-20, -3916237, -357920, -3620601, 7374819, -7330761, 30, 6246457, -6461594, 266854, -520, -470};
    vector<int >test2={5 ,4, 3, 2};
    vector <int> test3={-5 ,15 ,25 ,71 ,63};
    closestNumbers(test3);

    return 0;
}
