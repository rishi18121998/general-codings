#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<int>> adj;
vector<int> vis;
int cont=0;
void dfs(int src)
{
	for(auto x:adj[src])
	{
		if(!vis[x])
		{
			cout<<x<<" ";
			vis[x]=1;
			dfs(x);
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
	ll n,e;
	cin>>n>>e;
	adj.resize(n+1);
	vis.resize(n+1,0);
	for(int i=1;i<=e;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			cout<<i<<" "; 
			cont++;
			dfs(i);
			cout<<endl;
		}
	}
	cout<<cont;
	return 0;
}











//this is a code for to reach end from the start in minimum path in minimum time by bfs

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// ll row , col;
// vector<vector<pair<int,int>>> par;
// vector<vector<int>> v;
// int dcol[]={-1,0,1,0};
// int drow[]={0,-1,0,1};
// void bfs(int a, int b , int c)
// {
// 	queue<pair<pair<int,int>,int>> q;
// 	q.push({{a,b},c});
// 	while(!q.empty())
// 	{
// 		pair<pair<int,int>,int> u = q.front();
// 		int curr=u.second;
// 		int r=u.first.first;
// 		int c=u.first.second;
// 		q.pop();
// 		if(v[r][c]==1)
// 		{
// 			cout<<curr<<"\n";
// 		}
// 		for(int i=0;i<4;i++)
// 		{
// 			int rr = r + drow[i];
// 			int cc = c + dcol[i];
// 			if(rr<0 || cc<0 || rr>=row || cc>=col)
// 				continue;
// 			if(v[rr][cc]==0)
// 			{
// 				v[rr][cc]=-1;
// 				par[rr][cc]={r,c};
// 				q.push({{rr,cc},curr+1});
// 			}
// 			else if(v[rr][cc]==1)
// 			{
// 				par[rr][cc]={r,c};
// 				q.push({{rr,cc},curr+1});
// 			}
			
// 		}
// 	}
// }
// int main()
// {
// 	ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// 	cin>>row>>col;
// 	v.resize(row);
// 	par.resize(row);
// 	for(int i=0;i<row;i++)
// 	{
// 		v[i].resize(col);
// 		par[i].resize(col);
// 		for(int j=0;j<col;j++)
// 			cin>>v[i][j];
// 	}
// 	int currlevel=0;
// 	bfs(0,0,currlevel);
// 	return 0;
// }