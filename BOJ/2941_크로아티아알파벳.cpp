#include <iostream>
#include <string>
using namespace std;

int answer=0, len=0, dzCnt=0;
string input; 
string c[8] = {"dz=", "c=", "c-", "d-", 
				"lj", "nj", "s=", "z="};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>input;
	
	for(int i=0; i<8; i++)
	{
		int idx = input.find(c[i], 0);
	
		while(idx!=string::npos) //더이상 c[i]가 발견되지 않을때까지
		{
			if(i==0) dzCnt++;    //"dz="이면 dzCnt++
			if(i==7 && dzCnt!=0) //"z="이 발견되었는데, 이전에 "dz="도 있었다면		
				dzCnt--;         //answer을 갱신하지 않고 dzCnt를 빼준다.
			else
			{
				answer++;        
				len+=c[i].length(); //크로아티아 알파벳이 차지하는 길이를 더해준다
			}
			idx = input.find(c[i], idx+1); //다음 위치에서 해당 알파벳을 찾는다.
		}
	}
	
	cout<<answer+input.length()-len<<'\n'; //크로아티아 알파벳 개수 + 나머지 알파벳 개수
	
	return 0;
}
