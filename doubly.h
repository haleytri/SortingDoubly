#ifndef DOUBLY_H
#define DOUBLY_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct node
{
    int val;
    node * next;
    node * prev;
    node(int x)
    {
        val = x;
        prev = nullptr;
        next = nullptr;
    }
};

class linked
{
    private:
        node * head;
    public:
        linked()
        {
            head = nullptr;
        }
        void insertAtEnd(int x)
        {
            node * temp = new node(x);
            if(head == nullptr)
            {
                head = temp;
            }
            else
            {
                node * cur = head;
                while(cur->next != nullptr)
                {
                    cur = cur->next;
                }
                cur->next = temp;
                temp->prev=cur;
            }
        }
        void print()
        {
            node * cur = head;
            cout << "[";
            while(cur->next != nullptr)
            {
                cout << cur->val << ",";
                cur = cur->next;
            }
            cout << cur->val;
            cout << "]" << endl;
        }
        void print(ofstream &out)
        {
            node * cur = head;
            out << "[";
            while(cur->next != nullptr)
            {
                out << cur->val << ",";
                cur = cur->next;
            }
            out << cur->val;
            out << "]" << endl;
        }
        void bubble(ofstream &out)
        {
            if(head->next == nullptr)
            {
                out << "[";
                out << head->val;
                out << "]";
                return;
            }
            node * cur = nullptr;
            bool flag = false;
            while (!flag)
            {
                flag = true;
                cur = head;
                while (cur->next != nullptr)
                {
                    if(cur->val > cur->next->val)
                    {
                        flag = false;
                        node *temp0 = cur->prev;
                        node *temp1 = cur;
                        node *temp2 = cur->next;
                        node *temp3 = cur->next->next;
                        temp1->next = temp3;
                        temp2->next = temp1;
                        temp2->prev = temp0;
                        temp1->prev = temp2;

                        if(temp3 != nullptr)
                        {
                        temp3->prev = temp1;
                        }
                        if(temp0 != nullptr)
                        {
                            temp0->next = temp2;
                        }
                        if(temp1 == head)
                        {
                            head = temp2;
                        }
                        //print();
                    }
                    else
                    {
                        cur = cur->next;
                    }
                    print(out);
                }
            }   
        }

        void insertion(ofstream &out)
        {
            
            if(head->next ==nullptr)
            {
                out << "[";
                out << head->val;
                out << "]";
                return;
            }
            node * sorted = head;   //cur
            node * unsorted = sorted->next; //next
            node * insert = unsorted;   //saves next
            
            while(unsorted != nullptr)
            {
                //sorted = head;
                //print();
                while(sorted!=unsorted && sorted->val < insert->val)
                {
                    sorted = sorted->next;
                }
                //cout << insert->val;
                //sorted = head;
                //print();   
                
                node * insertprev = sorted->prev;
                if (sorted != unsorted)
                {   
                    unsorted = unsorted->next;
                    
                    if(sorted -> val > insert -> val)
                    {
                        cout << "\nnow inserting: " << insert->val << endl;
                        if(sorted == head && sorted->next == insert)
                        {
                            cout << "head1" << endl;
                            //cout << sorted->next->val << endl;
                            node * insertprev2 = insert->prev;
                            node * insertnext = insert->next;
                            
                            insert->next->prev = sorted;
                            sorted->next = insertnext;
                            insert->prev = nullptr;
                            insert->next = sorted;
                            sorted->prev = insert;
                            head = insert;

                            insert = unsorted;
                            //cout << "WORKING1!";
                        }
                        else if(sorted==head && sorted->next != insert)
                        {
                            
                            if(insert->next != nullptr)
                            {
                            cout << "head2";
                            cout << insert->prev->val << endl;
                            node * insertnext = insert->next;
                            node * insertprev2 = insert->prev;

                            insert->next->prev = insertprev2;
                            insert->prev->next = insertnext;
                            sorted->prev = insert;

                            
                            insert->prev = nullptr;
                            insert->next = sorted;
                            

                            head = insert;
                            insert = unsorted;
                            }
                            else if(insert->next == nullptr)
                            {
                                node * insertnext = insert->next;
                                node * insertprev2 = insert->prev;
                                
                                insert->prev->next = nullptr;
    
                                sorted->prev = insert;
                                //sorted->next = insertnext;
                                insert->prev = insertprev;
                                insert->next = sorted;

                                head = insert;
                                insert = unsorted;
                            }
                            

                            /*insert->prev->next = sorted;
                            sorted->next->prev = insert;
                            insert->next = sorted->next;
                            sorted->prev = insert->prev;
                            insert->prev = sorted;
                            sorted->next = insert;
                            head = insert;*/

                            //cout << "WORKING2!";
                        }
                        else //if(sorted != head)
                        {
                            if(insert->next != nullptr && sorted->next != insert)
                            {
                            cout << "Bye?" << endl;
                            node * insertnext = insert->next;
                            node * insertprev2 = insert->prev;

                            sorted->prev->next = insert;
                            sorted->prev = insert;

                            insert->prev->next = insertnext;
                            insert->next->prev = insertprev2;
                            insert->next = sorted;

                            insert->prev = insertprev;
                            
                            insert = unsorted;
                            }
                            else if(insert->next != nullptr && sorted->next == insert)
                            {
                                cout << "HI" << endl;
                                node * insertnext = insert->next;
                                node * insertprev2 = insert->prev;

                                sorted->prev->next = insert;
                                sorted->prev = insert;
                                sorted->next = insertnext;
                                
                                insert->next->prev = sorted;
                                insert->next = sorted;

                                insert->prev = insertprev;
                                
                                insert = unsorted;
                            }   
                            else{
                                cout << "WORKING3!";
                            sorted->prev->next = insert;
                            sorted->prev = insert;

                            insert->prev->next = nullptr;
                            insert->next = sorted;

                            insert->prev = insertprev;
                            
                            insert = unsorted;
                            }
                            //print();
                        }
                        //print(out);
                        //print();
                    }
                    //print(out);

                insert = unsorted;
                
                
                }
                else //if sorted == unsorted
                {
                    unsorted = unsorted->next;
                    insert = unsorted;
                }
                sorted=head;
                print(out);
                print(); 

                }
              
        }


