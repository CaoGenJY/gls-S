#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n, cnt;
int a[maxn], b[maxn], c[maxn], ys[maxn];
struct BIT {
    int tree[maxn];
    int lowbit (int x) {return x & (-x);}
    void init () {
        memset (tree, 0, sizeof tree);
    }
    void add (int pos, int val) {
        for (int i = pos; i <= n; i += lowbit (i)) tree[i] += val;
    }
    int query (int pos) {
        int ret = 0;
        for (int i = pos; i > 0; i -= lowbit (i)) ret += tree[i];
        return ret;
    }
} b1;
void swp () {
    for (int i = 1; i <= n; i++) swap (a[i], c[i]);
}
int solve () {
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        ys[a[i]] = ++cnt;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = ys[c[i]];
    }
    int ans = 0; b1.init ();
    for (int i = n; i >= 1; i--) {
        ans += b1.query (b[i]);
        b1.add (b[i], 1);
    }
    int tmp = ans;
    for (int i = n; i >= 1; i--) {
        tmp = tmp - (n - b[i]) + (b[i] - 1);
        ans = min (ans, tmp);
    }
    return ans;
}
signed main () {
    freopen ("mincross.in", "r", stdin);
    freopen ("mincross.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int a1 = solve ();
    swp ();
    int a2 = solve ();
    cout << min (a1, a2);
    return 0;
}