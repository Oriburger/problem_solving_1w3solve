
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

int n, k; 
vector<int> arr; 
int main() 
{
 	ios::sync_with_stdio(false);
 	cin.tie(NULL); cout.tie(NULL);

 	cin>>n>>k;
 	for(int i=0; i<n; i++)
 	{
 		int input;
 		cin>>input;
 		arr.push_back(input);
 	}
 	sort(arr.begin(), arr.end());
 	cout<<arr[k-1]<<'\n';
 	return 0; 
}
