var combine = function(n, k) {
    const allCombinations = [];

    const backtrack = (start, currentCombination) => {
        if (currentCombination.length === k) {
            allCombinations.push(currentCombination.slice());
            return;
        }

        for (let i = start; i <= n; i++) {
            currentCombination.push(i);
            backtrack(i + 1, currentCombination);
            currentCombination.pop();
        }
    };

    backtrack(1, []);
    return allCombinations;
};
