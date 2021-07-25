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
    int height;
    node(int x)
    {
        val = x;
        left = NULL;
        height=1;
        right = NULL;
    }
};
int height(node *root)
{
    int x,y;

    if(root!=NULL)
    {
        x = height(root->left);
        y = height(root->right);
        return x>y?x+1:y+1;
    }

    return 0; //if null return
}
void levelorder_traversal(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* t = q.front();
        q.pop();
        cout<<t->val<<" ";
        if(t->left!=NULL)
            q.push(t->left);
        if(t->right!=NULL)
            q.push(t->right);
    }
}
node* recinsert(node* root,int key)
{
    node* prev;
    if(root == NULL)
    {
        node *newnode = new node(key);
        return newnode;
    }
    else if(key<root->val)
    {
        root->left = recinsert(root->left,key);
    }
    else
    {
        root->right = recinsert(root->right,key);
    }
    return root;
}
node* in_order_precedence(node* temp)
{
    if(temp->right == NULL)
        return temp;
    return in_order_precedence(temp->right);
}
node* in_order_successor(node* temp)
{
    if(temp->left == NULL)
        return temp;
    return in_order_successor(temp->left);
}

int Node_height(node* p)
{
    int h1,h2;
    h1 = p && p->left?p->left->height:0;
    h2 = p && p->right?p->right->height:0;

    return h1>h2?h1+1:h2+1;
}

int balance_factor(node* p)
{
    int h1,h2;
    h1 = p && p->left?p->left->height:0;
    h2 = p && p->right?p->right->height:0;

    return h1-h2;
}

node* LL_rotation(node* p)
{
    // p->left = p->left->right;
    // p->left->right = NULL;
    // p->left->right = p;
    node* pl = p->left;
    node* plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = Node_height(p);
    pl->height = Node_height(pl);

    // if(root==p)
    //     root = pl; //yebhi important hai root globally define krke likhna
    
    return pl;
}

node* RR_rotation(node* p)
{
    return NULL;
}

node* LR_rotation(node* p)
{
    node* pl = p->left;
    node* plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = Node_height(pl);
    p->height = Node_height(p);
    plr->height = Node_height(plr);

}

node* RL_rotation(node* p)
{
    return NULL;
}
node* delete_node(node* p,int key)
{
    if(p==NULL)
        return NULL;

    if(p->left == NULL && p->right == NULL)
    {
        free(p);
        return NULL;
    }
    if(key<p->val)
    {
        p->left = delete_node(p->left,key);
    }
    else if(p->val<key)
    {
        p->right = delete_node(p->right,key);
    }
    else
    {
        if(height(p->left) > height(p->right))
        {
            node* val1 = in_order_precedence(p->left);

            p->val = val1->val;
            p->left = delete_node(p->left,val1->val);

        }
        else
        {
            node* val1 = in_order_successor(p->right);

            p->val = val1->val;
            p->right = delete_node(p->right,val1->val);

        }
    }
    p->height = Node_height(p);

    if(balance_factor(p) == 2 && balance_factor(p->left) == 1) // ll rotation
        return LL_rotation(p);
    else if(balance_factor(p) == 2 && balance_factor(p->left) == -1) // lr rotation
        return LR_rotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->right) == -1) // rr rotation
        return RR_rotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->right) == 1) // rl rotation
        return RL_rotation(p);

    
    return p;
}
// balance factor of avl -1,0,1;

int main()
{
    run();
    node* root = new node(10);
    root->left = new node(8);
    root->left->left = new node(7);
    root->right = new node(15);
    root->right->left = new node(13);
    root->right->right = new node(19);
    //cout<<height(root)<<endl;
    recinsert(root,1);
    recinsert(root,11);
    recinsert(root,22);
    recinsert(root,17);
    recinsert(root,16);
    levelorder_traversal(root);
    cout<<endl;
    delete_node(root,15);
    levelorder_traversal(root);
    return 0;
}