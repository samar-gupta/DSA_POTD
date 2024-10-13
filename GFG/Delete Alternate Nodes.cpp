class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Code here
        while(head && head->next) {
            head->next = head->next->next;
            head = head->next;
        }
    }
};
