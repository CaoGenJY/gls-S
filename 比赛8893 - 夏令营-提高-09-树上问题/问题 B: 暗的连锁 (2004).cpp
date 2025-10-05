#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
    char c=getchar(); int x=0,f=1;
    while(c<48){if(c=='-')f=-1;c=getchar();}
    while(c>47)x=(x*10)+(c^48),c=getchar();
    return x*f;
}
inline void mwrite(ll a)
{
    if(a>9)mwrite(a/10);
    putchar((a%10)|48);
}
inline void write(int a,char c)
{
	mwrite(a<0?(putchar('-'),a=-a):a);
	putchar(c);
}
const int maxn=1e5+5;
vector<int> to[maxn];
int n,m;
int anc[maxn][20],d[maxn],sum[maxn];
void dfs(int u,int fa)
{
    for(int i=0;i<to[u].size();i++)
    {
        int v=to[u][i];
        if(v==fa) continue;
        anc[v][0]=u;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}
void init()
{
    for(int j=1;j<=18;j++)
    {
        for(int i=1;i<=n;i++) anc[i][j]=anc[anc[i][j-1]][j-1];
    }
}
int lca(int u,int v)
{
    if(d[u]<d[v]) swap(u,v);
    for(int i=18;i>=0;i--)
    {
        if(d[anc[u][i]]>=d[v]) u=anc[u][i];
    }
    if(u==v) return u;
    for(int i=18;i>=0;i--)
    {
        if(anc[u][i]!=anc[v][i]) u=anc[u][i],v=anc[v][i];
    }
    return anc[u][0];
}
void dfs2(int u,int fa)
{
    for(int i=0;i<to[u].size();i++)
    {
        int v=to[u][i];
        if(v==fa) continue;
        dfs2(v,u);
        sum[u]+=sum[v];
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1,0);init();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        int l=lca(u,v);
        sum[u]++;sum[v]++;
        sum[anc[l][0]]-=2;
    }
    dfs2(1,0);
    ll ans=0;
    for(int i=2;i<=n;i++)
    {
        if(!sum[i]) ans+=m;
        else if(sum[i]==1) ans++;
    }
    write(ans,'\n');
    return 0;
}
/************************************************
  _____              _____             
 / ____|            / ____|            
| |     ____  ____ | |  __  ___   ____  
| |    / _  |/ _  || | |_ |/ _ \ |  _ \ 
| |___| (_| | (_| || |__| | (_)  | | | |   Coding
 \_____\____|\___ | \_____|\___/ |_| |_|
              __/ |                    
             |___/                     
************************************************/