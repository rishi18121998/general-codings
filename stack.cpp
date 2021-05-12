#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
class stacks
{
    public:
    int end=0;
    int v[10];
    void push(int);
    void pop();
    void top();
    void isempty();
};
void stacks :: push(int a)
{
    if(end==10)
    {
        cout<<"stack overflow  "<<endl;
        end--;
        return;
    }
    v[end]=a;
    end++;
}
void stacks :: pop()
{
    end--;
    if(end<0)
    {
        cout<<"stack is empty"<<endl;
        return;
    }
    cout<<v[end]<<" is poped"<<endl;
}
void stacks :: top()
{
    cout<<v[end]<<endl;
}
void stacks :: isempty()
{
    if(end==0)
    {
        cout<<"is empty"<<endl;

    }
    else
    {
        cout<<"not empty"<<endl;
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
    stacks t;
    t.push(12);
    t.push(13);
    t.push(14);
    t.push(15);
    t.push(16);
    t.push(17);
    t.push(18);
    t.push(19);
    t.push(20);
    t.push(22);
    t.pop();
    t.top();
    
    t.pop();
    t.top();
    t.isempty();
    return 0;
}






































// #include<iostream>
// #include<bits/stdc++.h>
// typedef long long int ll;
// using namespace std;
// // struct val{
// //     int start;
// //     int end;
// //     int maxsofar;
// // };
// // val kadanealgo(vector<int> &v)
// // {
// //     int maxsofar=INT32_MIN,maxtillhere=0;
// //     int start=0,end=0,s=0;
// //     int n=v.size();
// //     for(int i=0;i<n;i++)
// //     {
// //         maxtillhere+=v[i];
// //         if(maxtillhere>maxsofar)
// //         {
// //             maxsofar=maxtillhere;
// //             start=s;
// //             end=i;
// //         }
// //         if(maxtillhere<0)
// //         {
// //             maxtillhere=0;
// //             s=i+1;
// //         }
// //     }
// //     val k;
// //     k.start=start;
// //     k.end=end;
// //     k.maxsofar=maxsofar;
// //     return k;
// // }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(auto &x:v)
//         cin>>x;
//     vector<ll> presum(n);
//     presum[0]=v[0];
//     for(int i=1;i<n;i++)
//     {
//         presum[i]=presum[i-1]+v[i];
//         presum[i]=presum[i]%7;
//     }
//     // for(int i=0;i<n;i++)
//     // {
//     //     cout<<presum[i]<<" ";
//     // }
//     // cout<<endl;
//     unordered_map<ll,int> mp;
//     ll length=0;
//     for(ll i=0;i<n;i++)
//     {
//         //cout<<presum[i]<<" ";
//         if(presum[i]%7==0)
//         {
//             length=max(length,i+1);
//         }
//         auto it=mp.find(presum[i]);
//         if(it!=mp.end())
//         {
//            // cout<<i<<" x "<<length<<"\n";
//             length=max(length,(i-it->second));
//             //cout<<"x+ "<<length;
//         }
//         if(it==mp.end())
//             mp[presum[i]]=i;
//         //cout<<endl;
//     }
//     cout<<length<<endl;
//     return 0;
// }