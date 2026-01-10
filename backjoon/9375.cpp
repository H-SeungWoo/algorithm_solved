#include <iostream>
#include <string>
#include <map>

using namespace std;

int test, n;
string wear_name, wear_category;

int main() 
{
	cin >> test;
	while (test--)
	{
		map<string, int> wear;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> wear_name >> wear_category;
			wear[wear_category]++;
		}

		long long cases = 1;
		for (pair<string, int> category_cnt : wear)
		{
			cases *= ((long long)category_cnt.second + 1);
		}
		cases--;
		cout << cases << '\n';

	}
	return 0;
}