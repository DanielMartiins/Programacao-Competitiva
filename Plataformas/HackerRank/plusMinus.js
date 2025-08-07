'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;
process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the 'plusMinus' function below.
*
* The function accepts INTEGER_ARRAY arr as parameter.
*/

function plusMinus(arr) {
    let positives = 0, negatives = 0, zeros = 0;
    const length = arr.length;
    for (const num of arr) {
        if (num > 0) positives++;
        else if (num < 0) negatives++;
        else zeros++
    }

    process.stdout.write((positives/length).toFixed(6) + "\n");
    process.stdout.write((negatives/length).toFixed(6) + "\n");
    process.stdout.write((zeros/length).toFixed(6) + "\n");
}

function main() {
    const n = parseInt(readLine().trim(), 10);

    const arr = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));

    plusMinus(arr);
}