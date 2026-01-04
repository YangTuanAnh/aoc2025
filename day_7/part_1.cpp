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
    vector<int> coords; int start;
    while (getline(cin, s)) {
        grid.push_back(s);
        for (int i=0; i<s.length(); i++)
            if (s[i]=='S') start = i;
            else if (s[i]=='^') coords.push_back(i);
    }
    ll ans = 0;
    vector<bool> beams(s.length());
    beams[start]=1;
    for (auto &i: coords) {
        if (beams[i]) {
            beams[i+1] = 1;
            beams[i-1] = 1;
            beams[i]=0;
            ans++;
        }
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