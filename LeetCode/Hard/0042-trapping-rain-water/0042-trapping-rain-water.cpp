class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = height[0]; 
        int maxRight = height[height.size() - 1];
        int left = 0;
        int right = height.size() - 1;
        int water = 0;
        while(left < right){
            if(height[left] < height[right]){
                left++;
                maxLeft = max(height[left], maxLeft);
                water += maxLeft - height[left];
            }
            else{
                right--;
                maxRight = max(height[right], maxRight);
                water += maxRight - height[right];
            }
        }
        return water;
    }
};