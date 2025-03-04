#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {1, 0 ,-1 ,0};

int n, m, ny, nx, a[54][54], cDist = 25000000;
vector<pair<int, int>> homeList, storeList, testList;

// 1. 모든 치킨집이 있는 경우와 없는 경우에서 (2^m의 경우의 수 )
// 2. 한 집과 다른 치킨집들 사이에 최단거리를 구한다.

int GethDist(int x1, int x2, int y1, int y2)
{
    return abs(x2-x1) + abs(y2-y1);
}

// 치킨가게 배치하는 함수
int GetcDist(vector<pair<int, int>> v)
{
    int sum = 0;
    for(auto home: homeList)
    {
        int dist = 5010;
        for(auto store: v)
        {
            dist = min(dist, GethDist(home.first,store.first, home.second, store.second));
        }

        sum += dist;
    }

    return sum;
}

// m개의 치킨집을 고르는 함수
void solve(int index, vector<pair<int, int>> v)
{
    if(v.size() == m)
    {
        cDist = min(cDist, GetcDist(v));
        return;
    }

    if(index == storeList.size()) return;

    v.push_back(storeList[index]);
    solve(index +1, v);
    v.pop_back();
    solve(index+1, v);
    
}


int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1) homeList.push_back({i, j});
            if(a[i][j] == 2) storeList.push_back({i, j});
        }
    }

    // for(auto home: homeList) cout << "(" <<home.second<<","<<home.first<<") ";
    // cout << '\n';
    // for(auto store: storeList) cout << "(" <<store.second<<","<<store.first<<") ";
    // cout << '\n';

    solve(0, testList);
    cout << cDist << '\n';
}