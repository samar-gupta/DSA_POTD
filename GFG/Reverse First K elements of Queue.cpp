//GfG Link  : https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
//Approach (Usingh stack to reverse efficiently)
//T.C : O(n)
//S.C : O(k)
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        
        int remaining = q.size() - k; 
        stack<int> st;
        while(k--) {
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        
        while(remaining--) {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};
