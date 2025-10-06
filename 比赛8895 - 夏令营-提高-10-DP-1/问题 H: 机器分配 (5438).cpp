#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read() {
    char c = getchar(); int x = 0, f = 1;
    while (c < 48) {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c > 47)
        x = (x * 10) + (c ^ 48), c = getchar();
    return x * f;
}

inline void mwrite(ll a) {
    if (a > 9) mwrite(a / 10);
    putchar((a % 10) | 48);
}

inline void write(int a, char c) {
    mwrite(a < 0 ? (putchar('-'), a = -a) : a);
    putchar(c);
}
const int maxn=20;
int n,m;
int v[maxn][maxn];
int dp[maxn][maxn];      //dp[i][j]代表前i个分公司分得j台设备的最大盈利
int path[maxn][maxn][maxn];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>v[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=j;k++){
                int now=dp[i-1][j-k]+v[i][k];
                if(now>=dp[i][j]){
                    dp[i][j]=now;
                    for(int u=1;u<i;u++) path[i][j][u]=path[i-1][j-k][u];
                    path[i][j][i]=k;
                }
            }
        }
    }
    write(dp[n][m],'\n');
    for(int i=1;i<=n;i++){
        write(i,' ');write(path[n][m][i],'\n');
    }
    return 0;
}
/**************************************************************
   ____                    ____                      _  __   __
  / ___|   ____    ___    / ___|   ___   ____       | | \ \ / /
 | |      / _  |  / _ \  | |  _   / _ \ |  _ \   _  | |  \ V / 
 | |___  | (_| | | (_) | | |_| | |  __/ | | | | | |_| |   | |  
  \____|  \____|  \___/   \____|  \___| |_| |_|  \___/    |_|  
                                                               
**************************************************************/