/*    AUTHOR  :  AYUSH AVASTHI.........
      PROBLEM :  https://www.spoj.com/problems/AKBAR/    
      TAG     :  BFS
*/


#include <bits/stdc++.h>
using namespace std;
typedef long ll;
ll maxi=1;

 
int main() {
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       ll t;
       cin>>t;
       while(t--)
       {  
           ll n,r,m,u,vv,flag=1;
           cin>>n>>r>>m;
           vector<ll>move(n+5,0);
           vector<pair<ll,ll>>v;      //  scanning position and power of soldiers
           vector<ll>adj[n+5];        //adjecency list
 
           while(r--)
           {
               cin>>u>>vv;
               adj[u].push_back(vv);
               adj[vv].push_back(u);
           }
           while(m--)
           {
               cin>>u>>vv;
               v.push_back(make_pair(u,vv));
           }
           
           vector<bool>visited(n+5,false);
           ll dis[n+5]={0};
           for(ll j=0;j<v.size();j++)
           {   
               ll a=v[j].first;
               ll b=v[j].second;
                queue<ll> q;
                q.push(a);
                visited[a]=true;
                dis[a]=0;
                while(!q.empty())
                {   
                   ll gg=q.front();
                   q.pop();
                   if(dis[gg]>b)
                   break;
                   if(move[gg]==1)
                   {
                       flag=0;
                       break;
                   }
                   for(ll i=0;i<adj[gg].size();i++)
                   {
                       if(!visited[adj[gg][i]])
                       {   if(move[adj[gg][i]]==1)
                           {
                            flag=0;
                            break;
                            }
                           visited[adj[gg][i]]=true;
                           q.push(adj[gg][i]);
                           dis[adj[gg][i]]=dis[gg]+1;
                           
                       }
                   }
                   move[gg]=1;
                   
               }
               
               if(flag==0)
               break;
               
           }
          for(ll i=1;i<=n;i++)
           if(move[i]==0)
           flag=0;
           if(flag==0)
           cout<<"No"<<endl;
           else 
           cout<<"Yes"<<endl;
         
       }
 
      return 0;
} 
