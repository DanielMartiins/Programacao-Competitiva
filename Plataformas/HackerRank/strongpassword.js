let inputString = "";

process.stdin.on("data", function (data) {
	inputString += data;
});

process.stdin.on("end", function () {
	main();
});

function minimumNumber(password) {
	let answer = 0;
    let invalidCriterias = 0;
    const passLength= password.length;
	const verifications = [
		"[a-z]", //Contains at least one lowercase letter
		"[A-Z]", //Contains at least one uppercase letter
		"[0-9]", //Contains at least one digit
		"[!@#$%^&*()+-]", //Contains at least one special character
	];

    for (const regexStr of verifications) {
        if (!(new RegExp(regexStr).test(password)))
            invalidCriterias++;
    }

    answer = Math.max(invalidCriterias, 6 - passLength)
    console.log(answer);
}

function main() {
	const lines = inputString.trim().split("\n");
	const n = lines[0];
	const password = lines[1];

    minimumNumber(password);
}
