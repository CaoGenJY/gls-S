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
const int maxn=1005;
ll n,s,t;
ll a[maxn];
ll f[maxn];
int main()
{
    memset(f,-1,sizeof f);
    n=read();s=read();t=read();
    for(int i=1;i<=n;i++) a[i]=read();
    f[1]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=s;j<=t;j++){
            if(i<=j) break;
            if(~f[i-j]) f[i]=max(f[i],f[i-j]+a[i]);
        }
    }
    cout<<f[n];
    return 0;
}
/**************************************************************
   ____                    ____                      _  __   __
  / ___|   ____    ___    / ___|   ___   ____       | | \ \ / /
 | |      / _  |  / _ \  | |  _   / _ \ |  _ \   _  | |  \ V / 
 | |___  | (_| | | (_) | | |_| | |  __/ | | | | | |_| |   | |  
  \____|  \____|  \___/   \____|  \___| |_| |_|  \___/    |_|  
                                                               
**************************************************************/