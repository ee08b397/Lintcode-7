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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head->next == NULL)return;
        ListNode *fastp = head, *lowp = head, *tail = NULL;
        while(fastp != NULL && fastp->next != NULL)
        {//利用快慢指针找到链表的中点
            tail = lowp;
            fastp = fastp->next->next;
            lowp = lowp->next;
        }
        tail->next = NULL; //此时tail 指向前半段的结尾
        reverseList(lowp);//翻转链表后半段
        fastp = head;
        tail = NULL;
        while(fastp != NULL)
        {
            ListNode *tmp = lowp->next;
            lowp->next = fastp->next;
            fastp->next = lowp;
            tail = lowp;
            fastp = lowp->next;
            lowp = tmp;
        }
        if(lowp != NULL)
            tail->next = lowp;

    }
    void reverseList(ListNode* &head)
    {//翻转链表
        if(head == NULL || head->next == NULL)return;
        ListNode *pre = head, *p = pre->next;
        while(p != NULL)
        {
            ListNode *tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        head->next = NULL;
        head = pre;
    }
};
