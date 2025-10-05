#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e6 + 6;
struct query {
    int l, r, id;
} q[maxn];
int n, bel[maxn], cnt[maxn], aa[maxn], out[maxn];
int l, r, ql, qr, ans = 0;
 
bool cmp(query a, query b) {
    return bel[a.l] == bel[b.l] ? bel[a.r] < bel[b.r] : bel[a.l] < bel[b.l];
}
 
void add(int pt) {
    if(!cnt[aa[pt]]) ans ++ ;
    cnt[aa[pt]] ++ ;
}
 
void del(int pt) {
    cnt[aa[pt]] -- ;
    if(!cnt[aa[pt]]) ans -- ;
}
 
void init() {
    int siz = sqrt(n);
    int bnum = ceil((double)n / siz);
    for(int i = 1; i <= bnum; i ++ ) {
        for(int j = (i - 1) * siz + 1; j <= i * siz; j ++ ) {
            bel[j] = i;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i ++ ) {
        cin >> aa[i];
    }
    int Q;
    cin >> Q;
    for(int i = 1; i <= Q; i ++ ) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    init();
    sort(q + 1, q + Q + 1, cmp);
    for(int i = 1; i <= Q; i ++ ) {
        ql = q[i].l, qr = q[i].r;
        while(l < ql) del(l ++ );
        while(l > ql) add( -- l);
        while(r > qr) del(r -- );
        while(r < qr) add( ++ r);
        out[q[i].id] = ans;
    }
    for(int i = 1; i <= Q; i ++ ) cout << out[i] << "\n";
    return 0;
}