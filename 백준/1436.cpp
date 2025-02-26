#include<bits/stdc++.h>

using namespace std;

int n, ret = 665;

int main()
{
    cin >> n;
    while(n)
    {
        ret++;
        if(to_string(ret).find(to_string(333*2)) != string::npos) n--;
        //cout << "ret : "<< ret << " || n : " << n << '\n';
    }

    cout << ret << '\n';
    return 0;
}