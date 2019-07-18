#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mod 1000000007
const ll big=1000000000000000;
#define f(i,a,n) for(ll i=a;i<n;i++)
void reverseArray(ll arr[], ll start, 
                            ll end) 
{ 
    while (start < end) 
    { 
        std::swap(arr[start], arr[end]); 
        start++; 
        end--; 
    } 
} 
  
void rightRotate(ll arr[], ll d, ll n) 
{ 
    reverseArray(arr, 0, n-1); 
    reverseArray(arr, 0, d-1); 
    reverseArray(arr, d, n-1); 
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
        ll sum[n+1],dp[n][n],v[n];
        f(i,0,n)
        {
            cin>>v[i];
        }
        ll max=v[0];
        ll index=0;
        f(i,1,n)
        {
            if(max<v[i])
            {
                max=v[i];
                index=i;
            }
        }
        rightRotate(v,n-1-index,n);
        sum[0]=0;
        f(i,1,n+1)
        {
            sum[i]=sum[i-1]+v[i-1];
        }
        f(i,0,n)
        {
            f(j,0,n)
            {
                if(i!=j)
                {
                    dp[i][j]=big;
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        f(st,1,n)
        {
            ll i=0,j=st;
            for(;j<n;j++,i++)
            {
                f(k,i,j)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[(k+1)%n][j]+sum[j+1]-sum[i]);
                }
            }
        }
        ll final_ans = dp[0][n-1];
        f(i,1,n)
        {
            final_ans = min(final_ans,dp[i][i-1]);
        }
        cout<<final_ans<<endl;
    }
    return 0;
}
