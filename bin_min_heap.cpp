#include<bits/stdc++.h>

using namespace std;

vector<int> heap;
bool stop = false;

class MinHeap{
    private:
        int* min_ptr;
    
    public:
        MinHeap() : min_ptr(NULL) {}

        void insert(int value){

            heap.push_back(value);
            if(min_ptr == NULL)
                min_ptr = &heap[0];
            
            else{
                bool fixed = false;
                int curr_idx = heap.size()-1;
                int parent_idx;
                int temp;

                while(!fixed){
                    parent_idx = (curr_idx % 2) ? (curr_idx / 2 ) : (curr_idx / 2 - 1);

                    if(heap[parent_idx] > heap[curr_idx]){
                        temp = heap[curr_idx];
                        heap[curr_idx] = heap[parent_idx];
                        heap[parent_idx] = temp;
                    }

                    else
                        fixed = true;

                    curr_idx = parent_idx;

                }
            }
            
            cout << "\n Inserted element " << value << "\n" << endl;
        }

        void print_min(){
            if(min_ptr == NULL){
                cout << "\n Heap is empty \n" << endl;
            }

            else{
                cout << "\n Min: " << *min_ptr << "\n" << endl;
            }
        }

        void delete_min(){
            if(heap.size() == 0)
                cout << "\n Heap is empty \n" << endl;

            else if(heap.size() == 1){
                heap.pop_back();
                min_ptr = NULL;
            }
            
            else{
                heap[0] = heap[heap.size()-1];
                heap.pop_back();

                int curr_idx = 0;
                int child_idx;
                int limit = (heap.size() % 2) ? (heap.size() / 2 ) : (heap.size() / 2 - 1);

                bool fixed = false;
                
                while(true){
                    if (curr_idx > limit)
                        break;

                    else{
                        child_idx = heap[2*curr_idx+1] < heap[2*curr_idx+2] ? (2*curr_idx+1) : (2*curr_idx+2);
                        child_idx = heap[curr_idx] > heap[child_idx] ? child_idx : curr_idx;

                        if(curr_idx == child_idx)
                            break;
                        
                        else{
                            int temp = heap[curr_idx];
                            heap[curr_idx] = heap[child_idx];
                            heap[child_idx] = temp;
                        }
                    }

                    curr_idx = child_idx;
                }
            }

        }

        void print_heap(){
            int out_sep = 16;

            int offset = 0;
            int limit = floor(log(heap.size()) / log(2));


            for(int i = 0; i <= limit; ++i){
                
                int end = heap.size() < (offset + pow(2,i)) ? heap.size() : (offset+pow(2,i));
                
                if(i == 0)
                    cout << string(out_sep-1, ' ') << ends;
                else
                    cout << string(out_sep, ' ') << ends;
                for(int j = offset; j < end; ++j){
                    cout << heap[j] << ends;

                    if(j != end-1){
                        cout << ' ' << ends;
                    }
                }
                cout << string(out_sep, ' ') <<endl;

                out_sep = out_sep - 2;
                offset = offset + pow(2,i);
                
            }
            cout << endl;
        }
};

MinHeap* h = NULL;

void print_menu(){
    cout<< "\n\n\t------ Menu------"<<endl;
    cout<<"\t(1) Create empty Min Heap"<<endl;
    cout<<"\t(2) Insert element"<<endl;
    cout<<"\t(3) Print min"<<endl;
    cout<<"\t(4) Delete min"<<endl;
    cout<<"\t(5) Print Heap"<<endl;
    cout<<"\t(6) Exit\n\n"<<endl;
}

void get_and_do(){
    int op; cin >> op;

    if(op == 1){
        heap.clear();
        h = new MinHeap();
        cout << "\n Created empty Heap \n" << endl;
    }

    else if(op == 2){
        if(h == NULL)
            cout << "\n Create MinHeap first using (1)" << endl;
        
        else{
            cout << "\nEnter element to be inserted: " << ends;
            int value; cin >> value;

            h->insert(value);
        }
    }

    else if(op == 3){
        if(h == NULL)
            cout << "\n Create MinHeap first using (1)" << endl;
        
        else{
            h->print_min();
        }
    }

    else if(op == 4){
        if(h == NULL)
            cout << "\n Create MinHeap first using (1)" << endl;
        
        else{
            h->delete_min();
        }
    }

    else if(op == 5){
        if(h == NULL)
            cout << "\n Create MinHeap first using (1)" << endl;
        
        else{
            h->print_heap();
        }
    }

    else if(op == 6){
        stop = true;
    }

    else{
        cout << "\n Enter a valid option between (1) and (6)" << endl;
    }
}

int main(){

    /*
        Menu - driven program
        1) Create empty Min heap
        2) insert element
        3) Print min
        4) Delete min
        5) Print heap
        6) Exit
    */

    while(!stop){
        print_menu();

        get_and_do();
    }

    cout << "\n------Program Terminated------\n" <<endl; 

    return 0;
}