///
/// benchmark.js
///

var readline = require('readline');

function timestamp() {
	return new Date().getTime();
}

function seconds_from(from) {
	return (timestamp() - from) / 1000.0;
}

// Fibonacci

function fibo(n) {
	return n < 2 ? n : fibo(n - 2) + fibo(n - 1);
}

// Matrix

function Matrix(M) {
	var R = [];
	for (var i = 0; i < M; ++i) {
		R[i] = [];
		for (var j = 0; j < M; ++j) {
			R[i][j] = Math.random();
		}
	}
	return R;
}

function show_matrix(matrix) {
	console.log('[');
	var M = matrix.length;
	for (var i = 0; i < M; ++i) {
		console.log('\n[');
		var row = matrix[i];
		var N = row.length;
		for (var j = 0; j < N; ++j) {
			console.log(matrix[i][j] + ' ');
		}
		console.log(']');
	}
	console.log('\n]');
}

function mmult(lhs, rhs) {
	var M = lhs.length;
	var K = lhs[0].length;
	console.assert(K == rhs.length);
	var N = rhs[0].length;
	var result = [];
	for (var i = 0; i < M; ++i) {
		result[i] = [];
		for (var j = 0; j < N; ++j) {
			var r = 0.0;
			for (var k = 0; k < K; ++k) {
				r = r + lhs[i][k] * rhs[k][j];
			}
			result[i][j] = r;
		}
	}
	return result;
}

// Matrix multiplication

function handler(command) {
	if (command === ".") {
		return -1;
	}
	var cmd = command.split(/\b\s+/)
	switch (cmd[0]) {
		case "fibo":
			var N = parseInt(cmd[1]);
			var start = timestamp();
			var result = fibo(N);
			var t = seconds_from(start);
			console.log("fibo(" + N + ") = " + result + " (" + t + "s)");
			break;
		case "mm":
			var N = parseInt(cmd[1]);
			var ML = Matrix(N);
			var MR = Matrix(N);
			var start = timestamp();
			var result = mmult(ML, MR);
			var t = seconds_from(start);
			console.log("(" + t + "s)");
			break;
		default:
			console.log("Huh?");
	}
}

function interactive(handler) {
	var rl = readline.createInterface(process.stdin, process.stdout);
	rl.setPrompt('<Benchmark> ');
	rl.prompt();

	rl.on('close', function () {
		process.exit(0);
	});

	rl.on('line', function (line) {
		var status = handler(line);
		if (status === -1) {
			rl.close();
		} else {
			rl.prompt();
		}
	});
}

interactive(handler);
