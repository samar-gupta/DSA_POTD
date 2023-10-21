/*
    Company Tags  		: Google, HyperVerge
    Leetcode Link 		: https://leetcode.com/problems/constrained-subsequence-sum/
    
    "Leetcode - 239 Sliding Window Maximum"  Both are similar to a great extent and this is the hard version.
*/

/******************************************************* C++ ******************************************************/
//Approach-4 (Using Priority_queue) Accepted
/*
	Basically in Approach-3, you want the maximum value in the range of [i, i-k]
	Why not store them in max heap and access them in one go
*/
//T.C - O(nlogn)
class Solution {
public:
    typedef pair<int, int> P;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> t(n);

        for(int i = 0; i<n; i++) {
            t[i] = nums[i];
        }

        priority_queue<P> pq;              
        pq.push({t[0], 0});
        int result = t[0];

        for(int i = 1; i<n; i++) {

            while(!pq.empty() && i - pq.top().second > k) {      //Note : The while loop will be amortised O(1), An element is pushed/popped only once.       The max size of priority queue will go till n When we pop any element, so it willl be log(n) , Overall T.C = O(nlogn)
                pq.pop();
            }

            t[i] = max(t[i], nums[i] + pq.top().first);
            pq.push({t[i], i});

            result = max(result, t[i]);
        }

        return result;
    }
};





//Approach-1 (Recursion+Memo) Similar to LIS - TLE (18 / 25 test cases passed)
/*
	You should always start from an approach like this for 
	any DP problem.
*/
class Solution {
private:
    int n, k;
    unordered_map<string, int> mp;
public:
    int solve(vector<int>& nums, int last_chosen_index, int curr_index) {
        if(curr_index >= n)
            return 0;
        string key = to_string(last_chosen_index) + "_" + to_string(curr_index);
        
        if(mp.find(key) != end(mp))
            return mp[key];
        int result = 0;
        if(last_chosen_index == -1 || curr_index-last_chosen_index <= k) {
            //take curr_index element
            int taken = nums[curr_index] + solve(nums, curr_index, curr_index+1);
            
            //don't take curr_index element
            int not_taken = solve(nums, -1, curr_index+1);
            
            result = max(taken, not_taken);
            
	}
        return mp[key] = result;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        this->n = nums.size();
        this->k = k;
        
        int val = solve(nums, -1, 0);
        if(val == 0)
            return -1;
        return val;
    }
};



//Approach-2 (1-D memoization) - TLE
class Solution {
public:
    int t[100001];
    int K;
    //solve(j) = maximum sum of the subsequence with nums[j] as the last number
    int solve(int j, vector<int>& nums) {
        if (j < 0) {
            return 0;
        }
        
        if(t[j] != -1)
            return t[j];
        
        int max_val = 0;
        /*
            solve[j] = nums[j] + max(solve(j-1), solve(j-2), ..., solve(j-K))
        */
        for (int i = 1; i <= K; ++i) {
            max_val = max(max_val, solve(j - i, nums));
        }
        
        return t[j] = nums[j] + max_val;
    }
    
    int constrainedSubsetSum(vector<int>& nums, int k) {
        memset(t, -1, sizeof(t));
        K = k;
        
        int result = INT_MIN;
        
        for (int i = 0; i < nums.size(); ++i) {
            result = max(result, solve(i, nums));
        }
        
        return result;
    }
};



//Approach-3 (Bottom Up DP) Similar to LIS - TLE
/*
	NOTE : This is basically using the concept of Longest Increasing Subsequence (LIS)
	This can be further improved (from TLE) by using extra data structure. Look for next approaches.
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> t(n, 0);
        for(int i = 0; i<n; i++)
            t[i] = nums[i];
        
        int maxR = t[0];
        
        for(int i = 1; i<n; i++) {
            for(int j = i-1; i-j <= k && j >= 0; j--) {
                t[i] = max(t[i], nums[i] + t[j]);
            }
            
            maxR = max(maxR, t[i]);
        }
        
        
        return maxR;
    }
};



//Approach-5 (Using monotonic decreasing deque) Accepted
/*
    This is similar to approach-4 it's just we maintain decreasing order.
    NOTE : Approach-4 and Approach-5 are used to solve "Sliding Window Maximum" also with similar approach (Leetcode-239)
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> t(nums);
        int maxR = t[0];
        
        for(int i = 0; i<n; i++) {
            
	    //first get rid of out of range indices
            while(!deq.empty() && deq.front() < i-k)
                deq.pop_front();
            
            if(!deq.empty())
                t[i] = max(t[i], nums[i] + t[deq.front()]);
            
            //we maintain the deque in descending order
	    //So that you can get the optimum value at once from front
            while(!deq.empty() && t[i] >= t[deq.back()])
                deq.pop_back();
            
            deq.push_back(i);
            
            maxR = max(maxR, t[i]);
        }
        
        return maxR;
    }
};
