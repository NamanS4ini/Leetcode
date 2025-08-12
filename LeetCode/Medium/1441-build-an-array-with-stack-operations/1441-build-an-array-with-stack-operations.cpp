class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for (int i = 1; i <= target[target.size()-1]; i++) {
            bool flag = false;
            for (int num : target) {
                if (num == i) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                ans.push_back("Push");
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};