var partition = function(s) {
    const palindromePartitions = [];
    
    const isPalindrome = (str) => {
        let left = 0, right = str.length - 1;
        while (left < right) {
            if (str[left] !== str[right]) return false;
            left++; right--;
        }
        return true;
    };
    
    const findPalindromePartitions = (start, currentPartition) => {
        if (start === s.length) {
            palindromePartitions.push([...currentPartition]);
            return;
        }
        
        for (let end = start; end < s.length; end++) {
            const candidate = s.substring(start, end + 1);
            if (isPalindrome(candidate)) {
                currentPartition.push(candidate);
                findPalindromePartitions(end + 1, currentPartition);
                currentPartition.pop();
            }
        }
    };
    
    findPalindromePartitions(0, []);
    return palindromePartitions;
};
