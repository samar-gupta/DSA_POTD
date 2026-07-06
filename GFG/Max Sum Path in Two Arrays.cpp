//Approach-1 : 
class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int i = 0;
        int j = 0;

        int sumA = 0;
        int sumB = 0;

        int answer = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                sumA += a[i];
                i++;
            } 
            else if (a[i] > b[j]) {
                sumB += b[j];
                j++;
            } 
            else {
                answer += max(sumA, sumB);

                answer += a[i];

                sumA = 0;
                sumB = 0;

                i++;
                j++;
            }
        }

        while (i < a.size()) {
            sumA += a[i];
            i++;
        }

        while (j < b.size()) {
            sumB += b[j];
            j++;
        }

        answer += max(sumA, sumB);

        return answer;
    }
};



//Approach-2 :
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int sum1 =0;
        int sum2 =0;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i= n1-1,j =n2-1;
        while(i>=0 && j>=0)
        {
            if(arr1[i]>arr2[j])
            {
                sum1+=arr1[i];
                i--;
            }
             if(arr1[i]<arr2[j])
            {
                sum2+=arr2[j];
                j--;
            }
            if(arr1[i]==arr2[j])
            {
                if(sum1>sum2)
                {
                    sum1+=arr1[i];
                    sum2=sum1;
                }
                else
                {
                    sum2+=arr2[j];
                    sum1=sum2;    
                }
                i--,j--;
            }
        }
        while(i>=0)
        {
            sum1+=arr1[i];
            i--;
        }
        while(j>=0)
        {
            sum2+=arr2[j];
            j--;
        }
        return max(sum1,sum2);
    }
};
