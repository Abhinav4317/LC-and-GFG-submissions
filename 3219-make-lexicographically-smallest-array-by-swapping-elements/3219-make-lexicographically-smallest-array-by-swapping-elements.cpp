class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        /**
        Visual Solution:check out https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/solutions/6325811/visual-explanation-grouping-and-reordering-detailed-solution

Intuition
The problem involves rearranging elements in the array to make it lexicographically smallest, adhering to the constraint that elements can only be swapped within a given difference range (maxDifference).

The key insight is that:

Sorting the array by values ensures we have the lexicographical order.
By grouping elements based on the maxDifference constraint, we can limit swaps to valid elements.
Extracting elements in the order of their indices while respecting group priorities guarantees the smallest lexicographical result.
Approach
1. Pair Representation and Sorting
Each number in the array is stored as a pair (value, index) to retain both the value and its original position in the array.
These pairs are sorted based on the value. This ensures that smaller values come first, facilitating the construction of a lexicographically smallest array.
2. Forming Groups Based on maxDifference
Traverse the sorted array to identify groups of elements where consecutive values differ by at most maxDifference.
Use two pointers to determine the range of elements that belong to the same group. This grouping ensures that swaps are valid within the constraints.
3. Mapping Groups to Original Indices
For each element in a group, map its original index to the group it belongs to. This allows for efficient reconstruction of the result array in the next step.
Store the values of each group in a data structure for later use.
4. Reconstructing the Result Array
Iterate over the original indices of the array.
For each index, find the group it belongs to and take the smallest available value from that group.
Append this value to the result array and remove it from the group.
5. Output the Result
The final array is constructed by iteratively choosing the smallest possible value from valid groups while respecting the original index order.
Complexity Analysis
Time Complexity:
Sorting the Array:
Sorting the elementIndexPairs array of size n takes O(nlogn).
Grouping Elements:
Traversing the sorted array and forming groups takes O(n).
Reconstructing the Result Array:
Iterating through the original indices and extracting values from groups also takes O(n).
Overall Time Complexity: O(nlogn)

Space Complexity:
Storage Requirements:
elementIndexPairs stores the value-index pairs, taking O(n).
groupMapping stores the group index for each original index, taking O(n).
groups stores the values for each group, taking O(n).
Overall Space Complexity: O(n)
        */
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int s=0;
        vector<int> ans(n);
        vector<int> idx;
        for(int i=1;i<n;i++){
            if(v[i].first-v[i-1].first<=limit) idx.push_back(v[i].second);
            else{
                idx.push_back(v[s].second);
                sort(idx.begin(),idx.end());
                for(int j=s;j<=i-1;j++){
                    ans[idx[j-s]]=v[j].first;
                }
                idx.clear();
                s=i;
            }
        }
        if(idx.size()==0) ans[v[n-1].second]=v[n-1].first;
        else{
            idx.push_back(v[s].second);
            sort(idx.begin(),idx.end());
            for(int j=s;j<=n-1;j++){
                ans[idx[j-s]]=v[j].first;
            }
            idx.clear();
        }
        return ans;

    }
};