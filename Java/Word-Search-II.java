public class Solution {
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    public class TrieTree {
        public int count;
        public TrieTree[] next;
        TrieTree() {
            next = new TrieTree[26];
            for (int i = 0; i < 26; i ++) {
                this.next[i] = null;
            }
            count = 0;
        }
    }
    public int[] dx = {1, -1, 0, 0};
    public int[] dy = {0, 0, 1, -1};
    public void insert(String word, TrieTree root) {
        TrieTree cur = root;
        for (int i = 0; i < word.length(); i ++) {
            int v = word.charAt(i) - 'a';
            if (cur.next[v] != null) {
                cur = cur.next[v];
            } else {
                TrieTree node = new TrieTree();
                cur.next[v] = node;
                cur = cur.next[v];
            }
        }
        cur.count = 1;
    }
    public void exist(char[][] board, int[][] vis, int x, int y, ArrayList<String> words, StringBuffer sb, TrieTree root) {
        if (root.count > 0) {
            words.add(sb.toString());
            root.count = 0;
        }
        for (int i = 0; i < 4; i ++) {
            int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 >= 0 && x1 < board.length && y1 >= 0 && y1 < board[0].length && vis[x1][y1] == 0) {
                int temp = board[x1][y1] - 'a';
                if (root.next[temp] != null) {
                    vis[x1][y1] = 1;
                    StringBuffer sb_n = new StringBuffer(sb);
                    sb_n.append(board[x1][y1]);
                    exist(board, vis, x1, y1, words, sb_n, root.next[temp]);
                    vis[x1][y1] = 0;
                }
            }
        }
    }
    public ArrayList<String> wordSearchII(char[][] board, ArrayList<String> words) {
        // write your code here
        ArrayList<String> res = new ArrayList<String>();
        if (board == null || board.length <= 0 || words.isEmpty()) return res;
        TrieTree root = new TrieTree();
        for (int i = 0; i < words.size(); i ++) {
            insert(words.get(i), root);
        }
        int lenx = board.length, leny = board[0].length;
        int[][] vis = new int[lenx][leny];
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < leny; j ++) {
                int temp = board[i][j] - 'a';
                if (root.next[temp] != null) {
                    vis[i][j] = 1;
                    StringBuffer sb = new StringBuffer();
                    sb.append(board[i][j]);
                    exist(board, vis, i, j, res, sb, root.next[temp]);
                    vis[i][j] = 0;
                }
            }
        }
        return res;
    }
}