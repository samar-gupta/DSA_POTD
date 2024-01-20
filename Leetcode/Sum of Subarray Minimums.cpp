//Company Tags    : Facebook, Amazon, Google
//Leetcode Link   : https://leetcode.com/problems/sum-of-subarray-minimums/


//Approach-1 (Simple Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int M = 1e9 + 7;
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        long result = 0;

        for (int i = 0; i < n; i++) {
            int minVal = arr[i];

            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                result = (result + minVal) % M;
            }
        }

        return result;
    }
};






//Approach - 2
//T.C : O(n)
//S.C : O(n)
typedef unsigned long long ll;
class Solution {
public:
    
    //This is just we are finding next smaller to each element to left
    //Similar : Leetcode-84
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    //This is just we are finding next smaller to each element to right
    //Similar : Leetcode-84
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) //non-strictly less
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n); //Next smaller to left
        vector<int> NSR = getNSR(arr, n); //Next smaller to right
        
        
        ll sum = 0;
        int M = 1e9+7;
        for(int i = 0; i<n; i++) {
            ll d1 = i - NSL[i]; //distance to nearest smaller to left from i
            
            ll d2 = NSR[i] - i; //distance to nearest smaller to right from i
            
            /*
                we have d1 numbers in the left and d2 numbers in the right
                i.e. We have d1 options to start from the left of arr[i] 
                and d2 options to end in the right of arr[i]
                so the total options to start and end are d1*d2
            */
            ll total_ways_for_i_min = d1*d2;
            ll sum_i_in_total_ways  = arr[i] * (total_ways_for_i_min);
            
            sum  = (sum + sum_i_in_total_ways)%M;
        }
        
        return sum;
        
    }
};
