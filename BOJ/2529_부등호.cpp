#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
bool flag[2];
vector<char> s;
vector<int> arr, arr2;

bool isPossible(vector<int>& arr)
{
	for(int i=0; i<s.size(); i++)
	{
		if(s[i] == '>' && arr[i] < arr[i+1]) return false;
		else if(s[i] == '<' && arr[i] > arr[i+1]) return false;
	}
	return true;
}

void prtAnswer(vector<int>& arr, bool bIsReverse = false)
{
	do
	{
		if(isPossible(arr))
		{
			for(auto &p : arr)
				cout<<p;
			cout<<'\n';
			return;
		}
		if(!bIsReverse && !next_permutation(arr.begin(), arr.end())) break;
		else if(bIsReverse && !prev_permutation(arr.begin(), arr.end())) break;
	} while(1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	s = vector<char>(n);
	for(int i=0; i<=n; i++)
	{
		if(i!=n) cin>>s[i];
		arr2.push_back(i);
		arr.push_back(9-i);
	}
	
	prtAnswer(arr, true);
	prtAnswer(arr2);

	return 0;
}
