class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           int mod = 1e9 + 7;
           
           int n = 0;
           string str = "";
           long long unsigned int power = 1;
           long long unsigned int ans = 0;
           
           Node* temp = head;
           
           while(temp) {
               n++;
               str += char(temp->data);
               temp = temp->next;
           }
           
           for(int i = n-1; i>=0; i--) {
               int x = int(str[i]);
               ans = (ans + (x*power)) % mod;
               power = (power * 2) % mod;
           }
           
           return ans % mod;
        }
};
