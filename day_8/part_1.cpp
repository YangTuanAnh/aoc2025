#include <bits/stdc++.h>
#include <sstream>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e5+5;

struct P {
    ll x, y, z;
};

struct E {
    ll u, v, w;
};

ll dist2(P &u, P&v) {
    return  (u.x-v.x)*(u.x-v.x) + 
            (u.y-v.y)*(u.y-v.y) + 
            (u.z-v.z)*(u.z-v.z);
}

struct DSU {
    vector<ll> dsu;

    void init(int n) {
        dsu.clear();
        dsu.assign(n, -1);
    }

    int find(int u) {
        return dsu[u] < 0 ? u : dsu[u] = find(dsu[u]);
    }

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u==v) return false;
        if (dsu[u] > dsu[v]) swap(u, v);
        dsu[u] += dsu[v];
        dsu[v] = u;
        return true;
    }
};
void solve() {
    // read input
    string s;
    vector<P> pts;
    while (cin >> s) {
        stringstream ss(s);
        string a,b,c;
        getline(ss, a, ',');
        getline(ss, b, ',');
        getline(ss, c, ',');
        pts.push_back({stoll(a), stoll(b), stoll(c)});
    }
    vector<E> edges;
    for (int i=0; i<pts.size(); i++)
        for (int j=i+1; j<pts.size(); j++) {
            edges.push_back({i, j, dist2(pts[i], pts[j])});
        }

    sort(edges.begin(), edges.end(), [](const E &a, const E &b){
        return a.w < b.w;
    });

    DSU dsu;
    dsu.init(pts.size());

    for (int i=0; i<1000; i++) dsu.merge(edges[i].u, edges[i].v);

    vector<ll> sz;
    for (int i=0; i<pts.size(); i++) {
        if (dsu.dsu[i] < 0) sz.push_back(-dsu.dsu[i]);
    }

    sort(sz.rbegin(), sz.rend());
    cout << sz[0] * sz[1] * sz[2];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';   
}