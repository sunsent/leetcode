/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int min_num,max_num,mid_num;
        int nums_size=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(min_num=0;min_num<nums_size-2;min_num++){
            if(min_num==0||nums[min_num]>nums[min_num-1]){
                mid_num=min_num+1;
                max_num=nums_size-1;
                while(mid_num<max_num){
                    if(nums[min_num]+nums[mid_num]+nums[max_num]==0){
                        vector<int> row;
                        row.push_back(nums[min_num]);
                        row.push_back(nums[mid_num]);
                        row.push_back(nums[max_num]);
                        res.push_back(row);
                        mid_num++;
                        max_num--;
                        while(mid_num<max_num&&nums[mid_num]==nums[mid_num-1]){
                            mid_num++;
                        }
                        while(mid_num<max_num&&nums[max_num]==nums[max_num+1]){
                            max_num--;
                        }
                    }
                    else if(nums[min_num]+nums[mid_num]+nums[max_num]>0){
                        max_num--;
                    }
                    else if(nums[min_num]+nums[mid_num]+nums[max_num]<0){
                        mid_num++;
                    }
                }
            }
        }
        return res;
        
    }
};