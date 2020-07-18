#include <iostream>
#include <vector>
#define INF 2147000000
using namespace std;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k; 
	vector<int> arr, answer;

	cin>>n>>k;
		
	arr.resize(n);
	for(int i=0; i<n; i++)
		arr[i]=i+1;
	
	vector<int>::iterator curr = arr.begin(), temp;
	
	while(1)
	{
		if(arr.size()==0)
			break;
			
		for(int i=1; i<k; i++)
		{
			curr++;
			if(curr==arr.end())
				curr = arr.begin();
		}

		answer.push_back(*curr);
		arr.erase(curr);
		
		if(curr==arr.end())
			curr = arr.begin();
	}
	
	cout<<'<';
	for(int i=0; i<n; i++)
	{
		cout<<answer[i];
		if(i<n-1) cout<<", ";
		else cout<<'>';
	}
	
	return 0;
}	
