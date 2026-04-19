
class LRUCache {
  public:
  struct node{
    int key;
    int value;
    node* next;
    node *prev;
    node(int k , int v){
        key = k;
        value = v;
        next = prev = NULL;
    }
  };
  int cap;
  unordered_map<int , node*> mp;
  node *head;
  node *tail;
  LRUCache(int capacity) {
   cap = capacity;
    head = new node(-1,-1);
    tail = new node(-1 ,-1);
    head->next = tail;
    tail->prev = head;
  }
  void remove(node* nodetoremove){
    nodetoremove->prev->next = nodetoremove->next;
    nodetoremove->next->prev = nodetoremove->prev;
  }
  void insert(node* nodetoinsert){
    nodetoinsert->prev = tail->prev;
    nodetoinsert->next = tail;
    tail->prev->next = nodetoinsert;
    tail->prev = nodetoinsert;    
  }
  int get(int key){
    if(mp.find(key) == mp.end()){
        return -1;
    }
     node* curr = mp[key];
     remove(curr);
     insert(curr);
    return curr->value;
  }
  void put(int key , int val){
    if(mp.find(key) != mp.end()){
        node* curr = mp[key];
        curr->value = val;
        remove(curr);
        insert(curr);
        return;
    }
    else{
        if(mp.size() == cap){
            node* lru = head->next;
            int k  = lru->key;
            mp.erase(k);
            remove(lru);
            delete(lru);
        }
        node *curr = new node(key,val);
        insert(curr);
        mp[key] = curr;
    }
  }
};
