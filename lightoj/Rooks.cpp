using namespace std;
#define ull unsigned long long
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull i,j,t,n,k,ans;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>n>>k;
        if(k==1)
            ans=n*n;
        else if(k>n)
            ans=0;
        else
        {
            ans=1;
            for(i=1;i<=k;i++)
            {
                ans*=(n*n);
                ans/=i;
                n--;
            }
        }
        cout<<"Case "<<j<<": "<<ans<<endl;
    }
}
