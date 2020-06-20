#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n, aCnt=0, answer=0; //문자열 구성하는 알파벳 종류 개수 
int alphabet[26];
vector<string> words;
vector<int> num;
vector<bool> visited;

void Answer(int toPick)
{
	if(toPick == 0)
	{
		int j=0;
		
		for(int i=0; i<aCnt; i++)
		{
			while(1)
			{
				if(alphabet[j]==0) j++;
				else break; 
			}
			
			alphabet[j++] = num[i];
		}
		
		
	//	for(int i=0; i<aCnt; i++)
	//		cout<<num[i]<<' ';
	//	cout<<'\n';
		
		
		int sum=0;
		for(int i=0; i<words.size(); i++)
		{
			for(int j=words[i].length()-1; j>=0; j--)
			{
				sum += alphabet[ words[i][j] - 'A' ] * pow(10, j);
			}
		}
		
		if(num[0]==9)
		{
			cout<<sum<<'\n';
			
			for(int i=0; i<aCnt; i++)
				cout<<alphabet[i]<<' ';
			cout<<'\n';
		}
		
		answer = max(answer, sum);
		
		return;
	}
	
	for(int i=9; i>=10-aCnt; i--)
	{	
		if(visited[i]) continue;
		
		visited[i]=true;
		num.push_back(i);
		Answer(toPick-1);
		visited[i]=false;
		num.pop_back();
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	visited.resize(11);
	for(int i=0; i<n; i++)
	{
		string input;
		cin>>input;
		
		for(int j=0; j<input.length(); j++)
			alphabet[ input[j]-'A' ] = true;
		
		words.push_back(input);
	}
	
	for(int i=0; i<26; i++)
		if(alphabet[i]==true) aCnt++;
	
	Answer(aCnt);
	
	cout<<answer<<'\n';
	
	return 0;
} 
