class Solution {
    int lowerBound(int[] arr, int x){
        int low = 0, high = arr.length - 1, index = arr.length;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(arr[mid] < x){
                low = mid + 1;
            }
            else{
                index = mid;
                high = mid - 1;
            }
        }
        return index;
    }
    
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> kClosestElements = new ArrayList <>();
        int leftEnd = lowerBound(arr, x) - 1;
        int rightEnd = leftEnd + 1;
        while(kClosestElements.size() < k){
            if(rightEnd == arr.length || leftEnd >= 0 && x - arr[leftEnd] <= arr[rightEnd] - x){
                kClosestElements.add(arr[leftEnd]);
                leftEnd--;
            }
            else{
                kClosestElements.add(arr[rightEnd]);
                rightEnd++;
            }
        }
        Collections.sort(kClosestElements);
        return kClosestElements;
    }
}
