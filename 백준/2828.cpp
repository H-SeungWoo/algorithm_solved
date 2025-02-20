#include <bits/stdc++.h>

using namespace std;

int n,m,j, s, e, ret;
vector<int> apples;

int main()
{
    cin >>n >> m >> j;
    s= 1;
    e= m;
    while(j--)
    {
        int temp;
        cin>>temp;
        apples.push_back(temp);
    }

    for(int apple: apples)
    {
        //cout << "s, e, apple:" << s <<' ' << e << ' ' << apple << '\n';
        if(apple>=s && apple<=e) continue;
        else
        {
            //cout << "move!" << '\n';
            int dist = 0;
            if(apple<s)
            {
                dist = s-apple;
                s -= dist;
                e -= dist;
                ret += dist;
                //cout << "dist: " << dist << '\n';
                
            }
            else if(apple > e)
            {
                dist = apple - e;
                s += dist;
                e += dist;
                ret += dist;
                //cout << "dist: " << dist << '\n';

            }
        }
    }
    cout << ret << '\n';
    return 0;
}