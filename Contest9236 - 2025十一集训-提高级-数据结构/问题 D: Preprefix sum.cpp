#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
int n, m, a[maxn];
struct BIT {
    int tree[maxn];
    int lowbit (int x) {return x & (-x);}
    void add (int pos, int val) {
        for (int i = pos; i <= n; i += lowbit (i)) tree[i] += val;
    }
    int query (int pos) {
        int ret = 0;
        for (int i = pos; i > 0; i -= lowbit (i)) ret += tree[i];
        return ret;
    }
} b1, b2;
signed main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b1.add (i, a[i]);
        b2.add (i, a[i] * i);
    }
    for (int i = 1; i <= m; i++) {
        string op;
        int x, y;
        cin >> op >> x;
        if (op[0] == 'Q') {
            cout << (x + 1) * b1.query (x) - b2.query (x) << endl;
        } else {
            cin >> y;
            b1.add (x, y - a[x]);
            b2.add (x, (y - a[x]) * x);
            a[x] = y;
        }
    }
    return 0;
}