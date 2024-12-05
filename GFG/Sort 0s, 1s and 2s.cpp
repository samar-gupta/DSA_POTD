//Approach-1
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
    }
};


//Approach-2
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int zeros=0,ones=0,twos=0;
        for(int i=0;i<n;i++)
        {
              if(arr[i]==0){
               zeros++;
              }
              else if(arr[i]==1){
               ones++;
              }
        }
      
        for(int i=0;i<n;i++)
        {
          if(zeros>0){
            arr[i]=0;
            zeros--;
          }
          else if(ones>0){
            arr[i]=1;
            ones--;
          }
           
          else{
            arr[i]=2;
          }
        }
      
    }
};


//Approach-
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int l=0,m=0,h=n-1;
        
        while(m<=h){
            if(arr[m]==0){
                swap(arr[l],arr[m]);
                l++;
                m++;
            }
            else if(arr[m]==2){
                swap(arr[m],arr[h]);
                h--;
            }
            else m++;
        }
    }
};
