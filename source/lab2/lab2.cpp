//
// Created by user on 3/1/2024.
//

#include "lab2.h"
using namespace std;
int lab2(){
    Point a;

    int inp;
    double inpd;
    do{
        cout<<"Choose class you want to work:\n";
        cout<<"1. Point\n";
        cout<<"2. Stack\n";
        cout<<"3. End"<<endl;

        cin >> inp;
        system("cls");
        switch(inp){
            case 1:
            {
                Point point;
                do{
                    cout<<"Choose option of point you want to use:\n";
                    cout<<"1.  print values of point\n";
                    cout<<"2.  print increment & decrement\n";
                    cout<<"3.  set X\n";
                    cout<<"4.  set Y\n";
                    cout<<"5.  set Z\n";
                    cout<<"6.  set increment\n";
                    cout<<"7.  set decrement\n";
                    cout<<"8.  point++\n";
                    cout<<"9.  point--\n";
                    cout<<"10. ++point\n";
                    cout<<"11. --point\n";
                    cout<<"12. point = !point\n";
                    cout<<"13. Back"<<endl;

                    cin >> inp;
                    system("cls");
                    switch(inp){
                        case 1:
                            cout<<"X: "<<point.getX()<<" Y: "<<point.getY()<<" Z: "<<point.getZ()<<endl;
                            break;
                        case 2:
                            cout<<"Increment: "<<point.getIncrement()<<" Decrement: "<<point.getDecrement()<<endl;
                            break;
                        case 3:
                            cout<<"Enter X: ";
                            cin>>inpd;
                            point.setX(inpd);
                            break;
                        case 4:
                            cout<<"Enter Y: ";
                            cin>>inpd;
                            point.setY(inpd);
                            break;
                        case 5:
                            cout<<"Enter Z: ";
                            cin>>inpd;
                            point.setZ(inpd);
                            break;
                        case 6:
                            cout<<"Enter Increment: ";
                            cin>>inpd;
                            point.setIncrement(inpd);
                            break;
                        case 7:
                            cout<<"Enter Decrement: ";
                            cin>>inpd;
                            point.setDecrement(inpd);
                            break;
                        case 8:
                            point++;
                            break;
                        case 9:
                            point--;
                            break;
                        case 10:
                            ++point;
                            break;
                        case 11:
                            --point;
                            break;
                        case 12:
                            point = !point;
                            break;
                        case 13:
                            break;
                        default:
                            if(inp == EOF) inp = 14;
                            cout<<"There is no enough command. If you want to go back enter 13"<<endl;
                            break;
                    }
                }while(inp != 13);
            }
            break;
            case 2:
            {
                bool usedCopy = false;
                MyStack orig,cpy;
                do {
                    cout << "Choose option you want to do with stack\n";
                    cout << "1.  Choose orig\n";
                    cout << "2.  Choose copy\n";
                    cout << "3.  add number to current stack\n";
                    cout << "4.  enter stack\n";
                    cout << "5.  pop number of current stack\n";
                    cout << "6.  print current stack\n";
                    cout << "7.  get length of current stack\n";
                    cout << "8.  clear current stack\n";
                    cout << "9.  current -= another\n";
                    cout << "10. current /= another\n";
                    cout << "11. current == another (True or False)\n";
                    cout << "12. current > another (True or False)\n";
                    cout << "13. current < another (True or False)\n";
                    cout << "14. current = !current (reverse)\n";
                    cout << "15. make current random\n";
                    cout << "16. back\n";

                    cin >> inp;
                    system("cls");
                    switch (inp) {
                        case 1:
                            usedCopy = false;
                            cout << orig << endl;
                            break;
                        case 2:
                            usedCopy = true;
                            cout << cpy << endl;
                            break;
                        case 3:
                            cout << "Enter number: ";
                            cin >> inpd;
                            if (usedCopy) cpy.add(inpd);
                            else orig.add(inpd);
                            break;
                        case 4:
                            cout << "Please enter num of inputs and then enter your numbers:\n";
                            if (usedCopy){
                                cin >> cpy;
                                cout << cpy << endl;
                            }
                            else {
                                cin >> orig;
                                cout << orig << endl;
                            }
                            break;
                        case 5:
                            if (usedCopy) cout << "Poped: " << cpy.pop() << endl;
                            else cout << "Poped: " << orig.pop() << endl;
                            break;
                        case 6:
                            if (usedCopy) cout << cpy << endl;
                            else cout << orig << endl;
                            break;
                        case 7:
                            if (usedCopy) cout << "Length: " << cpy.getLen() << endl;
                            else cout << "Length: " << orig.getLen() << endl;
                            break;
                        case 8:
                            if (usedCopy) cpy.clear();
                            else orig.clear();
                            break;
                        case 9:
                            if (usedCopy){
                                cout << "Current before: " << cpy << endl;
                                cout << "Another:        " << orig << endl;
                                cpy -= orig;
                                cout << "Current now:    " << cpy << endl;
                            }
                            else{
                                cout << "Current before: " << orig << endl;
                                cout << "Another:        " << cpy << endl;
                                orig = orig - cpy;
                                cout << "Current now:    " << orig << endl;
                            }
                            break;
                        case 10:
                            if (usedCopy){
                                cout << "Current before: " << cpy << endl;
                                cout << "Another:        " << orig << endl;
                                cpy /= orig;
                                cout << "Current now:    " << cpy << endl;
                            }
                            else{
                                cout << "Current before: " << orig << endl;
                                cout << "Another:        " << cpy << endl;
                                orig = orig / cpy;
                                cout << "Current now:    " << orig << endl;
                            }
                            break;
                        case 11:
                            if (orig == cpy){
                                cout << "Current: " << cpy << endl;
                                cout << "Another: " << orig << endl;
                                cout << "True" << endl;
                            }
                            else {
                                cout << "Current: " << cpy << endl;
                                cout << "Another: " << orig << endl;
                                cout << "False" << endl;
                            }
                            break;
                        case 12:
                            if (usedCopy) {
                                cout << "Current: " << cpy << endl;
                                cout << "Another: " << orig << endl;
                                if (cpy > orig) cout << "True" << endl;
                                else cout << "False" << endl;
                            } else {
                                cout << "Current: " << orig << endl;
                                cout << "Another: " << cpy << endl;
                                if (orig > cpy) cout << "True" << endl;
                                else cout << "False" << endl;
                            }
                            break;
                        case 13:
                            if (usedCopy) {
                                cout << "Current: " << cpy << endl;
                                cout << "Another: " << orig << endl;
                                if (cpy < orig) cout << "True" << endl;
                                else cout << "False" << endl;
                            } else {
                                cout << "Current: " << orig << endl;
                                cout << "Another: " << cpy << endl;
                                if (orig < cpy) cout << "True" << endl;
                                else cout << "False" << endl;
                            }
                            break;
                        case 14:
                            if (usedCopy){
                                cout << "Current before: " << cpy << endl;
                                cpy = !cpy;
                                cout << "Current now:    " << cpy << endl;
                            }
                            else {
                                cout << "Current before: " << orig << endl;
                                orig = !orig;
                                cout << "Current now:    " << orig << endl;
                            }
                            break;
                        case 15:{
                            srand(time(nullptr));
                            int len = rand()%6+5;
                            MyStack stack;
                            while(0<len--)
                                stack.add(rand()%101-50);
                            if (usedCopy) {
                                cpy = stack;
                                cout << cpy << endl;
                            }
                            else {
                                orig = stack;
                                cout << orig << endl;
                            }
                        }
                            break;
                        case 16:
                            break;
                        default:
                            if (inp == EOF) inp = 17;
                            cout << "There is no enough command. If you want to exit enter 16\n";
                            break;
                    }
                }while(inp != 16);
            }
            break;
            case 3:
                inp = EOF;
                break;
            default:
                if(inp == EOF) inp = 4;
                cout<<"There is no enough command. If you want to exit enter 3\n";
            break;
        }
    }while(inp != EOF);

    return 0;
}