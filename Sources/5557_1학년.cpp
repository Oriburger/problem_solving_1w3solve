#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX_N = 101;

int n; 
ll arr[MAX_N], cache[MAX_N][21];

//k번째의 숫자를 고를 차례이고,
//현재까지의 연산 결과가 val인 경우에
//상근이가 만들 수 있는 올바른 등식의 개수
ll GetAnswer(int k, int val) 
{	
	ll &ret = cache[k][val]; //캐싱(메모이제이션)
	if(ret != -1) return ret;
	
	if(k==n-1) //등식을 다 만들었다면? 
		return ret = (val == arr[n-1]); //등식이 올바른지 여부를 반환(1 or 0)
		
	ret = 0; //cache[k][val]의 초기값은 0.
	if(val+arr[k] <= 20) //덧셈의 결과가 20이 넘지 않으면, 덧셈기호를 추가할 수 있음
		ret += GetAnswer(k+1, val+arr[k]);
	if(val-arr[k] >= 0)  //뺄셈의 결과가 음수가 아니라면, 뺄셈기호를 추가할 수 있음
		ret += GetAnswer(k+1, val-arr[k]);
	
	return ret;
}

int main()   
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	memset(cache, -1, sizeof(cache)); //cache 초기화
	for(int i=0; i<n; i++) 
		cin>>arr[i];

	cout<<GetAnswer(1, arr[0])<<'\n'; //첫번째 숫자부터 시작
	
	return 0;
}
