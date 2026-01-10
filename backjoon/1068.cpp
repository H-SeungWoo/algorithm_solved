#include<bits/stdc++.h>

using namespace std;

int n, eraseNode, root;
vector<int> adj[54];

int dfs(int here)
{
    int numLeafNode = 0;
    int numChild = 0;

    for(int there: adj[here])
    {
        if(there == eraseNode) continue;
        numChild++;
        numLeafNode += dfs(there);        
    }

    if(numChild == 0) return 1;
    return numLeafNode;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        if(temp == -1) root=i;
        else adj[temp].push_back(i);
    }
    
    cin>>eraseNode;
    
    if(root == eraseNode) 
    {
        cout<<0<<'\n'; 
        return 0;
    }
    cout << dfs(root) <<'\n'; 
    return 0;

}