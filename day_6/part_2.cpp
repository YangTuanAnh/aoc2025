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
    while (getline(cin, s)) grid.push_back(s + ' ');

    int n = grid[0].size();
    int idx = 0;
    ll ans = 0;
    for (int i=0; i<n; i++) {
        if (i!=n) {
            if (grid.back()[i+1]==' ') continue;
        }
        char ch = grid.back()[idx];
        ll tot = ch == '*' ? 1 : 0;
        for (int j=idx; j<i; j++) {
            ll val = 0;
            for (int k=0; k<grid.size()-1; k++)
                if (grid[k][j]!=' ')
                    val = val * 10 + grid[k][j] - '0';
            ch == '*' ? tot *= val : tot += val;
        }
        ans += tot;
        idx = i+1;
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