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

class Disjoint_SetArray: public Disjoint_Set{
    public:
        Disjoint_SetArray();

        void MakeSet(int x) override;
        int Find(int x) override;
        void Union(int x, int y) override;
        bool isConected(int x, int y) override;

        ~Disjoint_SetArray() override;
};

class Disjoint_SetTree: public Disjoint_Set{
    public:
        Disjoint_SetTree();

        void MakeSet(int x) override;
        int Find(int x) override;
        void Union(int x, int y) override;
        bool isConected(int x, int y) override;

        ~Disjoint_SetTree() override;
};

#endif //DISJOINT_SET_H