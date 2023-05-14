#include <bits/stdc++.h>

using namespace std;
class DisjointSet{
    //rank array
    vector<int> size;
    //parent array
    vector<int> parent;
    public:
    //constructor to initialize the objects
     DisjointSet(int n){
         //for 1-based indexing will work both o and 1 based graph
         
         size.resize(n+1);
         parent.resize(n+1);
         for(int i=0;i<n+1;i++){
             parent[i]=i;
             size[i]=1;
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
     void unionBySize(int u, int v){
         int ulp_u = findUPar(u);
         int ulp_v=findUPar(v);
           if(ulp_u==ulp_v){
               return;
           }
           if(size[ulp_u] < size[ulp_v]){
               parent[ulp_u] = ulp_v;
               size[ulp_v]+=size[ulp_u];
           }
           else {
               parent[ulp_v] = ulp_u;
               size[ulp_u]+=size[ulp_v];
               
           }
           
           
         }
     
     
};



int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // check 3 and 7 belongs to same component
    if(ds.findUPar(3) == ds.findUPar(7)){
      cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }
    ds.unionBySize(3,7);
    if(ds.findUPar(3) == ds.findUPar(7)){
      cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }
    

    return 0;
}


