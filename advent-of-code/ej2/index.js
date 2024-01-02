const { readFile } = require("../readInput.js");

// part 1
const SET_OF_CUBES = {
  RED: 12,
  GREEN: 13,
  BLUE: 14,
};

const numRegex = /\d+/g;
function getPossibleGames() {
  const input = readFile("./input.txt");
  let possibleGames = 0;
  input.forEach((line) => {
    const gameId = parseInt(line.slice(0, 7).match(numRegex));
    const game = line.slice(7).split(";");
    const isPosible = game.every((play) => {
      const moves = play.split(",");
      return (isPlayPosible = moves.every((move) => {
        return getIsPosible(move);
      }));
    });
    if (isPosible) possibleGames += gameId;
  });
  console.log(possibleGames);
}

function getIsPosible(play) {
  if (play.includes("r")) {
    return parseInt(play.match(numRegex)) <= SET_OF_CUBES.RED;
  } else if (play.includes("g")) {
    return parseInt(play.match(numRegex)) <= SET_OF_CUBES.GREEN;
  } else if (play.includes("b")) {
    return parseInt(play.match(numRegex)) <= SET_OF_CUBES.BLUE;
  }
}

getPossibleGames();

// part 2 adapted version
function sumAllMins() {
  const input = readFile("./input.txt");
  return input
    .filter((n) => !!n)
    .map((r) => r.split(":"))
    .map((e) => ({
      gn: e[0],
      tn: e[1]
        .split(";")
        .map((x) => x.trim())
        .map((x) =>
          x
            .split(",")
            .map((z) => z.trim().split(" "))
            .reduce((acc, y) => ((acc[y[1]] = Number(y[0])), acc), {})
        ),
    }))
    .map(({ tn }) => {
      const mins = {
        red: 1,
        green: 1,
        blue: 1,
      };
      return tn.reduce((acc, x) => {
        if (x.red && x.red > acc.red) acc.red = x.red;
        if (x.green && x.green > acc.green) acc.green = x.green;
        if (x.blue && x.blue > acc.blue) acc.blue = x.blue;
        return acc;
      }, mins);
    })
    .reduce((acc, { red, green, blue }) => acc + red * green * blue, 0);
}

console.log(sumAllMins());
