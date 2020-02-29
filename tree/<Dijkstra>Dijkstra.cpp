// problem : https://codeforces.com/contest/20/problem/C

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define M 1000000007
typedef long long ll;
vector<ll> path(100009,-1);
ll INF = LLONG_MAX;
ll dij(vector<vector<pair<ll,ll>>> v,ll n,ll source)
{
  vector<long long> distance(v.size(),INF);

    distance[source]=0;
    set<pair<ll,ll>> s;
    s.insert({0,source});

    while(!s.empty())
    {
          for(auto i : v[s.begin()->second])
          {
             ll k=s.begin()->second;
             ll mmm=s.begin()->first;
              
             if(distance[i.first]>mmm+i.second)
            {
                if(s.find({distance[i.first],i.first})!=s.end())
                s.erase({distance[i.first],i.first});
                distance[i.first]=mmm+i.second;
                s.insert({distance[i.first],i.first});
                path[i.first]=k;
            }
            
        }
        
        s.erase(s.begin());
        
    }   
    if(distance[n]==INF)
    return 0;
    
    return n;
}
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,a,b,c;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n+3);
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        
    }
        ll k= dij(adj,n,1);
        if(k!=n)
        cout<<"-1"<<endl;
        else
        {   ll i=n;
            path[1]=0;
            vector<ll>vvv;
            vvv.push_back(n);
            while(path[i]!=0)
            { 
            vvv.push_back(path[i]);
            i=path[i];
            }
         
          for(ll i=vvv.size()-1;i>=0;i--)
          cout<<vvv[i]<<" ";
           
        //   for(ll i=1;i<=10;i++)
        //   cout<<path[i]<<" ";
        }
    return 0;
}
