//facilito 
#include <iostream> //cout
#include <conio.h> //getch
//#include <vector> // casi lo uso
#include <string> //getline
#include <math.h> //abs
#include <cstring> //memset
#include <time.h>  //time
using std::cout; //Using std::cout para evitar escribir tanto std...

//Variables Globales, hay algunas más que deberían serlo...
std::string m1, password, passwordIngresada;
int v[100][100], passwordInt, passwordIngresadaInt, v2[100][100];
int icounter = 0, jcounter = 0, mezclar = 0, contadorLetras = 0, endvalue = 0;
///////////////////////
/*---HACKEO---, la función llena de valores aleatorios los arrays bidimensionales*/
void hackeo()
{
   srand(time(NULL));
   for (int i = 0; i < 100; i++)
   {
      for (int j = 0; j < 100; j++)
      {
         v2[i][j] = rand() % 99999 + 10000;
         v[i][j] = rand() % 99999 + 10000;
      }
   }
}
/*----MENSAJE----, la función llama a getline para obtener el valor del mensaje*/
void mensaje()
{
   //
   cout << "Ingrese el mensaje" << std::endl;
   std::cin.ignore();
   std::getline(std::cin, m1);
   if (m1.size() % 2 != 0)
   {
      m1.push_back(' ');
      m1.push_back(' ');
   }
   //
}
/*----OBTENERPASSWORD----, la función llama a getline para obtener el valor del PASSWORD, además, obtiene su valor int de la suma de sus valores ASCII y se multiplica por si mismo*/
void obtenerPassword()
{
   passwordInt = 0;
   //
   cout << "Ingrese la contraseña" << std::endl;
   std::getline(std::cin, password);
   for (int i = 0; i < password.size(); i++)
   {
      passwordInt += password[i]; //la suma de los valores ascii de la pass
   }
   passwordInt *= passwordInt; //multiplicado por si mismo
   //
}
/*---ENCRIPTADO----, la función establece el memset del array v a 0, determina el tamaño del array con la raiz cuadrada del size de la cadena
además, convierte dichos valores de nuestro string en valores ASCII*/
void encriptado()
{
   memset(v, 0, sizeof(v));
   char m = '0';
   int oracionSize = m1.size();
   int contador = 0;
   for (int i = 0; i < sqrt(m1.size()); i++) //Transcribimos los valores ascii en la matriz
   {

      for (int j = 0; j < sqrt(m1.size()); j++)
      {
         if (contador <= oracionSize)
         {
            v[i][j] = ((int(m1[contador])));
            contador++;
         }
         cout << v[i][j] << "\t\t" << j;
      }
      cout << std::endl;
      cout << std::endl;
   }
   cout << "------------------1-------------------" << std::endl;
   contador = 0;                             // resetear contador para futuros mensajes
    /*"Encriptamos" sumando la contraseña para cada valor y lo mostramos, es el PRIMER PASO*/
   for (int i = 0; i < sqrt(m1.size()); i++)
   {
      for (int j = 0; j < sqrt(m1.size()); j++)
      {
         v[i][j] += passwordInt;
         cout << v[i][j] << "\t\t";
      }
      cout << std::endl;
      cout << std::endl;
   }
   cout << "-----------------2----------------------" << std::endl;
   int mezclar = passwordInt;
   int limite = (sqrt(m1.length())) + 1;
   icounter = 0;
   jcounter = 0;
   srand(time(NULL));
   contadorLetras = m1.length();
   /*"Encriptamos" mezclamos los valores dependiendo de lacontraseña y creamos BAIT con valores aleatorios para despistar*/
   for (int i = 0; i < (sqrt(m1.size())) * 2; i++) 
   {

      for (int j = 0; j < (sqrt(m1.size())) * 2; j++)
      {
         v2[i][j] = rand() % 99999 + 10000;
         if (mezclar % 2 != 0)
         {
            if (jcounter < limite && v[icounter][jcounter] != 0)
            {
               v2[i][j] = v[icounter][jcounter];
               jcounter++;

               if (jcounter == limite)
               {
                  jcounter = 0;
                  icounter++;
               }
            }
         }
         mezclar--;
         cout << v2[i][j] << "\t\t";
      }
      cout << std::endl;
      cout << std::endl;
   }
   double endvalue2;
   endvalue2 = (sqrt(m1.size()) * 2);
   /*Establecemos si nuestra raiz fue irracional o no, con su valor absoluto, para posicionarlo en última o penultima posición, así sabremos el LENGTH de nuestro array que estará en el propio código*/
   if (endvalue2 == abs(endvalue2) && endvalue2 > 5)
   {
      endvalue = (sqrt(m1.size()) * 2) - 1; 
   }
   else
   {
      endvalue = (sqrt(m1.size()) * 2); 
   }

   v2[endvalue][endvalue] = contadorLetras; 
   cout << "\nEl mensaje es :\n";
   /*Hacemos un OUTPUT de los valores de nuestro ARRAY BIDIMENSIONAL, este ya es el mensaje encriptado*/
   for (int i = 0; i < (sqrt(m1.size())) * 2; i++) //cout valores
   {
      for (int j = 0; j < (sqrt(m1.size())) * 2; j++)
      {
         cout << v2[i][j];
      }
   }
   endvalue = 0;
}
/*------------DESENCRIPTADO---------Esta función sirve para desencriptar nuestro array bidimensional*/
void desencriptado()
{
   if (passwordInt == 0) //comprobación de password, si no la hay no deja continuar
   {
      cout << "Debes encriptar primero" << std::endl;
      return;
   }
   srand(time(NULL));
   int hackeadoPapa = rand() % 5 + 1;
   if (hackeadoPapa == 1) //Comprobación de hackeo, es al azar con una chance de 1/5(20%) de ser hackeado
   {
      hackeo();
      cout << "\nEl mensaje fue hackeado y por lo tanto es ilegible.\n";
      passwordInt = 0;
      return;
   }
   cout << "\nIngresa la contraseña" << std::endl; //Pedimos la contraseña para iniciar el proceso de desencriptado
   std::cin >> passwordIngresada;
   passwordIngresadaInt = 0;
   //Contraseña
   for (int i = 0; i < passwordIngresada.length(); i++)
   {
      passwordIngresadaInt += int(passwordIngresada[i]);
   }
   passwordIngresadaInt *= passwordIngresadaInt;
   //
   mezclar = passwordIngresadaInt;
   double endvalue2 = (sqrt(m1.size()) * 2);
   if (endvalue2 == abs(endvalue2) && endvalue2 > 5) // Comprobamos igual que en el encriptado, si nuestro cuadrado es irracional o no
   {
      endvalue = (sqrt(m1.size()) * 2) - 1; 
   }
   else
   {
      endvalue = (sqrt(m1.size()) * 2); 
   }
   contadorLetras = v2[endvalue][endvalue];
   //Establecemos un valor char inicializado para desencriptar valores ASCII
   char ch = '0';
   //
   for (int i = 0; i < (sqrt(m1.size())) * 2; i++) //Desencriptamos
   {
      for (int j = 0; j < (sqrt(m1.size())) * 2; j++)
      {
         if (mezclar % 2 != 0 && contadorLetras > 0) //Mezclar es el valor de nuestra contraseña en int, si es un número par pasa algo, si es un impar pasa otra cosa
         {
            if (v2[i][j] - passwordIngresadaInt != 0)
            {
               ch = char(v2[i][j] - passwordIngresadaInt); //Output de nuestro valor desencriptado
               std::cout << ch;
            }

            contadorLetras--;
         }
         mezclar--;
      }
   }
}
void limpiar() //Función para limpiar y mostrar mensaje
{
   cout << "\nPresione una tecla para continuar" << std::endl;
   getch();
   system("cls");
}

void menu()//Función del menú
{
   cout << "1)Envio de Mensajería\n";
   cout << "2)Recepción de Mensajería\n";
   cout << "3)Salir\n";
}
int opt = 0;
/*Main en el cual daremos lugar a todos nuestros procesos*/
int main()
{
   do
   {
      menu();
      std::cin >> opt;
      switch (opt)
      {
      case 1:
      {
         mensaje();
         obtenerPassword();
         encriptado();
         limpiar();
         break;
      }
      case 2:
      {
         desencriptado();
         limpiar();
         break;
      }
      case 3:
      {
         opt = 0;
      }
      default:
         break;
      }
   } while (opt != 0);
   return 0;
}