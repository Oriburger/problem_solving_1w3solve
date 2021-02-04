#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll>::iterator ITER;

ll n, temp, ans_left, ans_right, sum;
vector<ll> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	arr.resize(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	sort(arr.begin(), arr.end());


	ITER lo = arr.begin(), hi = arr.end();
	hi = hi - 1; 
	ans_left = *lo; 
	ans_right = *hi;
	sum = *hi + *lo;

	while(lo < hi)
	{
		temp = *lo + *hi;

		if(abs(sum) > abs(temp))
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
