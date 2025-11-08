class Solution {
public:
void subsequence(vector<int>& arr , int n , int index , vector<vector<int>> &ans , vector<int>temp){
    // stopping condition 
    if(index==n){
        ans.push_back(temp);
        return;
    }
    // include nhi karna hai 
    subsequence(arr , n , index+1 , ans , temp);

    // include karna hai 
    temp.push_back(arr[index]);
    subsequence(arr , n , index+1 , ans , temp );

}
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int> >ans;
        vector<int>temp;
        subsequence(arr, arr.size(), 0,ans, temp);

        return ans;
        
    }
};