public class Solution {
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    public int majorityNumber(ArrayList<Integer> nums, int k) {
        if (nums==null || nums.size()==0) return 0;

        int len = nums.size();
        Map<Integer,Integer> nMap = new HashMap<Integer,Integer>();
        nMap.put(nums.get(0),1);
        for (int i=1;i<len;i++)
            if (nMap.containsKey(nums.get(i))){
                int val = nMap.get(nums.get(i))+1;
                if (val==0) nMap.remove(nums.get(i));    
                else nMap.put(nums.get(i),val);
            } else {
                //if the number of existing numbers is less than k-1, then just add one.
                if (nMap.size()<k-1){
                    nMap.put(nums.get(i),1);
                } else {
                    List<Integer> keyList = new ArrayList<Integer>();
                    //decrease the value of every key by 1.
                    for (Map.Entry en : nMap.entrySet()){
                        int key = (int) en.getKey();
                        int value = (int) en.getValue();
                        value--;
                        if (value==0) keyList.add(key);
                        nMap.put(key,value);
                    }
                    for (int key : keyList) nMap.remove(key);
                }
            }

        for (Map.Entry en: nMap.entrySet()) en.setValue(0);
        int num = 0, count = 0;
        for (int i=0;i<len;i++)
            if (nMap.containsKey(nums.get(i))){
                int val = nMap.get(nums.get(i))+1;
                if (val>count){
                    num = nums.get(i);
                    count = val;
                }
                nMap.put(nums.get(i),val);
            }        
        return num;

    }
}