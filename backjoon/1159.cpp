#include <iostream>
#include <string>

using namespace std;

int num_player, arr[26];
string player_name, ret;
char first;

int main() 
{
	cin >> num_player;
	for (int i = 0; i < num_player; i++)
	{
		cin >> player_name;
		first = player_name[0];
		arr[first - 'a']++;
	}

	for (int j=0; j < 26; j++)
	{
		if ( arr[j] >= 5)
		{
			ret.push_back(j + 'a');
		}
	}

	if (ret.empty())
	{
		ret = "PREDAJA";
	}
	cout << ret << "\n";

	return 0;
}