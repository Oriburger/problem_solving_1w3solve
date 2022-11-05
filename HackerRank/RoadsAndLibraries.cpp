long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    vector<vector<int> > adj(n+1, vector<int>()); //정점은 1~n
    vector<bool> visited(n+1, false); 
    queue<int> q; 
    long ret = 0;
    
    for(vector<int>& edge : cities){ //인접 리스트화 
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
       
    for(int i=1; i<=n; i++){ //모든 정점에 대해 탐색
        if(visited[i]) continue; 
        
        int cnt = 0; //각 CC(Connected Component)의 개수
      
        q.push(i); 
        visited[i] = true;
        while(!q.empty()){ //BFS를 돌며 각 CC의 원소 개수를 센다
            int curr = q.front();
            q.pop();
            cnt += 1;
            
            for(int& next : adj[curr]){
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }
        //본 CC의 모든 정점에 도서관을 짓는 것 vs 하나만 짓고 최소 수의 간선들을 연결하는 비용 비교
        if(cnt*c_lib < (cnt-1)*c_road + c_lib) ret += cnt*c_lib;
        else ret += (cnt-1)*c_road + c_lib;
    }
    return ret;
}
