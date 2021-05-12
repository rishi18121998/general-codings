#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
template<typename t,typename w>
class pairs{
    t x;
    w y;
    public:
    void setx(t a)
    {
        this->x = a;
    }
    void sety(w b)
    {
        this->y= b;
    }
    t getx()
    {
        return this->x;
    }
    w gety()
    {
        return this->y;
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
    // pairs<int,double> p;
    // p.setx(10);
    // p.sety(20);
    // cout<<p.getx()<<" "<<p.gety()<<"\n";
    // pairs<double,double> a;
    // a.setx(20.223);
    // a.sety(221.009);
    // cout<<a.getx()<<" "<<a.gety();
    pairs<pairs<int,char>,double> s;
    s.sety(101.28);
    pairs<int,char> k;
    k.setx(10);
    k.sety('A');
    s.setx(k);
    cout<<s.getx().getx()<<" "<<s.getx().gety()<<" "<<s.gety();
    return 0;
}

