class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List <Double> average = new ArrayList <>();
        ArrayDeque <TreeNode> elementsAtLevel = new ArrayDeque <>();
        elementsAtLevel.addFirst(root);
        while(elementsAtLevel.size() > 0){
            int levelSize = elementsAtLevel.size();
            long levelSum = 0;
            for(int i = 0; i < levelSize; ++i){
                TreeNode currentElement = elementsAtLevel.removeFirst();
                levelSum += currentElement.val;
                if(currentElement.left != null){
                    elementsAtLevel.addLast(currentElement.left);
                }
                if(currentElement.right != null){
                    elementsAtLevel.addLast(currentElement.right);
                }
            }
            average.add((double) levelSum / levelSize);
        }
        return average;
    }
}
