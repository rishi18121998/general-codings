#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int  q;
    cin>>q;
    while(q--)
    {
        long long int n,k;
        cin>>n>>k;
        int v[n];
        long long int min=1000000,max=0;
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
            if(min>v[i])
            {
                min=v[i];
            }
            if(max<v[i])
            {
                max=v[i];
            }
        }
        if(min+k<max-k)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            min+=k;
            cout<<min<<endl;
        }                 
    }
    return 0;
}