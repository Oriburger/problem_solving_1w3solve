using namespace std;

long long solution(int price, int money, int count)
{
    long long tmp=0;
    for(int i=1; i<=count; i++)
        tmp += price*i;

    return (tmp > money ? tmp - money: 0);
}
