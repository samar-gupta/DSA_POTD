class kQueues {

  public:
    int size ,N;
    unordered_map<int,queue<int>>mp;
    kQueues(int n, int k) {
        // Initialize your data members
        size = 0,N = n;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        mp[i].push(x);
        size++;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        int res = -1;
        if(!mp[i].empty()){
            res = mp[i].front();
            mp[i].pop();
            size--;
        }
        return res;
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return mp[i].size()==0;
    }

    bool isFull() {
        // check if array is full
        return size == N;
    }
};
