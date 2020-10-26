#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lop ios; ll t; cin>>t; while(t--)
#define pb push_back
#define vi vector<ll>
#define vivi vector<vector<ll>> 
#define vipa vector<pair<ll,ll>>
#define F first
#define S second
#define M 1000000007
#define kl "\n"
#define _p(v) for(auto i:v)cout<<i<<" ";
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
typedef long long ll;
ll lcm(ll x, ll y){ll k=x*y; k/=(__gcd(x,y)); return k;}
ll power(ll x,ll y){ ll r= 1;x = x % M;if(x==0) return 0; while(y>0) {if(y&1) r=(r*x)%M; y=y>>1; x=(x*x)%M;} return r;}  
ll prime[100005];
ll x;
ll maxCount;
ll dfsUtil(ll node, ll count, bool visited[], vivi& adj) 
{ 
    visited[node] = true; 
    count++; 
    for (auto i:adj[node]) { 
        if (!visited[i]) { 
            if (count >= maxCount) { 
                maxCount = count; 
                x = i; 
            } 
            dfsUtil(i, count, visited, adj); 
        } 
    } 
} 

ll dfs(ll node,ll n, vivi& adj) 
{ 
    bool visited[n + 1]; 
    ll count = 0; 
    for (int i = 1; i <= n; ++i) 
        visited[i] = false;  
    dfsUtil(node, count + 1, visited, adj); 
} 

void solve()
{
   ll n;
   cin>>n;
   x=0;
   vivi adj(n+3);
   for(ll i=1;i<=n-1;i++){
       ll x,y;
       cin>>x>>y;
       adj[x].pb(y);
       adj[y].pb(x);
   }
   maxCount=1e-9;
   dfs(1,n,adj);
   dfs(x,n,adj);
   cout<<(maxCount/2)<<kl;
}
int main() 
{ 
  
    // ll t;
    // cin>>t;
    // for(ll i=1;i<=t;i++){
    //     cout<<"Case #"<<i<<": ";
    //     solve();
    // }
    lop
    solve();
	return 0; 
} 
