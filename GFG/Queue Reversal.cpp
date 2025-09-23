//Approach-1 : (Using Stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int> st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
    }
};


//Approach-2 : 
//T.C : O(n)
//S.C : O(n)  -  (Recursion stack space)
class Solution {
  public:
    void helper(queue<int> &q) {
        if(q.empty()) 
            return;
        int x=q.front();
        q.pop();
        helper(q);
        q.push(x);
    }
    
    void reverseQueue(queue<int> &q) {
        // code here
        helper(q);
    }
};
