#include <iostream> 
#include <string>
using namespace std;

string input, answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>input;

	for(int i=0; i<input.size(); i++)
	{
		if(i==0) answer.push_back(input[i]);
		else if(input[i]=='-' && i+1 < input.size()) answer.push_back(input[i+1]);
	}
	
	cout<<answer<<'\n'; 
	
	return 0;
}
