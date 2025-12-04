#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

void solve() {
    vector<string> g;
    string s;
    while (cin >> s) g.push_back(s);
    int n = g.size(), m = g[0].size();
    int ans = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (g[i][j]!='@') continue;
            int cnt = 0;
            for (int k=0; k<8; k++) 
                if (i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<m)
                    cnt += (g[i+dx[k]][j+dy[k]]=='@');
            ans += cnt < 4;
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