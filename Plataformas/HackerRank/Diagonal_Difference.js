let inputString = "";

process.stdin.on("data", (data) => {
	inputString += data;
});

process.stdin.on("end", () => {
	main();
});

function main() {
	const lines = inputString.trim().split("\n");
	const n = lines[0];
	lines.splice(0, 1);
	const matrix = lines.map((line) =>
		line.split(" ").map((num) => parseInt(num))
	);

    let primDiag = 0, secDiag = 0;
    for (let i = 0; i < n; i++) primDiag += matrix[i][i];
    for (let i = n-1; i >= 0; i--) secDiag += matrix[i][n-(i+1)];

    const answer = Math.abs(primDiag- secDiag);
    console.log(answer);
}
