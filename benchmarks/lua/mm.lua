dim = io.read("*number");

a = {}
b = {}
c = {}
temp = {}
temp2 = {}
for i=0, dim-1 do
    a[i]={}
    b[i]={}
    c[i]={}
    for j=0, dim-1 do
        a[i][j] = 2
        b[i][j] = 2
        c[i][j] = 0
    end
end

for i=0, dim-1 do
    for k=0, dim-1 do
        for j=0, dim-1 do
            c[i][j] = c[i][j] + (a[i][k]*b[k][j])
        end
    end
end

for i=0, dim-1 do
    for j=0,dim-1 do
        io.write(c[i][j])
        io.write(" ")
    end
    io.write("\n")
end
