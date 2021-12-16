#include <iostream>
#include <string>
using namespace std;

string str;
int head, tail;
bool flag;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>str;

	head=0; tail=str.length()-1;

	while(1)
	{
		if(head>=tail) break;

		if(str[head]!=str[tail])
		{
			flag=true; 
			break;
		}
		
		head+=1; tail-=1;
	}

	cout<<!flag<<'\n';

	return 0;
}
