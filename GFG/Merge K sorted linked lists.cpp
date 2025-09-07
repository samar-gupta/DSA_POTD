//Approach-1 : (Using Merge Sort)
class Solution {
public:
    Node* merge(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->data <= l2->data) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }

    Node* sortli(vector<Node*>& li, int st, int end) {
        if (st > end) return nullptr;
        if (st == end) return li[st];

        int mid = st + (end - st) / 2;
        Node* l1 = sortli(li, st, mid);
        Node* l2 = sortli(li, mid + 1, end);

        return merge(l1, l2);
    }

    Node* mergeKLists(vector<Node*>& lists) {
        if (lists.empty()) return nullptr;
        return sortli(lists, 0, static_cast<int>(lists.size()) - 1);
    }
};


//Approach-2 : (Using Min Heap)
class Solution {
  public:
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };
    
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        priority_queue<Node*, vector<Node*>, compare> pq;
    
        for (auto node : arr) {
            if (node != nullptr) pq.push(node);
        }
    
        Node* dummy = new Node(0);
        Node* current = dummy;
    
        while (!pq.empty()) {
            Node* node = pq.top(); pq.pop();
            current->next = node;
            current = current->next;
    
            if (node->next) pq.push(node->next);
        }
    
        return dummy->next;
    }
};



//old
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;  // Min-heap based on node value
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<Node*, vector<Node*>, Compare> pq;
        
        // Push the head of each linked list into the priority queue
        for (Node* node : arr) {
            if (node) {
                pq.push(node);
            }
        }
        
        Node* newHead = nullptr, *tail = nullptr;
        
        while (!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();
            
            if (!newHead) {
                newHead = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
            
            if (temp->next) {
                pq.push(temp->next);
            }
        }
        return newHead;
    }
};
