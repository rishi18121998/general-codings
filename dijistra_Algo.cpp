#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<pair<int,int>>> adj;
vector<int> dis;
set<pair<int,int>> s;
// dijistra algo using set 
//try to do by min heap or priority queue
void dijistra()
{
    while(!s.empty())
    {
        auto u=*s.begin();
        s.erase(s.begin());
        int discurr=u.first;
        int currcity=u.second;
        for(auto x:adj[currcity])
        {
            int newcity=x.first;
            int weight=x.second;
            if(dis[newcity]>(dis[currcity]+weight))
            {
                auto it=s.find({dis[newcity],newcity});
                if(it!=s.end())
                {
                    s.erase(it);
                }
                dis[newcity]=dis[currcity]+weight;
                s.insert({dis[newcity],newcity});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int vert,edge;
    cin>>vert>>edge;
    adj.resize(vert+1);
    dis.resize(vert+1,INT32_MAX);
    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int src=1;
    s.insert({0,src});
    dis[src]=0;
    dijistra();
    for(auto x:dis)
    {
        cout<<x<<" ";
    }
    return 0;
}