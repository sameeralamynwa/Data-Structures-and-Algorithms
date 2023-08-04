var wordBreak = function(s, wordDict) {
    const canBreakTill = new Array(s.length).fill(false);
    
    for(let rightIndex = 0; rightIndex < s.length; ++rightIndex){
        for(let leftIndex = 0; leftIndex <= rightIndex; ++leftIndex){
            if(wordDict.includes(s.substring(leftIndex, rightIndex + 1))){
                canBreakTill[rightIndex] |= leftIndex == 0 || canBreakTill[leftIndex - 1];
            }
        }
    }

    return canBreakTill[s.length - 1];
};
