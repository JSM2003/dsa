#include<bits/stdc++.h>

using namespace std;

class llNode{
    public:
        int val;
        llNode* next;
        llNode(int value) : val(value), next(NULL) {}

};

class LinkedList{
    private:
        llNode* head;
    
    public:
        LinkedList() : head(NULL) {}

        void insert(int value){
            llNode* newNode = new llNode(value);
            llNode* curr = head;

            if(curr == NULL)
                head = newNode;

            else{
                while(curr->next != NULL){
                    curr = curr->next;
                }

                curr->next = newNode;
            }
            cout << "\n Inserted element " << value << "\n"<<endl;
        }

        void search(int value){
            llNode* curr = head;

            while(curr != NULL){
                if(curr->val == value)
                    break;
                
                curr = curr->next;
            }

            if(curr != NULL){
                cout << "\nElement " << value << " is present\n" << endl;
            }

            else
                cout << "\n Element " << value << " is not present\n" << endl;
        }

        void del(int value){
            llNode* curr = head;
            llNode* prev = head;

            while(curr != NULL){
                if(curr->val == value)
                    break;
                
                prev = curr;
                curr = curr->next;
            }

            if(curr == NULL){
                cout << "\n Element " << value << " is not present\n" << endl;
                return;
            }

            else if(prev == curr)
                head = NULL;
            
            else if(prev == head)
                head = curr;
            
            else{
                prev->next = prev->next->next;
                curr->next = NULL;
            }

            cout << "\n Element " << value << " was deleted\n" << endl;
        }

        void print_info(){
            int length = 0;

            llNode* curr = head;
            cout << "Linked List: " << ends;

            while(curr != NULL){
                cout << curr->val << ", " << ends;
                length++;
                
                curr = curr->next;
            }

            cout << "\nLength:"  << length << '\n' << endl;
        }
};

LinkedList* ll = NULL;
bool stop = false;

void print_menu(){
    cout<< "\n\n\t------ Menu------"<<endl;
    cout<<"\t(1) Create empty linked list"<<endl;
    cout<<"\t(2) Insert element at end"<<endl;
    cout<<"\t(3) Search element"<<endl;
    cout<<"\t(4) Delete 1st instance of element"<<endl;
    cout<<"\t(5) Print length and elements of linked list"<<endl;
    cout<<"\t(6) Exit\n\n"<<endl;
}

void get_and_do(){
    int op; cin >> op;

    if(op == 1){

        ll = new LinkedList;

        cout<< "\n Empty linked list created \n" <<endl;
    }

    else if(op == 2){
        if(ll == NULL)
            cout << "\n Create list first using (1)" << endl;
        
        else{
            cout << "\n Enter the element to be inserted: " << ends;
            int val; cin >> val;

            ll->insert(val);
        }
    }

    else if(op == 3){
        if(ll == NULL)
            cout << "\n Create list first using (1)" << endl;
        
        else{
            cout << "\n Enter the element to be found: " << ends;
            int val; cin >> val;

            ll->search(val);
        }
    }

    else if(op == 4){
        if(ll == NULL)
            cout << "\n Create list first using (1)" << endl;
        
        else{
            cout << "\n Enter the element to be deleted: " << ends;
            int val; cin >> val;

            ll->del(val);
        }
    }

    else if(op == 5){
        if(ll == NULL)
            cout << "\n Create list first using (1)" << endl;

        else
            ll->print_info();
    }

    else if(op == 6){
        stop = true;
    }

    else
        cout << "\n Enter a valid option between (1) and (6) \n" << endl;
}

int main(){

    /*
        Menu - driven program
        1) Create Empty Linked List
        2) Insert element at end
        3) Search element
        4) Delete 1st instance of element
        5) Print length and elements of linked list
        6) Exit

    */

    

    while(!stop){
        print_menu();
        
        get_and_do();
    }

    cout << "\t------Program Terminated-------" << endl;
    
    return 0;
}