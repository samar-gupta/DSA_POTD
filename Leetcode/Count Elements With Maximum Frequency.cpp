//Leetcode Link  : https://leetcode.com/problems/count-elements-with-maximum-frequency/

//Approach-1 (Using 2 Pass)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> arr(101);
        
        int maxFreq = 0;
        
        for(int &num : nums) {
            arr[num]++;
            maxFreq = max(maxFreq, arr[num]);
        }
        
        return count(arr.begin(), arr.end(), maxFreq)*maxFreq;
    }
};


//Approach-2 (Using 1 Pass)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> arr(101);
        
        int maxFreq = 0;
        int total   = 0;
        
        for(int &num : nums) {
            arr[num]++;
            
            int freq = arr[num];
            
            if(freq > maxFreq) {
                maxFreq = freq;
                total   = freq;
            } else if(freq == maxFreq) {
                total += freq;
            }
            
        }
        
        return total;
    }
};
