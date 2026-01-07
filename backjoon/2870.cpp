#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> nums;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;

        int dist = 0;
        // 숫자를 발견하면, 숫자가 아닐때까지, 인덱스 ++.
        // 서브 스트링으로 추출하기. 계속 탐색하기.
        for(int j = 0; j < s.size(); j++)
        {
            if(isdigit(s[j]) && dist <=j)
            {
                dist= j;
                while(isdigit(s[dist]))
                {
                    dist++;
                }

                string subStr = s.substr(j, dist-j) ;

                while( subStr.size()>1 && subStr[0] == '0')
                {
                    subStr.erase(0,1);
                }

                //cout << "substr: " << s.substr(j, dist-j) <<'\n';
                nums.push_back(subStr);
            }
        }
    }

    
    sort(nums.begin(), nums.end(), [](const string &a, const string &b){
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    for(string num: nums)
    {
        cout << num << '\n';  
    }
    
    
    return 0;
}