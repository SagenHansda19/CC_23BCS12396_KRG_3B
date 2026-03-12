class Solution {
   public:
    using ll = long long;
    ll pps(vector<int>& nums, ll m) {
        ll pp = 0;
        for (int i : nums) {
            if (i <= m) {
                pp++;
            } else {
                pp += (i + m - 1) / m;
            }
        }
        return pp;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        ll l = 1, r = *max_element(nums.begin(), nums.end()), n = nums.size(),
           ans = LLONG_MAX;
        while (l <= r) {
            ll m = l + (r - l) / 2;
            if (pps(nums, m) <= n + maxOperations) {
                ans = min(ans, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
