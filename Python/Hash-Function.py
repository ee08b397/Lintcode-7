class Solution:
    """
    @param key: A String you should hash
    @param HASH_SIZE: An integer
    @return an integer
    """
    def hashCode(self, key, HASH_SIZE):
        # write your code here
        res = 0
        for item in key:
            res = ((res * 33) % HASH_SIZE + ord(item)) % HASH_SIZE;
        return res