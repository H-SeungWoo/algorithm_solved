#include <bits/stdc++.h>

using namespace std;

string password;
bool bCanPassword = true;
bool bHasVowel = false;

bool IsVowel(int i)
{
    return {i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'};
}

int main()
{
    while(true)
    {
        cin >> password;
        if(password == "end") break;
        
        bCanPassword = true;
        bHasVowel = false;

        for(int i=0; i< password.length(); i++)
        {

            // 모음을 포함하고 있는지 체크
            if(IsVowel(password[i])) bHasVowel = true;

            // 세번 연속 모음/자음인지 체크
            if(i>=2)
            {
                if(IsVowel(password[i-2]) && IsVowel(password[i-1]) && IsVowel(password[i])) bCanPassword = false;
                else if( !IsVowel(password[i-2]) && !IsVowel(password[i-1]) && !IsVowel(password[i])) bCanPassword = false;
            }

            // 두번 연속 같은 글자인지 체크 ('oo','ee' 제외)
            if(i>=1)
            {
                if(password[i-1] == password[i]) 
                {
                    if(password[i] != 'o' && password[i] != 'e') bCanPassword = false;
                }
            }
        }

        if(!bHasVowel) bCanPassword = false;

        if (bCanPassword) cout << "<" << password << "> is acceptable." << '\n';
        else cout << "<" << password << "> is not acceptable." << '\n';
    }

    return 0;
}