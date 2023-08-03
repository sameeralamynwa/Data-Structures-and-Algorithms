var letterCombinations = function(digits) {
  const digitToLetters = {
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz",
  };

  const backtrack = (index, combination) => {
    if (index === digits.length) {
      allCombinations.push(combination);
      return;
    }
    
    const currentDigit = digits[index];
    const letters = digitToLetters[currentDigit];

    for (const letter of letters) {
      backtrack(index + 1, combination + letter);
    }

  };

  const allCombinations = [];
  if (digits.length > 0) {
    backtrack(0, "");
  }
  return allCombinations;
};
