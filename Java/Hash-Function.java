class Solution {
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    public int hashCode(char[] key,int HASH_SIZE) {
        // write your code here
        long cur = 0;
        for (int i = 0; i < key.length; i ++) {
            cur = ((cur * 33) % HASH_SIZE + key[i]) % HASH_SIZE;
        }
        return (int)cur;
    }
};
