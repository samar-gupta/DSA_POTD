//Company Tags  : Amazon
//Leetcode Link : https://leetcode.com/problems/maximize-happiness-of-selected-children

//Approach-1 (Using Sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness), end(happiness), greater<int>());
        
        long long result = 0;
        
        int count = 0;
        
        for(int i = 0; i < k; i++) {
            
            result += max(happiness[i] - count, 0);
            
            count++;
            
        }
        
        return result;
    }
};


//Approach-2 (Using Max Heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result = 0;
        
        int count = 0;
        
        priority_queue<int> pq; //max-heap
        
        for(int &hap : happiness) {
            pq.push(hap);
        }
        
        for(int i = 0; i < k; i++) {
            
            int hap = pq.top();
            pq.pop();
            
            result += max(hap - count, 0);
            
            count++;
            
        }
        
        return result;
    }
};
