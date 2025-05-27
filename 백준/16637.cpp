#include<bits/stdc++.h>

using namespace std;

vector<int> nums;
vector<char> opers;
int n, maxValue = INT_MIN;
string s;

int calculate(char a, int b, int c)
{
    if(a=='+') return b+c;
    else if(a=='*') return b*c;
    else return b-c;
}

void solve(int here, int curNum)
{
    //cout << here << " : " << curNum << '\n';
    if(here == nums.size()-1)
    {
        maxValue = max(maxValue, curNum);
        return;
    }

    
    solve(here+1, calculate(opers[here], curNum, nums[here+1]));
    if(here < nums.size()-2)
    {
        int temp = calculate(opers[here+1], nums[here+1], nums[here+2]);
        solve(here+2,calculate(opers[here], curNum, temp));
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    cin >> s;

    for(int i=0; i<s.size(); i++)
    {
        if(i%2==0) nums.push_back(s[i]-'0');
        else opers.push_back(s[i]);
    }

    solve(0, nums[0]);
    cout<<maxValue << '\n';
    
}