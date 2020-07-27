#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

/*

R = 배열에 있는 숫자의 순서를 뒤집는 함수
D = 첫 번째 숫자를 버리는 함수

*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin>>t;

	while(t--)
	{
		int n; bool flag=false, ansFlag=false;
		vector<int> temp;
		deque<int> arr;
		string cmd, input;

		cin>>cmd>>n>>input;

		for(int i=0; i<input.size(); i++)
		{
			if(input[i]>='0' && input[i]<='9')
				temp.push_back((int)input[i]-'0');

			else
			{
				int num=0;
				for(int j=0; j<temp.size(); j++)
				{
					num += temp[j];
					if(j!=temp.size()-1) num*=10;
				}

				if(!temp.empty())
				{
					arr.push_back(num);
					temp.clear();
				}
			}
		}

		for(int i=0; i<cmd.size(); i++)
		{
			if(cmd[i]=='R')
				flag = !flag;
			
			else if(cmd[i]=='D')
			{
				if(arr.size()==0)
				{
					cout<<"error\n";
					ansFlag = true;
					break;
				}
				
				
				if(!flag) arr.pop_front();
				else arr.pop_back();
			}
		}
		if(ansFlag) continue;

		deque<int>::iterator st, dest;
		if(!flag)
		{
			st = arr.begin();
			dest = arr.end()-1;
		}
		else
		{
			st = arr.end()-1;
			dest = arr.begin();
		}

		cout<<'[';
		if(arr.size()!=0)
			for(deque<int>::iterator j = st; ; j+=(!flag ? 1 : -1))
			{
				cout<<*j;
				if(j==dest) break;
				cout<<',';
			}
		cout<<"]\n";
	}

	return 0;
}
