#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<int> uset[9];
const int temp[8] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111};

int main()
{    
	int k, n;

	cin>>k>>n;

    for(int i=1; i<=8; i++)
        uset[i].insert(temp[i-1]*k); //미리 N, NN, ... , NNNNNNNN을 insert
    
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(i + j > 8) continue; //8을 넘는건 찾을 필요가 없음
            
            for(int a : uset[i]) //a는 uset[i]의 원소
            {
                for(int b : uset[j]) //b는 uset[j]의 원소
                {
                    if(a!=b) uset[i+j].insert(abs(a-b)); //뺄셈 : a-b가 0이 되어선 안됨
                    uset[i+j].insert(a+b); //덧셈 
                    uset[i+j].insert(a*b); //곱셈 
                    if(a && b) uset[i+j].insert(max(a, b)/min(a, b)); //나눗셈 : 0으로 나눠지면 안됨
                }
            }
        }
    }

	while(n--) //정답을 탐색
	{
		int target;
		cin>>target;

	    int answer = -1;
	
	    for(int i=1; i<=8; i++)
        	if(uset[i].count(target)) //target이 uset[i]에 있는지?
        	{                         //즉, k를 i번 사용해서 target이 만들어졌는지?
	            answer = i; //그렇다면 정답 갱신후
            	break;      //break
        	}
		
		if(answer==-1) cout<<"NO\n";
		else cout<<answer<<'\n';
	}

	return 0;
}
