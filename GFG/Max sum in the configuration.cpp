//Approach:
/*
We'll need some values to be calculated:
--sum of all values in the array  [sum1]
--sum of all values by given rule (a[i]*i)  [sum2]

-- how can I move the first element to last?

sum1-a[i-1] -> this will help u to remove the value from the first.
a[i-1]*(N-1) -> this will help u to add that value from the last with having n-1 instances (as described in the previous diagram)


-- how can I make "--reduce every instances from current element to ." this step?

It is simple. Just substitute sum1 from the sum2

ULTIMATELY:
sum2=  sum2  -  (sum1-a[i-1])  + (a[i-1]*(N-1));
            removal of 1 instance [ taking the first value from the front to the last ]


Now Simply get the max value of sum2.
DONE!!!
*/
class Solution {
  public:
    int maxSum(vector<int> &a) {
        // code here
        long long sum1=0, sum2=0;
        long long N=a.size();
        for(long long i=0;i<N;i++){
            sum1+=a[i];// sum up all the elements for a single instance
            sum2+=a[i]*i;// sum up all the elements as the number of instance == i;
        }
        long long ans=sum2;
        for(long long i=1;i<N;i++){
            sum2=sum2-(sum1-a[i-1])+(a[i-1]*(N-1));// removing all single instances except the 0th elemnet, and then take the 0th element and put it at the last making (n-1) instances
            ans=max(ans,sum2);//then simply get the maximun answer
        }
        return ans;
    }
};


// old
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum=0;
        for(long long i=0;i<n;i++){
            sum+=a[i];
        }
        
        long long initial=0, max=0;
        for(long long i=0;i<n;i++){
            initial+=i*a[i];
        }
        max=initial;
        
        for(long long i=1;i<n;i++){
            long long next=initial - (sum-a[i-1]) + 1LL*(n-1)*a[i-1];
            initial=next;
            if(max<initial){
                max=initial;
            }
        }
        return max;
    }
};
