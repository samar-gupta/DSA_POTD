//Approach-1 :
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        vector<pair<int,int>> intervals;

       
        for(int i=0;i<n;i++){
            
            if(arr[i] != -1){
                
                int l=max(0,i-arr[i]);
                int r=min(n-1,i+arr[i]);
                
                intervals.push_back({l, r});
            }
        }

      
        sort(intervals.begin(),intervals.end());

        int ans=0;
        int curr=0;
        int i=0;


        while(curr<n){
            int farthest=-1;

            while(i < intervals.size() && intervals[i].first <= curr){
                farthest=max(farthest,intervals[i].second);
                i++;
            }

            if(farthest<curr){
                return -1; 
            }

            ans++;
            curr=farthest+1;
        }

        return ans;
    }
};



//Approach-2 :
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>temp(n,-1);
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=-1)
            {
                int idx=max(0,i-arr[i]);
                temp[idx]=max(temp[idx],i+arr[i]);
            }
        }
        int ans=0;
        int curr=-1;
        int mx=-1;
        int i=0;
        while(i<n)
        {
            mx=max(mx,temp[i]);
            if(curr<i)
            {
                if(mx<i)
                {
                    return -1;
                }
                else{
                    curr=mx;
                    ans++;
                }
            }
            i++;
        }
        return ans;
    }
};


//Approach-2 : 
class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> maxReach(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                int left = max(0, i - arr[i]);
                int right = min(n-1, i + arr[i]);
                
                maxReach[left] = max(maxReach[left], right);
            }
        }
        
        if(maxReach[0] == -1) {
            return -1;
        }
        
        int currEnd = 0;
        int farthest = 0;
        int i = 0;
        int people = 0;
        
        while(currEnd < n) {
            while(i <= currEnd && i < n) {
                farthest = max(farthest, maxReach[i]);
                i++;
            }
            
            if(farthest < currEnd) return -1;
            people++;
            currEnd = farthest + 1;
        }
        return people;
    }
};
