#include <iostream>
#include <string>
using namespace std;

int answer=0, len=0, dzCnt=0;
string input; 
string c[8] = {"dz=", "c=", "c-", "d-", 
				"lj", "nj", "s=", "z="};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>input;
	
	for(int i=0; i<8; i++)
	{
		int idx = input.find(c[i], 0);
	
		while(idx!=string::npos)
		{
			if(i==0) dzCnt++;
			if(i==7 && dzCnt!=0)		
				dzCnt--;
			else
			{
				answer++;
				len+=c[i].length();
			}
			idx = input.find(c[i], idx+1);
		}
	}
	
	cout<<answer+input.length()-len<<'\n';
	
	return 0;
}
