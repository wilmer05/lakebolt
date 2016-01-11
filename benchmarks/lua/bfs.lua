require "queue"

q = List.new()

n = io.read("*number")
m = io.read("*number")
graph = {}
tam = {}
visit = {}
for i=0,n-1 do
    graph[i]={}
    tam[i]=0
    visit[i]=0
end

for i=0,m-1 do
    u = math.random(0,n-1)
    v = math.random(0,m-1)
    local usz = tam[u]
    local vsz = tam[v]
    graph[u][usz] = v
    graph[v][vsz] = u
    tam[u] = usz + 1
    tam[v] = vsz + 1
    --io.write(u)
    --io.write(" -> ")
    --io.write(v)
    --io.write("\n")
    
end

for i=0,n-1 do

    if(visit[i]==0) then
        visit[i]=1;
        List.pushright(q,i)
        while(q.first<= q.last) do
            local nod = List.popleft(q)
            local sz = tam[nod]
           -- io.write(nod)
           -- io.write("\n")
            for j=0,sz-1 do
                local nx = graph[nod][j]
                if(visit[nx]==0) then
                    visit[nx]=1
                    List.pushright(q,nx) 
                end
            end
            
        end
    end

end

