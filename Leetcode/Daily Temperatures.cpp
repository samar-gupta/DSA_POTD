//Company Tags     : Google, Meta, Tokopedia
//Leetcode Link    : https://leetcode.com/problems/daily-temperatures/

//Approach - 1 : (Brute Force) (T.L.E)
//T.C : O(n^2)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        vector<int> result(n);
        
        for(int i = 0; i<n; i++) {
            
            int days = 0;
            for(int j = i+1; j<n; j++) {
                if(temperatures[j] > temperatures[i]) {
                    days = j - i;
                    break;
                }
            }
            
            result[i] = days;
        }
        
        return result;
    }
};





//Approach - 2 : (Using Stack) (Monotonic behaviour {just greater element}) 
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        
        vector<int> result(n);
        
        for(int i = n-1; i>=0; i--) {
            
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            
            if(st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top() - i;  //days
            }
            
            st.push(i);
        }
        
        return result;
    }
};
