/*Question:https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

Solution:*/
class Solution {
    public static ArrayList<String> findPath(int[][] m, int n) {
        ArrayList<String> list= new ArrayList<String>();
        boolean vis[][]=new boolean[n][n];
        String s="";
        if(m[0][0]==0)
            return list;
        else
            find(m,vis,n,0,0,s,list);
        Collections.sort(list);
        return list;
    }
    static void find(int[][] m,boolean vis[][],int n,int si,int sj,String s,ArrayList<String> list)
    {
        if(si==n-1 && sj==n-1 && m[si][sj]==1)
            {
                list.add(s);
                s="";
                return;
            }
        if(si<0 || si>=n || sj<0 || sj>=n)
            return;
        if(vis[si][sj] || m[si][sj]==0)
            {
                s="";
                return;
            }
        vis[si][sj]=true;
        
        s+="R";
        find(m,vis,n,si,sj+1,s,list);
        s=s.substring(0,s.length()-1);
        
        
        s+="D";
        find(m,vis,n,si+1,sj,s,list);
        s=s.substring(0,s.length()-1);
        
        s+="L";
        find(m,vis,n,si,sj-1,s,list);
        s=s.substring(0,s.length()-1);
        
        s+="U";
        find(m,vis,n,si-1,sj,s,list);
        s=s.substring(0,s.length()-1);
        vis[si][sj]=false;
        
    }
}
