#include<bits/stdc++.h>

using namespace std;

struct Node{
    char value;
    Node* left;
    Node* right;

    Node(int n): value(n), left(nullptr), right(nullptr){}
};

int n;
Node* nodes[26];
char p,l,r;

void preorder(Node* cur);
void inorder(Node* cur);
void postorder(Node* cur);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        nodes[i] = new Node('A'+i);
    }
    for(int i=0; i<n; i++){
        cin>>p>>l>>r;

        if(l != '.') nodes[p-'A']->left=nodes[l-'A'];
        if(r != '.') nodes[p-'A']->right=nodes[r-'A'];
    }

    Node* root = nodes[0];
    preorder(root); 
    cout<<'\n';
    inorder(root);
    cout<<'\n';
    postorder(root);
    cout<<'\n';
    return 0;
}

void preorder(Node* cur){
    if(!cur) return;
    cout<<cur->value;
    preorder(cur->left);
    preorder(cur->right);
}

void inorder(Node* cur){
    if(!cur) return;
    inorder(cur->left);
    cout<<cur->value;
    inorder(cur->right);
}

void postorder(Node* cur){
    if(!cur) return;
    postorder(cur->left);
    postorder(cur->right);
    cout<<cur->value;
}


