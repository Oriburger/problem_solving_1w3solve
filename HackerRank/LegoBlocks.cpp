typedef long long ull;
ull block[1001], answer[1001]; 
const ull INF = 1e9+7;

ull Pow(int val, int p){ // pow(val, p) 연산 과정에 mod 연산을 추가
    ull ret = 1;
    for(int i=0; i<p; i++)
        ret = (ret * val) %INF;
    return ret;
}

int legoBlocks(int n, int m) {
    memset(block, 0, sizeof(block));
    block[1]=1, block[2]=2, block[3]=4, block[4]=8;
    
    for(int i=5; i<=m; i++) //bottom-up : 1 * m 의 전체 벽 제작 경우를 구함
        for(int j=1; j<=4; j++) //block(i) = block(i-4) + block(i-3) + ... + block(i-1) 
            block[i] = (block[i] + block[i-j]) % INF;
    
    for(int i=1; i<=m; i++) //n * m의 경우를 구하기 위해 block에 pow연산을 함
    {
        block[i] = Pow(block[i], n);
        answer[i] = block[i];
    }
    
    for(int i=1; i<=m; i++){ //전체에서 둘로 나눔 : 왼쪽은 완전한 블록, 오른쪽은 전체 경우 / bottom-up으로 구함
        for(int j=1; j<i; j++){
            answer[i] = (answer[i] - (answer[j]*block[i-j])%INF)%INF;
        }
    }
    while(answer[m]<0) answer[m]+=INF; // * 연산으로 인해 값 오버 가능, 양수가 될 때 까지 INF 더함
    
    return answer[m]%INF;
}
