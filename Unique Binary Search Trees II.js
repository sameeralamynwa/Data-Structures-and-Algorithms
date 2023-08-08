var generateTrees = function(n) {
    if (n === 0) {
        return [];
    }
    
    return generateTreesHelper(1, n);
};

function generateTreesHelper(start, end) {
    const allPossibleTrees = [];
    
    if (start > end) {
        allPossibleTrees.push(null);
        return allPossibleTrees;
    }
    
    for (let rootValue = start; rootValue <= end; rootValue++) {
        const leftSubtrees = generateTreesHelper(start, rootValue - 1);
        const rightSubtrees = generateTreesHelper(rootValue + 1, end);
        
        for (const leftSubtree of leftSubtrees) {
            for (const rightSubtree of rightSubtrees) {
                const root = new TreeNode(rootValue, leftSubtree, rightSubtree);
                allPossibleTrees.push(root);
            }
        }
    }
    
    return allPossibleTrees;
}
