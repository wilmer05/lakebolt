var f = function fibo(x){
    if(x<=2) return 1;
    return fibo(x-1) + fibo(x-2);
}

var z = f(parseInt(process.argv[2]))
console.log(z)
