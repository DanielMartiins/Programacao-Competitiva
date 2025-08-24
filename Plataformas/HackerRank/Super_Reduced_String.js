let inputString = "";

process.stdin.on("data", (data) => {
	inputString += data;
});

process.stdin.on("end", () => {
	main(inputString.trim());
});

function main(str) {
	let idx = 1;
	while (idx < str.length) {
		if (str.charAt(idx) === str.charAt(idx - 1)) {
			str =
			str.slice(0, idx - 1) + str.slice(idx + 1);
			idx = 1;
		}
		else idx++;
	}

	if (str.length === 0) console.log("Empty String");
	else console.log(str);
}
