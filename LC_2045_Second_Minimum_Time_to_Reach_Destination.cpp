class Solution {
public:
    using ll = long long;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for(auto i : edges) {
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(1);
        ll dd = -1, curT = 0;
        vector<vector<int>> tts(n + 1);
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int x = q.front();
                q.pop();
                if(x == n) {
                    if(dd != -1) {
                        return curT; 
                    } 
                    dd = curT;
                }
                for(int nei : adj[x]) {
                    if(tts[nei].size() == 0 || (tts[nei].size() == 1 && tts[nei][0] != curT)) {
                        tts[nei].push_back(curT);
                        q.push(nei);
                    }
                }
            }
            if((curT / change) % 2 == 1) {
                curT += change - (curT % change);
            }
            curT += time;
        }
        return dd;
    }
};