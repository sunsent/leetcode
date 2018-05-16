//https://leetcode-cn.com/problems/longest-palindromic-substring/description/
class Solution {
public:
    string longestPalindrome(string s) {
       if(s.empty()){
           return s;
       }
        if(s.size()==1){
            return s;
        }
        int max_start=0;//最长回文的第一个字符的位置
        int maxlen=1;
        for(int i=0;i<s.size();i++){//假设第i+1个字符是回文中间的字符
            if(s.size()-i<=maxlen/2) break;
            int left=i;
            int right=i;
            while(right<s.size()-1&&s[left]==s[right+1]){//left指向重复字符的最左,right指向重复字符的最右
                right++;
            }
            while(left>0&&right<s.size()-1&&s[left-1]==s[right+1]){
                left--;
                right++;
            }
            int len=right-left+1;
            if(len>maxlen){
                maxlen=len;
                max_start=left;
            }
        }
        return s.substr(max_start,maxlen);
    }
};