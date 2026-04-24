class Solution {
public:
    const int mod = 1e9 + 7;
    using ll = long long;

    int nthMagicalNumber(int n, int a, int b){
        ll l = min(a, b);
        ll r = (ll)n * l;
        ll lcm = (ll)a * b / __gcd(a, b);
        while(l <= r){
            ll m = l + (r - l) / 2;
            ll cnt = m / a + m / b - m / lcm;
            if(cnt >= n) r = m - 1;
            else l = m + 1;
        }
        return l % mod;
    }
};