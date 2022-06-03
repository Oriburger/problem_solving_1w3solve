#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
private:
    int * Queue;
    int front;
    int rear; 
    int capacity; 
public:
    CircularQueue(int c) : capacity(c)
    {
        Queue = new int[c];
        front = rear = 0;
    }
    
    void push(int val)
    {
        if((rear+1)%capacity == front)
        {
            int * newQueue = new int[capacity*2];
            int start = (front + 1) % capacity; 
            if(start < 1) copy(Queue+start, Queue+start+capacity-1, newQueue);
            else
            {
                copy(Queue+start, Queue+capacity, newQueue);
                copy(Queue, Queue+rear+1, newQueue+capacity-start);
            }
            
            front = 2 * capacity - 1; //front는 다시 앞의 한칸 앞을 가리킴 
            rear = capacity - 2;
            capacity*=2;
            delete[] Queue;
            Queue = newQueue; 
        }
        rear = (rear+1)%capacity;
        Queue[rear] = val; 
    }
    /*
               |           |
     0 1 2 3 4 5 - - - - - -
    */
    void pop()
    {
        front = (front+1)%capacity; 
        Queue[front] = 0;
    }
    
    int size()
    {
        if(empty()) return 0;
        if(front > rear) return capacity - front + rear;
        return rear - front;
    }
    
    inline bool empty(){ return front == rear; }  
    
    int getFront(){ return empty() ? -1 : Queue[(front+1)%capacity]; }
    
    int getBack(){ return empty() ? -1 : Queue[rear];}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin>>n;
    
    CircularQueue cq(2);
    
    while(n--)
    {
        string cmd; 
        cin>>cmd;
        
        if(cmd == "push")
        {
            int val; cin>>val;
            cq.push(val);
        }
        else if(cmd == "pop")
        {
            cout<<cq.getFront()<<'\n';
            if(!cq.empty()) cq.pop();
        }
        else if(cmd == "front")
            cout<<cq.getFront()<<'\n';
            
        else if(cmd == "back")
            cout<<cq.getBack()<<'\n';
            
        else if(cmd == "empty")
            cout<<(cq.empty() ? 1 : 0)<<'\n';
            
        else if(cmd == "size")
             cout<<cq.size()<<'\n';
    }
    
    return 0;
}
