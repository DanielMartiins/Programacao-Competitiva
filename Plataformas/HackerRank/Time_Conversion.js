let inputString = "";

process.stdin.on("data", (data) => {
	inputString += data;
	inputString = inputString.trim();
});

process.stdin.on("end", () => {
	main();
});

function main() {
	const periodOfDay = inputString.endsWith("AM") ? "AM" : "PM";
	inputString = inputString.trim().slice(0, inputString.length - 2);

	const arr = inputString.split(":");
	let hour = arr[0].trim();

	if (hour === "12") {
		if (periodOfDay === "AM") arr[0] = "00";
		else arr[0] = "12";
	} else if (periodOfDay === "PM") arr[0] = parseInt(arr[0]) + 12;
	console.log(arr.join(":"));
}
