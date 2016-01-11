Trie = {}
Trie.__index = Trie

function Trie.new()
    local val = {}
    setmetatable(val,Trie)
    return val
end

function Trie.add(t,str,tam)
    --io.write(str)
    --io.write("\n")
    --io.write(" ") 
    --io.write(tam)
    --io.write("\n")
    if(0~=string.len(str)) then
        val = string.byte(str)
        if(t[val]==nil) then
              --io.write(val)
              t[val] = Trie.new()
        end

        Trie.add(t[val],string.sub(str,2),tam+1)
    end

end

ar = Trie.new()
tam = io.read("*number")
str = ""
for i=0,tam-1 do
    local val = math.random(97,97+25)
    str = str .. string.char(val) 
end
tmp = ""
for i=1,tam do
    tmp = string.sub(str,i)
    --io.write(tmp);io.write("\n") 
    Trie.add(ar,tmp,string.len(tmp))
end
--io.write(str) 
io.write("Done\n")
--bla = {}
--bla[string.byte("a")]='b';
--io.write(bla[string.byte("a")])
