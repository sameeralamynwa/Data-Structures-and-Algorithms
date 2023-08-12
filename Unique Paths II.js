var uniquePathsWithObstacles = function(obstacleGrid) {
    const numRows = obstacleGrid.length;
    const numCols = obstacleGrid[0].length;
    
    const pathsCount = new Array(numRows).fill().map(() => new Array(numCols).fill(0));
    
    for (let row = 0; row < numRows; row++) {
        for (let col = 0; col < numCols; col++) {
            if (obstacleGrid[row][col] === 1) {
                pathsCount[row][col] = 0;
            } else if (row === 0 && col === 0) {
                pathsCount[row][col] = 1;
            } else if (row === 0) {
                pathsCount[row][col] = pathsCount[row][col - 1];
            } else if (col === 0) {
                pathsCount[row][col] = pathsCount[row - 1][col];
            } else {
                pathsCount[row][col] = pathsCount[row - 1][col] + pathsCount[row][col - 1];
            }
        }
    }
    
    return pathsCount[numRows - 1][numCols - 1];
};
