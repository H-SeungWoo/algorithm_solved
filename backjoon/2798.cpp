#include<bits/stdc++.h>

using namespace std;

int n, m, retValue = 0, a[101];
vector<int> b;

void combi(int index, vector<int> v)
{
    if(v.size()==3)
    {
        int temp = 0;
        for(int i: v)
        {
            temp += i;
        }
        if(retValue == 0) retValue = temp; 
        else if(m>=temp && abs(m-temp) < abs(m-retValue)) retValue = temp;

        return;
    }

    for(int i= index+1; i<n; i++)
    {
        v.push_back(a[i]);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main()
{
    cin>> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    combi(-1, b);
    cout << retValue <<'\n';

    return 0;

}