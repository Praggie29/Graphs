class LRUCache {
public:
    
    class Node {
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map <int,Node*> mpp;
    int n;

    LRUCache(int capacity) {
         n = capacity;
         head -> next = tail;
         tail -> prev = head;
    }
    
    void addNode ( Node* node ) {
       Node* nodeAfterHead = head -> next;
       head -> next = node;
       node -> next = nodeAfterHead;
       nodeAfterHead -> prev = node;
       node -> prev = head;
    }

    void deleteNode ( Node* node ) {
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }

    int get(int key) {
        if ( mpp.find(key) == mpp.end() ) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        addNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if ( mpp.find(key) != mpp.end() ) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            addNode(node);
            return;
        }
        if ( mpp.size() == n ) {
            Node* node = tail -> prev;
            mpp.erase(node->key);
            deleteNode(node);
            delete node;
        }
        
        Node* node = new Node ( key , value );
        addNode(node);
        mpp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */