/*
Steps :-
1. Iterate over the linked list 
   and check if the value of the node is prime or not.

2. If the node's value is prime 
    then continue iterarting.

3. If the node's value is not prime 
    then simultaneously increase and decrease the node's value 
    and check whether any of the increased and decreased value is prime or not.

4. If both the increased and decreased value are prime 
    then put the node's value with the decreased one 
    because we have to put the minimum of the values which are at the nearest equal distance from the node's original value;
*/
class Solution {
  public:
    bool isPrime(int n){
        if(n==1 or n<=0) return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    Node *primeList(Node *head){
        //code here
        Node* root=head;
        while(head!=NULL){
            int temp = head->val;
            
            if(isPrime(temp)){
                head = head->next;
                continue;
            }
            else{
                int temp2 = temp;
                while(!isPrime(temp) and !isPrime(temp2)){
                    temp++;
                    temp2--;
                }
                
                if(isPrime(temp) and isPrime(temp2)){
                    head->val = min(temp,temp2);
                }
                else if(isPrime(temp2)){
                    head->val = temp2;
                }
                else{
                    head->val = temp;
                }
                
                head = head->next;
            }
        }
        return root;
    }
};
