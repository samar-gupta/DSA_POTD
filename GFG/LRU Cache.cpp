class LRUCache {
  private:
      unordered_map<int, int> mp;
      vector<int> v;
      int n;
    
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        n=cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        auto it=find(v.begin(), v.end(), key);
           if (it!=v.end()){
               v.erase(it);
               v.push_back(key);
               return mp[key];
            }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        auto it=find(v.begin(), v.end(), key);
        if (it==v.end()){
            if (n==0){
                v.erase(v.begin());
                v.push_back(key);
                mp[key]=value;
            }
            else{
                v.push_back(key);
                mp[key]=value;
                n--;
            }
        }
        else{
            v.erase(it);
            v.push_back(key);
            mp[key]=value;
        }
    }
};
