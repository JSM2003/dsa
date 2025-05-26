#include<bits/stdc++.h>

using namespace std;
bool stop = false;

class Node{
    public:
        int val;
        Node* next;

        Node(int value) : val(value) , next(NULL) {}
};

class Queue{
    private:
        Node* head;
    public:
        Queue() : head(NULL) {}

        void enqueue(int val){
            Node* newnode = new Node(val);

            Node* curr = head;

            if(curr == NULL)
                head = newnode;

            else{
                while(curr->next != NULL){
                    curr = curr->next;
                }

                curr->next = newnode;
            }
            cout << "\n Enqueued element " << val << "\n"<<endl;
            
        }

        void dequeue(){
            if(head->next == NULL)
                head = NULL;
            
            else{
                Node* aft_head = head->next;
                head->next = aft_head->next;
                aft_head->next = NULL;
            }

            cout << "\n Dequeued \n" << endl;
        }

        void isEmpty(){
            if(head == NULL)
                cout << "\n YES \n" << endl;
        
            else
                cout << "\n NO \n" << endl;
        }

        void print_info(){
            int length = 0;

            Node* curr = head;
            cout << "Queue: " << ends;

            while(curr != NULL){
                cout << curr->val << ", " << ends;
                length++;
                
                curr = curr->next;
            }

            cout << "\nLength:"  << length << '\n' << endl;
        }

};

Queue* q = NULL;

void print_menu(){
    cout<< "\n\n\t------ Menu------"<<endl;
    cout<<"\t(1) Create empty Queue"<<endl;
    cout<<"\t(2) Enqueue"<<endl;
    cout<<"\t(3) Dequeue"<<endl;
    cout<<"\t(4) IsEmpty"<<endl;
    cout<<"\t(5) Print length and elements of Queue"<<endl;
    cout<<"\t(6) Exit\n\n"<<endl;
}

void get_and_do(){
    int op; cin >> op;

    if(op == 1){

        q = new Queue;

        cout<< "\n Empty Queue created \n" <<endl;
    }

    else if(op == 2){
        if(q == NULL)
            cout << "\n Create queue first using (1)" << endl;
        
        else{
            cout << "\n Enter the element to be pushed: " << ends;
            int val; cin >> val;

            q->enqueue(val);
        }
    }

    else if(op == 3){
        if(q == NULL)
            cout << "\n Create queue first using (1)" << endl;
        
        else{

            q->dequeue();
        }
    }

    else if(op == 4){
        if(q == NULL)
            cout << "\n Create queue first using (1)" << endl;
        else
            q->isEmpty();
        
    }

    else if(op == 5){
        if(q == NULL)
            cout << "\n Create queue first using (1)" << endl;
        else
            q->print_info();
    }

    else if(op == 6){
        stop = true;
    }

    else
        cout << "\n Enter a valid option between (1) and (5) \n" << endl;
}

int main(){
    /*
        Menu - driven program
        1) Create Empty Queue
        2) Enqueue
        3) Dequeue
        4) IsEmpty
        5) Print length and elements of queue
        6) Exit

    */
    while(!stop){
        print_menu();
        
        get_and_do();
    }

    cout << "\t------Program Terminated-------" << endl;
    return 0;
}