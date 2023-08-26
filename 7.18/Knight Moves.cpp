#include<queue>
//STL队列，更方便操作，不至于混淆指针
#include<cstdio>
#include<cstring>
using namespace std;
const int N=10;
char a[N],b[N];
int dx[N]={-1,-2,-2,-1,1,2,2,1};
int dy[N]={-2,-1,1,2,2,1,-1,-2};
struct horse{
    int x,y,t;//节点坐标、深度
}st,ed,tmp;
//st起始状态 ed结束状态 tmp临时转换状态
int dis[N][N],vis[N][N];
//dis节点的深度 vis节点的访问情况
inline int bfs()
{
    if(st.x==ed.x&&st.y==ed.y) return 0;
    queue<horse> q1;
    queue<horse> q2;
    vis[st.x][st.y]=1;
    vis[ed.x][ed.y]=2;
    //起始状态访问的节点记为1，结束状态的记为2
    //当某一状态的队列拓展节点时
    //若vis为0，则标记为自己队列的
    //若已被另一状态的队列标记，则意味着出现重合 
    q1.push(st);
    q2.push(ed);
    int fx,fy,xx,yy;
    while(true){
        if(q1.size()<q2.size()){
        //q.size() 该队列中节点的个数
            fx=q1.front().x;
            fy=q1.front().y;
            //当前q1的节点少，取q1的节点
            for(int i=0;i<8;i++){
                xx=fx+dx[i];yy=fy+dy[i];
                if(xx<1||xx>8||yy<1||yy>8) continue;
                if(vis[xx][yy]==0){
                    tmp.t=q1.front().t+1;
                    tmp.x=xx;tmp.y=yy;
                    q1.push(tmp);
                    vis[xx][yy]=1;
                    //没访问过，标记1表示q1
                    dis[xx][yy]=tmp.t;
                }
                else if(vis[xx][yy]==2)
                return dis[xx][yy]+q1.front().t+1;
                //q2曾访问过这，q1目前访问这，即重合
            }q1.pop();
        }
        else{
            fx=q2.front().x;
            fy=q2.front().y;
            //同样的，这里q2的节点少，取q2的队首
            for(int i=0;i<8;i++){
                xx=fx+dx[i];yy=fy+dy[i];
                if(xx<1||xx>8||yy<1||yy>8) continue;
                if(vis[xx][yy]==0){
                    tmp.t=q2.front().t+1;
                    tmp.x=xx;tmp.y=yy;
                    q2.push(tmp);
                    vis[xx][yy]=2;
                    dis[xx][yy]=tmp.t;
                }
                else if(vis[xx][yy]==1)
                return dis[xx][yy]+q2.front().t+1;
            }q2.pop();
        }
    }
}
int main(void)
{
    while(scanf("%s%s",a,b)!=EOF){
    	//"!=EOF"指输入不为空
        st.x=a[0]-'a'+1;st.y=a[1]-'0';
        ed.x=b[0]-'a'+1;ed.y=b[1]-'0';
        st.t=ed.t=0;
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        //多组数据需清空数组
        printf("To get from %c%c to %c%c takes %d knight moves.\n",a[0],a[1],b[0],b[1],bfs());
    }
    return 0;
}