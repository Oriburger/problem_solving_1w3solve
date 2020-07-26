#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input; cin>>input;

	vector<char> num, oper;
	vector<int> arr;
	for(int i=0; i<input.size(); i++)
	{
		if(input[i]>='0' && input[i]<='9')
			num.push_back(input[i]);

		if(input[i]=='+' || input[i]=='-' || i==input.size()-1)
		{
			int n=0;
			for(int i=0; i<num.size(); i++)
			{
				n+=(num[i]-'0');
				if(i!=num.size()-1)	n*=10;
			}
			arr.push_back(n);
			num.clear();

			if(input[i]=='+' || input[i]=='-')
				oper.push_back(input[i]);
		}
	}

	int result=0;
	for(int i=0; i<oper.size(); i++)
	{
		if(oper[i]=='+')
		{
			if(arr.size()==3) break;

			arr[i]+=arr[i+1];
			arr.erase(arr.begin()+i+1);

			for(int i=0; i<arr.size(); i++)
				cout<<arr[i]<<' ';
			cout<<'\n';

			//oper.erase(oper.begin()+i);
			//i--;
		}
	}

	for(int i=0; i<arr.size(); i++)
		cout<<arr[i]<<' ';

	return 0;
}
