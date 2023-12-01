// You are given a sequence of numbers p1,p2,…,pn. This number sequence contains a permuataion of numbers from 1 to n . SwapAdj operation to swap two adjacent values in the sequence. Your task is to find the minimum number of swapAdj calls required to generate sub-segment 1,2….k. That is after the sequence of swapAdj operations, there should be an integer i 1≤i≤n−k+1 such that pi=1,pi+1=2,…,pi+k−1=k.

//If g(k) is the minimum number of moves that you need to make a sub-segment with values 1,2,…,k appear in the sequence of numbers, you should return g(1),g(2),…,g(n).

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<int> g(n + 1);
    for (int i = 0; i < n; i++)
    {
        g[p[i]] = i;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int x = g[i + 1] - i;
        if (x < 0)
            x += n;
        ans[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}