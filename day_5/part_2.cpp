#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

void solve() {
    string s;
    bool get_query=false;
    vector<pll> range, range_merged;
    vll q;
    int idx = 0;
    while (getline(cin, s)) {
        if (s.length()==1) {
            get_query = true;
            continue;
        }
        if (!get_query) {
            ll l = 0, r = 0, idx = 0;

            for (int i = 0; i < s.length()-1; i++) {
                if (s[i] == '-') {
                    idx = i;
                    break;
                }
                l = l * 10 + (s[i] - '0');
            }
            for (int i = idx + 1; i < s.length()-1; i++) 
                r = r * 10 + (s[i] - '0');
            range.push_back({l, r});
        }
    }
    sort(range.begin(), range.end());
    
    ll ans = 0;
    while (!range.empty()) {
        while (range.size()>1 && range[0].second >= range[1].first) {
            range[1].first = min(range[0].first, range[1].first);
            range[1].second = max(range[0].second, range[1].second);
            range.erase(range.begin());
        }
        range_merged.push_back(range[0]);
        range.erase(range.begin());
    }
    for (auto &i: range_merged) ans += i.second - i.first + 1;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';   
}