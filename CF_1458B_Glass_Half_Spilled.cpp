#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int C = 10005;

void buildDP(vector<vector<int>>& dp, vector<int>& a, vector<int>& b, int n) {
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j >= 0; j--) {
            for(int x = 0; x + a[i] < C; x++) {
                if(dp[j][x] == -1) continue;
                dp[j + 1][x + a[i]] = max(dp[j + 1][x + a[i]], dp[j][x] + b[i]);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(C, -1));
    buildDP(dp, a, b, n);
    int sum = 0;
    for(int x : b) sum += x;
    cout << fixed << setprecision(13);
    for(int k = 1; k <= n; k++) {
        double ans = 0;
        for(int x = 0; x < C; x++) {
            if(dp[k][x] == -1) continue;
            ans = max(ans, min((double)x, (double)(sum + dp[k][x]) / 2.0));
        }
        cout << ans << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}