#include<bits/stdc++.h>

using namespace std;

int n, goalTeam, scoreTeam1, scoreTeam2, recordedTeam, winningTimeTeam1, winningTimeTeam2;
string goalTime, recordedTime;
bool flag = true; // 동점인지 아닌지. true면 동점. false면 동점아님.

int ConvertTimeToInt(string strTime)
{
    return atoi(strTime.substr(0,2).c_str())*60 + atoi(strTime.substr(3,2).c_str());
}

string ConvertTimeToStr(int intTime)
{
    string ret;
    if(intTime/60 == 0)
    {
        ret += "00";
    }
    else if(intTime/60 <10)
    {
        ret += "0"+to_string(intTime/60);
    }
    else
    {
        ret += to_string(intTime/60);
    }
    ret += ":";

    if(intTime%60 == 0)
    {
        ret += "00";
    }
    else if(intTime%60 <10)
    {
        ret += "0"+to_string(intTime%60);
    }
    else
    {
        ret += to_string(intTime%60);
    }
    return ret;
}


int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        // 골 넣은 시각 ~ 동점이 된 시각의 차
        cin >> goalTeam >> goalTime;
        
        if(goalTeam == 1) scoreTeam1++;
        else scoreTeam2++;

        if(scoreTeam1 != scoreTeam2)
        {
            if(!flag) continue;
            flag = false;
            recordedTeam = goalTeam;
            recordedTime = goalTime;
        }
        else
        {
            // 점수 처리
            flag = true;
            if(recordedTeam == 1)
            {
                winningTimeTeam1 += ConvertTimeToInt(goalTime) - ConvertTimeToInt(recordedTime);
            }
            else
            {
                winningTimeTeam2 += ConvertTimeToInt(goalTime) - ConvertTimeToInt(recordedTime);
            }

        }        
    }

    if(!flag)
    {
        if(recordedTeam == 1)
        {
            winningTimeTeam1 += ConvertTimeToInt("48:00") - ConvertTimeToInt(recordedTime);
        }
        else
        {
            winningTimeTeam2 += ConvertTimeToInt("48:00") - ConvertTimeToInt(recordedTime);
        }
    }

    cout << ConvertTimeToStr(winningTimeTeam1) << '\n';
    cout << ConvertTimeToStr(winningTimeTeam2) << '\n';

    return 0;
}
