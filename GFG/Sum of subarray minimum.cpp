// Approach 1: Brute force by iterating all subarrays and tracking the minimum element for each
// Time Complexity: O(n^2) due to the nested loops over start and end indices of subarrays
// Space Complexity: O(1) uses only a few integer variables regardless of input size
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n      = arr.size();      // total number of elements in the array
        int result = 0;               // accumulator for sum of subarray minimums

        // iterate over all possible starting points of subarrays
        for (int i = 0; i < n; i++) {
            int mini = arr[i];        // initialize minimum to the first element of the subarray
            // extend the subarray one element at a time
            for (int j = i; j < n; j++) {
                // update the minimum for the current subarray [i..j]
                mini = min(mini, arr[j]);

                // add the current minimum to the result
                result += mini;
            }
        }
        return result;                // return the total sum
    }
};


// Approach 2: Use monotonic stacks to compute Next Smaller to Left (NSL) and Next Smaller to Right (NSR) for each element, then sum each element’s contribution as arr[i] * leftDistance * rightDistance
// Time Complexity: O(n) since each element is pushed and popped at most once from each stack
// Space Complexity: O(n) for storing NSL, NSR arrays and the stacks
class Solution {
public:

    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int>  st;

        for (int i = 0; i < n; i++) {
            // pop until you find a smaller element or stack becomes empty
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // if empty, no smaller to left; else top of stack is NSL
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }
    
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int>  st;

        for (int i = n - 1; i >= 0; i--) {
            // pop until you find a strictly smaller element or stack becomes empty
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            // if empty, no smaller to right; else top of stack is NSR
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    int sumSubMins(vector<int>& arr) {
        int         n   = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        int sum = 0;

        for (int i = 0; i < n; i++) {
            // distance to previous smaller on left
            int leftD = i - NSL[i];
            // distance to next smaller on right
            int rightD = NSR[i] - i;
            // each element contributes arr[i] * leftD * rightD
            sum += arr[i] * leftD * rightD;
        }
        return sum;
    }
};
