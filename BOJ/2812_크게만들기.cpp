#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, k, ans;
string str, tmp;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cout.tie(NULL);

    cin>>n>>k>>str;

	k = n-k; //k개를 빼는 거에서 n-k개를 뽑는 걸로 문제를 재구성
    for(int i=0; i<n; i++) //입력된 수를 한 자리씩 순회
    {
    	char curr = str[i];
    	char top = tmp.empty() ? '0' : tmp[tmp.size()-1];
    	
        if(tmp.size() + n-i > k) //남아있는 수의 개수가 넉넉하다면?
        {
        	if(curr == top) tmp.push_back(curr); //top랑 curr이 같다면 그냥 push
        	else
        	{
        		while(!tmp.empty()) //스택에서 pop(a. 스택이 빌 때 까지) 
        		{
        			if(tmp.size() + n-i == k) break; // b. 또는 남은 수가 넉넉하지 않다면
        			if(curr <= top) break; // c. curr이 top보다 작거나 같다면 break;
        			tmp.pop_back(); //스택 pop
        			top = tmp.empty() ? '0' : tmp[tmp.size()-1]; //top 갱신
				}
				tmp.push_back(curr); //수를 넣어줌
			}
		}
		else //남은 수들로 n-k를 채워야하는 경우?
			tmp.push_back(curr);
    }
    cout<<tmp.substr(0, k)<<'\n';

    return 0;
}
