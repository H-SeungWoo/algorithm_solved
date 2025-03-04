#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {1, 0 ,-1 ,0};

int n, m, ny, nx, a[54][54], cDist = 0;
vector<pair<int, int>> homeList, storeList;

// 1. 모든 치킨집이 있는 경우와 없는 경우에서 (2^m의 경우의 수 )
// 2. 한 집과 다른 치킨집들 사이에 최단거리를 구한다.

// 치킨가게 배치하는 함수
int GetcDist()
{
    for(auto startPos: homeList)
    {

    }

}

// m개의 치킨집을 고르는 함수
void solve(int index, vector<pair<int, int>> v)
{
    if(index == m)
    {
        for(auto store: v)
        {
            a[store.first][store.second] = 2;
        }
        cDist = min(cDist, GetcDist());
        for(auto store: v)
        {
            a[store.first][store.second] = 0;
        }
        return;
    }

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
            if(a[i][j] == 2) 
            {
                a[i][j] = 0;
                storeList.push_back({i, j});
            }
        }

        //combi(-1);
    }




}