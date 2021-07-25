#include<iostream>
#include<bits/stdc++.h>
typedef 	long long int 	ll;
#define 	mod 	1000000007
#define	rep(i,a,n)	for(int i=a;i<n;i++)
#define	all(v)	v.begin(),v.end()
#define	yes	std::cout<<"YES"
#define	no	std::cout<<"NO"
using	namespace	std;
void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
void bubble_sort(vector<int> &v)
{
    int n = v.size();
    for(int i=0;i<n-1;i++) 
    {
        int flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
                flag=1;
            }
        }
        if(!flag)
            break;
    }
}

void insertion_sort(vector<int> &v)
{
    int n = v.size();
    for(int i=1;i<n;i++)
    {
        int j = i-1;
        int x = v[i];
        while(j>=0 && v[j]>x)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}

void selection_sort(vector<int> &v)
{
    int n = v.size();
    for(int i=0;i<n;i++)
    {
        int ind = i;
        for(int j=i;j<n;j++)
        {
            if(v[ind]>v[j])
            {
                ind = j;
            }
        }
        swap(v[i],v[ind]);
    }
}
/// quick sort
int partition(vector<int> &v,int l,int h)
{
    int pivot = v[l];
    int i = l,j = h;
    do
    {
        do{i++;}while(v[i]<=pivot);
        do{j--;}while(v[j]>pivot);

        if(i<j)
        {
            swap(v[i],v[j]);
        }

    } while (i<j);
    swap(v[l],v[j]);
    return j;
        
}
void quick_sort(vector<int> &v,int l,int h)
{   
    int j;
    if(l<h)
    {
        j = partition(v,l,h);
        quick_sort(v,l,j);
        quick_sort(v,j+1,h);
    }

}

// merge sort
void merge(vector<int> &v,int l,int mid,int h)
{
    int i = l,j = mid+1,k = l;
    vector<int> temp(100);

    while(i<=mid && j<=h)
    {
        if(v[i]<v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }
    for(;i<=mid;i++)
    {
        temp[k++] = v[i];
    }
    for(;j<=h;j++)
    {
        temp[k++] = v[j];
    }

    for(int i=l;i<=h;i++)
    {
        v[i] = temp[i];
    }
}

void imergesort(vector<int> &v)
{
    int n = v.size();
    int p,l,h,mid,i;
    for(p = 2;p<=n;p*=2)
    {
        for(i=0;i+p-1<=n;i+=p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(v,l,mid,h);
        }
    }
    if(p/2 < n)
    {
        merge(v,0,p/2 - 1,n);
    }
}

void rec_merge_sort(vector<int> &v,int l,int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        rec_merge_sort(v,l,mid);
        rec_merge_sort(v,mid+1,h);
        merge(v,l,mid,h);
    }
}
int main()
{
    run();
    vector<int> v = {7,6,5,4,3,2,1,9,8};
    //imergesort(v);
    rec_merge_sort(v,0,9);
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    return 0;
}