//Approach - (Using Set)
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        int count = 0;
        unordered_set<int> set;

        // Insert all elements of the first linked list into a set
        while (head1 != NULL) {
            set.insert(head1->data);
            head1 = head1->next;
        }

        // Traverse the second linked list
        while (head2 != NULL) {
            // Check if (x - current node's data) exists in the set
            if (set.find(x - head2->data) != set.end()) {
                // If found, increment the count
                count++;
            }
            head2 = head2->next;
        }
        return count;
    }
};



//Approach - (Using Map)
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_map<int, int> freq;
        while (head1) {
            freq[head1->data]++;
            head1 = head1->next;
        }
    
        int ans = 0;
        while (head2) {
            int complement = x - head2->data;
            if (freq.count(complement) > 0) {
                ans += freq[complement];
            }
            head2 = head2->next;
        }
    
        return ans;
    }
};
