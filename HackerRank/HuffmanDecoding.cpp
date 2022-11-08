pair<char, string> GetNextCharacter(node* start, string s){ //허프만 부호화 문자열을 복호화
    if(start->data == '\0'){  //부호가 아닌 루트 노드 
        if(s[0]=='0'){ 
            if(start->left != nullptr && start->left->freq != 0){
                return GetNextCharacter(start->left, s.substr(1, s.size()-1));
            }
        }
        else{   
            if(start->right != nullptr && start->right->freq != 0){
                return GetNextCharacter(start->right, s.substr(1, s.size()-1));
            }
        }
    }
    start->freq -= 1; //빈도수를 낮추고 
    return {start->data, s}; //반환
}

void decode_huff(node * root, string s) {
    while(s.size()){ //s가 있을 동안에 연산
        pair<char, string> temp = GetNextCharacter(root, s);
        s = temp.second;
        cout<<temp.first;
    }
}
