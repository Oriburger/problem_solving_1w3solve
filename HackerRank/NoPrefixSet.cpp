
const int ALPHABETS = 11; //A~J
int toNumber(char ch) { return ch - 'a'; }

struct TrieNode{
    TrieNode* children[ALPHABETS];
    int terminalCnt; bool hasChild; //중복 문자열의 체크를 위해 terminal을 integer로 관리
    
    TrieNode() : terminalCnt(0), hasChild(false){
        memset(children, 0, sizeof(children));
    }
    ~TrieNode(){
        for(int i=0; i<ALPHABETS; i++){
            if(!children[i]) continue;
            delete children[i];
        }
    }
    
    void insert(const char* key){
        if(*key == 0) terminalCnt += 1; //끝에 다다르면 terminalCnt 추가
        else{
            int next = toNumber(*key);
            if(children[next] == NULL) //할당되지 않았다면 할당
                children[next] = new TrieNode();
            hasChild = true; 
            children[next]->insert(key+1); //다음 문자 삽입
        }
    }
    
    bool GetIsGoodSet(){ //좋은 set인지 반환
        if(terminalCnt && hasChild) return false; //만약 문자열이 끝났는데, Child가 있다? -> Prefix 존재
        if(terminalCnt >= 2) return false; //중복 문자열? -> Prefix
        
        for(int i=0; i<ALPHABETS; i++) //자식들에 대해 전체 탐색
            if(children[i] && !children[i]->GetIsGoodSet()) 
                return false;
                
        return true;
    }
    
    bool GetIsBadWords(const char* key, bool hasPrefix = false){ //해당 단어가 나쁜 단어인지 반환 
        if(*key == 0){ //끝에 다다르면
            if(terminalCnt >= 2) return true; //terminalCnt가 2이상인지 판단
            else if(terminalCnt && hasChild) return true; //prefix 여부 판단
            return hasPrefix; 
        }
        int next = toNumber(*key);
        if(children[next]==NULL) return hasPrefix; //자식이 없다면? prefix을 찾았는지 여부 반환
        return children[next]->GetIsBadWords(key+1, hasPrefix ? hasPrefix : terminalCnt); //자식에 대해서도 탐색
    }
};

void noPrefix(vector<string> words) {
    TrieNode * root = new TrieNode();
    
    string badWord = "";
    for(const string& str : words)
    {
        root->insert(str.c_str());
        if(root->GetIsBadWords(str.c_str()) && badWord == "")
            badWord = str;
    }
    
    if(root->GetIsGoodSet()) cout<<"GOOD SET\n";
    else{ 
        cout<<"BAD SET\n";                
        cout<<badWord<<'\n';
    }
}
