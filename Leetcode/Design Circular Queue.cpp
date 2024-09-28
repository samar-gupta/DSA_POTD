//Company Tags  : Google, Facebook, Apple, Goldman Sachs, Amazon
//Leetcode Link : https://leetcode.com/problems/design-circular-queue/

//Approach-1 (Using Array)
//T.C : O(1)
//S.C : O(k)
class MyCircularDeque {
public:
    vector<int> deq;
    int K;
    int front;
    int rear;
    int currentCount;

    MyCircularDeque(int k) {
        K = k;
        deq = vector<int>(K, 0);
        front = 0;
        rear  = K-1;
        currentCount = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }

        front = (front - 1 + K) % K;
        deq[front] = value;
        currentCount++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }

        rear = (rear + 1) % K;
        deq[rear] = value;
        currentCount++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }
        front = (front + 1) % K;
        currentCount--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }

        rear = (rear - 1 + K) % K;
        currentCount--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) {
            return -1;
        }        

        return deq[front];
    }
    
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return deq[rear];
    }
    
    bool isEmpty() {
        return currentCount == 0;
    }
    
    bool isFull() {
        return currentCount == K;
    }
};



//Approach-2 (Using Double Linked List)   (list has all features front->push,pop and rear->push,pop)
//T.C : O(1)
//S.C : O(k)
class MyCircularDeque {
private:
    list<int> deq;  // Using list instead of vector
    int cnt;        // Current number of elements
    int k;          // Maximum capacity
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        this->k = k;   // Assign capacity
        cnt = 0;       // Initialize count to 0
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (cnt == k) {
            return false; // If the deque is full, insertion fails
        }
        deq.push_front(value); // Insert at the front of the deque
        ++cnt;                 // Increment count
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (cnt == k) {
            return false; // If the deque is full, insertion fails
        }
        deq.push_back(value); // Insert at the rear of the deque
        ++cnt;                // Increment count
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (cnt == 0) {
            return false; // If the deque is empty, deletion fails
        }
        deq.pop_front();  // Remove the front element
        --cnt;            // Decrement count
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (cnt == 0) {
            return false; // If the deque is empty, deletion fails
        }
        deq.pop_back();   // Remove the last element
        --cnt;            // Decrement count
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (cnt == 0) {
            return -1; // If the deque is empty, return -1
        }
        return deq.front(); // Return the front element
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (cnt == 0) {
            return -1; // If the deque is empty, return -1
        }
        return deq.back(); // Return the last element
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt == 0; // Return true if the deque is empty
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt == k; // Return true if the deque is full
    }
};
