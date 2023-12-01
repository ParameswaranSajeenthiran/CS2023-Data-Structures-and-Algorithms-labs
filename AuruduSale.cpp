//Bigbuy.lk is an emerging e-commerce platform in Sri Lanka. Currently they are in the process of announcing special avurudu sales on April 14 which would result in increased traffic to their website. To handle the sudden influx of traffic, the management has decided to use dedicated servers for each item going on sale. Bigbuy.lk is facing severe financial constraints due to covid, hence to reduce the cost, the traffic needs to be managed with minimal number of servers. 5 mins needed for each server to switch from current sale item to new sale item. So if a sale finishes at 10 20 and another sale starts at 10 25, then the same server can be used as they have a 5-minute time gap. But, the server doesn’t take any time to handle the first sale item since those have been configured two days prior to the sale date. Write a program to effectively manage the servers.
// Input Format
// First line contains the number of servers available
// Second line contains the number of sale items
// Third line contains the time taken to configure each server
// Fourth line contains the time taken to switch between sale items
// Fifth line contains the time at which each sale item starts
// Output Format
// Print the minimum number of servers required to handle the traffic
// Constraints
// 1<=N<=100
// 1<=M<=100
// 1<=T1<=100
// 1<=T2<=100
// 1<=T<=100
// Sample Input/Output
// Input
2
4
2
5
// 10 20 25 40
// Output
// 2
// Explanation
// 2 servers are available
// 4 sale items
// 2 mins needed to configure each server
// 5 mins needed to switch between sale items
// 10 20 25 40 are the times at which each sale item starts
// 2 servers are enough to handle the traffic
// 1st server handles the first two sale items
// 2nd server handles the last two sale items
// 1st server handles the first sale item from 10 to 10 20
// 1st server handles the second sale item from 10 25 to 10 30
// 2nd server handles the third sale item from 10 35 to 10 40
// 2nd server handles the fourth sale item from 10 45 to 10 50
// Hence 2 servers are enough to handle the traffic
// code implementation
#include <iostream>
using namespace std;
int main()
{
    int n, m, t1, t2, t, i, j, k, l, count = 0;
    cin >> n >> m >> t1 >> t2;
    int a[m];
    for (i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < m; i++)
    {
        if (i == 0)
        {
            count++;
        }
        else
        {
            if (a[i] - a[i - 1] > t1 + t2)
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
// Path: BigBuy..cpp
