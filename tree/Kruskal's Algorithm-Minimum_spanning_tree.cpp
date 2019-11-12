/* 
AUTHOR : AYUSH AVASTHI......
KRUSKAL's ALGO TO FIND MINIMUM COST OF MINIMUM SPANNING TREE 
(basic use of DSU)
*/


#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e4 + 5;
int id[MAX],size[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(long long  i = 0;i < MAX;++i)
        {id[i] = i;
        size[i]=1;}
}

long long parent(long long  v)
{
    if (v == id[v])
        return v;
    return id[v] = parent(id[v]);
}

void union1(long long  x, long long  y)
{
    long long  p = parent(x);
    long long  q = parent(y);
     if (size[p] < size[q])
     swap(p, q);
     id[q] = p;
     size[p] += size[q];
    
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    long long  x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(parent(x) != parent(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}
