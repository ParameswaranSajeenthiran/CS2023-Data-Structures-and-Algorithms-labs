#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Complete the activityNotifications function below.



double calculateMedian(const vector<int>& expenditure, int d, int start, int end) {
    // sort expenditure from start to end
    vector<int> sortedExpenditure;
    for(int i=start;i<end;i++){
        sortedExpenditure.push_back(expenditure[i]);
    }
    //print sorted expenditure
    for(int i=0;i<sortedExpenditure.size();i++){
        cout<<sortedExpenditure[i]<<" ";
    }
    cout<<endl;
    sort(sortedExpenditure.begin(),sortedExpenditure.end());
     for(int i=0;i<sortedExpenditure.size();i++){
        cout<<sortedExpenditure[i]<<" ";
    }
    cout<<endl;
    // calculate median in sorted expenditure
    int n= sortedExpenditure.size();
     if (5 % 2 != 0)
      return sortedExpenditure[n / 2];
   return (sortedExpenditure[(n - 1) / 2] + sortedExpenditure[n / 2]) / 2.0;
    




   

}


int activityNotifications(vector<int> expenditure, int d) {
    int notifications = 0;
    int n = expenditure.size();
    int end =n-1;

    for (int i = 0; i <= (end -d); i++) {
        double median = calculateMedian(expenditure, d,i,i+d);
        cout<< "median :"<<2* median;
        cout<< " expenditure[i] :"<< (double) expenditure[i+5]<<endl;
        if (  expenditure[i+d] >= 2 * median) {
            cout<<"notification"<<endl;
            notifications++;
        }

        // // Update the frequency array for the next iteration
        // expenditure[i - d]--;
        // expenditure[i]++;
    }

    return notifications;
}

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> expenditure(n);
    for (int i = 0; i < n; i++) {
        cin >> expenditure[i];
    }

    int result = activityNotifications(expenditure, d);
    cout << result << endl;

    return 0;
}