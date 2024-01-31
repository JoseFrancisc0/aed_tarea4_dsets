#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <vector>
using namespace std;

class Disjoint_Set{
    public:
        virtual void MakeSet(int x) = 0;
        virtual int Find(int x) = 0;
        virtual void Union(int x, int y) = 0;
        virtual bool isConected(int x, int y) = 0;

        virtual ~Disjoint_Set();
};

class DisjointSetArray: public Disjoint_Set{
    private:
        static const int MAX_SIZE = 100;
        int parent[MAX_SIZE];
        int rank[MAX_SIZE];
    public:
        DisjointSetArray(){
            for(int i = 0; i < MAX_SIZE; i++){
                parent[i] = 0;
                rank[i] = 0;
            }
        }

        void MakeSet(int x) override{
            parent[x] = x;
            rank[x] = 0;
        }

        int Find(int x) override{
            if(parent[x] == x)
                return x;
            else
                return Find(parent[x]);
        }

        void Union(int x, int y) override{
            int xRoot = Find(x);
            int yRoot = Find(y);

            if(rank[xRoot] < rank[yRoot])
                parent[xRoot] = yRoot;
            else if(rank[xRoot] > rank[yRoot])
                parent[yRoot] = xRoot;
            else{
                parent[yRoot] = xRoot;
                rank[xRoot]++;
            }
        }

        bool isConected(int x, int y) override{
            return Find(x) == Find(y);
        }

        ~DisjointSetArray() override = default;
};

class DisjointSetTree: public Disjoint_Set{
    private:
        struct Node{
            int parent;
            int rank;
        };

        vector<Node> nodes;

    public:
        DisjointSetTree(){};

        void MakeSet(int x) override{
            if(x >= nodes.size())
                nodes.resize(x + 1);

            nodes[x].parent = x;
            nodes[x].rank = 0;
        }

        int Find(int x) override{
            if(nodes[x].parent == x)
                return x;
            else
                return Find(nodes[x].parent);
        }

        void Union(int x, int y) override{
            int xRoot = Find(x);
            int yRoot = Find(y);

            if(nodes[xRoot].parent < nodes[yRoot].parent)
                nodes[xRoot].parent = yRoot;
            else if(nodes[xRoot].parent > nodes[yRoot].parent)
                nodes[yRoot].parent = xRoot;
            else{
                nodes[yRoot].parent = xRoot;
                nodes[xRoot].rank++;
            }
        }

        bool isConected(int x, int y) override{
            return Find(x) == Find(y);
        }

        ~DisjointSetTree() override = default;
};

#endif //DISJOINT_SET_H