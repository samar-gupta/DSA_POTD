//Approach-1 :
/*
1. Create an empty stack (or vector/list).
2. Traverse the array from left to right.
3. For each element:
     Check if stack is not empty AND top element has opposite sign.
     If yes → resolve conflict:
        If absolute values are equal → remove both
        Else → keep the one with larger absolute value
     Keep resolving until no more conflicts.
4. If current element survives → push it into stack.
5. Finally, return the stack as the result.
*/
class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        vector<int> st;
        
        for (int x : arr) {
            bool alive = true;
            
            while (!st.empty() && alive && (st.back() * x < 0)) {
                int top = st.back();
                
                if (abs(top) == abs(x)) {
                    st.pop_back();
                    alive = false;
                } else if (abs(top) > abs(x)) {
                    alive = false;
                } else {
                    st.pop_back();
                }
            }
            
            if (alive) st.push_back(x);
        }
        
        return st;
    }
};



//Approach-1 :
class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        vector<int> s;

        // Traverse each element
        for (int element : arr) {

            // Process while there is a collision (opposite signs)
            while (!s.empty() && s.back() * element < 0) {

                int top = s.back();

                // Top has larger absolute value, keep top
                if (abs(top) > abs(element)) {
                    element = top;
                    s.pop_back();
                }

                // Current element has larger absolute value
                // keep current element
                else if (abs(top) < abs(element)) {
                    s.pop_back();
                }

                // Both have same absolute value, both removed
                else {
                    s.pop_back();
                    element = 0;
                    break;
                }
            }

            // If current element still exists, push into stack
            if (element != 0)
                s.push_back(element);
        }

        return s;
    }
};
