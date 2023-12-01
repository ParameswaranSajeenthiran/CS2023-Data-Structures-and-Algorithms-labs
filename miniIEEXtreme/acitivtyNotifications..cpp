#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double calculateMedian(const vector<int>& expenditure, int d) {
    int count = 0;
    vector<int> freq(201, 0);  // Frequency array to count occurrences

    for (int i = 0; i < d; i++) {
        freq[expenditure[i]]++;
    }

    int medianPos1 = (d + 1) / 2;
    int medianPos2 = d / 2;

    int i = 0;
    for (; count < medianPos1; i++) {
        count += freq[i];
    }
    int median1 = i - 1;

    for (; count < medianPos2 + 1; i++) {
        count += freq[i];
    }
    int median2 = i - 1;

    return (d % 2 == 0) ? (median1 + median2) / 2.0 : median1;
}

int activityNotifications(vector<int>& expenditure, int d) {
    int notifications = 0;
    int n = expenditure.size();

    for (int i = d; i < n; i++) {
        double median = calculateMedian(expenditure, d);
        if (expenditure[i] >= 2 * median) {
            notifications++;
        }

        // Update the frequency array for the next iteration
        expenditure[i - d]--;
        expenditure[i]++;
    }

    return notifications;
}

int main() {
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
