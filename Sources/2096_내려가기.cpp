#include <iostream>
using namespace std;

int n, a1[2], b1[2], c1[2]; //[0] - max의 연산, [1] - min의 연산
int a2[2], b2[2], c2[2];

int main()
{
	ios::sync_with_stdio(false) ;
	cin.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>a1[0]>>b1[0]>>c1[0];
		
		//min값을 위한 입력 값 복사
		a1[1]=a1[0];
		b1[1]=b1[0];
		c1[1]=c1[0]; 
		
        //max값 연산
		a1[0] += max(a2[0], b2[0]);
		c1[0] += max(b2[0], c2[0]);
		b1[0] += max(a2[0], max(b2[0], c2[0]));
            
        //min값 연산
		a1[1] += min(a2[1], b2[1]);
		c1[1] += min(b2[1], c2[1]);
		b1[1] += min(a2[1], min(b2[1], c2[1]));
            
        //연산값 갱신
		a2[0]=a1[0]; b2[0]=b1[0]; c2[0]=c1[0];
		a2[1]=a1[1]; b2[1]=b1[1]; c2[1]=c1[1];
	}

	cout<<max(a2[0], max(b2[0], c2[0]))<<' ';
	cout<<min(a2[1], min(b2[1], c2[1]))<<'\n';

	return 0;
}
