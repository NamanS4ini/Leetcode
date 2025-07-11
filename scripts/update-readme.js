const fs = require("fs");
const fetch = require("node-fetch");

const username = "namansaini";

(async () => {
  const res = await fetch(`https://leetcode-stats-api.herokuapp.com/${username}`);
  const data = await res.json();

  const easy = data.easySolved;
  const medium = data.mediumSolved;
  const hard = data.hardSolved;
  const total = data.totalSolved;
  const today = new Date().toISOString().split("T")[0];

  const readmePath = "./README.md";
  let readme = fs.readFileSync(readmePath, "utf-8");

  // Replace problem counts
  readme = readme.replace(/🟢 Easy\s+\|\s+\d+/, `🟢 Easy     | ${easy}`);
  readme = readme.replace(/🟡 Medium\s+\|\s+\d+/, `🟡 Medium   | ${medium}`);
  readme = readme.replace(/🔴 Hard\s+\|\s+\d+/, `🔴 Hard     | ${hard}`);
  readme = readme.replace(/\*\*✅ Total\*\*\s+\|\s+\d+/, `**✅ Total**   | ${total}`);

  // Replace last updated timestamp
  readme = readme.replace(/<!-- LAST_UPDATED -->/, today);

  fs.writeFileSync(readmePath, readme);
})();
