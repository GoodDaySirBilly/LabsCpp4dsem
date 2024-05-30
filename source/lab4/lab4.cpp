//
// Created by user on 4/18/2024.
//

#include "lab4.h"
int lab4() {
    system("cls");
    int inp,type;
    cout<<"Please choose type ypu want to work:"<<endl;
    cout<<"1. int"<<endl;
    cout<<"2. char"<<endl;
    cout<<"3. float"<<endl;
    cout<<"4. double"<<endl;
    cout<<"5. string"<<endl;
    cin>>type;
    if(type<1 || type>5) {
        cout<<"Try again and choose correct type!"<<endl;
        return -1;
    }

    TempArray<int> i1;
    TempArray<char> c1;
    TempArray<float> f1;
    TempArray<double> d1;
    TempArray<string> s1;

    int* i2;
    char* c2;
    float* f2;
    double* d2;
    string* s2;
    string z;
    z==s2[0];

    srand(time(nullptr));
    unsigned len = 1+rand()%20;
    i2 = new int[len];
    c2 = new char [len];
    f2 = new float [len];
    d2 = new double [len];
    s2 = new string [len];
    for(unsigned i = 0;i<len;++i){
        i2[i] = rand()%101-50;
         c2[i] = rand()%101-50;
         f2[i] = rand()%101-50;
         d2[i] = rand()%101-50;
         s2[i] = to_string(rand()%101-50);
    }

    system("cls");
    do{
        cout<<"1. Create(Replace) TempArray of length and enter it"<<endl;
        cout<<"2. Print TempArray"<<endl;
        cout<<"3. Print TempArray[index]"<<endl;
        cout<<"4. Print array"<<endl;
        cout<<"5. Hard swap with step and swap step"<<endl;
        cout<<"6. End"<<endl;

        cin>>inp;
        system("cls");

        switch(inp){
            case 1:
                unsigned length;
                cout<<"Enter length: ";
                cin>>length;
                switch(type){
                    case 1:{
                        TempArray<int> i3{length};
                        i3.operator>>(cin);
                        i1 = i3;
                        break;
                    }
                    case 2:{
                        TempArray<char> c3{length};
                        c3.operator>>(cin);
                        c1 = c3;
                        break;
                    }
                    case 3:{
                        TempArray<float> f3{length};
                        f3.operator>>(cin);
                        f1 = f3;
                        break;
                    }
                    case 4:{
                        TempArray<double> d3{length};
                        d3.operator>>(cin);
                        d1 = d3;
                        break;
                    }
                    case 5:{
                        TempArray<string> s3{length};
                        s3.operator>>(cin);
                        s1 = s3;
                        break;
                    }
                    default:
                        break;
                }
                break;
            case 2:
                switch(type){
                    case 1:
                        i1.operator<<(cout)<<endl;
                        break;
                    case 2:
                        c1.operator<<(cout)<<endl;
                        break;
                    case 3:
                        f1.operator<<(cout)<<endl;
                        break;
                    case 4:
                        d1.operator<<(cout)<<endl;
                        break;
                    case 5:
                        s1.operator<<(cout)<<endl;
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                int c;
                cout<<"Enter index: ";
                cin>>c;
                try {
                    switch(type){
                        case 1:
                            cout<<i1[c]<<endl;
                            break;
                        case 2:
                            cout<<c1[c]<<endl;
                            break;
                        case 3:
                            cout<<f1[c]<<endl;
                            break;
                        case 4:
                            cout<<d1[c]<<endl;
                            break;
                        case 5:
                            cout<<s1[c]<<endl;
                            break;
                        default:
                            break;
                    }
                }catch (const char * error){
                    cerr<<error;
                    delete[] i2;
                    delete[] c2;
                    delete[] f2;
                    delete[] d2;
                    return -1;
                }
                break;
            case 4:
                switch (type) {
                    case 1:
                        for (int i = 0; i < len; ++i) cout << i2[i] << " ";
                        cout << endl;
                        break;
                    case 2:
                        for (int i = 0; i < len; ++i) cout << c2[i] << " ";
                        cout << endl;
                        break;
                    case 3:
                        for (int i = 0; i < len; ++i) cout << f2[i] << " ";
                        cout << endl;
                        break;
                    case 4:
                        for (int i = 0; i < len; ++i) cout << d2[i] << " ";
                        cout << endl;
                        break;
                    case 5:
                        for (int i = 0; i < len; ++i) cout << s2[i] << " ";
                        cout << endl;
                        break;
                    default:
                        break;
                }
                break;
            case 5:
                int step,swap;
                cout<<"Enter step: ";
                cin>>step;
                cout<<"Enter swap: ";
                cin>>swap;
                try{
                    switch(type){
                        case 1:
                            hardSwap(i2,len,step,swap);
                            break;
                        case 2:
                            hardSwap(c2,len,step,swap);
                            break;
                        case 3:
                            hardSwap(f2,len,step,swap);
                            break;
                        case 4:
                            hardSwap(d2,len,step,swap);
                            break;
                        case 5:
                            hardSwap(s2,len,step,swap);
                            break;
                        default:
                            break;
                    }
                }catch (const char* error){
                    cerr<<error;
                    delete[] i2;
                    delete[] c2;
                    delete[] f2;
                    delete[] d2;
                    return -1;
                }
                break;
            case 6:
                break;
            default:
                if (inp == EOF) inp = 7;
                cout << "There is no enough command. If you want to exit enter 6\n";
                break;
        }
    }while(inp != 6);

    delete[] i2;
    delete[] c2;
    delete[] f2;
    delete[] d2;

    return 0;
}
