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
struct node{
    int val;
    node* left;
    node* right;
    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
int idx,idx1;
node* build_tree(int postorder[] , int inorder[] ,int start,int end)
{
    if(start>end)
        return NULL;
    int val = postorder[idx];
    idx--;
    int pos;
    for(int i=start;i<=end;i++)
    {
        if(inorder[i] == val)
        {
            pos = i;
            break;
        }
    }

    node* curr = new node(val);

    if(start == end)
    {
        return curr;
    }
    curr->right = build_tree(postorder,inorder,pos+1,end);
    curr->left = build_tree(postorder,inorder,start,pos-1);

    return curr;
}
void inorderprint(node* p)
{
    if(p!=NULL)
    {
        inorderprint(p->left);
        cout<<p->val<<" ";
        inorderprint(p->right);
    }
}

node* build_tree2(int preorder[] , int inorder[] ,int start,int end)
{
    if(start>end)
        return NULL;
    int val = preorder[idx1];
    idx1++;
    int pos;
    for(int i=start;i<=end;i++)
    {
        if(inorder[i] == val)
        {
            pos = i;
            break;
        }
    }

    node* curr = new node(val);

    if(start == end)
    {
        return curr;
    }
    
    curr->left = build_tree2(preorder,inorder,start,pos-1);
    curr->right = build_tree2(preorder,inorder,pos+1,end);
    

    return curr;
}
int main()
{
    //run();
    int postorder[] = {4,2,5,3,1};
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    //idx = sizeof(postorder)/sizeof(postorder[0]);
    idx = 4;
    idx1=0;
    //node* root = build_tree(postorder,inorder,0,4);
    node* root = build_tree2(preorder,inorder,0,4);
    inorderprint(root);
    return 0;
}