#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f(i,a,n) for(ll i=a;i<n;i++)
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,f;
        cin>>n;
        vector<ll>v(n-1);
        f(i,0,n-1)
        {
            cin>>v[i];
        }
        cin>>f;
        ll attack=1e18+7,ele1,ele2,pos;
        f(i,0,n-1)
        {
            if((v[i]-f)>0) 
            {
                continue;
            }
            ll d=f;
            ll a1=0,j=1;
            ll e11=(i-a1+j-1)/j,e22=(n-i+j-2)/j;
            while(e11+e22>1)
            {
                if(e11&1)
                {
                    d+=v[a1+(e11-1)*j];
                }
                if(e22&1)
                {
                    if(e11==0)
                    {
                        d+=v[i+(e22-1)*j];
                    }
                    else
                    {
                        a1+=j*2;
                    }
                }
                j*=2;
                e11=(i-a1+j-1)/j;
                e22=(n-i+j-2)/j;
            }
            if(d<attack)
            {
                attack=d;
                pos=i;
            }
        }
        if(attack==1e18+7)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<"possible"<<endl;
            cout<<pos+1<<" "<<attack<<endl;
        }
    }
    return 0;
}
