#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

char ch;
int id;

template<class T> inline void fint(T &n){
    for(ch=getchar();ch<48 || ch>57;ch=getchar());
    n=ch-48;
    for(ch=getchar();ch>47 && ch<58;ch=getchar())
        n=(n<<3)+(n<<1)+ch-48;
}
inline void fstring(char *str){
    id=0;ch=0;
    for(;ch<33;ch=getchar());
    while (ch!='\n'){
        str[id]=ch;
        if ((ch=getchar())==EOF) break;
        id++;
    }
    str[id]='\0';
}

char s[100];
long long n;
double cl;

int main(){
    return 0;
}
