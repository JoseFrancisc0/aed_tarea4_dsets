#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

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

template<typename T>
class Disjoint_SetTree: public Disjoint_Set{
    private:
        // Define the structures
    public:
        Disjoint_SetTree();

        void MakeSet(int x) override;
        int Find(int x) override;
        void Union(int x, int y) override;
        bool isConected(int x, int y) override;

        ~Disjoint_SetTree() override;
};

#endif //DISJOINT_SET_H