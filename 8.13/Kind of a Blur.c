#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAXSIZE 12 // 定义最大的图像大小
#define MAXN 105 // 定义最大的线性方程组的大小
#define EPS 1e-6 // 定义一个极小值，用于判断浮点数是否为0

int W,H,D,Rank; // 图像的宽度、高度、模糊距离和线性方程组的秩
double Img[MAXSIZE][MAXSIZE]; // 存储输入的图像
double A[MAXN][MAXN]; // 存储构造的线性方程组

// 交换两个浮点数的值
void swap(double *a,double *b)
{
    double temp=*a;
    *a=*b;
    *b=temp;
}

// 高斯消元算法
void Gauss()
{
    int r,c,n=W*H,m=W*H+1; // n为未知数的个数，m为方程的个数
    int mxr; // 记录主元所在的行
    for(r=1,c=1;r<=n&&c<m;r++,c++) // 遍历每一列
    {
        mxr=r;
        for(int i=r+1;i<=n;i++) // 选取主元
            if(fabs(A[i][c])-fabs(A[mxr][c])>EPS)
                mxr=i;
        if(fabs(A[mxr][c])<EPS) // 如果主元为0，则跳过
        {r--;continue;}
        if(mxr!=r) // 如果主元不在第r行，则交换两行
            for(int i=c;i<=m;i++)
                swap(&A[mxr][i],&A[r][i]);
        for(int i=1;i<=n;i++) // 消元
            if(i!=r&&fabs(A[i][c])>0)
                for(int j=m;j>=c;j--)
                    A[i][j]-=A[r][j]*A[i][c]/A[r][c];
    }
    Rank=r-1; // 计算秩
}

// 将二维坐标转换为一维坐标
inline int Code(int x,int y)
{return (x-1)*W+y;}

int main()
{
    int test=0;
    while(1)
    {
        memset(A,0,sizeof A); // 初始化线性方程组
        memset(Img,0,sizeof Img); // 初始化图像
        W=H=D=Rank=0; // 初始化图像的宽度、高度、模糊距离和线性方程组的秩
        scanf("%d%d%d",&W,&H,&D); // 读入图像的宽度、高度和模糊距离
        if(!W&&!H&&!D)break; // 如果输入为0，则退出循环
        if(test++)printf("\n"); // 输出换行符
        for(int i=1;i<=H;i++)
            for(int j=1;j<=W;j++)
                scanf("%lf",&Img[i][j]); // 读入图像的像素值
        for(int i=1;i<=H;i++)
            for(int j=1;j<=W;j++)
            {
                int cnt=0,id=Code(i,j); // cnt记录像素点周围的像素点个数，id为当前像素点的编号
                for(int p=i-D;p<=i+D;p++) // 构造线性方程组
                {
                    if(p<=0||p>H)continue;
                    int d=(D-abs(i-p));
                    for(int q=j-d;q<=j+d;q++)
                    {
                        if(q<=0||q>W)continue;
                        cnt++;
                        A[id][Code(p,q)]=1;
                    }
                }
                A[id][H*W+1]=cnt*Img[i][j]; // 将像素点的值乘以周围像素点的个数作为方程的常数项
            }
        Gauss(); // 解线性方程组
        for(int i=1;i<=H;i++)
        {
            for(int j=1;j<=W;j++)
                printf("%8.2f",A[Code(i,j)][H*W+1]/A[Code(i,j)][Code(i,j)]); // 输出去模糊后的像素值
            printf("\n");
        }
    }
    return 0;
}