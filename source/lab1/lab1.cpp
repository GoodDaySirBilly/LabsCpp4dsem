#include "lab1.h"
using namespace std;

int lab1(){
    
    int symb = 0;
    bool flag = false; //false = original, true = copy
    MyQueuePubl *orig = new MyQueuePubl();
    MyQueuePubl *cpy, *uni;
    system("cls");

    do{
        cout<<"-------------------------------\n\n";
        cout<<"Queue inheritance logic program\n\n";
        cout<<"-------------------------------\n\n";
        
        
        cout<<"List of commads:\n";
        cout<<"1. Add new element to current queue\n";
        cout<<"2. Pop element from current queue\n";
        cout<<"3. Print curent queue\n";
        cout<<"4. Print task value from current queue\n";
        cout<<"5. Creaty copy of current queue\n";
        cout<<"6. Unite copy and original queues\n";
        cout<<"7. End\n";

        cout<<"Creating copy makes current queue copied queue.\n";
        cout<<"Uniting makes current queue original queue.\n";

        cout<<"Please enter num of command to use it:"<<endl;
        cin>>symb;
        if(symb==EOF) symb = 7;
        system("cls");

        switch(symb){
            case 1:{
                cout<<"Integer number: ";
                cin>>symb;
                if(!flag) orig->add(symb);
                else cpy->add(symb); 
            }
            break;
            case 2:{
                if(!flag) cout<<orig->pop()<<endl;
                else cout<<cpy->pop()<<endl;
            }
            break;
            case 3:{
                if(!flag) orig->print();
                else cpy->print();
            }
            break;
            case 4:{
                if(!flag) orig->printTask();
                else cpy->printTask();
            }
            break;
            case 5:{
                if(!flag){
                    flag = true;
                    cpy = static_cast<MyQueuePubl*>(orig->copy());
                }
                else cout<<"You already use copy!\n";
            }
            break;
            case 6:{
                if(!flag) cout<<"You already use original!\n";
                else{
                    flag = false;
                    uni = static_cast<MyQueuePubl*>(unite(orig,cpy));
                    delete orig;
                    delete cpy;
                    orig = static_cast<MyQueuePubl*>(uni->copy());
                    delete uni;
                    orig->print();
                    
                }
            }
            break;
            case 7:{
                delete orig;
                if(flag) delete cpy;
                symb = EOF;
                std::cout<<"End."<<std::endl;
                
            }
            break;
        }


    }while(symb != EOF);

    return 0;
}
