class Solution {
    public:
        
        int maxProfit(vector<int>&price){
            int n=price.size();
            vector<int>temp(n,0);
            
            //first traversal was from right to left
            int maxi=price[n-1];
            for(int i=n-2;i>=0;i--){
                maxi=max(maxi, price[i]);
                temp[i]=max(temp[i+1], maxi-price[i]);
            }
            
            //second traversal
            int mini=price[0];
            for(int i=1;i<n;i++){
                mini=min(mini, price[i]);
                temp[i]=max(temp[i-1], price[i]-mini+temp[i]);
            }
            
            return temp[n-1];
        }
};
