var queue=require('./Queue');

var n = parseInt(process.argv[2]);
var m = parseInt(process.argv[3]);
var q = new queue.Queue();
var visit = new Array(n);
var tmp = 1;
var graph = new Array(n);
for(i=0;i<n;i++) visit[i]=0,graph[i]=new Array();
while(tmp<n) tmp*=10;

for(i=0;i<m;i++){
    u = Math.floor((Math.random()*tmp))%n;
    v = Math.floor((Math.random()*tmp))%n;
//    console.log(u + " -> " + v );
    graph[u].push(v);
    graph[v].push(u);        
}

for(i=0;i<n;i++){
    if(visit[i]==0){
        visit[i]=1;
        q.enqueue(i);
        while(q.getLength()>0){
            var nod = q.dequeue();
 //           console.log(nod);
            for(j=0;j<graph[nod].length;j++){
                var nx = graph[nod][j];
                if(visit[nx]==0){
                    q.enqueue(nx);
                    visit[nx]=1;
                }
            }
        } 
    }
}

console.log("done");
