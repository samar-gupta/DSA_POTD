//Approach-1 : (Using array to store frequency)
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if (head == nullptr) return head;
        int count[3] = {0, 0, 0};

        Node* temp = head;
        while (temp != nullptr) {
            count[temp->data]++;
            temp = temp->next;
        }

        temp = head;
        for (int i = 0; i < 3; i++) {
            while (count[i]-- > 0) {
                temp->data = i;
                temp = temp->next;
            }
        }
        return head;
    }
};


//Approach-2 : (3 Pointer) (Good)
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if (head == nullptr || head->next == nullptr) return head;

        Node* zeroDummy = new Node(0);
        Node* oneDummy  = new Node(0);
        Node* twoDummy  = new Node(0);

        Node* zero = zeroDummy;
        Node* one  = oneDummy;
        Node* two  = twoDummy;

        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else { 
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        zero->next = (oneDummy->next != nullptr) ? oneDummy->next : twoDummy->next;
        one->next  = twoDummy->next;
        two->next  = nullptr;

        Node* newHead = zeroDummy->next;

        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;

        return newHead;
    }
};



//old
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* temp=head;
        int zero=0, one=0, two=0;
        while(temp){
            if(temp->data==0) zero++;
            else if(temp->data==1) one++;
            else two++;
            
            temp=temp->next;
        }
        
        temp=head;
        while(zero){
            temp->data=0;
            zero--;
            temp=temp->next;
        }
        while(one){
            temp->data=1;
            one--;
            temp=temp->next;
        }
        while(two){
            temp->data=2;
            two--;
            temp=temp->next;
        }
        return head;
    }
};
