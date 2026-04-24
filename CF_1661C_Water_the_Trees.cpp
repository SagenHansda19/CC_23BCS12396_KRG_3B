#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(vector<int>& h, int x) {
    ll c1 = 0, c2 = 0;
    for(int v : h) {
        int d = x - v;
        c2 += d / 2;
        c1 += d % 2;
    }
    ll diff = c2 - c1;
    if(diff > 3) {
        ll take = (diff - 3) / 3;
        c2 -= take;
        c1 += 2 * take;
    }
    ll res = 1e18;
    for(int i = 0; i < 10; i++) {
        if(c2 >= i) {
            res = min(res, max(2 * (c1 + 2 * i) - 1, 2 * (c2 - i)));
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    int mx = *max_element(h.begin(), h.end());
    ll ans = 1e18;
    ans = min(ans, calc(h, mx));
    ans = min(ans, calc(h, mx + 1));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}