#include <bits/stdc++.h>
#include <sstream>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

void solve() {
    vector<string> grid;
    string s;
    while (getline(cin, s)) grid.push_back(s);

    int R = grid.size() - 1;
    int C;

    stringstream ss0(grid[0]);
    vector<vll> v;
    ll x;

    while (ss0 >> x) v.push_back({x});
    C = v.size();

    for (int i = 1; i < R; i++) {
        stringstream ss(grid[i]);
        for (int j = 0; j < C; j++) {
            ss >> x;
            v[j].push_back(x);
        }
    }

    stringstream ss1(grid.back());
    vector<char> ops(C);
    for (int i = 0; i < C; i++) ss1 >> ops[i];

    ll ans = 0;
    for (int i = 0; i < C; i++) {
        ll tot = v[i][0];
        for (int j = 1; j < R; j++) {
            if (ops[i] == '*') tot *= v[i][j];
            else tot += v[i][j];
        }
        ans += tot;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';   
}