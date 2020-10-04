#include<bits/stdc++.h>
using namespace std;

int bfs(vector<int> v[],bool vis[],int clr[])
{
    int c=0;
    int start=1;
    vis[start]=true;
    queue<int> q;
    q.push(start);
    clr[start]=0;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<v[p].size();i++)
        {
            if(vis[v[p][i]] && clr[p]==clr[v[p][i]])
            {
                return 0;
            }
            if(!vis[v[p][i]])
            {
                q.push(v[p][i]);
                vis[v[p][i]]=true;
                clr[v[p][i]]=clr[p]^1;
            }
        }
    }
    return 1;
}


int main()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    int clr[n+9];
    bool vis[n+9]={false};
    vector<int> v[n+9];
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<bfs(v,vis,clr);
    return 0;
}
