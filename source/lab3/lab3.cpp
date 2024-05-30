//
// Created by user on 4/15/2024.
//

#include "lab3.h"
int lab3(){

    ifstream is;
    ofstream os;
    double a,b,c,d;

    vector<Figure*> array;

    is.open(R"(C:\Users\user\Desktop\cmakeproject\source\lab3\Input.txt)");
    is>>a;
    Circle* circle = new Circle(a);

    is>>a>>b;
    RectTriangle* rectTriangle = new RectTriangle(a,b);

    is>>a>>b;
    Rectangle* rectangle = new Rectangle(a,b);

    is>>a>>b>>c>>d;
    Trapezoid* trapezoid = new Trapezoid(a,b,c,d);

    is.close();
    array.push_back(circle);
    array.push_back(rectTriangle);
    array.push_back(rectangle);
    array.push_back(trapezoid);

    system("cls");
    int inp;
    do{
        cout<<"1. Print squares to Output.txt"<<endl;
        cout<<"2. Print squares here"<<endl;
        cout<<"3. Print parameters of figures from Input.txt"<<endl;
        cout<<"4. Refresh parameters from Input.txt again"<<endl;
        cout<<"5. End"<<endl;

        cin>>inp;
        system("cls");

        switch(inp){
            case 1:
                os.open(R"(C:\Users\user\Desktop\cmakeproject\source\lab3\Output.txt)");
                os<<"Circle:       "<<array[0]->square()<<endl;
                os<<"RectTriangle: "<<array[1]->square()<<endl;
                os<<"Rectangle:    "<<array[2]->square()<<endl;
                os<<"Trapezoid:    "<<array[3]->square()<<endl;
                os.close();
                break;
            case 2:
                cout<<"Circle:       "<<array[0]->square()<<endl;
                cout<<"RectTriangle: "<<array[1]->square()<<endl;
                cout<<"Rectangle:    "<<array[2]->square()<<endl;
                cout<<"Trapezoid:    "<<array[3]->square()<<endl;
                break;
            case 3:
                for(int i = 0;i!=4;++i) array[i]->operator<<(cout)<<endl;
                break;
            case 4:
                array.clear();
                delete circle;
                delete rectTriangle;
                delete rectangle;
                delete trapezoid;
                is.open(R"(C:\Users\user\Desktop\cmakeproject\source\lab3\Input.txt)");
                is>>a;
                circle = new Circle(a);

                is>>a>>b;
                rectTriangle = new RectTriangle(a,b);

                is>>a>>b;
                rectangle = new Rectangle(a,b);

                is>>a>>b>>c>>d;
                trapezoid = new Trapezoid(a,b,c,d);
                array.push_back(circle);
                array.push_back(rectTriangle);
                array.push_back(rectangle);
                array.push_back(trapezoid);
                is.close();
                for(int i = 0;i!=4;++i) array[i]->operator<<(cout)<<endl;
                break;
            case 5:
                break;
            default:
                if (inp == EOF) inp = 6;
                cout << "There is no enough command. If you want to exit enter 5\n";
                break;
        }
    }while(inp != 5);

    delete circle;
    delete rectTriangle;
    delete rectangle;
    delete trapezoid;

    return 0;
}
