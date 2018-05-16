//https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        if(nums1.empty()){
            if(nums2.size()%2==0){
                return (nums2[nums2.size()/2-1]+nums2[nums2.size()/2])/2.0;
            }
            return nums2[nums2.size()/2];
        }
        if(nums2.empty()){
            if(nums1.size()%2==0){
                return (nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/2.0;
            }
            return nums1[nums1.size()/2];
        }
        int i;
        int j;
        int i_min=0;
        int i_max;
        double maxleft=0.0;
        double minRight=0.0;
        int m=nums1.size();
        int n=nums2.size();

        i_max=nums1.size();
        
        int isOdd=1;//
        if((m+n)%2==0){
            isOdd=0;
        }
        
        while(i_max>=i_min){
            i=(i_min+i_max+1)/2;
            j=(n+m+1)/2-i;
            if(i>0&&j<n&&nums1[i-1]>nums2[j]){
                i_max=i-1;
            }
            else if(i<m&&j>0&&nums1[i]<nums2[j-1]){
                i_min=i+1;
            }
            else{
                if(i==0){
                    maxleft=nums2[j-1];
                }
                else if(j==0){
                    maxleft=nums1[i-1];
                }
                else{
                    maxleft=nums1[i-1]<nums2[j-1]?nums2[j-1]:nums1[i-1];
                }
                break;
            }
            
        }
        if((m+n)&1==1){
            return maxleft;
        }
        if(i==m){
            minRight=nums2[j];
        }
        else if(j==n){
            minRight=nums1[i];
        }
        else{
            minRight=nums1[i]<nums2[j]?nums1[i]:nums2[j];
        }
        return (maxleft+minRight)/2.0;
    }
};