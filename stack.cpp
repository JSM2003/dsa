#include<bits/stdc++.h>

using namespace std;
bool stop = false;

class Node{
    public:
        int val;
        Node* next;

        Node(int value) : val(value) , next(NULL) {}
};

class Stack{
    private:
        Node* stack_ptr;
        Node* head;
    public:
        Stack() : head(NULL), stack_ptr (NULL) {}

        void push(int val){
            Node* newnode = new Node(val);

            if(stack_ptr != NULL)
                stack_ptr->next = newnode;
            
            else
                head = newnode;
            
            stack_ptr = newnode;
            
        }

        void pop(){
            if(head == NULL){
                cout << "\n Stack is already empty \n" << endl;
                return;
            }

            else if(head == stack_ptr)
                head = stack_ptr = NULL;
            
            else{
                Node* curr = head;

                while(curr->next != stack_ptr){
                    curr = curr->next;
                }

                stack_ptr = curr;
                stack_ptr->next = NULL;
            }

            cout << "\n Stack's top is popped \n" << endl;
        }

        void isEmpty(){
            if(head == NULL)
                cout << "\n YES \n" << endl;
        
            else
                cout << "\n NO \n" << endl;
        }

        void print_info(){
            int length = 0;
            string op= "";
            string temp;

            Node* curr = head;
            while(curr != NULL){

                temp = to_string(curr->val);
                op = temp + ", " + op;
                
                length++;
                
                curr = curr->next;
            }

            cout << "Stack: " << op << '\n'<< ends;
            cout << "\nLength: " << length << '\n' << endl;
        }

};

Stack* s = NULL;

void print_menu(){
    cout<< "\n\n\t------ Menu------"<<endl;
    cout<<"\t(1) Create empty Stack"<<endl;
    cout<<"\t(2) Push"<<endl;
    cout<<"\t(3) Pop"<<endl;
    cout<<"\t(4) IsEmpty"<<endl;
    cout<<"\t(5) Print length and elements of stack"<<endl;
    cout<<"\t(6) Exit\n\n"<<endl;
}

void get_and_do(){
    int op; cin >> op;

    if(op == 1){

        s = new Stack;

        cout<< "\n Empty linked list created \n" <<endl;
    }

    else if(op == 2){
        if(s == NULL)
            cout << "\n Create list first using (1)" << endl;
        
        else{
            cout << "\n Enter the element to be pushed: " << ends;
            int val; cin >> val;

            s->push(val);
        }
    }

    else if(op == 3){
        if(s == NULL)
            cout << "\n Create list first using (1)" << endl;
        
        else{

            s->pop();
        }
    }

    else if(op == 4){
        s->isEmpty();
        
    }

    else if(op == 5){
        s->print_info();
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
        1) Create Empty Stack
        2) Push
        3) Pop
        4) IsEmpty
        5) Exit

    */
    while(!stop){
        print_menu();
        
        get_and_do();
    }

    cout << "\t------Program Terminated-------" << endl;
    return 0;
}