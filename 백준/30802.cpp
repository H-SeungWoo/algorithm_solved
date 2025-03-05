#include <bits/stdc++.h>

using namespace std;

int n, s, m, l, xl, xxl, xxxl, t, p;

int solve(int s, int t)
{
    if(s%t == 0) return s/t;
    else return s/t+1;
}

int main()
{
    cin >> n;
    cin >> s >> m >> l >> xl >> xxl >> xxxl ;
    cin >> t >> p;

    cout << solve(s,t) + solve(m ,t) + solve(l, t) + solve(xl, t) + solve(xxl, t) + solve(xxxl, t) <<'\n';
    cout << n/p << ' ' << n%p << '\n';
    return 0;
}