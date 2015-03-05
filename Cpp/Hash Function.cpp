class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        int res = 0;
        for (int i = 0; i < key.size(); i ++) {
          res = ((res * 33) % HASH_SIZE + key[i] % HASH_SIZE) % HASH_SIZE;
        }
        return res % HASH_SIZE;
    }
};
