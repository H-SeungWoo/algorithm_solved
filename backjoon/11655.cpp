#include <iostream>
#include <string>

using namespace std;

string str, ret;

int main() 
{
	getline(cin, str);
	for (char ch: str)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			if (ch + 13 > 'z') ret.push_back(ch - 13);
			else ret.push_back(ch + 13);
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			if (ch + 13 > 'Z') ret.push_back(ch - 13);
			else ret.push_back(ch + 13);
		}
		else
		{
			ret.push_back(ch);
		}
	}

	cout << ret << "\n";

	return 0;
}