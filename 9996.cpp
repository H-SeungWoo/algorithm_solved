#include<bits/stdc++.h>

using namespace std;

int N;
string pre, suf, s_ori, test;

int main()
{
    cin >> N;
    cin >> s_ori;
    int index_star = s_ori.find('*');
    pre = s_ori.substr(0,index_star);
    suf = s_ori.substr(index_star+1);

    for(int i=0; i<N; i++)
    {
        cin>>test;
        if(pre.size()+suf.size()>test.size()) cout << "NE" << '\n';
        else
        {
            if( pre == test.substr(0,pre.size()) && suf == test.substr(test.size()-suf.size())) cout<<"DA"<<'\n';
            else cout<<"NE"<<'\n';
        }
    }

    return 0;
}
