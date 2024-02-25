//Approach-1
class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	vector<long long>v(n+1, 0);
    	v[0]=1;
    	
    	for(int i=3;i<=n;i++){
    	    v[i]+=v[i-3];
    	}
    	for(int i=5;i<=n;i++){
    	    v[i]+=v[i-5];
    	}
    	for(int i=10;i<=n;i++){
    	    v[i]+=v[i-10];
    	}
    	
    	return v[n];
    }
};





//Approach-2
class Solution {
    public:
    long long int count(long long int n) {   
    	vector<int> v(n+1, 0);
    	v[0]=1;
    	
    	for(auto x:{3,5,10}) {
    	    for(int i=x;i<=n;i++) {
                v[i]+=v[i-x];
            }
    	}
            
      return v[n];
    }
};
