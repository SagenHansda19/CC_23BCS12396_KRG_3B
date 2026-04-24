class Solution {
public:
    using ll = long long;
    bool is(int n, vector<int>& b, ll m) {
        ll cur = 0;
        for(int i = 0; i < b.size(); i++) {
            cur += min(m, (ll)b[i]);
        }
        return cur >= (ll)n * m;
    }
    long long maxRunTime(int n, vector<int>& b) {
        ll l = 1, r = accumulate(b.begin(), b.end(), 0LL) / n;
        ll ans = 0;
        while(l <= r) {
            ll m = l + (r - l) / 2;
            if(is(n, b, m)) {
                l = m + 1;
                ans = m;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};