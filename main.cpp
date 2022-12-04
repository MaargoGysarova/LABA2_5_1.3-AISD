#include <iostream>
#include "Broken_line.h"
#include "Complex.h"
#include "Broken_compl.h"
using namespace std;
#include <conio.h>
#include "Graphics.h"
#include "ESetErrors.h"
#include "Menu_Compl.cpp"



int get_key(){
    int key = _getch();
    if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 57)) {
        return key;
    }
}

template <class T>
T check()
{
	T number = -1;
        while (number < 0)
        {
            while (!(cin >> number) || (cin.peek() != '\n'))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Input correct value\n";
            }
            if (number < 0) cout << "Input correct value\n";

        }

        return number;
    
}

template <class T>
void print_image(Broken_line<T>& line, int num_reg, int shift) {
    
    cout << "Print image" << endl;
    // draw line with tops graphics.h library
    Graphics window(900, 900);
    for (int i = 0; i < line.get_counter()-1; i++) {
        Point<T> A = line[i];
		
       
            Point<T> B = line[i + 1];
            window.DrawLine(A.GetPointX() * 100, A.GetPointY() * 100, B.GetPointX() * 100, B.GetPointY() * 100);
        }

    
    Point<T> A = line[num_reg-1+shift];
    Point<T> B = line[0+shift];
    window.DrawLine(A.GetPointX() * 100, A.GetPointY() * 100, B.GetPointX() * 100, B.GetPointY() * 100);
}

template <class T>
void print_image_first(Broken_line<T>& line) {
    cout << "Print image" << endl;
    // draw line with tops graphics.h library
    Graphics window(900, 900);
    for (int i = 0; i < line.get_counter()-1; i++) {
        Point<T> A = line[i];
        Point<T> B = line[i + 1];
        window.DrawLine(A.GetPointX() * 100, A.GetPointY() * 100, B.GetPointX() * 100, B.GetPointY() * 100);

    }
}

template <class T>
Broken_line<T> create_new_line(){

    cout << "Creating broken line" << endl;
    cout << "What is the num of top" << endl;
    cout << "Num of top = "; 
    int num_of_top;
    cin >> num_of_top;
    while (num_of_top <= 0)
    {
        cout << "Incorrect value" << endl;
        cout << "Num of top = ";
        cin >> num_of_top;
    }
    Broken_line<T> new_line(5,num_of_top);
    Point<T> tmp(0, 0);
    int x=0,y=0;
    for(int i=0;i<num_of_top;i++){
        cout << "Enter the tup["<<i+1<<"]values"<< endl;
        cout << "x["<<i+1<<"]= " << endl;
        x = check<T>();
        cout << "y["<<i+1<<"]= " << endl;
        y = check<T>();
        tmp.SetPointX(x);tmp.SetPointY(y);
        new_line += tmp;
    }
    return new_line;
}

template <class T>
Point<T> get_top(Broken_line<T>& line,int index){
    return line[index];
}

template <class T>
void set_top(Broken_line<T>& line, int index){
    Point<T> new_point(0,0);
    T x=0,y=0;
    cout << "Enter the tup[" << index+1 << "]values" << endl;
    cout << "x["<<index<<"]= " << endl;
    x = check<T>();
    cout << "y["<<index<<"]= " << endl;
    y = check<T>();
    new_point.SetPointX(x);new_point.SetPointY(y);
    line(new_point,index-1);
}

template <class T>
Broken_line<T> sum(Broken_line<T>&  line){
    cout << "Summarize" << endl;
	Broken_line<T> second_line = create_new_line<T>();
    print_image_first(second_line);
    _getch();
	line = line + second_line;
    return line;
}

template <class T>
void add_to_end(Broken_line<T>& line){
    cout << "Add to end of line" << endl;
    T x=0,y=0;
    cout << "Creating top" << endl;
    cout << "Enter the tup[i+1] values" << endl;
    cout << "x = " << endl;
    x = check<T>();
    cout << "y = " << endl;
    y = check<T>();
    Point<T> new_point(x,y);
    line += new_point;
}

template <class T>
void add_to_start(Broken_line<T>& line){
    cout << "Add to start of line" << endl;
    T x=0,y=0;
    cout << "Creating top" << endl;
    cout << "Enter the tup[i+1] values" << endl;
    cout << "x = " << endl;
    x = check<T>();
    cout << "y = " << endl;
    y = check<T>();
    Point<T> new_point(x,y);
    line + new_point;
}

template <class T>
double get_length(Broken_line<T>& line){
    cout << "Calculating line's length" << endl;
    return line.get_length();
}

template <class T>
void show_all_tops(Broken_line<T>& line){
    cout << "Show all tops" << endl;
    Point<T> tmp(0, 0);
    for(int i=0;i<line.get_counter();i++){
        tmp = line[i];
        cout << "["<<i<<"]:";
        cout <<"("<<tmp.GetPointX() << "," << tmp.GetPointY()<<")"<<endl;
    }
}

template <class T>
void show_one_tops(Broken_line<T>& line){
    int index=0;
    cout << "index = " << endl;
    index = check<T>();
    while (index <= 0 || index> line.get_counter()){
       cout << "Incorrect value" << endl;
      cout << "index = ";
      cin >> index;
     }
    Point<T> tmp(0,0);
    tmp = line[index-1];
    cout << "["<<index<<"]:";
    cout << "(" << tmp.GetPointX() << "," << tmp.GetPointY() << ")" << endl;
}


