//Approach-1 : (Using slow and fast pointer)
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int countLoopNodes(Node* loopNode) {
        int count = 1;
        Node* temp = loopNode->next;

        while (temp != loopNode) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return countLoopNodes(slow);
            }
        }
        return 0;
    }
};


//old
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                int count =1;
                Node* temp = slow->next;
                while(temp!=slow){
                    count++;
                    temp=temp->next;
                }
                return count;
            }
        }
        return 0;
    }
};
