int cookies(int k, vector<int> cookies) { 
    priority_queue<int, vector<int>, greater<int> > pq; //minimum_heap
    for(auto& c : cookies){
        pq.push(c);
    }
    
    int cnt = 0;
    while(!pq.empty()){ 
        int top[2] = {-1, -1};
        for(int i=0; i<2; i++){
            if(pq.empty()) return top[0] >= k ? cnt : -1; //pq가 비었다면? 마지막 뽑은 쿠키의 값을 판단
            top[i] = pq.top();
            pq.pop();
        }
        if(top[0] >= k) return cnt;
        
        cnt+=1;
        pq.push(top[0] + 2*top[1]);
    }
    return pq.empty() ? -1 : cnt;
}
