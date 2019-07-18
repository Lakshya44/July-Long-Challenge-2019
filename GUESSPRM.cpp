#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f(i,a,n) for(ll i=a;i<n;i++)
ll maxPrimeFactors(ll n) 
{ 
    ll maxPrime = -1; 
  
    while (n % 2 == 0) { 
        maxPrime = 2; 
        n >>= 1; 
    } 
  
    for (ll i = 3; i <= sqrt(n); i += 2) { 
        while (n % i == 0) { 
            maxPrime = i; 
            n = n / i; 
        } 
    } 
  
    if (n > 2) 
        maxPrime = n; 
  
    return maxPrime; 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        ll prime=31622;
        cout<<"1"<<" "<<prime<<endl;
        ll y;
        cin>>y;
        ll n11=abs((prime*prime)-y);
        ll prime1=2*sqrt(prime)+prime;
        cout<<"1 "<<prime1<<endl;
        ll y1;
        cin>>y1;
        ll n22=abs((prime1*prime1)-y1);
        ll gcd=__gcd(n11,n22);
        cout<<"2 "<<maxPrimeFactors(gcd)<<endl;
        string s;
        cin>>s;
        if(s=="No") exit(0);
    }
    return 0;
}
