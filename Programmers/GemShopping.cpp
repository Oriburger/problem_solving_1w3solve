#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
const int MAX = 100001;

unordered_map<string, int> umap;
vector<int> check(MAX, 0);

vector<int> solution(vector<string> gems)
{
    int count = 0; //보석의 종류 개수
    for(const auto &s : gems) //보석 종류를 세고, 보석마다 인덱스를 붙여준다.
    {
        if(umap.count(s)) continue;
        umap[s] = ++count;
    }

    int lo = 0, hi = 0, sum = umap[gems[lo]]; //lo, hi는 0에서 시작
    check[umap[gems[lo]]] = 1; //sum 값과 check 값을 초기화해준다.
    vector<int> answer = {0, MAX};
  
    while(lo != gems.size())
    {   
        if(sum >= (count*(count+1))/2) //모든 보석을 하나 이상 포함하는 경우? 
        {
            if((hi - lo) < (answer[1] - answer[0])) //기존에 찾은 정답보다 범위가 좁다면 
                answer = {lo+1, hi+1}; //정답 갱신
        }

        const int lo_idx = umap[gems[lo]]; 
        if(check[lo_idx] >= 2 || hi == gems.size()-1) //lo의 보석이 2개 이상이거나 hi가 gems.size()-1이라면?
        {
            if(check[lo_idx] > 0) check[lo_idx]-=1; //2개 이상이 아닐때, 0 미만으로 떨어지는 상황 방지
            if(!check[lo_idx]) sum -= lo_idx; //구간에 lo 보석이 없다면? sum에서 뺌
            lo++; //lo를 +1
        }
        else //이외의 상황에선 hi를 우선적으로 올림
        {
            hi++; 
            const int hi_idx = umap[gems[hi]]; 
            if(!check[hi_idx]) sum += hi_idx; //구간에 처음으로 포함된 보석이라면 sum에 더함
            check[hi_idx]+=1; //갯수 갱신
        }
    }

    return answer;
}
