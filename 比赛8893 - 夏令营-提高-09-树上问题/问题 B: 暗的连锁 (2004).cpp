#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int> to[maxn],to2[maxn];
int n,m;
int anc[maxn][20],d[maxn];
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
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        to2[u].push_back(v);
        to2[v].push_back(u);
        
    }

}
/************************************************
  _____              _____             
 / ____|            / ____|            
| |     __ _  __ _ | |  __  ___  _ __  
| |    / _` |/ _` || | |_ |/ _ \| '_ \ 
| |___| (_| | (_| || |__| | (_) | | | |   Coding
 \_____\__,_|\__, | \_____|\___/|_| |_|
              __/ |                    
             |___/                     
************************************************/