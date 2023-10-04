/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SerANdwnELI
    Company Tags                : Netflix, Google, Meta
    Leetcode Link               : https://leetcode.com/problems/design-hashmap/
*/

/************************************ C++ ************************************/

//Approach-1 : Brute Force - Using vector of size 10^6+1
//This solution is not good because we are taking huge space which might not be accepted in interviews
class MyHashMap {
public:
    vector<int> vec;
    int sz;
    
    MyHashMap() {
        sz = 1e6+1;
        
        vec.resize(sz);
        
        fill(vec.begin(), vec.end(), -1);
    }
    
    void put(int key, int value) {
       vec[key] = value; 
    }
    
    int get(int key) {
       return vec[key] ;
    }
    
    void remove(int key) {
      vec[key]  =-1;
    }
};


//Approach-2 : Using chaining approach and using less space
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<list<pair<int, int>>> bucket;
    int size = 10000;
    MyHashMap() {
        bucket.resize(size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int bucket_no = key%size;
        auto& chain = bucket[bucket_no];
        for(auto& it:chain) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int bucket_no = key%size;
        auto& chain = bucket[bucket_no];
        if(chain.empty())
            return -1;
        
        for(auto& it:chain) {
            if(it.first == key)
                return it.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int bucket_no = key%size;
        auto& chain = bucket[bucket_no];
        
        /*Traditional way to remove from a list*/
        for (auto it=chain.begin(); it!=chain.end(); ) {
            if(it->first == key) {
                chain.erase(it);
                return;
            }
            it++;
        }
        
        /*Smart way to remove from a list*/
        //chain.remove_if([key](auto it) { return it.first == key; });
    }
};
