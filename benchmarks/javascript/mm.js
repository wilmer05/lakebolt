function matriz(dim){
    this.d = dim;
    this.m = new Array(dim);
    for(i=0;i<dim;i++){
        this.m[i]=new Array(dim);
        for(j =0;j<dim;j++) this.m[i][j]=0;
    }
}

matriz.prototype.product = function(ot){
    
    dim = this.d;
    ans = new matriz(dim);
    for(i=0;i<dim;i++)
        for(j=0;j<dim;j++)
            for(k=0;k<dim;k++)
                ans.m[i][k]+=this.m[i][j]*ot.m[j][k];
    return ans; 
}

var dim = parseInt(process.argv[2]);

var m = new matriz(dim);

for(i=0;i<dim;i++)
    for(j=0;j<dim;j++)  
        m.m[i][j]=2;
m = m.product(m);
for(i=0;i<dim;i++){
    var line = "";
    for(j=0;j<dim;j++)
        line+= m.m[i][j]+" ";
    console.log(line);
}
