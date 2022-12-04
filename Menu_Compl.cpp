#include "Complex.h"
#include "Broken_compl.h"
#include <iostream>
#include <conio.h>
#include "Graphics.h"

template <class Ñ>
Ñ check_compl()
{
    int number = -1;
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


template <class C>
void print_image_compl(Broken_compl<C>& line) {
    cout << "Print image" << endl;
    // draw line with tops graphics.h library
    Graphics window(900, 900);
    for (int i = 0; i < line.get_counter() - 1; i++) {
        Complex<C> A = line[i];
        Complex<C> B = line[i + 1];
        window.DrawLine(A.Get_Re() * 100, A.Get_Im() * 100, B.Get_Re() * 100, B.Get_Im() * 100);

    }
}

template <class C>
Broken_compl<C> create_new_line_compl() {

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
    Broken_compl<C> new_line(5, num_of_top);
    Complex<C> tmp(0, 0);
    C x = 0, y = 0;
    for (int i = 0; i < num_of_top; i++) {
        cout << "Enter the tup[" << i + 1 << "]values" << endl;
        cout << "Re[" << i + 1 << "]= " << endl;
        x = check_compl<C>();
        cout << "Im[" << i + 1 << "]= " << endl;
        y = check_compl<C>();
        tmp.SetRe(x); tmp.SetIm(y);
        new_line += tmp;
    }
    return new_line;
}

template <class C>
Complex<C> get_top_compl(Broken_compl<C>& line, int index) {
    return line[index];
}

template <class C>
void set_top_compl(Broken_compl<C>& line, int index) {
    Complex<C> new_point(0, 0);
    C x = 0, y = 0;
    cout << "Enter the tup[" << index + 1 << "]values" << endl;
    cout << "Re[" << index << "]= " << endl;
    x = check_compl<C>();
    cout << "Im[" << index << "]= " << endl;
    y = check_compl<C>();
    new_point.SetRe(x); new_point.SetIm(y);
    line(new_point, index - 1);
}

template <class C>
Broken_compl<C> sum_compl(Broken_compl<C>& line) {
    cout << "Summarize" << endl;
    Broken_compl<C> second_line = create_new_line_compl<C>();
    print_image_compl<C>(second_line);
    _getch();
    line = line + second_line;
    return line;
}

template <class C>
void add_to_end_compl(Broken_compl<C>& line) {
    cout << "Add to end of line" << endl;
    C x = 0, y = 0;
    cout << "Creating top" << endl;
    cout << "Enter the tup[i+1] values" << endl;
    cout << "Re = " << endl;
    x = check_compl<C>();
    cout << "Im = " << endl;
    y = check_compl<C>();
    Complex<C> new_point(x, y);
    line += new_point;
}

template <class C>
void add_to_start_compl(Broken_compl<C>& line) {
    cout << "Add to start of line" << endl;
    C x = 0, y = 0;
    cout << "Creating top" << endl;
    cout << "Enter the tup[i+1] values" << endl;
    cout << "Re = " << endl;
    x = check_compl<C>();
    cout << "Im = " << endl;
    y = check_compl<C>();
    Complex<C> new_point(x, y);
    line + new_point;
}

template <class C>
double get_length(Broken_compl<C>& line) {
    cout << "Calculating line's length" << endl;
    return line.get_length();
}

template <class C>
void show_all_tops_compl(Broken_compl<C>& line) {
    cout << "Show all tops" << endl;
    Complex<C> tmp(0, 0);
    for (int i = 0; i < line.get_counter(); i++) {
        tmp = line[i];
        cout << "[" << i+1 << "]:";
        cout << "(" << tmp.Get_Re() << "+i" << tmp.Get_Im() << ")" << endl;
    }
}

template <class C>
void show_one_tops_compl(Broken_compl<C>& line) {
    int index = 0;
    cout << "index = " << endl;
    index = check_compl<C>();
    while (index <= 0 || index > line.get_counter()) {
        cout << "Incorrect value" << endl;
        cout << "index = ";
        cin >> index;
    }
    Complex<C> tmp(0, 0);
    tmp = line[index - 1];
    cout << "[" << index << "]:";
    cout << "(" << tmp.Get_Re() << "+i" << tmp.Get_Im() << ")" << endl;
};


template <class C>
int main_program_complex(int num_tops) {
    Broken_compl<C> line(5, num_tops + 1);
    Complex<C> tmp(0, 0);
    C x = 0, y = 0;
    for (int i = 0; i < num_tops; i++) {
        cout << "Enter the tup[" << i + 1 << "]values" << endl;
        cout << "Re[" << i + 1 << "]= ";
        x = check_compl<C>();
        cout << "Im[" << i + 1 << "]= ";
        y = check_compl<C>();
        tmp.SetRe(x);
        tmp.SetIm(y);
        line += tmp;
    }
    int m2;
    do {
        system("cls");
        //m2 = menu2();
        m2 = 54;

        switch (m2) {
        case 49:
            system("cls");
            sum_compl(line);
            
            
            print_image_compl(line);
            
            getchar();
            break;
        case 50:
            
                add_to_end_compl(line);
                _getch();
            
            break;
        case 51:
            
                add_to_start_compl(line);
                show_all_tops_compl(line);
                getchar();
            
            break;
        case 52:
            system("cls");
            cout << "Length = " << get_length(line) << endl;
            _getch();
            break;
        case 53:
           
                system("cls");
                show_all_tops_compl(line);
                // enter index of top
                int index;
                cout << "index = " << endl;
                cin >> index;
                while (index <= 0 || index > line.get_counter()) {
                    cout << "Incorrect value" << endl;
                    cout << "index = ";
                    cin >> index;
                }
                set_top_compl(line, index);
            
            break;
        case 54:
            system("cls");
            show_all_tops_compl(line);
            _getch();
            break;
        case 55:
            system("cls");
            show_one_tops_compl(line);
            _getch();

            break;
        case 56:
            system("cls");
            
                print_image_compl(line);
            
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