int menu2() {
    cout << "What are you want to do? To press.." << endl;
    cout << "1 - summarize with new line"<< endl;
    cout << "2 - Add new top to end"<< endl;
    cout << "3 - Add new top to start"<< endl;
    cout << "4 - Get length"<< endl;
    cout << "5 - Change one element" << endl;
    cout << "6 - Show all tops" << endl;
    cout << "7 - Show one top" << endl;
    cout << "8 - Print image" << endl;
    cout << "9 - Go out" << endl;
    int m2;
    m2= get_key();
    return m2;
}

template <class T>
bool check_regular_polygon(Broken_line<T>& line) {
    cout << "Checking regular polygon..." << endl;
    //create massive of length of polygon's sides
    auto *length_of_sides = new double[line.get_counter()];
    for (int i = 0; i < line.get_counter(); i++) {
        Point<T> A = line[i];
        if (i == line.get_counter() - 1) {
            Point <T> B= line[0];
            length_of_sides[i] = Broken_line<T>::get_length_two_tops(A, B);
        }
        else {
            Point<T> B = line[i + 1];
            length_of_sides[i] = Broken_line<T>::get_length_two_tops(A, B);
        }
    }
	
    int index = 0;
    //create massive of nulls
    //привет
    int index_massive = -1;
    //check if all sides are equal
    for (int i = 0; i < line.get_counter()-2; i++) {
        if (length_of_sides[0] != length_of_sides[i + 1]) {
            index = i + 1;
             
            index_massive++;
            break;
        }
    }
    // check if massive is empty
    if (index_massive == -1) {
        return true;
    } 
        
        
        return false;
    }

 
template <class T>
       int main_program(int num_tops) {
		
         Broken_line<T> line(5, num_tops+1);
         Point<T> tmp(0,0);
         bool reg = false;
		 bool sum_cheak = false;
         int shift = 0;
         T x = 0, y = 0;
         for (int i = 0; i < num_tops; i++) {
             cout << "Enter the tup[" << i + 1 <<"]values"<< endl;
             cout << "x[" << i + 1 << "]= ";
             x = check<T>();
             cout << "y[" << i + 1 << "]= ";
			 y = check<T>();
             tmp.SetPointX(x);
             tmp.SetPointY(y);
             line += tmp;
         }
         if (check_regular_polygon(line)) {
            // line[line.get_counter()] = line[0];
             cout << "This is regular polygon" << endl;
             reg = true;
             _getch();
         } 

         int m2;
         do {
             system("cls");
             m2 = menu2();

             switch (m2) {
                 case 49:
                     system("cls");
                     sum(line);
                     sum_cheak = true;
                     if (reg) {
                         print_image(line, num_tops, shift);
                     }
                     else { print_image_first(line); }
                     getchar();
                     break;
                 case 50:
                     try {
                         add_to_end(line);
                         _getch();
                     }
                     catch (ESetErrors& err) {
                         err.print_error();
                     }
                     break;
                 case 51:
                     try {
                         add_to_start(line);
                         show_all_tops(line);
                         shift++;
                         getchar();
                     }
                     catch (ESetErrors& err) {
                         err.print_error();
                     }
                     break;
                 case 52:
                     system("cls");
                     cout << "Length = " << get_length(line) << endl;
                     _getch();
                     break;
                 case 53:
                     try {
                         system("cls");
                         show_all_tops(line);
                         // enter index of top
                         int index;
                         cout << "index = " << endl;
                         cin >> index;
                         while (index <= 0 || index > line.get_counter()) {
                             cout << "Incorrect value" << endl;
                             cout << "index = ";
                             cin >> index;
                         }
                         set_top(line, index);
                     }
                     catch (ESetErrors& err) {
                         err.print_error();
                     }
                     break;
                 case 54:
                     system("cls");
                     show_all_tops(line);
                     _getch();
                     break;
                 case 55:
                     system("cls");
                     show_one_tops(line);
                     _getch();
                     
                     break;
                 case 56:
                     system("cls");
                     if (reg == true) {
						 print_image(line,num_tops,shift);
                     }
                     else {
                         print_image_first(line);
                     }
					
                     break;
                 case 57:
                     cout << "Goodbye!" << endl;
                     return 0;
                 default:
                     cout << "Incorrect value" << endl;
                     break;
             }
         } while (m2 != 9);
     }
     
 template <class C>
 void main_program_2(int num_tops) {
     main_program_complex<C>(num_tops);
 }

         
       
   int main()
       {
           
           int num_tops;
           cout << "Hello! Enter the number of tops of the polygon" << endl;
           cin >> num_tops;
           while (num_tops <= 0) {
               cout << "Incorrect value" << endl;
               cout << "Num of top = ";
               cin >> num_tops;
           }
           while (true)
           {
               system("cls");
               cout << "Please, choose type:" << endl;
               cout << "Press 1 for int" << endl;
               cout << "Press 2 for float" << endl;
               cout << "Press 3 for double" << endl;
               cout << "Press 4 for complex (double)" << endl;
               cout << "Press 5 for complex (float)" << endl;
               cout << "Press Esc to finish the program" << endl;
               int choise;
               while (true)
               {
                   choise = get_key();
                   if ((choise >= 49 && choise <= 53) || choise == 27) break;
               }

               system("cls");
               if (choise == 27) break;
               switch (choise)
               {
               case 49:
                   cout << "tupe - int" << endl;
                   main_program <int>(num_tops);
                   break;
               case 50:
                   cout << "tupe - float" << endl;
                   main_program <float>(num_tops);
                   break;
               case 51:
                   cout << "tupe - double" << endl;
                   main_program <double>(num_tops);
                   break;
                   case 52:
                       cout << "tupe - complex<double>" << endl;
                       main_program_2<double>(num_tops);
                       break;
                   case 53:
                       cout << "tupe - complex<float>" << endl;
                       main_program_2<float>(num_tops);
                       break;
               }

               }
           }
       
