public class Solution {
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    public String IntToBinary(int cur) {
        StringBuffer sb = new StringBuffer();
        if (cur == 0) return "0";
        while (cur != 0) {
            int temp = cur % 2;
            sb.append(String.valueOf(temp));
            cur = cur / 2;
        }
        sb.reverse();
        return sb.toString();
    }
    boolean isValid(String s) {
        if (s.charAt(s.length() - 1) != '5' && s.charAt(s.length() - 1) != '0') return false;
        return true;
    }
    boolean isZero(String s) {
        for (int i = 0; i < s.length(); i ++) {
            if (s.charAt(i) != '0') return false;
        }
        return true;
    }
    public String shift(String s) {
        int d = 0;
        StringBuffer sb = new StringBuffer();
        for (int i = s.length() -1; i >= 0; i --) {
            int temp = s.charAt(i) - '0';
            sb.append(String.valueOf((temp * 2 + d) % 10));
            d = (temp * 2 + d) / 10;
        }
        //while (sb.charAt(index) == '0') index ++;
        s = sb.reverse().toString();
        int index = sb.length() - 1;
        while (index >= 0 && s.charAt(index) == '0') index --;
        s = s.substring(0, index + 1);
        return s;
    }
    public String binaryRepresentation(String n) {
        // write your code here
        //考虑负数，考虑零，考虑整数。
        if (n == null || n.length() == 0) return "";
        int sign = 1;
        if (n.charAt(0) == '-') {
            n = n.substring(1);
            sign = -1;
        }
        int Point_index = -1;
        for (int i = 0; i < n.length(); i ++) {
            if (n.charAt(i) == '.') {
                Point_index = i;
                break;
            }
        }
        String res;
        if (Point_index == -1) {
            int cur = Integer.parseInt(n);
            res = IntToBinary(cur);
        } else {
            String Int_part = n.substring(0, Point_index);
            int Int_p = Integer.parseInt(Int_part);
            Int_part = IntToBinary(Int_p);
            String dem_part = n.substring(Point_index + 1);
            StringBuffer cur = new StringBuffer();
            int count = 0;
            while (count < 32 && dem_part.length() > 0) {
                if (!isValid(dem_part)) return "ERROR";
                if (isZero(dem_part)) break;
                if (dem_part.charAt(0) >= '5') cur.append("1");
                else cur.append("0");
                String s = shift(dem_part);
                dem_part = s;
                count ++;
            }
            if (!isZero(dem_part)) return "ERROR";
            if (cur.length() > 0) res = Int_part + "." + cur.toString();
            else res = Int_part;
        }
        if (sign == -1) return "-" + res;
        return res;
    }
}