function fibo(x)
    if(x<=2) then
        return 1;
    end
    return fibo(x-1) + fibo(x-2);
end

local number = io.read("*number");
io.write(string.format("%d \n",fibo(number)));
