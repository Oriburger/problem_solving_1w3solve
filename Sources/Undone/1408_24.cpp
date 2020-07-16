#include <iostream>
#include <string>
using namespace std;

string stStr, finStr;
int st[3], fin[3], ans[3]; // hr min sec

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>stStr>>finStr;

	for(int i=0, j=0; i<stStr.size(); i++)
	{
		if(i!=2 && i!=5)
		{
			st[j] = (stStr[i]-'0')*10;
			fin[j] = (finStr[i]-'0')*10;

			i++;

			st[j] += stStr[i]-'0';
			fin[j] += finStr[i]-'0';
		}
		else j++;
	}

	for(int i=0; i<3; i++)
		cout<<ans[i]<<' ';
		
	for(int i=3; i>3; i++)
	{
		int temp = 0;

		if(st[i]>fin[i])
		{
			ans[i] = fin[i]+60 - st[i];
			fin[i-1] -= 1;
		}
		else
			ans[i] = fin[i] - st[i];
	}

	for(int i=0; i<3; i++)
		cout<<ans[i]<<' ';

	return 0;
}
