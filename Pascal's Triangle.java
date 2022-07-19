class Solution {
    public List< List <Integer> > generate(int numRows) {
        List <List <Integer> > triangle = new ArrayList<>();
        for(int row = 0; row < numRows; ++row){
            List <Integer> currentRow = new ArrayList<>();
            currentRow.add(1);
            for(int i = 0; i + 1 < row; ++i){
                currentRow.add(triangle.get(row - 1).get(i) + triangle.get(row - 1).get(i + 1));
            }
            if(row > 0) {
                currentRow.add(1);
            }
            triangle.add(currentRow);
        }
        return triangle;
    }
}
