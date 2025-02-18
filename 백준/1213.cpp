#include<bits/stdc++.h>

using namespace std;

char middle_char;
string name, ret;
int odd_cnt, cnt[26];


int main()
{
    cin>>name;

    for(char ch: name)
    {
        cnt[ch-'A']++;
    }

    for(int i: cnt)
    {
        if(i&1) odd_cnt++;
    }

    if(odd_cnt>1)
    {
        ret = "I'm Sorry Hansoo";
    }
    else
    {
        for(int i = 0; i < 26; i++ )
        {
            while(cnt[i]>0)
            {
                if(cnt[i]==1) 
                {
                    middle_char = i+'A';
                    cnt[i]--;
                }
                else
                {
                    ret.push_back(i+'A');
                    cnt[i]--;
                    cnt[i]--;
                }
            }
        }

        string temp;
        temp = ret; 
        reverse(temp.begin(), temp.end());

        if(middle_char)
        {
            ret.push_back(middle_char);
        }

        ret += temp;

    }

    cout<<ret<<'\n';

    return 0;
}