#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int l, r;
    vector<int> v;
};

void init(vector<Node>& seg, int i, int l, int r) {
    seg[i].l = l;
    seg[i].r = r;
    seg[i].v.clear();
    if(l == r) return;
    int m = (l + r) >> 1;
    init(seg, i << 1, l, m);
    init(seg, i << 1 | 1, m + 1, r);
}

void add(vector<Node>& seg, int i, int pos, int val) {
    if(seg[i].l > pos || seg[i].r < pos) return;
    seg[i].v.push_back(val);
    if(seg[i].l == seg[i].r) return;
    add(seg, i << 1, pos, val);
    add(seg, i << 1 | 1, pos, val);
}

void flush(vector<Node>& seg, int i) {
    sort(seg[i].v.begin(), seg[i].v.end());
    if(seg[i].l == seg[i].r) return;
    flush(seg, i << 1);
    flush(seg, i << 1 | 1);
}

int query(vector<Node>& seg, int i, int l, int r) {
    if(seg[i].l > r || seg[i].r < l) return 0;
    if(seg[i].l >= l && seg[i].r <= r) {
        auto& v = seg[i].v;
        int x = lower_bound(v.begin(), v.end(), l) - v.begin();
        return (int)v.size() - x;
    }
    return query(seg, i << 1, l, r) + query(seg, i << 1 | 1, l, r);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<Node> seg(4 * n + 5);
    vector<queue<int>> q(n + 1);
    init(seg, 1, 1, n);
    for(int i = 1; i <= n; i++) {
        if((int)q[a[i]].size() == k) {
            add(seg, 1, i, q[a[i]].front());
            q[a[i]].pop();
        }
        q[a[i]].push(i);
    }
    flush(seg, 1);
    int Q, ans = 0;
    cin >> Q;
    while(Q--) {
        int l, r;
        cin >> l >> r;
        l = (l + ans) % n + 1;
        r = (r + ans) % n + 1;
        if(l > r) swap(l, r);
        ans = r - l + 1 - query(seg, 1, l, r);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}