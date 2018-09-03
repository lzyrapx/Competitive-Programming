class MyLinkedList {
public:
    /** Initialize your data structure here. */
    vector<int>ve;
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= ve.size()) {
            return -1;
        }
        return ve[index];
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ve.insert(ve.begin(), val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ve.push_back(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > ve.size()) {
            return;
        }
        if(index == ve.size()) {
            ve.push_back(val);
            return;
        }
        ve.insert(ve.begin() + index, val);
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= ve.size()) {
            return;
        }
        ve.erase(ve.begin() + index);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */