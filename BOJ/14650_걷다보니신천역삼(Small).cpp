//간단한 재귀문제. 0, 1, 2로 만들 수 있는 모든 N자리 숫자를 탐색하며
//3의 배수인지 체크하면 된다. 굳이 문자열로 수가 만들어지는지 체크할 필요는 없고
//모든 자리수의 합을 인자로 넘기면 됨.

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int n, ans;

int getAnswer(int sum, int cnt)
{
	if(cnt == n) return (sum % 3 == 0); 
	
	int ret = 0;
	if(sum != 0) ret += getAnswer(sum, cnt+1);
	ret += getAnswer(sum+1, cnt+1);
	ret += getAnswer(sum+2, cnt+1);
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;
	
	ans = getAnswer(0, 0);
	
	cout<<ans<<'\n';
	
	return 0;
}
