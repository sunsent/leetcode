//https://leetcode-cn.com/problems/palindrome-number/description/#
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int inc=0;//后半部分的倒序
        int dec=x;//前半部分
        int half_time=x;
        while(half_time>=10&&x>10){
            inc=inc*10 + dec%10;
            dec=dec/10;
            half_time=half_time/100;
        }
        if((dec/10==inc)||dec==inc){
            return true;
        }
        else{
            return false;
        }
    }
};