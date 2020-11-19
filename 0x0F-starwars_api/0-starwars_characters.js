#!/usr/bin/node
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request(url, async function (error, response, body) {
  if (error) return console.error(error);
  const characters = JSON.parse(body).characters;
  for (const character of characters) {
    await new Promise((resolve, reject) => {
      request(character, function (err, func, bod) {
        if (err) return console.error(err);
        console.log(JSON.parse(bod).name);
        resolve();
      });
    });
  }
});
