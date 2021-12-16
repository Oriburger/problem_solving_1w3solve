/*---
## 참고 
- https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019

## 규칙?
- 일의 자리가 0인 A와  일의 자리가 9인 B가 있을 때,
- A부터 B까지 일의 자리에 0~9는 총 (B/10 - A/10 +1)번 등장

## 구현?
- [A가 B보다 작거나 같을 동안 반복] ------  
- A와 B의 일의 자리를 맞춰준다 (맞춰주면서 ans[]배열 갱신, 맞추는건 ++, --연산)
- A ~ B의 일의 자리에 있는 0~9의 개수를 ans[]에 더한다 (개수는 (B/10 - A/10 + 1)*squ )가 됨.
- A/=10, B/=10, squ*=10  (squ는 자릿수를 나타냄, 10의 거듭제곱 형태)
----*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n, head = 1, tail, squ = 1;
vector<int> ans(10, 0);

void subCalc(int num, int squ_tmp)
{
	while(num)
	{
		ans[num%10] += squ_tmp;
		num/=10;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	tail = n;
	while(head <= tail)
	{
		while(head%10 != 0 && head<=tail)
			subCalc(head++, squ);
		
		if(tail < head) break;

		while(tail%10 != 9 && head<=tail)
			subCalc(tail--, squ);

		head /= 10;
		tail /= 10;

		for(int i=0; i<10; i++)
			ans[i] += (tail-head+1) * squ;
		squ *= 10;
	}

	for(int i=0; i<10; i++)
		cout<<ans[i]<<' ';

	return 0;
}
