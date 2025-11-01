//Company Tags  : AMAZON
//Leetcode Link : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

//Approach (Using Simple straight forward approach) (asked again in potd, getting runtime error)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end (nums)); //inserted
        
        
        //Handle the Head
        while(head != NULL && st.find(head->val) != st.end()) {
            ListNode* temp = head;
            head = head->next;
            delete(temp); //deleting the hanging node
        }
        
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL) {
            if(st.find(curr->next->val) != st.end()) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next; //curr->next is updated
                delete(temp); //deleting hanging node
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};


//Accepted and Working version
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end (nums)); //inserted
        
        
        //Handle the Head
        while(head != NULL && st.find(head->val) != st.end()) {
            //ListNode* temp = head;
            head = head->next;
            //delete(temp); //deleting the hanging node
        }
        
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL) {
            if(st.find(curr->next->val) != st.end()) {
                //ListNode* temp = curr->next;
                curr->next = curr->next->next; //curr->next is updated
                //delete(temp); //deleting hanging node
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};


//Approach (Using Simple straight forward approach) (totally same as above)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end(nums));
        ListNode* prev = NULL;
        ListNode* curr = head;


        while (curr != NULL && st.count(curr->val)) {
            head = curr->next;
            curr = head;
        }

        while (curr != NULL) {
            int currVal = curr->val;
            if (!st.count(currVal)) {
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
