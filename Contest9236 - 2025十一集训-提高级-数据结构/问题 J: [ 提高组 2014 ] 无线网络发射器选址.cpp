#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
int n, d, ans, anscnt;
struct ndoe {
    int x, y, k;
} a[maxn];
int main () {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> d >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].k;
    for (int i = 0; i <= 128; i++) {
        for (int j = 0; j <= 128; j++) {
            int x = i - d, y = j - d, xx = i + d, yy = j + d;
            int cnt = 0;
            for (int k = 1; k <= n; k++) {
                if (a[k].x >= x && a[k].x <= xx && a[k].y >= y && a[k].y <= yy) {
                    cnt += a[k].k;
                }
            }
            if (ans && ans == cnt) anscnt++;
            else if (ans < cnt) {
                ans = cnt;
                anscnt = 1;
            }
        }
    }
    cout << anscnt << ' ' << ans << '\n';
    return 0;
}