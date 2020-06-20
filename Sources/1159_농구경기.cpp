#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n; bool flag;
int nameCnt[26];
vector<char> answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		string input;
		cin>>input;
		
		nameCnt[input.at(0) - 'a']++;
	}
	
	for(int i=0; i<26; i++)
		if(nameCnt[i]>=5)
		{
			putchar(i+'a');
			flag = true;
		}
	
	if(!flag) cout<<"PREDAJA\n";
	
	
	return 0;
}
