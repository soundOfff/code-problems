const path = require("path");
const fs = require("fs");

const readFile = (dir) => {
  return fs.readFileSync(path.join(dir), "utf8").toString().trim().split("\n");
};

module.exports = {
  readFile,
};
