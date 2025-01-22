//Approach-1 : 
class Solution {
  public:
    Node* reverseList(struct Node* head) {
        //CodeGenius
        Node *curr=head, *prev=NULL, *next=curr->next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        //CodeGenius
        num1=reverseList(num1);
        num2=reverseList(num2);
        int carry=0;
        Node* ans=new Node(0);
        Node* first=ans;
        while(num1 || num2 || carry){
            int sum=carry;
            if(num1){
                sum+=num1->data;
                num1=num1->next;
            }
            if(num2){
                sum+=num2->data;
                num2=num2->next;
            }
            ans->data=(sum%10);
            carry=sum/10;
            if(num1 || num2 || carry){
                ans->next=new Node(0);
                ans=ans->next;
            }
        }
        reverseList(first);
        while(ans->data==0 && ans->next) ans=ans->next;
        return ans;
    }
};


//Approach-2 : (without using reverse function for result linked list)
class Solution {
  public:
     Node* addTwoLists(Node* num1, Node* num2) {
        // Reverse both lists
        Node* l1 = reverseList(num1);
        Node* l2 = reverseList(num2);
        Node* curr = nullptr;
        int carry = 0;

        // Add numbers represented by the two linked lists
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int v1 = (l1 != nullptr) ? l1->data : 0;
            int v2 = (l2 != nullptr) ? l2->data : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            Node* tmp = new Node(sum % 10);
            tmp->next = curr;
            curr = tmp;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        // Remove leading zeros if any
        while (curr != nullptr && curr->data == 0) {
            curr = curr->next;
        }

        return curr;
    }

private:
    Node* reverseList(Node* head) {
        Node* tmpHead = nullptr;

        while (head != nullptr) {
            Node* nex = head->next;
            if (tmpHead == nullptr) {
                tmpHead = head;
                tmpHead->next = nullptr;
            } else {
                head->next = tmpHead;
                tmpHead = head;
            }
            head = nex;
        }

        return tmpHead;
    }
};
