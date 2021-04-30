#include <iostream>
#define tam 100

using namespace std;

void ej13_menu()
{
    cout << "1.Encolar" << endl;
    cout << "2. Desencolar" << endl;
    cout << "3. salir" << endl;
}

int ej13_t = 0;
int ej13_vec[tam];
int *pej13_vec;

void ej13_listado()
{
    for (int i = 0; i < ej13_t; i++)
    {
        cout << "persona " << i + 1 << endl;
    }
}

void ej13_encolar()
{
    ej13_t++;
    /*
    pej13_vec = ej13_vec;

    for (int i = ej13_t; i < ej13_t; i++)
    {

        pej13_vec = &i;

        cout << "persona " << *pej13_vec << endl;

        pej13_vec++;
    }
    */
    ej13_listado();
}

void ej13_desencolar()
{
    /*
    pej13_vec = &ej13_vec[0];

    if (ej13_t != 0)
    {

        for (int i = 0; i < ej13_t - 1; i++)
        {

            if (*pej13_vec != 0)
            {

                cout << "persona " << *pej13_vec << endl;

                pej13_vec++;
            }
        }
    }
    */
    if (ej13_t < 1)
    {

        cout << "no hay personas en fila" << endl;
    }
    
    ej13_t--;

    ej13_listado();
}

int main()
{

    int opc2 = 0;

    do
    {

        ej13_menu();

        cin >> opc2;

        switch (opc2)
        {

        case 1:
        {
            ej13_encolar();
            break;
        }

        case 2:
        {
            ej13_desencolar();
            break;
        }

        case 3:
        {
            cout << "hasta luego" << endl;
            break;
        }

        default:
        {
            cout << "ese numero no existe" << endl;
            break;
        }
        }

    } while (opc2 != 3);

    return 0;
}