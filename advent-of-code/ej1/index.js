const { readFile } = require("../readInput.js");

const numbers = {
  one: 1,
  two: 2,
  three: 3,
  four: 4,
  five: 5,
  six: 6,
  seven: 7,
  eight: 8,
  nine: 9,
};

function calibrateWithWords() {
  const input = readFile("./input.txt");
  let acum = 0;
  input.forEach((line, index) => {
    const { min, max } = findPatternIndex(line);
    // "2" || "two"
    let n = "";
    if (!isNaN(min)) {
      n += min;
    } else {
      n += numbers[min];
    }
    if (!isNaN(max)) {
      n += max;
    } else {
      n += numbers[max];
    }
    acum += parseInt(n);
    console.log({ line, n });
  });
  console.log(acum);
}

function findPatternIndex(str) {
  const pattern = new RegExp(Object.keys(numbers).join("|") + "|\\d", "g");
  const matches = str.match(pattern) || [];

  return {
    min: matches[0],
    max: matches[matches.length - 1],
  };
}

// Helper functions
// function findNumberIndex(str) {
//   const numberPattern = /\d+/g;
//   const nums = str.match(numberPattern);
//   return {
//     min: str.indexOf(nums[0]),
//     max: str.indexOf(nums[nums.length - 1]),
//   };
// }

// function findNumberStringIndex(str) {
//   const regex = new RegExp(numbers.join("|"), "g");
//   const strings = str.match(regex) || [];
//   const min = str.indexOf(strings[0]);
//   const max = str.indexOf(strings[strings.length - 1], min + 1);

//   return {
//     min,
//     max,
//   };
// }

calibrateWithWords();
