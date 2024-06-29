//danial tighbakhsh    4001406114
#include <iostream>
using namespace std;
template < typename input_type > 
class Node { 
public: 
    input_type data; 
    Node* next;
    Node* previous; 
    Node(input_type value){ 
        this->data = value; 
        this->next = nullptr; 
        this->previous = nullptr;
    } 
};  
template < typename input_type > 
class link_list{
    private:
        Node<input_type>* head;
    public:
        int size = 0;//size of link list
        link_list(){
            head = nullptr;
        }
        //=========================================================================================================================
        bool is_empty(){
            return (head == nullptr || size == 0);
        }
        //=========================================================================================================================
        void append_front(input_type value){        //Add value to front of link list
            //create a new Node
            Node<input_type>* newNode = new Node<input_type>(value);
            if(is_empty()){
                head = newNode;
            }else{
                Node<input_type>* temp = head; 
                while (temp->next != nullptr) { 
                    temp = temp->next; 
                }  
                temp->next = newNode; 
                newNode->previous = temp;
            }
            size++;     //count size of link list every time an value insert to link list
        } 
        //=========================================================================================================================
        void append_rear(input_type value){         //Add value to rear of link list
            //create a new Node
            Node<input_type>* newNode = new Node<input_type>(value);
            if(is_empty()){
                head = newNode;
            }else{
                newNode->next = head;
                head->previous = newNode;
                head = newNode;
            }
            size++;     //count size of link list every time an value insert to link list
        }   
        //=========================================================================================================================
        //Add a value between two values of data1, and data2 if they are continuous
        void append_between(input_type data1, input_type data2, input_type value){
            if(!is_empty()){
                Node<input_type>* temp = head; 
                bool flag1 = false;
                bool flag2 = false;
                while( temp->next != nullptr ){//it check if data1 and data2 are continuous and there is nothing between them
                    if( temp->data == data1 ){
                        flag1 = true;
                        temp = temp->next;
                        if( temp->data == data2 ){
                            flag2 = true;
                            break;
                        }
                        break;
                    }
                    temp = temp->next;
                }
                if( flag1 == true && flag2 == true ){
                    //set location of data1 and data2
                    Node<input_type>* newNode = new Node<input_type>(value);  
                    Node<input_type>* temp_before = temp->previous; 
                    temp = temp_before->next;
                    //------------------------------
                    temp->previous = newNode;
                    temp_before->next = newNode;
                    newNode->next = temp;
                    newNode->previous = temp_before;
                }else{
                    //Do nothing because two value aren`t continuous
                }
                size++;     //count size of link list every time an value insert to link list
            }
        }
        //=========================================================================================================================
        void replace(input_type find, input_type replace){//replace value of -find- with value of -replace- which will be given to function by user
            //will replace first given value in link list by another value
            if(!is_empty()){
                Node<input_type>* temp = head; 
                while(temp->data != find)
                    temp = temp->next;
                temp->data = replace;
            }else{
                //Do nothing because link list is empty
            }
        }
        //=========================================================================================================================
        void reverse(){//reverse link list values
            if(!is_empty()){
                Node<input_type>* first = head; 
                Node<input_type>* last = head; 
                input_type data_temp;
                while(last->next != nullptr)
                    last = last->next;
                while((first != last) && (first->previous != last) && (last->next != first)){
                    data_temp = first->data;
                    first->data = last->data;
                    last->data = data_temp;
                    first = first->next;
                    last = last->previous;
                }
            }else{
               //Do nothing because link list is empty 
            }
        }
        //=========================================================================================================================
        int count(){//return size of link list
            //if you change size it will change link delete duplicate or delete value or delete index
            if(!is_empty()){
                return size;
            }else{
                return -1;
            }
        }
        //=========================================================================================================================
        void delete_value(input_type value){//delete first node value which is same to given value
            Node<input_type>* temp = head;
            bool flag = false;
            if(!is_empty()){
                while(temp->data != value && temp != nullptr){
                    if (temp->next == nullptr){
                        cout<<value<<" doesn`t find in link list\n";
                        flag = true;
                        break;
                    }
                    temp = temp->next;
                }
                if(temp != nullptr && flag == false){
                    if(temp->previous != nullptr){
                        temp->previous->next = temp->next;
                    }else{
                        head = temp->next;
                    }
                    if(temp->next != nullptr){
                        temp->next->previous = temp->previous;
                    }
                    delete temp;
                    this->size--;//reduce size one time
                }
            }

        }
        //=========================================================================================================================
        void delete_index(int index){//delete value of given index
            Node<input_type>* temp = head;
            if(!is_empty() && index < this->size){
                while(index > 0){
                    temp = temp->next;
                    index--;
                }
                if(temp->previous != nullptr){
                    temp->previous->next = temp->next;
                }else{
                    head = temp->next;
                }
                if(temp->next != nullptr){
                    temp->next->previous = temp->previous;
                }
                delete temp;
                this->size--;//reduce size one time
                }
            }
        //=========================================================================================================================
        int find_index_of_value(input_type value){//return index of value
            int index = 0 ;
            Node<input_type>* temp = head;
            if(!is_empty()){ 
                while(temp->data != value){
                    index++;
                    temp = temp->next;
                    if(index >= size){
                        return -1;
                    }
                }
                return index;
            }else{
                return -1;
            }
        }
        //=========================================================================================================================
        input_type find_value_of_index(int index){//return value of index
            Node<input_type>* temp = head; 
            if(!is_empty() && index <= size){
                for(int i = 0 ; i != index ; i++){
                    temp = temp->next;
                }
                return temp->data;
            }else{
                cout<<"index "<<index<<" is out of range";
                return input_type();
            }
        }
        //=========================================================================================================================
        void delete_duplicate(input_type key){//delete all duplicate values except first one
            Node<input_type>* temp1 = head; 
            if(temp1 == nullptr || temp1->next == nullptr)  return;//if link list are empty or has only one Node
            while(temp1 != nullptr && temp1->data != key){
                temp1 = temp1->next;
            }
            if(temp1 == nullptr)    return;// if key doesn`t exist
            Node<input_type>* temp2 = temp1->next;
            while(temp2 != nullptr){
                if(key == temp2->data){
                    temp2->previous->next = temp2->next;
                    if(temp2->next != nullptr){
                        temp2->next->previous = temp2->previous;
                    }
                    Node<input_type>* temp3 = temp2->next;
                    delete temp2;
                    this->size--;//reduce size one time
                    temp2 = temp3;
                }else{
                    temp2 = temp2->next;
                }
            } 
        }
        //=========================================================================================================================
        input_type max_value(){//return maximum value of link list
            if(!is_empty()){
                Node<input_type>* temp = head; 
                input_type max = temp->data;//give value of first node to max
                while(temp != nullptr){
                    if(temp->data > max){
                        max = temp->data;
                    }
                    temp = temp->next;
                }
                return max;
            }else{
                return input_type();
            }
        }
        //=========================================================================================================================
        input_type min_value(){//return minimum value of link list
            if(!is_empty()){
                Node<input_type>* temp = head; 
                input_type min = temp->data;//give value of first node to min
                while(temp != nullptr){
                    if(temp->data < min){
                        min = temp->data;
                    }
                    temp = temp->next;
                }
                return min;
            }else{
                return input_type();
            }
        }
        //=========================================================================================================================
        input_type sum(){//return summation of all values
            if(!is_empty()){
                Node<input_type>* temp = head; 
                input_type sum = input_type();
                while(temp != nullptr){
                    sum += temp->data;
                    temp = temp->next;
                }
                return sum;
            }else{
                return input_type();
            }
        }
        //=========================================================================================================================
        void show(){//show link list
            if(!is_empty()){
                Node<input_type>* temp = head; 
                for (int i = 0 ; temp != nullptr ; i++){
                    cout<<temp->data<<", ";
                    temp = temp->next;
                }
                cout<<'\n';
            }
        }
        input_type pop_first(){//return first node`s value and move head to next node
        //it work like queue and change link list nodes
            if(!is_empty()){
                input_type value = head->data;
                if(head->next != nullptr){
                    head = head->next;
                }
                delete head->previous;
                head->previous = nullptr;
                size--;
                return value;
            }else{
                return input_type();
            }
        }
        input_type pop_last(){//return last node`s value and delete it
        //it work like stack and change link list nodes
            if(!is_empty()){
                Node<input_type>* temp = head; 
                for (int i = 0 ; temp->next != nullptr ; i++){
                    temp = temp->next;
                }
                input_type value = temp->data;
                if(temp->previous != nullptr){
                    temp->previous->next = nullptr;
                }
                delete temp;
                size--;
                return value;
            }else{
                return input_type();
            }
        }
        //=========================================================================================================================
};
int main(){
    link_list<int> a;
    a.append_front(25);
    cout<<a.pop_first()<<'\n';
    a.append_front(68);
    a.append_front(47);
    a.append_rear(-58);
    a.append_front(976);
    a.append_front(11);
    a.show();
    a.delete_value(212);
    a.show();
    a.delete_value(78);
    cout<<a.find_index_of_value(36)<<'\n';
    cout<<a.find_value_of_index(365422)<<'\n';
    a.show();
    a.delete_duplicate(12);
    cout<<a.pop_first()<<'\n';
    cout<<"===========================\n";
    cout<<a.pop_last()<<'\n'; 
    return 0;
}
