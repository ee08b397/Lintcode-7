class Solution:
    """
    @param head: The first node of the linked list.
    @return: You should return the head of the reversed linked list.
                  Reverse it in-place.
    """
    def reverse(self, head):
        # write your code here
        if head is None or head.next is None:
            return head
        pre = None
        while head is not None:
            temp = head.next
            head.next = pre
            pre = head
            head = temp
        return pre