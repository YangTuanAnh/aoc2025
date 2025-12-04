#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

string next_invalid(const string &a, bool after=true) {
    string s;
    if (a.length()&1) {
        int len = (after ? a.length()+1 : a.length()-1);
        for (int i=0; i<len; i++)
            s += after ? (i==0 || i==len/2 ? '1' : '0') : '9';
        return s;
    }
    int len = a.length();
    s = a.substr(0, len/2);
    s += s;
    if ((s >= a && after) || (s <= a && !after)) return s;
    int num = 0;
    for (int i=0; i<len/2; i++) num = num*10 + (s[i]-'0');
    after ? num++ : num--;
    string ss = to_string(num);
    ss += ss;
    return ss;
}
ll range_sum(string &a, string &b) {
    int l=0, r=0;
    for (size_t i=0; i<a.length()/2; i++) l = l * 10 + (a[i]-'0');
    for (size_t i=0; i<b.length()/2; i++) r = r * 10 + (b[i]-'0');
    if (l > r) return 0;
    
    ll ans = 0;
    ans += (r+l) * (r-l+1) / 2;
    ll curr = 10;
    while (curr <= l) curr *= 10;
    if (curr >= r) {
        ans += (r+l) * (r-l+1) / 2 * curr;
        return ans;
    }

    ans += (curr + l - 1) * (curr - l) / 2 * curr;
    while (curr * 10 < r) {
        ll next = curr * 10 - 1;
        ans += (curr + next) * (curr - next + 1) / 2 * curr;
        curr *= 10;
    }
    ans += (r + curr) * (r - curr + 1) / 2;
    return ans;
}
void solve() {
    string data; cin >> data;
    stringstream ss(data);
    string s;
    ll ans = 0;
    while (getline(ss, s, ',')) {
        // cout << s << '\n';
        int idx = 0;
        for (int i=0; i<s.length(); i++)
            if (s[i]=='-') {
                idx = i;
                break;
            }
        
        string a = s.substr(0, idx), b = s.substr(idx+1, s.length()-idx-1);
        string aa = next_invalid(a), bb = next_invalid(b, false);
        cout << a << ' ' << b << '\n';
        cout << aa << ' ' << bb << '\n';
        if (stoll(aa) <= stoll(bb)) ans += range_sum(aa, bb);
        cout << "===\n";
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