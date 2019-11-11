/*  AUTHOR AYUSH AVASTHI 
TREE'S DFS
question : https://www.codechef.com/BCF12019/problems/CHFLOL2
my accepted solution
https://www.codechef.com/viewsolution/27870366
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void dfs(vector<vector<ll>>&adj, ll start, ll arr[],ll brr[])
{   for(auto i : adj[start])
    {
        dfs(adj,i,arr);
        brr[start]+=arr[i];
       
    }
    
  return ;
}
int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,k,x,u,vt,sum=0;
	    cin>>n>>k>>x;
	    ll vv=n;
	    ll arr[n+8],brr[n+8];
	    for(ll i=1;i<=n;i++)
        { cin>>arr[i];
        brr[i]=arr[i];
        }
        vector<vector<ll>>adj(100009);
        for(ll i=1;i<n;i++)
        {
            cin>>u>>vt;
            adj[u].push_back(vt);
        }
        dfs(adj,1,arr);
        sort(arr+1,arr+n+1);
        for(ll i=1;i<=n&&k>0;i++)
        {
            sum+=arr[i];
            k--;
        }
        if(sum>=x) cout<<0<<endl;
        else cout<<x-sum<<endl;
	}
	return 0;
}
