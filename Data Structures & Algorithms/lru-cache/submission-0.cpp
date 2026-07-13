class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int k, int v) {key = k; value = v; next = nullptr; prev = nullptr;}  
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;
public:
    LRUCache(int capacity) {
     this->capacity = capacity;

     head = new Node(0,0);
     tail = new Node(0,0);

     head->next = tail;
     tail->prev = head;    
    }

    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }
    void removeNode(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void moveToFront(Node* node){
        removeNode(node);
        addToFront(node);
    }
    Node* removeTail(){
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
    int get(int key) {
        if(cache.count(key) == 0) return -1;
        Node* node = cache[key];
        moveToFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
            return;
        }
        Node* node = new Node(key, value);
        addToFront(node);
        cache[key] = node;
        if (cache.size() > capacity){
            Node* last = removeTail();
            cache.erase(last->key);
            delete last;
        }

    }
};
