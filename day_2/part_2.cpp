#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

vector<ll> ids, p;
void precompute_invalid_ids() {
    for (auto &a : {2, 3, 5, 7, 11}) {
        ll curr = 1;
        while (true) {
            string s = "";
            for (int i=0; i<a; i++) s+=to_string(curr);
            if (s.length()>12) break;
            ids.push_back(stoll(s));
            curr++;
        } 
    }
    sort(ids.begin(), ids.end());
    ids.erase(unique(ids.begin(), ids.end()), ids.end());
    p.resize(ids.size()+1);
    for (int i=1; i<=ids.size(); i++) p[i] = p[i-1] + ids[i-1];
}
void solve() {
    string data; cin >> data;
    stringstream ss(data);
    string s;
    ll ans = 0;
    while (getline(ss, s, ',')) {
        int idx = 0;
        for (int i=0; i<s.length(); i++)
            if (s[i]=='-') {
                idx = i;
                break;
            }
        
        string a = s.substr(0, idx), b = s.substr(idx+1, s.length()-idx-1);
        int l = lower_bound(ids.begin(), ids.end(), stoll(a)) - ids.begin();
        int r = upper_bound(ids.begin(), ids.end(), stoll(b)) - ids.begin() - 1;
        if (l <= r) ans += p[r+1]-p[l];
    }
    cout << ans;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    precompute_invalid_ids();
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';   
}