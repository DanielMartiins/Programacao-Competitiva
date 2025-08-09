let inputString = '';
process.stdin.on('data', (data) => {
    inputString += data;
})

process.stdin.on('end', (data) => {
    main();
})

function main() {
    const lines = inputString.trim().split("\n")
    const n = lines[0].trim();
    const arr = lines[1].trim().split(" ").map(Number);
    const map = new Map();

    let tallest = -1;
    for (const num of arr) {
        if (!map.get(num)) map.set(num, 1);
        else {
            const count = map.get(num);
            map.set(num, count+1);
        };
        tallest = Math.max(tallest, num);
    }

    console.log(map.get(tallest));
}