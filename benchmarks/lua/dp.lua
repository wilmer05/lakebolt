memo = {}
d = {}
oo = 1000000;
v = {};
N = 0
--io.write(string.format("%s\n",v[0]<=v[1]));
T = io.read("*number");
a = {}
v2 = {}
function sort()
    a = {}
    v2 = {}
    for n in pairs(v) do 
        --print(v[n])
        table.insert(a,v[n]) 
    end
    table.sort(a)
    for i,n in ipairs(a) do 
        --io.write(string.format("%d ->",c) .. n)
        --print(i)
        v2[i-1] = n
    end
end

function init(v1,v2)
    memo={}
    d={}
    for i=0,v1+1 do
       memo[i]={}
       d[i]={}
       for j=0,v2+1 do
            memo[i][j]=-1
       end 
       
       for j=0,v1+1 do
            d[i][j]=0
       end 
    end

end

function calc() 
    local i = 0
    local j = 0
    for i=0,N do
        for j=i+1,N do
            local sz = string.len(v2[i])
            local sz2 = string.len(v2[j])
            sz = math.min(sz,sz2)
           -- print(sz)
           -- print(sz2)
            local dd = 1
            while(dd<=sz and string.byte(v2[i],dd,dd)==string.byte(v2[j],dd,dd)) do 
                --print(v2[i][dd])
                --print(v2[j][dd])
                dd = dd + 1 
            end
            dd = dd-1;
            --print()
            --print(dd)
            sz2 = sz2 - dd
            sz2 = sz2 + string.len(v2[i]) - dd
            d[i][j] = sz2
--            io.write(string.format("%d %d %d",i,j,d[i][j]) .. "\n")
        end
    end

end

function dp(nn,kk) 
    --io.write(string.format(nn) .. " - > " .. string.format(kk).."\n")
    if(kk==0) then
        return string.len(v2[nn])
    end
    if(nn>N) then return oo; end
    if(memo[nn][kk]~=-1) then return memo[nn][kk] end 
    memo[nn][kk]=oo
    for i=nn+1,N do
        --print(i)
        --print(d[nn][i])
        memo[nn][kk] = math.min(memo[nn][kk],dp(i,kk-1)+d[nn][i]+1)
    end
    return memo[nn][kk]
end

--sort();
for t=1,T do
    io.write("Case #" .. string.format("%d",t) .. ": ")
    N = io.read("*number")
    K = io.read("*number")
    init(N,K)
    --io.write(string.format("%d %d\n",N,K))
    --print(N)
    --print(K);
    v = {}
    io.read();
    for i=0,(N-1) do
        --print(i)
        v[i] = io.read()
        --io.write(v[i].."\n")
        --print(string.byte(v[i]))
        --print(string.len(v[i]))
        --if(v[i]=="") then i = i-1 end
    end
    v[N] = "";
    sort()
    --io.write("\n")
    --for i=0,N do
    --    if(v2[i]>v2[i+1]) then
    --        io.write(v2[i] .. "\n");
    --    end
    --end
    calc()
    --for i=0,N do
    --    print(v2[i])
    --end
    io.write(dp(0,K))
    io.write("\n")
end
