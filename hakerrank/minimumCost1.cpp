//You are given a keypad with ten buttons representing digits from [0,9], when pressed, the corresponding digit appears on the screen. There is an additional button called Addition Modulo 10 which can be used to replace the last two digits a, b with x according to the following equation.

//x=(a+b)mod10

//If there are less than two digits on the screen, Addition Modulo 10 does not work. The cost of pressing any digit is Ci for i = 0, 1, …., 9 and the cost of pressing Addition Modulo 10 button is always 0.

//If you are given the cost of pressing each button, find the minimum cost of feeding a given target number S into the screen using a sequence of button presses

//Input Format

//The first line contains an integer T, the number of test cases. Then the test cases follow.
//Each test case contains two lines of input.
//The first line contains a string S, the target number.
//The second line contains 10 space-separated integers C0,C1,…,C9, where Ci is the cost of pressing the digit i.
//Output Format

//For each test case, output in a single line the minimum cost of feeding the target number into the screen.

//Constraints

//1≤T≤100
// code 
 #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    using namespace std;

    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            string s;
            cin >> s;
            vector<int> c(10);
            for (int i = 0; i < 10; i++)
            {
                cin >> c[i];
            }
            int n = s.size();
            int dp[n + 1];
            dp[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                dp[i] = 1e9;
                int num = 0;
                for (int j = i - 1; j >= 0 && i - j <= 10; j--)
                {
                    num = num * 10 + (s[j] - '0');
                    if (num > 1e6)
                        break;
                    dp[i] = min(dp[i], dp[j] + c[num % 10]);
                }
            }
            cout << dp[n] << endl;
        }
        return 0;
    }