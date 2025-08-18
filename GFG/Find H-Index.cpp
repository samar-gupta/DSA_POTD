//Approach-1 : Using Sorting
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.begin(), citations.end());

        int n = citations.size();

        int res = 0;

        for (int i = 0; i < n; i++) {
            int x = n - i; 
            if (citations[i] >= x) {
                res = x;
                break; 
            }
        }

        return res;
    }
};


//Approach-2 
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();

        vector<int> count(n + 1, 0);


        for (int c : citations) {
            if (c >= n) {
                count[n]++;
            } else {
                count[c]++;
            }
        }

        int total = 0;
        for (int i = n; i >= 0; i--) {
            total += count[i];
            if (total >= i) {
                return i;
            }
        }

        return 0;
    }
};



//old
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        int len= citations.size();
        vector<int> bucket(len+1);
        
        for(int c: citations){
            bucket[min(c, len)]++;
        }
        
        int count=0;
        
        for(int i=len;i>=0;i--){
            count+=bucket[i];
            if(count >= i){
                return i;
            }
        }
        
        return 0;
    }
};
