class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        int[][] temp=new int[n][n];
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                temp[y][x]=matrix[n-1-x][y];       
            }
        }
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                matrix[y][x]=temp[y][x];
            }
        }
    }
}