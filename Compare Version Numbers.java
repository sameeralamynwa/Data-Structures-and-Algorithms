class Solution {
    public int compareVersion(int pos1, int pos2, String version1, String version2){
        if(pos1 >= version1.length() && pos2 >= version2.length()){
            return 0;
        }
        
        int version1Value = 0, version2Value = 0;
        while(pos1 < version1.length() && version1.charAt(pos1) != '.'){
            version1Value *= 10;
            version1Value += (int) version1.charAt(pos1) - (int) '0';
            ++pos1;
        }
        while(pos2 < version2.length() && version2.charAt(pos2) != '.'){
            version2Value *= 10;
            version2Value += (int) version2.charAt(pos2) - (int) '0';
            ++pos2;
        }
        return version1Value == version2Value ? compareVersion(pos1 + 1, pos2 + 1, version1, version2) : version1Value > version2Value ? 1 : -1;
    }
    
    public int compareVersion(String version1, String version2) {
        return compareVersion(0, 0, version1, version2);
    }
}
