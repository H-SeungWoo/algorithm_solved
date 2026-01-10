#include <bits/stdc++.h>

using namespace std;

int n,k, cnt;
vector<int> v;

void combi(int index, vector<int> v)
{
    if(v.size()==k)
    {
        cnt++;
        return;
    }

    for(int i = index+1; i<n; i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}
int main()
{
    cin >> n >> k;
    combi(-1, v);

    cout<< cnt <<'\n';
}