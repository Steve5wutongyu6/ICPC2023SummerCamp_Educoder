#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define maxn 1005
#define INF 10000005
using namespace std;
struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f) :from(u),to(v),cap(c),flow(f) {}
};
vector<Edge> edges;
vector<int> G[maxn];
int a[maxn];
int p[maxn];
int n,m,pig[maxn];
int flag[maxn];//注意这个flag，它记录打开猪舍的最新的顾客以及该猪舍是否被打开过；
 void AddEdge(int from,int to,int cap) {
     edges.push_back(Edge(from,to,cap,0));
     edges.push_back(Edge(to,from,0,0));
     int num=edges.size();
     G[from].push_back(num-2);
     G[to].push_back(num-1);
 }
  
 int Maxflow(int s,int t) {
     int flow=0;
     for(;;) {
         memset(a,0,sizeof(a));
         queue<int > Q;
         Q.push(s);
         a[s]=INF;
         while(!Q.empty()) {
             int x=Q.front(); Q.pop();
             for(unsigned int i=0;i<G[x].size();i++) {
                 Edge& e=edges[G[x][i]];
             if(!a[e.to] && e.cap>e.flow){
                 p[e.to]=G[x][i];
                 a[e.to]=min(a[x],e.cap-e.flow);
                 Q.push(e.to);
             }
         }
         if(a[t]) break;
         }
      if(!a[t]) break;
          for(int u=t;u!=s;u=edges[p[u]].from) {
              edges[p[u]].flow+=a[t];
              edges[p[u]^1].flow-=a[t];
          }
          flow+=a[t];
      }
      return flow;
  }
   //模板
int main()
  {std::ios::sync_with_stdio(false);
      cin>>m>>n;
      for(int i=1;i<=m;i++)
          cin>>pig[i];
      int k,exp;
      for(int i=1;i<=n;i++)
      {cin>>k;
          for(int j=1;j<=k;j++){
              cin>>exp;
              if(!flag[exp]) AddEdge(0,i,pig[exp]);
                  else AddEdge(flag[exp],i,INF);
                      flag[exp]=i;}
                      cin>>exp;
                      AddEdge(i,n+1,exp);
                  }
                  cout<<Maxflow(0,n+1)<<endl;
                  return 0;
              }