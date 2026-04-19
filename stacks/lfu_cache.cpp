class LFUCache {
public:
    struct node{
        int key;
        int value;
        int freq;
        node* next;
        node* prev;
        node(int k , int val){
            key = k;
            value = val;
            next = prev = nullptr;
            freq = 1;
        }
    };

    struct DLL{
        int size;
        node* head;
        node* tail;
        DLL(){
            size = 0;
            head = new node(-1,-1);
            tail = new node(-1,-1);
            head->next = tail;
            tail->prev = head;
        }
        void addlast(node* nodetobeadded){
            nodetobeadded->next = tail;
            nodetobeadded->prev = tail->prev;
            tail->prev->next = nodetobeadded;
            tail->prev = nodetobeadded;
            size++;
        }
        void remove(node* curr ){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            size--;
        }
        node* removefirst(){
            if(size == 0) return nullptr;
            node* temp = head->next;
            remove(temp);
            return temp;
        }
    };

    int cap;
    int minfreq;

    unordered_map<int, DLL*> freqnodes;
    unordered_map<int, node*> nodeaddress;

    LFUCache(int capacity) {
        cap = capacity;
        minfreq = 0;
    }

    void updatefreq(node* curr){
        int freq = curr->freq;
        freqnodes[freq]->remove(curr);
        if(freq == minfreq && freqnodes[freq]->size == 0){
            minfreq++;
        }
        curr->freq++;
        if(freqnodes.find(curr->freq) == freqnodes.end()){
            freqnodes[curr->freq] = new DLL();
        }
        freqnodes[curr->freq]->addlast(curr);
    }

    int get(int key) {
        if(nodeaddress.count(key) == 0) return -1;
        node* curr = nodeaddress[key];
        int val = curr->value;
        updatefreq(curr);
        return val;
    }

    void put(int key, int value) {
        if(cap == 0) return;

        if(nodeaddress.count(key)){
            node* curr = nodeaddress[key];
            curr->value = value;
            updatefreq(curr);
            return;
        }

        if(nodeaddress.size() == cap){
            DLL* list = freqnodes[minfreq];
            node* toremove = list->removefirst();
            nodeaddress.erase(toremove->key);
        }

        node* newnode = new node(key,value);
        minfreq = 1;

        if(freqnodes.find(1) == freqnodes.end()){
            freqnodes[1] = new DLL();
        }

        freqnodes[1]->addlast(newnode);
        nodeaddress[key] = newnode;
    }
};
