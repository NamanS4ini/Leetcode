class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        while(left < right){
            int leftHeight = height[left];
            int rightHeight = height[right];
            if(leftHeight < rightHeight){
                maxWater = max(maxWater,leftHeight * (right - left));
                left++;
            }
            else{
                maxWater = max(maxWater,rightHeight * (right - left));
                right--;
            }
        }
        return maxWater;
    }
};