# include <cstring>
# include <iostream>
# include <vector>
using namespace std;
# define maxn 102

int hn[10][10];
int ln[10][10];
int gn[10][10];
int map[10][10];

struct pos
{
    int r,c;
    pos(int rr,int cc):r(rr),c(cc){}
};

vector<pos> b;

inline int gb(int r,int c)
{
    int rr=r/3,cc=c/3;
    return rr*3+cc;
}

int saf(int i ,int j ,int num ,int f)
{
    hn[i][num]=f;
    ln[j][num]=f;
    gn[gb(i,j)][num]=f;
}

bool isk(int i,int j,int num)
{
    return !gn[gb(i,j)][num]&&!hn[i][num]&&!ln[j][num];
}

int dfs (int n)
{
    if(n<0) return 1;
    int r=b[n].r,c=b[n].c;
    for (int  i = 1; i <=9 ; ++i)
    {
        if(isk(r,c,i))
        {
            map[r][c]=i;
            saf(r,c,i,1);
            if(dfs(n-1)) return 1;
            saf(r,c,i,0);
        }
    }
    return 0;
}