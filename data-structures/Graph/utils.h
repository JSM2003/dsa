class llNode{
    public:
        int val;
        llNode* next;
        llNode(int x);
};

class LinkedList{
    public:
        llNode* head;
        LinkedList(llNode* hp);

        void insert(int value);
        void del(int value);
};