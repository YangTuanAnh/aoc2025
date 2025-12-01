#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

void solve() {
    string s;
    int ans = 0, curr = 50;
    while (cin >> s) {
        char c = s[0]; int cnt = 0;
        for (int i=1; i<s.length(); i++) cnt = cnt * 10 + (s[i]-'0');
        ans += cnt / 100;
        cnt %= 100;
        if (!cnt) continue;
        int prev = curr;
        c == 'L' ? curr -= cnt : curr += cnt;
        if (prev && (curr <= 0 || curr >= 100)) ans++;
        curr = (curr + 100) % 100;
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