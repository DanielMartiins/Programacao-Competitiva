let inputString = "";

process.stdin.on("data", (data) => {
	inputString += data;
});

process.stdin.on("end", () => {
	main();
});

function swap(arr, i, j) {
    const aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux
}

function main() {
	const lines = inputString.trim().split("\n");
	const arr = lines[1].split(" ").map((num) => parseInt(num));
    const sortedArr = [...arr];
    const posSorted = new Map();
    let answer = 0;
    sortedArr.sort((a,b) => {return a - b});
    
    console.log(arr);
    console.log(sortedArr);

    for (let i = 0; i < sortedArr.length; i++)
        posSorted.set(sortedArr[i], i);

    for (let i = 0; i < arr.length; i++) {
        if (arr[i] != sortedArr[i]) {
            const j = posSorted.get(arr[i]);
            swap(arr, i, j);
            answer++;
        }
        cn
    }

    console.log(answer);
}
