#include <iostream>
#include <vector>
using namespace std;

int n;
vector<bool> student;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	student.resize(31);
	
	for(int i=0; i<28; i++)
	{
		int input;
		cin>>input;
		
		student[input]=true;
	}
	
	for(int i=1; i<=30; i++)
		if(!student[i]) cout<<i<<'\n';
	
	return 0;
}
