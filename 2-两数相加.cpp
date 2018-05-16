//https://leetcode-cn.com/problems/add-two-numbers/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int pow_num=0;

        ListNode* result;
        int carry=0;
        ListNode* rear;//尾指针
        int flag=0;
        int flag1=0;
        int flag2=0;
        while(carry!=2){
            int num1=0;
            int num2=0;
            
            if(l1!=NULL){
                num1=l1->val;
                l1=l1->next;
            }
            
            if(l2!=NULL){
                num2=l2->val;
                l2=l2->next;
            }
            
            int sum=num1+num2+carry;
            if(sum>9){
                carry=1;
                sum=sum-10;
            }
            else{
                carry=0;
            }
            
            if(flag==0){
                result=new ListNode(sum);
                rear=result;
                flag=1;
            }
            else{
                ListNode* current=new ListNode(sum);
                rear->next=current;
                rear=current;//移动尾指针到尾部
            }
            if(l2==NULL&&l1==NULL&&carry==0){//l1,l2都为空时进位carry可能为1
                carry=2;
            }
            
        }
        return result;
    }
};