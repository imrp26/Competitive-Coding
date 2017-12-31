#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,ans=0,ax,ay,bx,by,cx,cy,p1,p2,p3,p;
    cin>>n;
    while(n--)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        p1=bx*ay-ax*by;
        p2=cx*by-bx*cy;
        p3=ax*cy-cx*ay;
        if((p1>=0 && p2>=0 && p3>=0) || (p1<=0 && p2<=0 && p3<=0))
            ans++;
    }
    cout<<ans;
}
