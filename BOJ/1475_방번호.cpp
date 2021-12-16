#include <iostream> 
#include <string>
using namespace std;

string input;
int arr[10], answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>input;
	
	for(int i=0; i<input.length(); i++)
	{
		arr[input[i]-'0']++;
	}
	
	int temp1 = (arr[6] + arr[9])/2 + (arr[6] + arr[9])%2;
	int temp2 = (arr[6] + arr[9])/2;
	
	if(arr[6]+arr[9]!=1)
	{
		arr[6]=temp1;
		arr[9]=temp2;
	}
	
//	cout<<arr[6]<<arr[9]<<'\n';
		
	answer=0;
	for(int i=0; i<10; i++)
		answer=max(arr[i], answer);
	
	cout<<answer<<'\n';	
	
	return 0;
}
