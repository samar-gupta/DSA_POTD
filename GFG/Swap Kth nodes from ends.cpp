class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        if (!head) return NULL;

        int n = 0;
        Node* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        if (k > n) return head;

        Node* x = head;
        for (int i = 1; i < k; i++) x = x->next;

        Node* y = head;
        for (int i = 1; i < n - k + 1; i++) y = y->next;

        int temp = x->data;
        x->data = y->data;
        y->data = temp;

        return head;
    }
};
