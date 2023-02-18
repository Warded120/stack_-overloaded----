#include <iostream>
#include <vector>

using namespace std;

class vecray
{
    int* vec;
    int size = 0;
    
public :

   /* vecray()
    {
        vec = nullptr;
    }*/

    ~vecray()
    {
        delete[]vec;
    }

    /*void push(int elem)
    {
        //vec = new int[size + 1];
        int* temp = new int[size + 1];
        if (vec)
        {
            for (int i = 0; i < size; i++)
                temp[i] = vec[i];
            delete[] vec;
        }
        vec = temp;
        vec[size] = elem;
        size++;
    }*/

    void operator+(int elem)
    {
        //vec = new int[size + 1];
        int* temp = new int[size + 1];
        if (vec)
        {
            for (int i = 0; i < size; i++)
                temp[i] = vec[i];
            delete[] vec;
        }
        vec = temp;
        vec[size] = elem;
        size++;
    }

   /* void pop()
    {
        size--;
    }*/

    void operator--()
    {
        cout << endl << "The last element in a vecray is deleted" << endl;
        size--;
    }

    int operator~()
    {
        return vec[size - 1];
    }

    int len()
    {
        return size;
    }

    void print()
    {
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << vec[i] << ' ';
        }
        cout << endl;
    }

};

int main()
{
    vecray vec;
    cout << "You have an empty vector\nHow many elements do you want to enter : ";
    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter a variable number " << i + 1 << " : ";
        cin >> num;
        vec + num;
        //vec.push(n);
    }
    
loop:

    cout << endl << "What do you wanna do\n1 - add element\n2 - delete element\n3 - get the last element\n4 - print the array\n5 - get element count\n6 - finish the program\n: ";
    cin >> n;

    switch (n)
    {
        case 1:
        {
            cout << "Enter a variable : ";
            cin >> n;
            //vec.push(n);
            vec + n;
            goto loop;
        }
        case 2:
        {
            //vec.pop();
            --vec;
            goto loop;
        }
        case 3:
        {
            cout << "Your last element is : " << ~vec << endl;
            goto loop;
        }
        case 4:
        {
            vec.print();
            goto loop;
        }
        case 5:
        {
            cout << "The size of your vecray is : " << vec.len() << endl;
            goto loop;
        }
        case 6:
        {
            cout << "Bye!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid input!\nEnter again" << endl;
            goto loop;
        }
    }

    return 0;
}