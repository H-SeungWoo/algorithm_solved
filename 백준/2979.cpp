#include <iostream>

using namespace std;

int price_a = 0;
int price_b = 0;
int price_c = 0;

int time[101];
int total = 0;

int main()
{
    cin >> price_a >> price_b >> price_c;
    for (int i = 0; i < 3; i++)
    {   
        int start, end;
        cin >> start >> end;
        for(int j=start; j<end; j++)
        {
            time[j]++;
        }
    }

    for (int t: time)
    {
        if(t)
        {
            if(t == 1) total += price_a;
            else if (t == 2) total += 2*price_b;
            else if (t == 3) total += 3*price_c;
        }
    }

    cout << total << "\n";
    return 0;
}