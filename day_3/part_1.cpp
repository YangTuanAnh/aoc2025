#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

void solve() {
    ll ans = 0;
    string s;
    while (cin >> s) {
        int curr = 0;
        vector<bool> seen(10);
        for (auto &c: s) {
            for (int i=9; i>=1; i--) 
                if (seen[i]) 
                    curr = max(curr, i*10+c-'0');
            if (!seen[c-'0']) seen[c-'0']=1;
        }
        ans += curr;
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