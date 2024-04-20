class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(arr1[i]);
        } 
        for(int j=0;j<m;j++){
            s.insert(arr2[j]);
        }
        vector<int>vec;
        for(auto i:s){
            vec.push_back(i);
        }
        return vec;
    }
};
