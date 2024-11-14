#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* left;
    node* right;
    node* parent;
    char c;
};
void inorder(node* n){
    if(n==nullptr)return;
    if(n->left!=nullptr)inorder(n->left);
    cout<<n->c;
    if(n->right!=nullptr)inorder(n->right);
}
bool judgeFull(node* n){
    if(n==nullptr)return false;
    if(n->left!=nullptr&&n->right!=nullptr)return true;
    return false;
}
void setLeft(node* l,node* p){
    p->left=l;
    l->parent=p;
}
void setRight(node* r,node* p,stack<node*> s){
    if(r==nullptr)return;
    p->right=r;
    r->parent=p;
    s.pop();
    
    if(judgeFull(p)){
        node* pp=p->parent;
        if(pp->left==nullptr){
            setLeft(p,pp);
        }else{
            setRight(p,pp,s);
        }
    }
}
int main(){
    stack<node*> op;

    string str;
    getline(cin,str);

    node* root=nullptr;
    char* c=&str[0];
    for(int i=0;i<strlen(c);i++){
        if(c[i]=='('||c[i]==')'||c[i]==',')continue;
        node* current=new node{NULL,NULL,NULL,str[i]};
        if(root==nullptr)root=current;
        if(str[i]<='z'&&str[i]>='a'){
            node* top=op.top();
            if(top->left==nullptr){
                setLeft(current,top);
            }else{
                setRight(current,top,op);
            }
        }else{
            op.push(current);
        }
    }
    inorder(root);
    return 0;
}
