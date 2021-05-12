#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
template<typename t>
class stacks{
    t* data;
    int nextind;
    int capacity;
    public:
    stacks(int totalsize=0)
    {
        //data = new int[totalsize];
        data = new t[4];
        nextind = 0;
        //capacity = totalsize;
        capacity = 4;

    }
    void push(t a)
    {
        if(capacity==nextind)
        {
            t* ndata = new t[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                ndata[i]=data[i];
            }
            cout<<"capaciydouble\n";
            delete [] data;
            capacity*=2;
            data = ndata;
        }
        // if(capacity<=nextind)
        // {
        //     cout<<"overflow";
        //      return;
        // }
        // else 
        data[nextind]=a;
        nextind++;
    }
    void pop()
    {
        if(nextind<0)
        {
            cout<<"underflow";
        }
        else 
        {
            nextind--;
        }
    }
    t top()
    {
        if(nextind==-1)
        {
            return 0;
        }
        if(capacity==nextind)
            nextind--;
        return data[nextind-1];
    }
};
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    stacks<char> s;
    for(char i=97;i<110;i++)
    {
        cout<<i<<"\n";
        s.push(i);
    }
    for(int i=0;i<=16;i++)
    {
        cout<<s.top()<<"\n";
        s.pop();
    }
    return 0;
}

