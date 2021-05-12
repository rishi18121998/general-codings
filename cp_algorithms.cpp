#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
//pow of any number in O(logn) iterative
int pow(int a,int n,int &res)
{
    while(n)
    {
        if(n&1)
            res=res*a;
        a=a*a;
        n>>=1;
    }
    return res;
}
//recursive version of finding power O(logn)
int powl(int a,int n)
{
    if(n==0)
        return 1;
    int res=powl(a,n/2);
    if(n%2)
        return res*res*a;
    else
        return res,res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int res=1;
    pow(9,3,res);
    cout<<res<<endl;
    cout<<powl(5,3);
}