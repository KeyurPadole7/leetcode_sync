class LRUCache {
public:
    class Node{
    public:
        int key;
        int value;
        Node* next = nullptr;
        Node* prev = nullptr;

        Node(int k, int v){
            key = k; value = v;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*> m;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertnode(Node* curr){
        Node* oldtemp = head->next;
        head->next = curr;
        curr->prev = head;
        oldtemp->prev = curr;
        curr->next = oldtemp;
        m[curr->key] = curr;
    }

    void delnode(Node* curr){
        m.erase(curr->key);
        Node* lnode = curr->prev;
        Node* rnode = curr->next;

        lnode->next = rnode;
        rnode->prev = lnode;

        m.erase(curr->key);
        delete(curr);
    }
    
    int get(int key) {
        if(!m.contains(key)) return -1;
        Node* curr = m[key];
        int val = curr->value;

        delnode(curr);
        Node* nwnode = new Node(key, val);
        insertnode(nwnode);

        return val;
    }
    
    void put(int key, int value) {
        if(m.contains(key)){
            Node* curr = m[key];
            delnode(curr);
        }
        if(m.size() == cap){
            Node* curr = tail->prev;
            delnode(curr);
        }

        Node* curr = new Node(key, value);
        insertnode(curr);

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */