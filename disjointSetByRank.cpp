#include <bits/stdc++.h>

using namespace std;
class DisjointSet{
    //rank array
    vector<int> rank;
    //parent array
    vector<int> parent;
    public:
    //constructor to initialize the objects
     DisjointSet(int n){
         //for 1-based indexing will work both o and 1 based graph
         
         rank.resize(n+1,0);
         parent.resize(n+1);
         for(int i=0;i<n+1;i++){
             parent[i]=i;
         }
     }
     
     // find parent function with path compression
     int findUPar(int node){
         if(node==parent[node]){
             return node;
         }
         //compression
         return parent[node] = findUPar(parent[node]);
     }
     void unionByRank(int u, int v){
         int ulp_u = findUPar(u);
         int ulp_v=findUPar(v);
           if(ulp_u==ulp_v){
               return;
           }
           if(rank[ulp_u] < rank[ulp_v]){
               parent[ulp_u] = ulp_v;
               //no change in rank becoz 
               //we connect smmaller to larger one.
           }
           else if(rank[ulp_u] > rank[ulp_v]){
               parent[ulp_v] = ulp_u;
               //no change in rank becoz 
               //we connect smmaller to larger one.
           }
           else{
               //connect to any one
               parent[ulp_v] = ulp_u;
               // increase in rank by 1;
               rank[ulp_u]++;
           }
           
         }
     
     
};



int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    // check 3 and 7 belongs to same component
    if(ds.findUPar(3) == ds.findUPar(7)){
      cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }
    ds.unionByRank(3,7);
    if(ds.findUPar(3) == ds.findUPar(7)){
      cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }
    

    return 0;
}

