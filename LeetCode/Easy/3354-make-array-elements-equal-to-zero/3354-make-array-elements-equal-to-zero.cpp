class Solution {
    vector<int> process(vector<int> nums, int curr, bool left){
        while(curr >= 0 && curr < nums.size()){
            if(left){
                curr--;
                while(curr >= 0 && nums[curr] == 0){
                    curr--;
                }
                if(curr < 0)
                    break;
                nums[curr]--;
                left = false;
            }
            else{
                curr++;
                while(curr < nums.size() && nums[curr] == 0){
                    curr++;
                }
                if(curr >= nums.size())
                    break;
                nums[curr]--;
                left = true;
            }
        }
        return nums;
    }
    bool checkZero(vector<int> nums){
        for(int i: nums)
            if(i != 0) return false;
        return true;
    }
public:
    int countValidSelections(vector<int>& nums) {
        bool left = false;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                vector<int> leftArr = process(nums, i, true);
                for(int num: leftArr)
                    cout << num;
                cout << endl;
                if(checkZero(leftArr))
                    ans++;
                vector<int> rightArr = process(nums, i, false);
                if(checkZero(rightArr))
                    ans++;
            }
        }
        return ans;
    }
};