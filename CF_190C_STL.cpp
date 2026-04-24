#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    if(n == 1) {
        string s;
        cin >> s;
        if(s == "int") cout << "int\n";
        else cout << "Error occurred\n";
        return;
    }
    stack<int> st;
    string s, ans = "";
    int cnt = 0;
    while(cin >> s) {
        if(cnt && st.empty()) {
            cout << "Error occurred\n";
            return;
        }
        cnt++;
        if(s == "int") {
            if(st.empty()) {
                cout << "Error occurred\n";
                return;
            }
            if(st.top() == 1) {
                ans += ",int";
                while(!st.empty() && st.top() == 1) {
                    st.pop();
                    ans += '>';
                }
                if(!st.empty()) {
                    st.pop();
                    st.push(1);
                }
            } else {
                st.pop();
                ans += "int";
                st.push(1);
            }
        } else {
            if(st.empty() || st.top() == 0) ans += "pair<";
            else ans += ",pair<";

            st.push(0);
        }
    }
    if(!st.empty()) cout << "Error occurred\n";
    else cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}