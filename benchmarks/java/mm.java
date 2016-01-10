import java.util.*;
class matriz{
    int[][] mat;
    int d1,d2;
    public matriz(){
    }
    public matriz(int dim1, int dim2){
        d1 = dim1;
        d2 = dim2;
        mat = new int[dim1][dim2];
    }

    public matriz product(matriz ot){
       matriz ans = new matriz(d1,ot.d2);
       for(int i=0;i<d1;i++){
        for(int j=0;j<ot.d2;j++){
            for(int k=0;k<ot.d1;k++)
                ans.mat[i][j]+=mat[i][k]*mat[k][j];
        }
       } 
       return ans; 
    }

}
public class mm{
    public static void main(String[] args){
       if(args.length!=1) {
            System.out.println("Usage: java mm <dimension>");
            return;
        }
        int dim = Integer.parseInt(args[0]);  
        matriz ans = new matriz(dim,dim);
        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
                ans.mat[i][j]=2;
        ans.mat[1][1]=3;
        ans = ans.product(ans);
        
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++)
                System.out.print(Integer.toString(ans.mat[i][j])+" ");
            System.out.println();
        }
    }
}
