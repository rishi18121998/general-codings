#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int maxsofar=INT32_MIN,maxtillhere=0;//int min is important for negative valued array
    int start=0,end=0,s=0;
    for(int i=0;i<n;i++)
    {
        maxtillhere+=v[i];
        if(maxtillhere>maxsofar)
        {
            maxsofar=maxtillhere;
            start=s;//gives start index of subarray
            end=i;//gives end index 
        }
        if(maxtillhere<0)
        {
            maxtillhere=0;
            s=i+1;//changes start when all become negative
        }
    }
    cout<<maxsofar<<endl;
    while(start<=end)
    {
        cout<<v[start]<<" ";
        start++;
    }
    return 0;
}