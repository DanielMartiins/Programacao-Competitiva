let inputString = "";

process.stdin.on("data", (data) => {
	inputString += data;
});

process.stdin.on("end", () => {
	main();
});

function main() {
	const input = inputString.trim().split("\n");
	const n = parseInt(input[0]);
	const arr = input[1].split(" ").map(Number);

	let positives, negatives, zeroes;
	positives = negatives = zeroes = 0;
	for (const num of arr) {
		if (num > 0) positives++;
		else if (num < 0) negatives++;
		else zeroes++;
	}

	console.log(
		(positives/arr.length).toFixed(6) + '\n' +
		(negatives/arr.length).toFixed(6) + '\n' +
		(zeroes/arr.length).toFixed(6)
	)
}
