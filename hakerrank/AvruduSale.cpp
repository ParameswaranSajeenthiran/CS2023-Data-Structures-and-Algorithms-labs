#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>> n;
    cout<< n;
    cout<< "hi";
    vector<vector <int> > itemTime(n);
    // read Time in format hh mm HH MM , where hh mm is the start time and HH MM is the end time
    
    for(int i=0; i<n; i++){
        int hh, mm, HH, MM;
        cin>> hh>> mm>> HH>> MM;
        itemTime[i].push_back(hh);
        itemTime[i].push_back(mm);
        itemTime[i].push_back(HH);
        itemTime[i].push_back(MM);
    }

    //print itemTime 
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            cout<< itemTime[i][j]<< " ";
        }
        cout<< endl;
    }

    //Bigbuy.lk is an emerging e-commerce platform in Sri Lanka. Currently they are in the process of announcing special avurudu sales on April 14 which would result in increased traffic to their website. To handle the sudden influx of traffic, the management has decided to use dedicated servers for each item going on sale. Bigbuy.lk is facing severe financial constraints due to covid, hence to reduce the cost, the traffic needs to be managed with minimal number of servers. 5 mins needed for each server to switch from current sale item to new sale item. So if a sale finishes at 10 20 and another sale starts at 10 25, then the same server can be used as they have a 5-minute time gap. But, the server doesn’t take any time to handle the first sale item since those have been configured two days prior to the sale date. Write a program to effectively manage the servers.
    // C++ implementation
    // code
    // #include <iostream>
    // using namespace std;
    // int main()
    // {
    //     int n, m, t1, t2, t, i, j, k, l, count = 0;
    //     cin >> n >> m >> t1 >> t2;
    //     int a[m];
    //     for (i = 0; i < m; i++)
    //     {
    //         cin >> a[i];
    //     }
    //     for (i = 0; i < m; i++)
    //     {
    //         if (i == 0)
    //         {
    //             count++;
    //         }
    //         else

    //         {
    //             if (a[i] - a[i - 1] > t1 + t2)
    //             {
    //                 count++;
    //             }
    //         }
    //     }
    //     cout << count;
    //     return 0;
    // }
    // // Input Format
    
}

