//Approach-1 : (Using Deque)
class SpecialQueue {
  public:
    queue<int> q;
    deque<int> minDeque;
    deque<int> maxDeque;

    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        
        while (!minDeque.empty() && minDeque.back() > x) {
            minDeque.pop_back();
        }
        minDeque.push_back(x);
        
        while (!maxDeque.empty() && maxDeque.back() < x) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(x);
    }

    void dequeue() {
        // Remove element from the queue
        if (q.empty()) return;
        
        int front = q.front();
        q.pop();
        
        if (!minDeque.empty() && minDeque.front() == front) {
            minDeque.pop_front();
        }
        
        if (!maxDeque.empty() && maxDeque.front() == front) {
            maxDeque.pop_front();
        }
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        return minDeque.front();
    }

    int getMax() {
        // Get maximum element
        return maxDeque.front();
    }
};


//Approach-2 : (Using multiset)
class SpecialQueue {
  public:
  
    queue<int>q;
    multiset<int> s;   //stores in ordered format
    
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        s.insert(x);
    }

    void dequeue() {
        // Remove element from the queue
        if (!q.empty()) {
            int f = q.front();
            q.pop();
            s.erase(s.find(f)); // erase one occurrence
        }
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        return *s.begin();   //auto it = s.begin(); return *it;
    }

    int getMax() {
        // Get maximum element
        return *s.rbegin();
    }
};
