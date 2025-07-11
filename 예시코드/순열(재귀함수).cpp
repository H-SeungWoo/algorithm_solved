#include<bits/stdc++.h>

using namespace std;
int a[9];
int n = 9, r = 7;
// 9개 중 7개를 뽑는다.
void print()
{
    for(int i=0; i < r; i++) cout << a[i] << " ";
    cout << '\n';
}

void makePermutation(int n, int r, int depth)
{
    if(depth == r)
    {
        print();
        return;
    }
    for(int i=depth; i<n; i++)
    {
        swap(a[i], a[depth]);
        makePermutation(n, r, depth+1);
        swap(a[i], a[depth]);
    }
}

int main()
{
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    makePermutation(n, r, 0);
    return 0;
}