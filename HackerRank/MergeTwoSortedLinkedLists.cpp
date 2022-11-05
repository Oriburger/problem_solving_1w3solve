SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1 == nullptr || head2 == nullptr) return head1 == nullptr ? head2 : head1;
    
    SinglyLinkedListNode *retHead, *retTail;
    retHead = retTail = nullptr;
    
    //head1 && head2 둘 다 차있을때
    while(head1!=nullptr && head2!=nullptr){
        if(retHead == nullptr){ //초기 : retHead, retTail 세팅
            if(head1->data < head2->data) retHead = head1, head1 = head1->next; 
            else retHead = head2, head2 = head2->next;
            retTail = retHead; 
        } 
        else{ //일반적인 경우 : retTail을 통해 하나씩 이어나감
            if(head1->data < head2->data){ 
                retTail->next = head1;
                retTail = retTail->next;
                head1 = head1->next;
            }
            else {
                retTail->next = head2;
                retTail = retTail->next;
                head2 = head2->next;
            }
        }
    }
    
    if(head1 == nullptr){ //남은게 있다면? 바로 
        retTail->next = head2;
    }
    else if(head2 == nullptr){
        retTail->next = head1;
    }
    
    return retHead;
}
