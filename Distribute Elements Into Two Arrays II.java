class FenwickTree {
    private int[] treeArray;
    private int size;

    public FenwickTree(int size) {
        this.size = size;
        this.treeArray = new int[size];
    }

    public void update(int index, int delta) {
        while (index < size) {
            treeArray[index] += delta;
            index += (index & -index);
        }
    }

    public int prefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += treeArray[index];
            index -= (index & -index);
        }
        return sum;
    }

    public int rangeSum(int x, int y) {
        return prefixSum(y) - (x > 0 ? prefixSum(x - 1) : 0);
    }

    public int getSize() {
        return size;
    }
}

public class Solution {
    
    public int[] resultArray(int[] nums) {
        int n = nums.length;

        TreeSet<Integer> sortedSet = new TreeSet<>();
        for (int num : nums) {
            sortedSet.add(num);
        }

        int index = 1;
        Map<Integer, Integer> numToIndexMap = new HashMap<>();
        for (int num : sortedSet) {
            numToIndexMap.put(num, index++);
        }

        FenwickTree tree1 = new FenwickTree(index);
        FenwickTree tree2 = new FenwickTree(index);
        
        ArrayList<Integer> list1 = new ArrayList<>();
        ArrayList<Integer> list2 = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            int choice;
            int indexInMap = numToIndexMap.get(nums[i]);
            if (i == 0) {
                choice = 1;
            } else if (i == 1) {
                choice = 2;
            } else {
                int greaterCount1 = tree1.rangeSum(indexInMap + 1, tree1.getSize() - 1);
                int greaterCount2 = tree2.rangeSum(indexInMap + 1, tree2.getSize() - 1);

                if (greaterCount1 > greaterCount2) {
                    choice = 1;
                } else if (greaterCount1 < greaterCount2) {
                    choice = 2;
                } else {
                    if (list1.size() <= list2.size()) {
                        choice = 1;
                    } else {
                        choice = 2;
                    }
                }
            }

            if (choice == 1) {
                list1.add(nums[i]);
                tree1.update(indexInMap, 1);
            } else {
                list2.add(nums[i]);
                tree2.update(indexInMap, 1);
            }
        }

        list1.addAll(list2);
        int[] result = list1.stream().mapToInt(Integer::intValue).toArray();
        return result;
    }
}
