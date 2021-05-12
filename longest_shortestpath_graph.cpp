#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<pair<int,int>>> adj;
vector<int> vis;
vector<int> dis;
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
    dis.resize(vert+1,INT32_MAX);// to find maxpath here store int max;
    vis.resize(vert+1,0);
    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    queue<int> q;
    q.push(1);
    vis[1]=1;
    dis[1]=0;
    int k=0;
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        for(auto x:adj[u])
        {
            k++;
            dis[x.first]=min(dis[x.first],(dis[u]+x.second)); //for max path here we will find the max from both ;
            if(!vis[x.first])
            {
                vis[x.first]=1;
                q.push(x.first);
            }
        }
    }
    for(int i=1;i<=vert;i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<k;//to calculate numner of computtaions
    return 0;
}




// 8 13
// 1 2 3
// 1 3 6
// 2 3 4
// 2 4 4
// 3 4 8
// 2 5 11
// 4 5 -4
// 4 6 5
// 4 7 2
// 3 7 11
// 5 8 9
// 6 8 1
// 7 8 2

//codeforces source code

// #include <iostream>
// #include <map>
// #include <string>
// using namespace std;
 
// int main()
// {
// 	int n, ans=1;
// 	string a, b, c;
// 	map<string, int>l;
// 	l["polycarp"] = 1;
// 	cin >> n;
// 	while (n--){
// 		cin >> a >> b >> c;
// 		for (int i = 0; i < a.size(); i++)
// 			a[i] = tolower(a[i]);
// 		for (int i = 0; i < c.size(); i++)
// 			c[i] = tolower(c[i]);
// 		int e = l[c] + 1;
// 		if (e > ans)
// 			ans = e;
// 		l[a] = e;
// 	}
// 	cout << ans;
// 	return 0;
// }