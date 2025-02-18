#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, m;
map<int, string> map1;
map<string, int> map2;
string name, input;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> name;
		map1[i] = name;
		map2[name] = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> input;
		int test = atoi(input.c_str());
		if (test) cout << map1[test] << '\n';
		else cout << map2[input] << '\n';
	}

	return 0;
}