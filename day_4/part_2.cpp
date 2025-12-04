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
    queue<pair<int, int>> q;
    vector<vector<int>> cnt_adj(n, vector<int>(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (g[i][j]!='@') continue;
            int cnt = 0;
            for (int k=0; k<8; k++) 
                if (i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<m)
                    cnt += (g[i+dx[k]][j+dy[k]]=='@');
            cnt_adj[i][j]=cnt;
            if (cnt<4) q.push({i, j});
        }
    
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        g[i][j] = '.';
        ans++;
        for (int k=0; k<8; k++) {
            int new_i = i+dx[k], new_j = j+dy[k];
            if (new_i>=0 && new_i<n && new_j>=0 && new_j<m && g[new_i][new_j]=='@') {
                cnt_adj[new_i][new_j]--;
                if (cnt_adj[new_i][new_j]==3) q.push({new_i, new_j});
            }
        }
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