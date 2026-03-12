class Solution {
   public:
    using ll = long long;
    const int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dd(32, 0);
        for (int x : nums) {
            for (int i = 0; i < 32; i++) {
                if (x & (1 << i)) dd[i]++;
            }
        }
        ll ans = 0;
        while (k--) {
            ll num = 0;
            for (int i = 0; i < 32; i++) {
                if (dd[i]) {
                    num += (1 << i);
                    dd[i]--;
                }
            }
            ans += (num * num) % mod;
            ans %= mod;
        }
        return ans;
    }
};
