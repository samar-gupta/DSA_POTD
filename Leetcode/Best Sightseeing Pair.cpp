//Leetcode Link : https://leetcode.com/problems/best-sightseeing-pair/description/

//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int result = 0;

        for(int j = 1; j < n; j++) {
            int max_val = 0;
            for(int i = j-1; i >= 0; i--) {
                max_val = max(max_val, values[i]+i);
            }

            result = max(result, max_val + values[j]-j);
        }

        return result;
    }
};


//Approach-2 : (Using extra space)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> vec(n, 0);
        //vec[i] = stores the maximum value of (values[i]+i) till index i in values wala array
        vec[0] = values[0] + 0;

        for(int i = 1; i < n; i++) {
            vec[i] = max(values[i]+i, vec[i-1]);
        }

        int result = 0;

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = vec[j-1]; //max value of (values[i]+i) in left hand side

            result = max(result, x+y);
        }

        return result;
    }
};


//Approach-3 : (Using max-heap)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(); 
        
        priority_queue<int> pq;
        pq.push(values[0]);
        
        int result = INT_MIN;
        
        for(int j = 1; j < n; j++) {
            result = max(result, pq.top()+values[j]-j);
            pq.push(values[j] + j);
        }
        
        return result;
    }
};


//Approach-4 : (Using O(1) space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int result = 0;

        int max_till_now = values[0]+0; //this stores the max value of (values[i]+i) till now

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = max_till_now;

            result = max(result, x+y);

            max_till_now = max(max_till_now, values[j]+j);
        }

        return result;
    }
};
