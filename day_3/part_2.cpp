#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

void solve() {
    ll ans = 0;
    string s;
    deque<char> dq;
    while (cin >> s) {
        ll res = 0;
        int n = s.length(), k=12;
        int cnt = n-k;
        for (auto &c: s) {
            while (!dq.empty() && cnt > 0 && dq.back() < c) {
                dq.pop_back();
                cnt--;
            }
            dq.push_back(c);
        }
        while (dq.size() > k) dq.pop_back();
        while (!dq.empty()) {
            res = res * 10 + dq.front() - '0';
            dq.pop_front();
        }
        ans += res;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';   
}