#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator ITER;

int n, ans_left, ans_right, temp, sum;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	arr.resize(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	sort(arr.begin(), arr.end());

	ITER lo, hi;
	lo = arr.begin();
	hi = arr.end()-1;

	ans_left = *lo;
	ans_right = *hi;
	sum = *lo + *hi;

	while(lo < hi)
	{
		int temp = *lo + *hi;
		if(abs(temp) < abs(sum))
		{
			sum = temp;
			ans_left = *lo;
			ans_right = *hi;
		}
		if(temp <= 0) lo++;
		else hi--;
	}
	
	cout<<ans_left<<' '<<ans_right<<'\n';

	return 0;
}
