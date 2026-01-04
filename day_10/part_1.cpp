#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

vector<int> parse_numbers(const string &s) {
    int x = 0; vector<int> res;
    for (int i=1; i<s.length(); i++) {
        if (!isdigit(s[i])) res.push_back(x), x=0;
        else x = x * 10 + s[i]-'0';
    }
    return res;
}
void solve() {
    string s, t;
    vector<string> v;
    vector<vector<int>> states;
    int res = 0;
    while (getline(cin, s)) {
        v.clear();
        states.clear();
        stringstream ss(s);
        while (ss >> t) v.push_back(t);
        int n = v[0].size() - 2;
        int bulbs = 0;
        for (int i=1; i<=n; i++) if (s[i]=='#') bulbs |= (1<<(i-1));
        for (int i=1; i<v.size()-1; i++)
            states.push_back(parse_numbers(v[i]));
        int m = states.size(), ans = oo;
        for (int i=0; i<(1<<m); i++) {
            int curr = 0;
            for (int j=0; j<m; j++) 
                if (i & (1<<j)) 
                    for (auto k: states[j]) curr ^= (1<<k);
                
            if (curr == bulbs) ans = min(ans, __popcount(i));
        }
        res += ans;
    }
    cout << res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
}
