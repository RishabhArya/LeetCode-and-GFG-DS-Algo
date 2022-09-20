class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next, *prev;
        Node(int _key,int _val){
            key = _key;
            val = _val;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>m;
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    void deleteNode(Node* deleteNode){
        Node* deletePrev = deleteNode->prev;
        Node* deleteNext = deleteNode->next;
        deletePrev->next = deleteNext;
        deleteNext->prev = deletePrev;
    }
    LRUCache(int capacity) {
        cap = capacity;
        head->prev = NULL;
        head->next = tail;
        tail->prev = head;
        tail->next = NULL;
    }
    
    int get(int key) {
     if(m.find(key)!=m.end())
        {
            Node* resnode=m[key];
            int res=resnode->val;
            deleteNode(resnode);
            addNode(resnode);
            m[key]=head->next;
            return res;
        }
        return -1;
            
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* toDelete = m[key];
            deleteNode(toDelete);
            addNode(new Node(key,value));
            m[key] = head->next;
        }
        else if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
            addNode(new Node(key,value));
            m[key] = head->next;
        }
        else{
        addNode(new Node(key,value));
        m[key] = head->next;}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */