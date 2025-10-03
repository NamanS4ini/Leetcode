class Solution {
    void heapify(vector<int>& nums, int size, int index){
        int largest = index;
        int left = 2 * index + 1;
        int right = (2 * index) + 2;
        if(left <= size && nums[largest] < nums[left]){
            largest = left;
        }
        if(right <= size && nums[largest] < nums[right]){
            largest = right;
        }
        if(largest != index){
            swap(nums[largest], nums[index]);
            heapify(nums, size, largest);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size() - 1;
        for(int i = size/2; i >= 0; i--){
            heapify(nums, size, i);
        }
        for(int i = nums.size() - 1; i > 0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, --size, 0);
        }
        return nums;
    }
};