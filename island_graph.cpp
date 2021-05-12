#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<int>> is;
int rows , cols;
int cont=0;
int drow[]={-1,0,1,0};
int dcol[]={0,1,0,-1};
void dfs(int row,int col)
{
    cont++;//count the area of single island
    for(int i=0;i<4;i++)
    {
        int rr=row+drow[i];
        int cc=col+dcol[i];
        if(rr<=0 || cc<=0)
            continue;
        if(rr>rows || cc>cols)
            continue;
        else if(is[rr][cc]==0)
            continue;
        else if(is[rr][cc]==1)
        {
            is[rr][cc]=0;
            dfs(rr,cc);
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
    cin>>rows>>cols;
    is.resize(rows+1,vector<int>(cols+1));
    for(int i=1;i<=rows;i++)
        for(int j=1;j<=cols;j++)
        {
            cin>>is[i][j];
        }
    int ans=INT_MIN;
    int island_num=0;
    for(int i=1;i<=rows;i++)
        for(int j=1;j<=cols;j++)
        {
            if(is[i][j]==1)
            {
                is[i][j]=0;
                island_num++;
                dfs(i,j);
                ans=max(ans,cont);
                cont=0;
            }
        }
    cout<<ans<<" "<<island_num;//here ans tells us the island of maximum area and island_num is 
    //the number of islands
    
    return 0;
}


// 5 6
// 1 0 0 0 1 1
// 1 1 0 0 1 0
// 0 1 1 1 1 1
// 1 1 0 1 0 1
// 0 1 0 0 0 1