//Approach-1 : (Using HashMap)
//T.C : O(N) 
//S.C : O(N) 
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second>(nums.size()/3)) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//Approach-2 : (Moore's Voting Algorithm)
//T.C : O(N)
//S.C : O(1)
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        vector<int>ans;
        int n=nums.size(),cand1,cand2=0,counter1=0,counter2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1){
                counter1++;
            }else if(nums[i]==cand2){
                counter2++;
            }else if(counter1==0){
                cand1=nums[i];
                counter1++;
            }else if(counter2==0){
                cand2=nums[i];
                counter2++;
            }else {
                counter1--;
                counter2--;
            }
        }
        // now cand1 and cand2 is the potential winner so at last 
        // veriry wheather they are majority element or not;
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1) count1++;
            else if(nums[i]==cand2) count2++;
        }
        if(count1>(n/3)) ans.push_back(cand1);
        if(count2>(n/3)) ans.push_back(cand2);
        // sort the elements of ans vector (there will be maximum 2 elements so no issue for the time complexity)
        sort(ans.begin(),ans.end());  
        // finally return the ans;
        // if(ans.size()==0) return {-1};
        return ans;
    }
};
