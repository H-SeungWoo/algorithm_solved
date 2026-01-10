#include <iostream>
#include <string>

using namespace std;

string word, tmp;
int length, half, ret = 1;

int main() 
{
	cin >> word;
	length = word.length();
	half = length / 2;
	for (int i = 0; i < half ; i++)
	{
		if (word[i] != word[length - (i+1)])
		{
			ret = 0;
			break;
		}
	}

	cout << ret << "\n";

	return 0;
}