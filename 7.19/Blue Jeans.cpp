//#include<bits/stdc++.h>
#include<string>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
#define R register int
#define inf 0x3f3f3f3f
#define mod 1000000007;
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
void put1(){ puts("YES") ;}
void put2(){ puts("NO") ;}
void put3(){ puts("-1"); }

const int manx=1e4+5;


string s[manx];

int main()
{
    ll t=read();
    while(t--)
    {
        ll  n=read();
        string b="";
        for(int i=0;i<n;i++) cin>>s[i];
        for(int i=0;i<=60;i++)
            for(int j=0;j<60;j++)
            {
                ll flag=1;
                string p=s[0].substr(j,i);
                for(int k=1;k<n;k++)
                    if(s[k].find(p)==string::npos){
                        flag=0;
                        break;
                    }
                if(flag) {
                    if(p.size()>b.size()) b=p;
                    else if(p.size()==b.size()&&p<b) b=p;
                }
            }
        if(b.size()<3) cout<<"no significant commonalities"<<endl;
        else cout<<b<<endl;
    }
    return 0;
}
