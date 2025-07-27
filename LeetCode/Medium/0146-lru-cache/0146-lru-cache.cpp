
class Node {
public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int x, int y) {
        key = x;
        val = y;
        next = nullptr;
        prev = nullptr;
    }
    Node() {
        val = 0;
        key = 0;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> values;
    int size;

    Node* moveToTail(int key, int val) {
        if(tail -> key == key){
            return tail;
        }
        if (head->key == key) {
            head -> val = val;
            Node* temp = head;
            head -> next -> prev = nullptr;
            head = head -> next;
            tail -> next = temp;
            temp -> prev = tail;
            temp -> next = nullptr;
            tail = temp;

            return tail;
        }
        Node* keyNode = values[key];
        keyNode->prev->next = keyNode->next;
        keyNode->next->prev = keyNode->prev;
        keyNode->prev = tail;
        keyNode->next = nullptr;
        tail->next = keyNode;
        tail = keyNode;
        return tail;
    }

    Node* insertAtTail(int key, int val) {

        if (head == nullptr) {
            head = new Node(key, val);
            tail = head;
            return tail;
        }
        Node* newNode = new Node(key, val);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return tail;
    }
    void removeAtHead() {
        if (head == tail) {
            Node* temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
            return;
        }

        Node* newHead = head->next;
        Node* temp = head;
        head = newHead;
        head->prev = nullptr;
        delete temp;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (values.find(key) == values.end()) {
            return -1;
        }

        moveToTail(key, values[key] -> val);
        return values[key] -> val;
    }

    void put(int key, int value) {
        Node* keyNode;
        if (values.find(key) != values.end()) {
            keyNode = moveToTail(key, value);
            keyNode -> val = value;
        } else if (capacity > size) {
            keyNode = insertAtTail(key, value);
            size++;
        } else {
            values.erase(head->key);
            removeAtHead();
            keyNode = insertAtTail(key, value);
        }
        values[key] = keyNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */