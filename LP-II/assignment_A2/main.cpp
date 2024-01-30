/*
Using A* algorithm to solve the cat and milk problem
*/

#include<bits/stdc++.h>
using namespace std;
class OpenList{
    public:
    OpenList(pair<int,int> coordinate,int f){
        this->coordinate=coordinate;
        this->f=f;
    }
    pair<int,int> coordinate;
    int f;
};
class Node{
    int f,g,h,x,y;
    bool obstacle;
    public:
        Node(int f=0,int g=0,int h=0){
            this->f=this->g+this->h;
            this->g=g;
            this->h=h;
        }
        int getF(){
            return f;
        }
        int getG(){
            return g;
        }
        int getH(){
            return h;
        }
        void setF(int f){
            this->f=this->g+this->h;
        }
        void setG(int g){
            this->g=g;
        }
        void setH(int h){
            this->h=h;
        }
        bool isObstacle(){
            return this->obstacle;
        }
        void setObs(bool obs){
            this->obstacle=obs;
        }
        int setPoint(int x,int y){
            this->x=x;
            this->y=y;
        }
        pair<int,int> getPoint(){
            return make_pair(x,y);
        }
};
void init(vector<vector<Node>> &g){
    for(int i = 0;i<g.size();i++){
        for(int j = 0;j<g[0].size();j++){
            g[i][j].setPoint(i,j);
        }
    }
    return;
}
void getObstacles(vector<vector<Node>> &v){
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v[0].size();j++){
            if(v[i][j].isObstacle())
            cout<<"["<<i<<"],["<<j<<"]\n";
        }
    }
}
int main(){
    vector<OpenList> openList;
    vector<pair<int,int>> closeList;
    vector<vector<Node>> g(5,vector<Node>(4));
    init(g);
    cout<<"The size of the matrix is "<<g.size()<<"x"<<g[0].size()<<"\n";
    cout<<"Enter obstacles \n";
    while(true){
        cout<<"Enter (-1,-1) to stop\n";
        int x,y;
        cin>>x>>y;
        if(x==-1 && y==-1){
            break;
        }
        g[x][y].setObs(true);
    }
    getObstacles(g);
    return 0;
}