#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	cin>>input;

	int cnt=0;
	for(int i=0; i<input.length()-1; i++)
		if(input[i]==input[i+1]) cnt++;

	cout<<input.length()*10 - (cnt)*5;

	return 0;
}
