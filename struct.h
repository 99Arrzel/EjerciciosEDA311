#include <iostream>  //cout
#include <string>    // string
#include <algorithm> //sort
#include <conio.h>   //getch

///Global Variables
int opt = 0;
int lectura = 0;
///
using std::cout;

struct productos //1
{
    double pCompra;
    double pVenta;
    int codigo;
    int cantidad;
};
struct datosAlumnos //2
{
    int cedula;
    std::string nombre;
    std::string apellido;
    int edad;
    std::string profesion;
    std::string lugarNacimiento;
    std::string direccion;
    int telefono;
};
struct amigos //3
{
    std::string nombre;
    std::string apellido;
    std::string fNacimiento;
    std::string sexo;
    std::string direccion;
    int telefono;
};
struct alumnosAprobadosEDA //4
{
    std::string nombre;
    int nota1;
    int nota2;
};
struct tiendaVideo //5
{
    std::string titulo;
    int duracionMinutos;
    double precioAlquiler;
    std::string fechaVenta;
    std::string clasificacion;
};
struct controlNombres //6
{
    std::string nombre;
    int edad;
    int calificaciones;
    int ci;
};
struct datosAlumnos2 //7, repetidozzz
{
    int cedula;
    std::string nombre;
    std::string apellido;
    int edad;
    std::string profesion;
    std::string lugarNacimiento;
    std::string direccion;
    int telefono;
};
struct suscripcionRevista //8
{
    std::string nombre;
    int cedula;
    int mesInscripcion;
    int yearInscripcion;
};
struct estudiante //9
{
    std::string nombreEstudiante;
    struct materiasEstudiante
    {
        std::string nombreMateria;
        char calificacion;
    };
    materiasEstudiante materia[6];//struct array en un struct?
};
struct biblioteca //10
{
    int numReferencia;
    std::string titulo;
    std::string nAutor;
    std::string editorial;
    std::string clase;
    int nEdicion;
    int year;
    std::string nRevista;
};
struct cadenas // 11 no tiene sentido, todas son string
{
    std::string a1;
    std::string a2;
    std::string a3;
};
struct calcularValores //12
{
    std::string nombre;
    int nota;
};
struct calcularNota //13
{
    std::string nombre;
    double I1;
    double I2;
    double T1;
    double T2;
    double nExamen;
    double NF;
    double NP;
};
struct datosPersona //14
{
    std::string nombre;
    int diaNacimiento;
    int mesNacimiento;
    int yearBorn;
};
struct otroDatosPersona //15
{
    std::string nombre;
    std::string direccion;
    int telefono;
    int edad;
};