#include <bits/stdc++.h>

using namespace std;

int h, w, cnt;
char test_map[101][101];

int main()
{
    cin >> h >> w;

    for(int i = 0; i< h; i++)
    {
        for(int j=0; j< w; j++)
        {
            cin >> test_map[i][j];
        }
    }

    for(int i = 0; i< h; i++)
    {
        cnt = -1;
        for(int j=0; j< w; j++)
        {
            if(test_map[i][j] == 'c')
            {
                cnt = 0;
            }
            else if( test_map[i][j] == '.' && cnt > -1)
            {
                cnt++;                
            }

            cout << cnt << ' ';

        }

        cout << '\n';
    }

    return 0;
}

