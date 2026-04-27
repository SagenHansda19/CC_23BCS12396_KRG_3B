class Solution {
  public:
  
    vector<int> calcLPS(string s) {
        int m = s.size(), len = 0, i = 1;
        vector<int> lps(m);
        while(i < m) {
            if(s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
  
    vector<int> search(string &t, string &s) {
        int n = s.size(), m = t.size();
        vector<int> lps = calcLPS(t);
        vector<int> ans;
        int i = 0, j = 0;
        while(i < n) {
            if(s[i] == t[j]) {
                i++, j++;
            } 
            if(j == m) {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
            else if(i < n && s[i] != t[j]) {
                if(j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return ans;
    }
};