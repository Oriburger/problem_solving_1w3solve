#include <iostream>
using namespace std;

int input[2][10];
int score[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=0; i<2; i++)
		for(int j=0; j<10; j++)
			cin>>input[i][j];
	
	for(int i=0; i<10; i++)
	{
		if(input[0][i] > input[1][i]) score[0]++;
		else if(input[0][i] < input[1][i]) score[1]++;
	}

	cout<<(score[0]==score[1] ? "D" : (score[0]>score[1] ? "A" : "B" ))<<'\n';

	return 0;
}
