class Maths {
    public static int min(int x, int y){
        return x < y ? x : y;
    }
    
    public static int max(int x, int y){
        return x > y ? x : y;
    }
}

class SegmentTree {
    int size;
    int[] tree;
    
    SegmentTree(int[] nums){
        this.size = nums.length;
        this.tree = new int [4 * this.size];
    }
    
    public void buildTree(int root, int[] nums, int tl, int tr){
        if(tl == tr){
            tree[root] = nums[tl];
            return;
        }
        
        int mid = (tl + tr) / 2;
        buildTree(2 * root + 1, nums, tl, mid);
        buildTree(2 * root + 2, nums, mid + 1, tr);
        
        tree[root] = tree[2 * root + 1] + tree[2 * root + 2];
    }
    
    public void updateValue(int root, int tl, int tr, int index, int value){
        if(tl == tr){
            tree[root] = value;
            return;
        }
        
        int mid = (tl + tr) / 2;
        if(index <= mid){
            updateValue(2 * root + 1, tl, mid, index, value);
        }
        else{
            updateValue(2 * root + 2, mid + 1, tr, index, value);
        }
        
        tree[root] = tree[2 * root + 1] + tree[2 * root + 2];
    }

    public int sumRange(int root, int tl, int tr, int l, int r){
        if(l == tl && r == tr){
            return tree[root];
        }
        
        if(l > r){
            return 0;
        }
        
        int mid = (tl + tr) / 2;
        int leftSubtree = sumRange(2 * root + 1, tl, mid, l, Maths.min(mid, r));
        int rightSubtree = sumRange(2 * root + 2, mid + 1, tr, Maths.max(mid + 1, l), r);
        
        return leftSubtree + rightSubtree;
    }
    
}

class NumArray {
    SegmentTree s;

    public NumArray(int[] nums) {
        s = new SegmentTree(nums);
        s.buildTree(0, nums, 0, nums.length - 1);
    }
    
    public void update(int index, int value) {
        s.updateValue(0, 0, s.size - 1, index, value);
    }
    
    public int sumRange(int left, int right) {
        return s.sumRange(0, 0, s.size - 1, left, right);
    }
}
