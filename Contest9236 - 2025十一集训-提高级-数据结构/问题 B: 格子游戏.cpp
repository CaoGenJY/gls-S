#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 4;
int fa[maxn], n, m;
map <pair<char, pair<int, int>>, int> mp;
void init () {
    for (int i = 1; i <= n * n + n; i++) fa[i] = i;
}
int find (int x) {
    if (x == fa[x]) return fa[x];
    else return fa[x] = find (fa[x]);
}
void unity (int x, int y) {
    int fx = find (x), fy = find (y);
    fa[fx] = fy;
}
int main () {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    init ();
    for (int i = 1; i <= m; i++) {
        int x, y; char dir;
        cin >> x >> y >> dir;
        if (mp.count ({dir, {x, y}})) continue ;
        else {
            mp[{dir, {x, y}}] = 1;
            int nx, ny;
            if (dir == 'D') nx = x + 1, ny = y;
            else nx = x, ny = y + 1;
            if (find (x * n + y) == find (nx * n + ny)) {
                cout << i << '\n';
                return 0;
            } else unity (x * n + y, nx * n + ny);
        }
    }
    puts ("draw");
    return 0;
}