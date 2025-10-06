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
const int maxn=1e6+6;
int n,cnt,idx;
int a[maxn],b[maxn],ys[maxn];
int f[maxn];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=read();
        ys[a[i]]=++cnt;
    }
    for(int i=1;i<=n;i++){
        int bb=read();
        b[i]=ys[bb];
    }
    f[++idx]=b[1];
    for(int i=2;i<=n;i++){
        if(b[i]>f[idx]){
            f[++idx]=b[i];
        }else{
            int id=lower_bound(f+1,f+idx+1,b[i])-f;
            f[id]=b[i];
        }
    }
    cout<<idx;
    return 0;
}
/**************************************************************
   ____                    ____                      _  __   __
  / ___|   ____    ___    / ___|   ___   ____       | | \ \ / /
 | |      / _  |  / _ \  | |  _   / _ \ |  _ \   _  | |  \ V / 
 | |___  | (_| | | (_) | | |_| | |  __/ | | | | | |_| |   | |  
  \____|  \____|  \___/   \____|  \___| |_| |_|  \___/    |_|  
                                                               
**************************************************************/