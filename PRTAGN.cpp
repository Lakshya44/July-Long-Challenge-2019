#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f(i,a,n) for(ll i=a;i<n;i++)
ll count(ll n)
{
    if(n==0)
    {
        return 0;
    }
    return 1 + count(n&(n-1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll x;
        vector<ll>v;
        map<ll,ll>m;
        ll even=0,odd=0;
        while(n--)
        {
            cin>>x;
            if((ll)v.size()==0)
            {
                m[x]++;
                v.pb(x);
                if(count(x)&1)
                {
                    odd++;
                }
                else
                {
                    even++;
                }
                cout<<even<<" "<<odd<<endl;
                continue;
            }
            if(m[x])
            {
                cout<<even<<" "<<odd<<endl;
                continue;
            }
            ll size=(ll)v.size();
            f(i,0,size)
            {
                if(v[i]!=x)
                {
                    if(m[v[i]^x]==0)
                    {
                        v.pb(v[i]^x);
                        m[v[i]^x]++;
                        if(count(v[i]^x)&1) odd++;
                        else even++;
                    }
                }
            }
            if(m[x]==0)
            {
                m[x]++;
                v.pb(x);
                if(count(x)&1) odd++;
                else even++;
            }
            cout<<even<<" "<<odd<<endl;
        }
    }
    return 0;
}
