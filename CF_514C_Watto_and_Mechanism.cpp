#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    bool end = 0;
    Node* nxt[26];

    Node() {
        memset(nxt, 0, sizeof(nxt));
    }
};

void insert(Node* root, string& s, int i = 0) {
    if(i == (int)s.size()) {
        root->end = 1;
        return;
    }

    int c = s[i] - 'a';
    if(!root->nxt[c]) root->nxt[c] = new Node();

    insert(root->nxt[c], s, i + 1);
}

bool query(Node* root, string& s, int i, int changed) {
    if(i == (int)s.size()) return root->end && changed;

    if(!changed) {
        for(int j = 0; j < 26; j++) {
            if(!root->nxt[j]) continue;

            if(query(root->nxt[j], s, i + 1, changed || (j != s[i] - 'a')))
                return 1;
        }
    } else {
        int c = s[i] - 'a';
        if(root->nxt[c])
            return query(root->nxt[c], s, i + 1, 1);
    }

    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    Node* root = new Node();

    while(n--) {
        string s;
        cin >> s;
        insert(root, s);
    }

    while(m--) {
        string s;
        cin >> s;

        cout << (query(root, s, 0, 0) ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) solve();
}