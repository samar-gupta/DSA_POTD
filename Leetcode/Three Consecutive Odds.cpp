//Leetcode Link : https://leetcode.com/problems/three-consecutive-odds/?envType=daily-question&envId=2024-07-01

//Approach-1 
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            if(arr[i] % 2 == 1) {
                count++;    //Count it
            } else {
                count = 0;   //Reset it
            }
            
            if(count == 3)
                return true;
        }  
        
        return false;       
    }
};



//Approach-2
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < n-2; i++){
            if(arr[i] % 2 == 1 && arr[i+1] % 2 == 1 && arr[i+2] % 2 == 1) {
                return true;
            } 
        }
        
        return false;
    }
};



//Approach-3
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < n-2; i++){
            if((arr[i] * arr[i+1] * arr[i+2]) % 2 == 1) {
                return true;
            } 
        }
        
        return false;
    }
};
