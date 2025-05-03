class DisjointSet{
    vector<int> size,par;
    public:
         DisjointSet(int n){
             size.resize(n+1);
             par.resize(n+1);
             for(int i=0;i<=n;i++){
                 par[i]=i;
                 size[i]=1;
             }
         }
         int findUpar(int node){
             if(node==par[node])return node;
             return par[node]=findUpar(par[node]);
         }
         void unionBySize(int u,int v){
             int ult_u=findUpar(u);
             int ult_v=findUpar(v);
             if(ult_v==ult_u)return;
             if(size[ult_u]<size[ult_v]){
                 par[ult_u]=ult_v;
                 size[ult_v]+=size[ult_u];
             }
             else{
                 par[ult_v]=ult_u;
                 size[ult_u]+=size[ult_v];
             }
         }
};
