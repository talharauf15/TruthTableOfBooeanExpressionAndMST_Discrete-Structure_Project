//c++ program for the above given truth table's boolean expression

#include<iostream>

using namespace std;

//function that evaluates the given expression
int evaluate1(int p, int q) {
    bool f;
    f = !(p || q);

    //if the expression's result is true then return 1 else return 0
    if (f) {
        return 1;
    }
    return 0;
}


//function that evaluates the given expression
int evaluate2(int p, int q) {
    bool f;
    f = !p && !q;

    //if the expression's result is true then return 1 else return 0
    if (f) {
        return 1;
    }
    return 0;
}


//function that evaluates the given expression
int evaluate3(int p, int q, int r) {
    bool f;

    //if the expression's result is true then return 1 else return 0
    f = (p || q) && !r;
    if (f) {
        return 1;
    }
    return 0;
}


//function that evaluates the given expression
int evaluate4(int p, int q, int r) {
    bool f;

    //if the expression's result is true then return 1 else return 0
    f = !(p || (!q && r));
    if (f) {
        return 1;
    }
    return 0;
}


int main()
{
    int p, q, r;
    char ch;

    //do while loop to make program runnable more n more if user want
    do {
        //taking values of p,q and r from user
        cout << "\nEnter the value of 'p': ";
        cin >> p;
        cout << "\nEnter the value of 'q': ";
        cin >> q;
        cout << "\nEnter the value of 'r': ";
        cin >> r;

        //if p,q and r have value 0 or 1
        //then we print the truth table
        if ((p == 1 || p == 0) && (q == 1 || q == 0) && (r == 1 || r == 0)) {
            int r1, r2, r3, r4;

            r1 = evaluate1(p, q);
            r2 = evaluate2(p, q);
            r3 = evaluate3(p, q, r);
            r4 = evaluate4(p, q, r);

            cout << "\np\tq\tr\t!(p || q)\t!p && !q\t(p || q) && !r\t!(p || (!q && r))";
            cout << "\n\n" << p << "\t" << q << "\t" << r << "\t " << r1 << "\t\t " << r2 << "\t\t " << r3 << "\t\t " << r4;

            //user input if user want to run one more time
            cout << "\nEnter Y/y for run the program again: ";
            cin >> ch;
        }

        //else printing invalid and exit the program
        else {
            cout << "\nInvalid Input!!\nProgram Terminated";
            exit(0);
        }
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
