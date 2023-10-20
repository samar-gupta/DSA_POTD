/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */




//Company Tags : Google, Twitter, Facebook, Netflix
//Approach-1 (Using stack of NestedInteger objects)
/*
    Always remember, if there is a nested structure and you need to flatten it, 
    stack can help most of the times. For example : flatten linkedlist, doubly linkedlist etc.
*/
class NestedIterator {
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = n-1; i>=0; i--) {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        int num = st.top().getInteger();               //I will always ensure that the top of the stack is an integer
        st.pop();
        return num;
    }
    
    bool hasNext() {                                 //This is always called before next()
        while(!st.empty()) {                        //I will always ensure that the top of the stack is an integer
            NestedInteger curr = st.top();
            if(curr.isInteger())
                return true;

            st.pop();
            vector<NestedInteger>& vec = curr.getList();
            for(int i = vec.size()-1; i>=0; i--) {
                st.push(vec[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
