class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<pair<int,int>> s;
        vector<int> ans(nums1.size(), -1);
        unordered_map<int,int> num;
        for(int i = 0; i < nums1.size(); i++){
            num[nums1[i]] = i;
        }
        for(int i = 0; i < nums2.size(); i++){
            while(!s.empty() && s.top().second < nums2[i]){
                ans[s.top().first] = nums2[i];
                s.pop();
            }
            if(num.find(nums2[i]) != num.end())
                s.push({num[nums2[i]], nums2[i]});
        }
        return ans;
    }
};