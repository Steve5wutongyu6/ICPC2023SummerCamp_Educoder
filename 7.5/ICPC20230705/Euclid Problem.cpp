 #include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int exct_gcd(int a,int b,int& x,int& y)
{
	if(!b)
	{
		x=1;
		y=0;
	    return a;
    }
	 int d=exct_gcd(b,a%b,y,x);
	 y-=a/b*x;
	 return d;
}
int main(){
	int a,b;
	while(cin>>a>>b)
	{
		int x=0,y=0;
		int d=exct_gcd(a,b,x,y);
		cout<<x<<" "<<y<<" "<<d<<endl;
	}
} 
