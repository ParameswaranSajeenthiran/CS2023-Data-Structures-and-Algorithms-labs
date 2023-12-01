#include <cmath>
#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool isPossible(long long int n)
{
    if (n == 1)
        return true;
    if (n % 10 != 0 && n % 20 != 0)
        return false;
    
    return isPossible(n / 10) || isPossible(n / 20);
}

int main()
{
    int m;
    cin >> m;
    long long int n;
    
    for ( int i=0; i< m; i++){
        cin>>n;
        if (isPossible(n))
        cout << "Yes"<<endl;
    else
        cout << "No"<<endl;
    }
    
    
    return 0;
}