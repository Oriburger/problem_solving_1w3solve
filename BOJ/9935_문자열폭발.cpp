#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000001;

string str, bomb;
char answer[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin>>str>>bomb;

	int idx = 0;
	const int blen = bomb.length();
	for(int i=0; i<str.size(); i++)
	{
		answer[idx++] = str[i];

		if(answer[idx-1] == bomb[blen-1])
		{
			if(idx - blen < 0) continue;

			bool flag = true;
			for(int j=0; j<blen; j++)
			{
				if(answer[idx-j-1] != bomb[blen-j-1])
				{
					flag = false;
					break;
				}
			}
			if(flag) idx-=blen;
		}
	}

	if(!idx) cout<<"FRULA\n";
	else 
	{
		for(int i=0; i<idx; i++)
			cout<<answer[i];
		cout<<'\n';
	}
	

	return 0;
}
