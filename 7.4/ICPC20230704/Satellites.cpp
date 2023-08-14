# include <iostream>
# include <cmath>
using namespace std;
const double r = 6440;
int main ()
{
    double ss=0,as=0;
    char s[10];
    while (cin>>ss>>as>>s)
    {
        if (s[0]=='m')
        {
            as=as/60;
        }
        double angle = M_PI*as/180;
        double arc = angle*(ss+r);
        double dis = 2*(ss+r)*sin(angle/2);
        if(as>180)
        {
            arc=2*M_PI*(ss+r)-arc;
        }
        printf("%.6lf %.6lf\n",arc,dis);        
    }
    return 0;
}