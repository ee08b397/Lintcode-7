class Solution:
    """
    @param numbers : An array of Integer
    @param target : target = numbers[index1] + numbers[index2]
    @return : [index1 + 1, index2 + 1] (index1 < index2)
    """
    def twoSum(self, numbers, target):
        # write your code here
        dict = {}
        for i in range(len(numbers)):
            if numbers[i] not in dict:
                dict[numbers[i]] = []
            dict[numbers[i]].append(i + 1)
        seq = []
        for item in numbers:
            if item * 2 == target:
                if len(dict[item]) >= 2:
                    seq.append(min(dict[item][0], dict[item][1]))
                    seq.append(max(dict[item][0], dict[item][1]))
                    return seq
            elif target - item in dict:
                seq.append(min(dict[item][0], dict[target - item][0]))
                seq.append(max(dict[item][0], dict[target - item][0]))
                return seq
        return seq
