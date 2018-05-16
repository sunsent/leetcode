//https://leetcode-cn.com/problems/roman-to-integer/description/
class Solution {
public:
    int romanToInt(string s) {
        if(s.size()==0) return 0;
        vector<int> nums;
        for(int i=0; i<s.size(); i++){
            switch(s[i]){
               case 'I':
                nums.push_back(1);
                break;
              case 'V':
                nums.push_back(5);
                break;
               case 'X':
                nums.push_back(10);
                break;
              case 'L':
                nums.push_back(50);
                break;
              case 'C':
                nums.push_back(100);
                break;
               case 'D':
                nums.push_back(500);
                break;
              case 'M':
                nums.push_back(1000);
                break;
              default:
                return 0;
                break;
          
            }
        }
        int res=0;
        int count;
        for(count=0; count<nums.size()-1; count++){
            if(nums[count]<nums[count+1]){//可以找到规律，如果左边的字母表示的数字小于右边的字母，则用右边的数字减去左边的数字；反之，则需要进行加法
                res=res-nums[count];
            }
            else{
                res=res+nums[count];
            }
        }
        res=res+nums[count];
        return res;
    }
};