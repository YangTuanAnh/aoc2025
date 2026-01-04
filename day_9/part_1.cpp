#include <bits/stdc++.h>
#include <sstream>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

struct P {
    ll x, y;
};

void solve() {
    // read input
    string s;
    vector<P> pts;
    while (cin >> s) {
        stringstream ss(s);
        string a,b;
        getline(ss, a, ',');
        getline(ss, b, ',');
        pts.push_back({stoll(a), stoll(b)});
    }
    ll ans = 0;
    for (int i=0; i<pts.size(); i++)
        for (int j=i+1; j<pts.size(); j++)
            ans = max(ans, abs(pts[i].x-pts[j].x+1)*abs(pts[i].y-pts[j].y+1));
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';   
}