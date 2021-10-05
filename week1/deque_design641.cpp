#include<iostream>
#include<vector>
using namespace std;

class MyCircularDeque {



public:
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        protectNodeHead.next = &protectNodeTail;
        protectNodeTail.pre = &protectNodeHead;
        protectNodeHead.pre = nullptr;
        protectNodeTail.next = nullptr;
      
    }

    
    bool insertFront(int value) {
        if ( size == capacity){ return false;}
        else {
            DualListNode * nodeToInsert = new DualListNode(value);
            DualListNode * curr_front =protectNodeHead.next;
            protectNodeHead.next = nodeToInsert;
            nodeToInsert->pre = &protectNodeHead;           
            nodeToInsert->next = curr_front;
            curr_front->pre = nodeToInsert;            
            ++ size;
            return true;
        }
         
    }   
    
    bool insertLast(int value) {
        if ( size == capacity){ return false;}
        else {
            DualListNode *nodeToInsert = new DualListNode(value);
            DualListNode *curr_back = protectNodeTail.pre;
            
            nodeToInsert->next = &protectNodeTail;
            protectNodeTail.pre = nodeToInsert;
            curr_back->next = nodeToInsert;
            nodeToInsert->pre = curr_back;
            ++ size;


            return true;
        }
         
    }
    
    bool deleteFront() {
        if (size == 0){return false;}
        else{
            DualListNode *nodeToDelete = protectNodeHead.next;
            protectNodeHead.next = nodeToDelete->next;
            nodeToDelete->next->pre =&protectNodeHead;
            --size;
            delete nodeToDelete;
            return true;
        }


    }
    
    bool deleteLast() {
        if (size == 0){return false;}
        else{
            DualListNode *nodeToDelete = protectNodeTail.pre;
            nodeToDelete->pre->next = &protectNodeTail;
            protectNodeTail.pre = nodeToDelete->pre;
            --size;
            delete nodeToDelete;
            return true;
        }
        
        

    }
    
    int getFront() {
        if (size !=0){return protectNodeHead.next->val;}
        else {return -1;}
    }
    
    int getRear() {
        if (size !=0){return protectNodeTail.pre->val;}
        else {return -1;}
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }

    int val;
    int size;
    int capacity;

    struct DualListNode{
    DualListNode(): val(0), pre(nullptr), next(nullptr) {}
    DualListNode(int _val): val(_val), pre(nullptr), next(nullptr) {}
    int val;
    DualListNode * pre;
    DualListNode * next;


 
    };

    DualListNode protectNodeHead;
    DualListNode protectNodeTail;


    void printQueue(){
        DualListNode *head = protectNodeHead.next;
        while (head!=&protectNodeTail){
            cout << head->val<<endl;
            head = head->next;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
template<typename T> void printVector(vector<T>vec){
    for (int i=0; i < vec.size(); ++i){
        cout << vec[i] <<endl;
    }

}
int main(){
    
    MyCircularDeque circularDeque(3); // 设置容量大小为3
    circularDeque.insertLast(1);			        // 返回 true
    circularDeque.insertLast(2);			        // 返回 true
    circularDeque.insertFront(3);
    circularDeque.deleteLast();
    circularDeque.printQueue();


    return 0;
}



// ["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]
// [[3],[1],[2],[3],[4],[],[],[],[4],[]]