// Check if the cell is path
const isPATH = (val) => {
  return val >= 0;
}

// Check if the cell is Diamond
const isDiamond = (val) => {
  return val === 1 ? 1 : 0;
}

// Check if the cell is Obstruction
const isObstruction = (val) => {
  return val === -1;
}

// Check if the cell is goal(n-1, n-1)
const isGoal = (mat, x, y) => {
  return x >= mat.length - 1 && y >= mat.length - 1;
}

// Check if current position is the out of Matrix
const isOutofMatrix = (mat, x, y) => {
  return x < 0 || x >= mat.length || y < 0 || y >= mat.length;
}

var isBack = -1; // isBack = 1 : I am on traveling back to (0, 0) after reaching (n-1, n-1)
var maxDiamond = 0; // Maximum number of Diamonds I can collect given the current Map.

// Check if I get back to (0, 0) after reaching (n-1, n-1)
const getBack = (x, y) => {
  return x === 0 && y === 0 && isBack === 1;
}

// Travelling and Calculate Maximum number of Diamonds.
const getMaxDiamond = (mat, x, y, curDiamondsCount) => {
  if (getBack(x, y)) {
    maxDiamond = Math.max(maxDiamond, curDiamondsCount);
    return;
  }

  // Move Left or Right.
  let posX = x;
  let posY = y - isBack;

  if (!isOutofMatrix(mat, posX, posY) && isPATH(mat[posX][posY])) {
    // Pick up Diamond
    const countDiamond = isDiamond(mat[posX][posY]) + curDiamondsCount;
    const prevMat = mat[posX][posY];
    mat[posX][posY] = 0;

    // if reached the Goal.
    let isG = 0;
    if (isGoal(mat, posX, posY)) {
      isBack = 1;
      isG = 1;
    }
    // Next travel
    getMaxDiamond(mat, posX, posY, countDiamond)
    // Back to previous status
    if (isG > 0) isBack = -1;
    mat[posX][posY] = prevMat;
  }

  // Move Up or Down
  posX = x - isBack;
  posY = y;

  if (!isOutofMatrix(mat, posX, posY) && isPATH(mat[posX][posY])) {
    // Pick up Diamond
    const countDiamond = isDiamond(mat[posX][posY]) + curDiamondsCount;
    const prevMat = mat[posX][posY];
    mat[posX][posY] = 0;

    // if reached the Goal.
    let isG = 0;
    if (isGoal(mat, posX, posY)) {
      isBack = 1;
      isG = 1;
    }
    // Next travel
    getMaxDiamond(mat, posX, posY, countDiamond)
    // Back to previous status
    if (isG > 0) isBack = -1;
    mat[posX][posY] = prevMat;
  }
}

// Start at (0, 0)
const collectMax = (mat) =>  {
  getMaxDiamond(mat, 0, 0, 0);
  return maxDiamond;
}

// Test Case: 5
let testCase = 5;

// Map list
var testMat = [
  [
    [0, 1, 1],
    [0, 0, 1],
    [-1, 0, 0],
  ],
  [
    [0, 1, 1],
    [0, 0, 1],
    [1, 0, 0],
  ],
  [
    [0, 1, 1, 0],
    [0, 0, 1, 0],
    [-1, 0, 0, 0],
    [-1, 0, 0, 0],
  ],
  [
    [0, 1, 1, 1],
    [0, 0, 0, 0],
    [-1, 1, 0, 0],
    [-1, 1, 1, 0],
  ],
  [
    [0, 1, 1, 1],
    [0, 0, 0, -1],
    [-1, 1, 0, 0],
    [-1, 1, 1, 0],
  ],
]

while(testCase--) {
  maxDiamond = 0;
  console.log('testCase: ', testCase, 'Matrix = ', testMat[testCase], 'Number of diamonds = ', collectMax(testMat[testCase]));
}
