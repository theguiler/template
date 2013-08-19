#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll gabs(ll a){
    return (a<0 ? -a:a);
}
ll gcd(ll a,ll b){
    ll r;
    while (b){r=a%b;a=b;b=r;}
    return a;
}
void add(ll &a,ll b,ll m){
    if ((a+=b)>=m) a-=m;
}

ll fmul(ll a,ll b,ll m){
    ll t=0LL,d=a;
    for(;b;b>>=1){
        if (b&1) add(t,d,m);
        add(d,d,m);
    }
    return t;
}
ll fpow(ll a,ll b,ll m){
    ll t=1LL,d=a;
    for(;b;b>>=1){
        if (b&1) t=fmul(t,d,m);
        d=fmul(d,d,m);
    }
    return t;
}
bool rabin(ll n,int k){
    if (n==2) return 1;
    if (n<2 || (1-n&1)) return 0;
    ll a,mod,t,s=n-1;
    for(;1-(s&1);s>>=1);
    while (k--){
        a=rand()%(n-2)+1;
        t=s;
        mod=fpow(a,s,n);
        while (t!=n-1 && mod!=1 && mod!=n-1){
            mod=fmul(mod,mod,n);
            t<<=1;
        }
        if (mod!=n-1 && (1-t&1)) return 0;
    }
    return 1;
}

ll pollardRho(ll n,ll a){
    ll x,y,d;
    x=y=rand()%(n-1)+1;
    ll l=1,r=2;
    while (1){
        x=fmul(x,x,n);
        add(x,a,n);
        if (x==y) return n;
        d=gcd(gabs(x-y),n);
        if (1<d && d<n) return d;
        l++;
        if (l==r) y=x,r<<=1;
    }
}

vector<ll> pr;

void fact(ll n){
    if (rabin(n,1)) {pr.push_back(n);return;}
    ll d=n;
    while (d>=n) d=pollardRho(n,rand()%(n-1)+1);
    fact(n/d);fact(d);
}

int main(){
    return 0;
}
