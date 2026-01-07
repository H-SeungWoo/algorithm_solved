#include <bits/stdc++.h>

using namespace std;

int n,m, cnt1, cnt2, ret=2500;
char a[54][54];

int solve(int y, int x)
{
    if(y+8>n || x+8 >m) return ret;
    
    char startChar = a[y][x];

    for(int i=y; i<y+8; i++)
    {
        for(int j=x; j<x+8; j++)
        {
            if(((y+x)&1) == ((i+j)&1))
            {
                if(a[i][j] != startChar) 
                {
                    cnt1++;
                    //cout << "(j,i): (" << j <<","<<i <<") it must be equla. but, " << startChar <<"," << a[i][j]  << '\n';
                }
                else cnt2++;
            }
            else
            {
                if(a[i][j] == startChar) 
                {
                    cnt1++;
                    //cout << "(j,i): (" << j <<","<<i <<") it must be diffrent. but, " << startChar <<"," << a[i][j]  << '\n';
                }
                else cnt2++;
                
            }
        }
    }
    //cout << "Result from (x,y): (" << x <<","<<y <<") ==>> " << min(cnt1,cnt2) << '\n';
    return min(cnt1, cnt2);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cnt1 = 0; cnt2 =0;
            ret = min(ret, solve(i,j));
        }
    }

    cout << ret <<'\n';
    return 0;

}