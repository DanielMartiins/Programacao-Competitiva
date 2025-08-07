let inputString = "";
const closestPairs = [];

function resetClosestPairsArray() {
	closestPairs.splice(0, closestPairs.length);
}

process.stdin.on("data", function (chunk) {
	inputString += chunk;
});

process.stdin.on("end", function () {
	main();
});

function main() {
	const lines = inputString.trim().split("\n");
	const n = parseInt(lines[0]);
	const arr = lines[1].split(" ").map(Number);
	arr.sort(function (a, b) { return a - b;});

	let smallest_diff = Math.abs(arr[0] - arr[1]);
    closestPairs.push(arr[0])
    closestPairs.push(arr[1])
    for (let i = 2; i < n; i++) {
        const diff = Math.abs(arr[i-1] - arr[i]);
        if (diff === smallest_diff) {
            closestPairs.push(arr[i-1])
            closestPairs.push(arr[i])
        }
        else if (diff < smallest_diff) {
            resetClosestPairsArray();
            smallest_diff = diff;
            closestPairs.push(arr[i-1])
            closestPairs.push(arr[i])        
        }
    }

    process.stdout.write(closestPairs.join(' ') + '\n');
}