        void selection(ofstream &out)
        {
            if(head->next ==nullptr)
            {
                out << "[";
                out << head->val;
                out << "]";
                return;
            }
            node * cur = head;      //finds the min
            node * count = head;    //spot to where min is moved
            node * count2 = count;
            node * min = head;      //min value
            node * temp = head;     //saves count
            int size = getSize();
            int move = 0;
            for(int i = 0; i < size; i++)
            {
                while(cur->next != nullptr) //loop to find min
                {
                    if(cur->val < min->val)
                        min = cur;

                        cur = cur->next; //keep traversing until end       

                    if(cur->val < min->val)
                        min = cur; 
                }
                cout << "\nthis is the min value: " << min->val << endl;
                //cout << "this is the move value" << move << endl;
                move++;
                cout << "this is the move value: " << move << endl;
                cout << "this is the temp val: " << temp->val << endl;
                if(temp->prev == nullptr)    //for the first swap
                {
                    
                    if(min->val == temp->val)
                    {
                        cout << "same\n";
                        cout << min->val << endl;
                        //print(out);
                    }
                    else if(min->next == nullptr)
                    {
                        node * countprev = count->prev;
                        node * minprev = min->prev;
                        node * countnext = count->next;

                        //count->prev->next = min;
                        count->next->prev = min;
                        min->prev->next = count;

                        min->next = countnext;
                        
                        min->prev = nullptr;
                        
                        count->next = nullptr;
                        head = min;
                    }
                    else if(min->val != temp->val)
                    {
                        min->next = count->next;
                        count->next->prev = min;
                        min->prev = nullptr;
                        if(min->next != nullptr)
                            min->next->prev = count;
                        else
                        {
                            min->next->prev = count;
                        }
                        //print(out);
                    }
                    //print();
                }
                else if(min->val != temp->val)   //swapping min and count
                {
                    if(min->next != nullptr && temp->next != min)
                    {
                        node * countprev = count->prev;
                        node * minprev = min->prev;
                        node * minnext = min->next;
                        node * countnext = count->next;

                        count->prev->next = min;
                        min->next->prev = count;
                        count->next->prev = min;
                        min->prev->next = count;

                        min->next = countnext;
                        
                        min->prev = countprev;
                        
                        
                        count->next = minnext;
                        count->prev = minprev;
                        
                        
                        
                        //FIX THIS FIX THIS FIX THIS!!!
                        //problem: 20 and 23 are getting lost!! find the pointers pls!
                    }
                    else if(temp->next == min && min->next != nullptr)
                    {
                        cout << "HI" << endl;
                        node * countprev = count->prev;
                        node * minprev = min->prev;
                        node * minnext = min->next;
                        node * countnext = count->next;

                        count->prev->next = min;
                        min->next->prev = count;
                        
                        min->next = count;
                        count->next = minnext;
                        min->prev = countprev;
                        
                        
                        count->prev = min;
                    }

                    else //if min->next == nullptr
                    {
                        node * countprev = count->prev;
                        node * minprev = min->prev;
                        node * countnext = count->next;

                        count->prev->next = min;
                        count->next->prev = min;
                        min->prev->next = count;

                        min->next = countnext;
                        
                        min->prev = countprev; 
                        
                        count->next = nullptr;
                        count->prev = minprev;
                    }
                }

                else if(min->val == temp->val)
                {
                    cout << "same" << endl;
                    cout << min->val;
                }

                cur = head;
                temp = head;
                for(int i = 0; i < move; i++)
                {
                    cur = cur->next;
                    temp = temp->next;
                    cout << "\nthis is the new cur: " << cur->val;
                }

                //temp = temp->next;
                count = temp;
                min = min->next;
                print(out);
                print();
            }
        }

        int getSize()
        {
            int size = 0;
            node * cur = head;

            while(cur->next != nullptr)
            {
                size++;
                cur=cur->next;
            }
            //cout << size;
            return size;
        }


};
#endif