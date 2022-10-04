#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    bool dp[n+1][s+1];
    memset(dp,false,sizeof(dp));
    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (dp[i][j]) {
                if (j + a[i] <= s) {
                    dp[i + 1][j + a[i]] = true;
                }
                if (j + b[i] <= s) {
                    dp[i + 1][j + b[i]] = true;
                }
            }
        }
    }
    if (dp[n][s]) {
        cout << "Yes\n";
        string t(n, 'H');
        for (int i = n - 1; i >= 0; --i) {
            if (s >= a[i] and dp[i][s - a[i]]) {
                t[i] = 'H';
                s -= a[i];
            } else {
                t[i] = 'T';
                s -= b[i];
            }
        }
        cout << t << '\n';
    } else {
        cout << "No\n";
    }
    return 0;
}