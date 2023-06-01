#include<bits/stdc++.h>
using namespace std;

//Brute Force
// void twoSum(vector<int>&arr, int n, int target){
//     for(int i=0; i<n; i++){
//         for(int j=1; j<n; j++){
//            if(arr[i]+arr[j] == target){
//                 cout<<i<<" "<<j<<" "<<endl;
//             }
//         }
//     }
// }


//Better Solution
// vector<int>twoSum(vector<int>&arr, int n, int target){
//     unordered_map<int, int>mpp;
//     for(int i=0; i<n; i++){
//         int num=arr[i];
//         int moreNeed=target-num;
//         if(mpp.find(moreNeed) != mpp.end()){
//             return {mpp[moreNeed], i};
//         }
//         mpp[num]=i;
//     }
//     return {-1, -1};
// }

//Optimal Solution
string twoSum(vector<int>&arr, int n, int target){
    sort(arr.begin(), arr.end());
    int left=0, right=arr.size()-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target){
            return "Yes";
        }
        else if(sum<target) left++;
        else left--;
    }
    return "No";
}

int main(){
    vector<int>arr{1,2,7,11,15,78};
    int n=arr.size();
    int target=9;
    string brr = twoSum(arr, n, target);
    // cout<<"["<<brr[0]<<","<<brr[1]<<"]"<<endl;
    cout<<brr<<endl;
}

//Time complexity O(N)
//Space Complexity O(1)