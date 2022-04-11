#include <iostream>
#include <string>
using namespace std;

string str[2];
long long ans[2];

long long GetAnswer(bool flag)
{
	for(int i=0; i<2; i++)
		for(auto &c : str[i])
			if(c== (!flag ? '6' : '5')) c = (!flag ? '5' : '6');
		
	return stoll(str[0]) + stoll(str[1]);
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>str[0]>>str[1];

	for(int i=0; i<2; i++)
		cout << GetAnswer(i) <<' ';
		
	return 0;
}
