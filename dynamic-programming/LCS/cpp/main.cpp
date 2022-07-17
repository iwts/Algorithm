/**
 * poj-1458 是LCS模板题，可以提交测试
 * http://poj.org/problem?id=1458
*/

#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#define TIME std::ios::sync_with_stdio(false)
#define MAX 233

using namespace std;

string s1,s2;
int len1,len2;
int dp[MAX][MAX];

int Max(int a,int b) {
    return a > b ? a : b;
}

int main() {
    TIME;
    while(cin >> s1 >> s2) {
        len1 = s1.size();
        len2 = s2.size();
        for (int i = 0;i <= len1;i++) {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for (int i = 1;i <= len1;i++) {
            for (int j = 1;j <= len2;j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        cout << dp[len1][len2] << endl;
    }

    system("pause");
    return 0;
}
