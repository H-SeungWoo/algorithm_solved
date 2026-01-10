#include<bits/stdc++.h>

using namespace std;

int a[100004], psum[100004];
int n, m, b, c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }

    for(int i=0; i<m; i++)
    {
        cin >> b >> c;
        cout << psum[c]-psum[b-1] << '\n';
    }

    return 0;
}