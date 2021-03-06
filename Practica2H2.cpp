/*Almacenar el nombre,estatura y anio de nacimiento de n estudiantes
Mostrar loa siguuentes requerimientos




1.Listado general ordenado por nombre
2.Mostrar el promedio de edades y estatura
3.Listado de pesonas mayores a 40
4.Mostar la persona con mayor y menor edad
*/
#include <iostream> //cout, cin
#include <conio.h>  //getch
#include <cstring>  //memeset
#define tam 100

using namespace std;

string nombre[tam];
float estatura[tam];
int anNac[tam];
int t, gestion;

void crear()
{
    memset(estatura, 0, sizeof(estatura));
    memset(anNac, 0, sizeof(anNac));
}
void menuListar()
{
    std::cout << "1.Insertar datos " << std::endl
              << "2.Mostrar el promedio de edades y estatura" << std::endl
              << "3.Listado de pesonas mayores a 40" << std::endl
              << "4.Mostar la persona con mayor y menor edad" << std::endl
              << "5.Listado general ordenado por nombre" << std::endl;
}
void insert_data()
{
    cout << "Introduzca gestion-->";
    cin >> gestion;
    cout << "Cantidad de alumnos--->";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Nombre-Estudiante" << i + 1 << "--->";
        cin >> nombre[i];
        cout << "Estatura--->";
        cin >> estatura[i];
        cout << "Anio nacimiento--->";
        cin >> anNac[i];
    }
}

void lista_gen40()
{
    float sumEst = 0, promEst;
    int sumEd = 0, promEd;
    cout << "\t LISTADO GENERAL DE ALUMNOS" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "NOMBRES\tESTATURAS\tANIO-NAC.\tEDAD" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < t; i++)
    {
        if ((gestion - anNac[i]) >= 40)
            cout << nombre[i] << '\t' << estatura[i] << "\t\t\t" << anNac[i] << "\t\t\t" << gestion - anNac[i] << endl;
        sumEst = sumEst + estatura[i];
        sumEd = sumEd + (gestion - anNac[i]);
    }
    cout << "-------------------------------------------" << endl;
    promEd = sumEd / t;
    promEst = sumEst / t;
    cout << "El promedio de estaturas--" << promEst << endl;
    cout << "El promedio de edades-->" << promEd << endl;
}
void listEstProm()
{
    float sumEst = 0, promEst;
    int sumEd = 0, promEd;
    for (int i = 0; i < t; i++)
    {
        if ((gestion - anNac[i]) >= 40)
            sumEst = sumEst + estatura[i];
        sumEd = sumEd + (gestion - anNac[i]);
    }
    cout << "-------------------------------------------" << endl;
    promEd = sumEd / t;
    promEst = sumEst / t;
    cout << "El promedio de estaturas--" << promEst << endl;
    cout << "El promedio de edades-->" << promEd << endl;
}
void listMenorMayor()
{
    float sumEst = 0, promEst;
    int sumEd = 0, promEd;
    cout << "\t LISTADO GENERAL DE ALUMNOS" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "NOMBRES\tESTATURAS\tANIO-NAC.\tEDAD" << endl;
    cout << "------------MAYORES----------" << endl;
    for (int i = 0; i < t; i++)
    {
        if ((gestion - anNac[i]) >= 18)
            cout << nombre[i] << '\t' << estatura[i] << "\t\t\t" << anNac[i] << "\t\t\t" << gestion - anNac[i] << endl;
        sumEst = sumEst + estatura[i];
        sumEd = sumEd + (gestion - anNac[i]);
    }
    cout << "------------MENORES-------------------" << endl;
    for (int i = 0; i < t; i++)
    {
        if ((gestion - anNac[i]) < 18)
            cout << nombre[i] << '\t' << estatura[i] << "\t\t\t" << anNac[i] << "\t\t\t" << gestion - anNac[i] << endl;
        //    sumEst = sumEst + estatura[i];
        //    sumEd = sumEd + (gestion - anNac[i]);
    }
    promEd = sumEd / t;
    //promEst = sumEst / t;
    //cout << "El promedio de estaturas--" << promEst << endl;
    //cout << "El promedio de edades-->" << promEd << endl;
}

void genList()
{
    float sumEst = 0, promEst;
    int sumEd = 0, promEd;
    cout << "\t LISTADO GENERAL DE ALUMNOS" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "NOMBRES\tESTATURAS\tANIO-NAC.\tEDAD" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < t; i++)
    {
        cout << nombre[i] << '\t' << estatura[i] << "\t\t\t" << anNac[i] << "\t\t\t" << gestion - anNac[i] << endl;
        sumEst = sumEst + estatura[i];
        sumEd = sumEd + (gestion - anNac[i]);
    }
    cout << "-------------------------------------------" << endl;
    promEd = sumEd / t;
    promEst = sumEst / t;
    //cout << "El promedio de estaturas--" << promEst << endl;
    //cout << "El promedio de edades-->" << promEd << endl;
}

void list_ord_nom()
{
    string auxnom;
    float auxest;
    int auxanNa;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t - 1; j++)
        {
            if (nombre[j] > nombre[j + 1])
            {
                auxnom = nombre[j];
                nombre[j] = nombre[j + 1];
                nombre[j + 1] = auxnom;

                auxest = estatura[j];
                estatura[j] = estatura[j + 1];
                estatura[j + 1] = auxest;

                auxanNa = anNac[j];
                anNac[j] = anNac[j + 1];
                anNac[j + 1] = auxanNa;
            }
        }
    }
    cout << endl;
    genList();
    cout << endl;
}
/*
1.Listado general ordenado por nombre
2.Mostrar el promedio de edades y estatura
3.Listado de pesonas mayores a 40
4.Mostar la persona con mayor y menor edad 
5.Insertar datos*/

int main()
{
    int opt = 0;
    do
    {
        menuListar();
        std::cin >> opt;
        switch (opt)
        {
        case 1:
        {
            insert_data();
            getch();
            break;
        }
        case 2:
        {
            listEstProm();
            getch();
            break;
        }
        case 3:
        {
            lista_gen40();
            getch();
            break;
        }
        case 4:
        {
            listMenorMayor();
            getch();
            break;
        }
        case 5:
        {
            list_ord_nom();
            getch();
            break;
        }
        default:
            break;
        }

    } while (opt != 0);
    return 0;
}