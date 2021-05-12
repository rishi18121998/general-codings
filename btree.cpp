#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    node(int x)
    {
        data=x;
        left=right=NULL;
    }
};
class btree
{
    public:
     node *root;
     vector<int> v;
     int res=0;
     void preorder(node *);
     void levelorder(node *);
     int height(node *);
     void diameter(node *);
     void rootToleaf(node *);
};
void btree::preorder(node *head)
{
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}
void btree::levelorder(node *head)
{
    queue<node *> q;
    if(head==NULL)
        return;
    q.push(head);
    while(!q.empty())
    {
        int count=q.size();
        int sum=0;
        for(int i=1;i<=count;i++)
        {
            auto it=q.front();
            q.pop();
            //to print left-view and right-view we will just use value of i to print
            //at i=1 every time their is l-view element so we will print it
            if(i==1)
                cout<<it->data<<" ";
                //i==count for right view
            if(i==count)
                cout<<it->data<<" ";
            //cout<<it->data<<" ";
            //sum+=(it->data);
            if(it->left)
                q.push(it->left);
            if(it->right)
                q.push(it->right);
        }
        cout<<endl;
        //cout<<"-->"<<sum<<endl;
    }
}
int btree::height(node *head)
{
    if(head==NULL)
        return 0; 
    int lh=height(head->left);
    int rh=height(head->right);
    return max(lh,rh)+1;
}
void btree::diameter(node *head)
{
    if(head==NULL)
        return;
    int lh=height(head->left);
    int rh=height(head->right);
    res=max(res,(lh+rh));
}
void btree::rootToleaf(node *head)
{
    if(head==NULL)
        return;
    v.push_back(head->data);
    if(head->left==NULL && head->right==NULL)
    {
        int sum=0;
        for(auto x:v)
        {
            cout<<x<<" ";
            sum+=x;
        }
        cout<<"-->"<<sum<<endl;
    }
    rootToleaf(head->left);
    rootToleaf(head->right);
    auto it=v.end();
        it--;
        v.erase(it);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    btree t;
    t.root=new node(10);
    t.root->left = new node(20);
    t.root->right = new node(30);
    t.root->left->left =new node(40);
    t.root->left->right = new node(50);
    t.root->right->left = new node(65);
    t.root->right->right = new node(70);
    t.preorder(t.root);
    cout<<endl;
    t.levelorder(t.root);
    cout<<endl;
    cout<<t.height(t.root)<<endl;
    t.diameter(t.root);
    cout<<t.res;
    cout<<endl;
    t.rootToleaf(t.root);
    return 0;
}