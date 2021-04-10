#include "struct.h" //mi codigo
void menu()         //El menú
{
    cout << "1)Tienda\n";
    cout << "2)Alumnos Programación ordenar\n";
    cout << "3)Amigos\n";
    cout << "4)Lista Alumnos porcentajes\n";
    cout << "5)Tienda de video\n";
    cout << "6)Control CI\n";
    cout << "7)Lo mmismo que el 2 sin ordenar\n";
    cout << "8)Suscriptores\n";
    cout << "9)Calificaciones A-E\n";
    cout << "10)Libreria\n";
    cout << "11)Sumar Strings y contar\n";
    cout << "12)Promedios\n";
    cout << "13)Notas finales\n";
    cout << "14)8 personas cumpleaños\n";
    cout << "15)50 personas\n";
}

bool sortearNombre(datosAlumnos const &lhs, datosAlumnos const &rhs)
{ //magia
    if (lhs.nombre != rhs.nombre)
    {
        return lhs.nombre < rhs.nombre;
    }
    else
    {
        return NULL; // para eliminar el warning
    }
}

void desarrollo2()
{
    cout << "¿Cúantos alumnos desea guardar?\n";
    std::cin >> lectura;
    struct datosAlumnos datos[100];

    for (int i = 0; i < lectura; i++)
    {
        cout << "Ingrese el nombre para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].nombre;
        cout << "Ingrese el apellido para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].apellido;
        cout << "Ingrese el cédula para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].cedula;
        cout << "Ingrese el dirección para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].direccion;
        cout << "Ingrese el edad para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].edad;
        cout << "Ingrese el lugar de nacimiento para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].lugarNacimiento;
        cout << "Ingrese la profesión para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].profesion;
        cout << "Ingrese el teléfono para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].telefono;
    }
    std::sort(std::begin(datos), std::begin(datos) + lectura, &sortearNombre); //+ lectura por que el tamaño máximo es 100

    for (int i = 0; i < lectura; i++)
    {
        cout << "Nombre del alumno " << i + 1 << " " << datos[i].nombre << "\n";
        cout << "--------------------\n";
        cout << "Apellido del alumno " << i + 1 << " " << datos[i].apellido << "\n";
        cout << "--------------------\n";
        cout << "Cédula del alumno " << i + 1 << " " << datos[i].cedula << "\n";
        cout << "--------------------\n";
        cout << "Dirección del alumno " << i + 1 << " " << datos[i].direccion << "\n";
        cout << "--------------------\n";
        cout << "Edad del alumno " << i + 1 << " " << datos[i].edad << "\n";
        cout << "--------------------\n";
        cout << "Lugar de nacimiento del alumno " << i + 1 << " " << datos[i].lugarNacimiento << "\n";
        cout << "--------------------\n";
        cout << "Profesión del alumno " << i + 1 << " " << datos[i].profesion << "\n";
        cout << "--------------------\n";
        cout << "Teléfono del alumno " << i + 1 << " " << datos[i].telefono << "\n";
        cout << "--------------------\n";
    }
}
void desarrollo3()
{
    struct amigos misAmigos[4];
    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese el nombre para el alumno " << i + 1 << "\n";
        std::cin >> misAmigos[i].nombre;
        cout << "Ingrese el apellido para el alumno " << i + 1 << "\n";
        std::cin >> misAmigos[i].apellido;
        cout << "Ingrese el cédula para el alumno " << i + 1 << "\n";
        std::cin >> misAmigos[i].fNacimiento;
        cout << "Ingrese el dirección para el alumno " << i + 1 << "\n";
        std::cin >> misAmigos[i].direccion;
        cout << "Ingrese el edad para el alumno " << i + 1 << "\n";
        std::cin >> misAmigos[i].sexo;
        cout << "Ingrese el lugar de nacimiento para el alumno " << i + 1 << "\n";
        std::cin >> misAmigos[i].telefono;
    }
    for (int i = 0; i < lectura; i++)
    {
        cout << "Nombre del amigo " << i + 1 << " " << misAmigos[i].nombre << "\n";
        cout << "--------------------\n";
        cout << "Apellido del amigo " << i + 1 << " " << misAmigos[i].apellido << "\n";
        cout << "--------------------\n";
        cout << "Fecha de nacimiento del amigo " << i + 1 << " " << misAmigos[i].fNacimiento << "\n";
        cout << "--------------------\n";
        cout << "Dirección del amigo " << i + 1 << " " << misAmigos[i].direccion << "\n";
        cout << "--------------------\n";
        cout << "Sexo del amigo " << i + 1 << " " << misAmigos[i].sexo << "\n";
        cout << "--------------------\n";
        cout << "Telefono de nacimiento del amigo " << i + 1 << " " << misAmigos[i].telefono << "\n";
        cout << "--------------------\n";
    }
}
void desarrollo4()
{
    cout << "Ingrese la cantidad de alumnos\n";
    std::cin >> lectura;
    struct alumnosAprobadosEDA notas[100];
    for (int i = 0; i < lectura; i++)
    {
        cout << "Ingrese el nombre para el alumno " << i + 1 << "\n";
        std::cin >> notas[i].nombre;
        cout << "Ingrese la primera nota para el alumno " << i + 1 << "\n";
        std::cin >> notas[i].nota1;
        cout << "Ingrese la primera nota para el alumno " << i + 1 << "\n";
        std::cin >> notas[i].nota2;
    }
    double aprobados = 0, reprobados = 0;
    for (int i = 0; i < lectura; i++)
    {

        double promedio = (notas[i].nota1 + notas[i].nota2) / 2;
        if (promedio >= 51)
        {
            aprobados++;
            cout << "APROBADO";
        }
        else
        {
            reprobados++;
        }
    }
    double porcentajeAprobados = (aprobados / lectura) * 100, porcentajeReprobados = (aprobados / lectura) * 100;
    cout << "El porcentaje de aprobados es del " << porcentajeAprobados << "% y el porcentaje de reprobados " << porcentajeReprobados << "%\n";
}
void desarrollo5()
{
    cout << "Ingrese la cantidad de cintas de video\n";
    std::cin >> lectura;
    struct tiendaVideo videos[100];
    for (int i = 0; i < lectura; i++)
    {
        cout << "Ingrese el titulo de la cinta de video" << i + 1 << "\n";
        std::cin >> videos[i].titulo;
        cout << "Ingrese el preico de la cinta de video " << i + 1 << "\n";
        std::cin >> videos[i].precioAlquiler;
        cout << "Ingrese la fecha de venta de la cinta de video " << i + 1 << "\n";
        std::cin >> videos[i].fechaVenta;
        cout << "Ingrese la duración de la cinta de video " << i + 1 << "\n";
        std::cin >> videos[i].duracionMinutos;
        cout << "Ingrese la clasificación de la cinta de video " << i + 1 << "\n";
        std::cin >> videos[i].clasificacion;
    } //almacenado, luego que hago?¿?¿?
}
void desarrollo6()
{
    struct controlNombres control[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese el nombre de el estudiante " << i + 1 << "\n";
        std::cin >> control[i].nombre;
        cout << "Ingrese la edad de el estudiante " << i + 1 << "\n";
        std::cin >> control[i].edad;
        cout << "Ingrese el CI de el estudiante " << i + 1 << "\n";
        std::cin >> control[i].ci;
        cout << "Ingrese calificaciones de el estudiante " << i + 1 << "\n";
        std::cin >> control[i].calificaciones;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << "El nombre de el estudiante " << i + 1 << "\n";
        cout << "---------------" << control[i].nombre << "------------------\n";
        cout << "La edad de el estudiante " << i + 1 << "\n";
        cout << "-----------------" << control[i].edad << "----------------\n";
        cout << "El CI de el estudiante " << i + 1 << "\n";
        cout << "---------------" << control[i].ci << "------------------\n";
        cout << "Calificaciones de el estudiante " << i + 1 << "\n";
        cout << "---------------" << control[i].calificaciones << "-----------------\n";
    }
}
void desarrollo7() //repetido del 2
{
    cout << "¿Cúantos alumnos desea guardar?\n";
    std::cin >> lectura;
    struct datosAlumnos2 datos[100];

    for (int i = 0; i < lectura; i++)
    {
        cout << "Ingrese el nombre para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].nombre;
        cout << "Ingrese el apellido para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].apellido;
        cout << "Ingrese el cédula para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].cedula;
        cout << "Ingrese el dirección para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].direccion;
        cout << "Ingrese el edad para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].edad;
        cout << "Ingrese el lugar de nacimiento para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].lugarNacimiento;
        cout << "Ingrese la profesión para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].profesion;
        cout << "Ingrese el teléfono para el alumno " << i + 1 << "\n";
        std::cin >> datos[i].telefono;
    }
    //std::sort(std::begin(datos), std::begin(datos) + lectura, &sortearNombre); //+ lectura por que el tamaño máximo es 100

    for (int i = 0; i < lectura; i++)
    {
        cout << "Nombre del alumno " << i + 1 << " " << datos[i].nombre << "\n";
        cout << "--------------------\n";
        cout << "Apellido del alumno " << i + 1 << " " << datos[i].apellido << "\n";
        cout << "--------------------\n";
        cout << "Cédula del alumno " << i + 1 << " " << datos[i].cedula << "\n";
        cout << "--------------------\n";
        cout << "Dirección del alumno " << i + 1 << " " << datos[i].direccion << "\n";
        cout << "--------------------\n";
        cout << "Edad del alumno " << i + 1 << " " << datos[i].edad << "\n";
        cout << "--------------------\n";
        cout << "Lugar de nacimiento del alumno " << i + 1 << " " << datos[i].lugarNacimiento << "\n";
        cout << "--------------------\n";
        cout << "Profesión del alumno " << i + 1 << " " << datos[i].profesion << "\n";
        cout << "--------------------\n";
        cout << "Teléfono del alumno " << i + 1 << " " << datos[i].telefono << "\n";
        cout << "--------------------\n";
    }
}
void desarrollo8()
{
    cout << "Ingrese la cantidad de suscriptores\n";
    std::cin >> lectura;
    struct suscripcionRevista subs[100];
    for (int i = 0; i < lectura; i++)
    {
        cout << "Ingrese el año de inscripción" << i + 1 << "\n";
        std::cin >> subs[i].yearInscripcion;
        cout << "Ingrese el nombre de el suscriptor " << i + 1 << "\n";
        std::cin >> subs[i].nombre;
        cout << "Ingrese el mes de inscripción " << i + 1 << "\n";
        std::cin >> subs[i].mesInscripcion;
        cout << "Ingrese la cédula del suscriptor" << i + 1 << "\n";
        std::cin >> subs[i].cedula;
    } //Luego qué?
}
void desarrollo9()
{
    struct estudiante ejemplo[20];
    for (int i = 0; i < 20; i++)
    {
        std::cout << "Ingrese el nombre de el estudiante\n";
        std::cin >> ejemplo[i].nombreEstudiante;
        for (int j = 0; j < 6; j++)
        {
            std::cout << "Ingrese el nombre de la materia\n";
            std::cin >> ejemplo[i].materia[j].nombreMateria;
            std::cout << "Ingrese la calificación de la materia en letras\n";
            std::cin >> ejemplo[i].materia[j].calificacion;
        }
    }
    for (int i = 0; i < 20; i++)
    {
        std::cout << "El estudiantes" << i + 1 << ejemplo[i].nombreEstudiante << "\n";
        for (int j = 0; j < 6; j++)
        {
            std::cout << "En la materia " << j + 1 << ejemplo[i].materia[j].nombreMateria << "\n";
            std::cout << "Con la calificación de " << ejemplo[i].materia[j].calificacion << "\n";
        }
    } //output
}
void desarrollo10()
{
    struct biblioteca revistas[100];
    std::cout << "¿Cúantas revistas va a almacenar?\n";
    std::cin >> lectura;
    for (int i = 0; i < lectura; i++)
    {
        std::cout << "Ingrese el año de la revista\n";
        std::cin >> revistas[i].year;
        std::cout << "Ingrese el titulo de la revista\n";
        std::cin >> revistas[i].titulo;
        std::cout << "Ingrese el numero de referencia de la revista\n";
        std::cin >> revistas[i].numReferencia;
        std::cout << "Ingrese el numero de la revista\n";
        std::cin >> revistas[i].nRevista;
        std::cout << "Ingrese la edición de la revista\n";
        std::cin >> revistas[i].nEdicion;
        std::cout << "Ingrese el nombre de autor de la revista\n";
        std::cin >> revistas[i].nAutor;
        std::cout << "Ingrese el nombre de la editorial de la revista\n";
        std::cin >> revistas[i].editorial;
        std::cout << "Ingrese el tipo de la revista\n";
        std::cin >> revistas[i].clase;
    } //Los almaceno y luego qué?
}
void desarrollo11()
{
    struct cadenas ejercicio; //YandereDevMoment
    std::cout << "Ingrese para la primera cadena\n";
    std::cin >> ejercicio.a1;
    std::cout << "Ingrese para la segunda cadena\n";
    std::cin >> ejercicio.a2;
    std::cout << "Ingrese para la tercera cadena\n";
    std::cin >> ejercicio.a3;
    transform(ejercicio.a1.begin(), ejercicio.a1.end(), ejercicio.a1.begin(), ::toupper); //no funciona el toupper(ejercicio.a1)
    ejercicio.a2 += ejercicio.a1;
    ejercicio.a3.length();
    std::cout << "1) " << ejercicio.a2 << " 2) " << ejercicio.a3.length() << "\n";
}
void desarrollo12()
{
    struct calcularValores notas[100];
    std::cout << "Ingrese el número de alumnos\n";
    std::cin >> lectura;
    int prom = 0, max = 0, min = 0;
    for (int i = 0; i < lectura; i++)
    {
        std::cout << "Nombre para el alumno " << i + 1 << "\n";
        std::cin >> notas[i].nombre;
        std::cout << "Nota para el alumno " << i + 1 << "\n";
        std::cin >> notas[i].nota;
    }
    min = notas[0].nota;
    for (int i = 0; i < lectura; i++)
    {
        if (notas[i].nota > max)
        {
            max = notas[i].nota;
        }
        if (notas[i].nota < min)
        {
            min = notas[i].nota;
        }
        prom += notas[i].nota;
    }
    prom = prom / lectura;
    std::cout << "La nota máxima es " << max << " la nota minima es " << min << " la nota promedio es " << prom << "\n";
}
bool sortearMaximo(calcularNota const &lhs, calcularNota const &rhs)
{ //magia
    if (lhs.NF > rhs.NF)
    {
        return lhs.NF < rhs.NF;
    }
    else
    {
        return NULL; // para eliminar el warning
    }
}
bool sortearMinimo(calcularNota const &lhs, calcularNota const &rhs)
{ //magia
    if (lhs.NF < rhs.NF)
    {
        return lhs.NF < rhs.NF;
    }
    else
    {
        return NULL; // para eliminar el warning
    }
}
void desarrollo13()
{
    calcularNota cnota[100];
    std::cout << "Ingresa la cantidad de estudiantes\n";
    std::cin >> lectura;
    for (int i = 0; i < lectura; i++)
    {
        std::cout << "Ingresa el nombre del estudiante " << i + 1 << "\n";
        std::cin >> cnota[i].nombre;
        std::cout << "Ingrese nota para I1\n";
        std::cin >> cnota[i].I1;
        std::cout << "Ingrese nota para I2\n";
        std::cin >> cnota[i].I2;
        std::cout << "Ingrese nota para T1\n";
        std::cin >> cnota[i].T1;
        std::cout << "Ingrese nota para T2\n";
        std::cin >> cnota[i].T2;
        std::cout << "Ingrese nota para Examen\n";
        std::cin >> cnota[i].nExamen;
        cnota[i].NP = (cnota[i].I1 + cnota[i].I2 + cnota[i].T1 + cnota[i].T2) / 4;
        cnota[i].NF = (0.7 * cnota[i].NP) + (0.3 * cnota[i].nExamen);
    }
    system("CLS");
    int promedio = 0;
    cout << "---------------------Listado---------------------\n";
    for (int i = 0; i < lectura; i++)
    {
        std::cout << "Nombre del estudiante " << i + 1 << cnota[i].nombre << "\n";
        std::cout << "Nota para I1 " << cnota[i].I1 << "\n";
        std::cout << "Nota para I2 " << cnota[i].I2 << "\n";
        std::cout << "Nota para T1 " << cnota[i].T1 << "\n";
        std::cout << "Nota para T2 " << cnota[i].T2 << "\n";
        std::cout << "Nota para Examen " << cnota[i].nExamen << "\n";
        std::cout << "Nota final " << cnota[i].NF << "\n";
        std::cout << "Nota Promedio del estudiante (Practicas) " << cnota[i].NP << "\n";
        promedio += cnota[i].NF;
    }
    cout << "------------------------------------------------\n";
    promedio /= lectura;
    std::cout << "------------------Nota Máxima-------------\n";
    std::sort(std::begin(cnota), std::begin(cnota) + lectura, &sortearMaximo);
    std::cout << "Nombre del estudiante " << cnota[0].nombre << "\n";
    std::cout << "Nota para I1 " << cnota[0].I1 << "\n";
    std::cout << "Nota para I2 " << cnota[0].I2 << "\n";
    std::cout << "Nota para T1 " << cnota[0].T1 << "\n";
    std::cout << "Nota para T2 " << cnota[0].T2 << "\n";
    std::cout << "Nota para Examen " << cnota[0].nExamen << "\n";
    std::cout << "Nota final " << cnota[0].NF << "\n";
    std::cout << "Nota Promedio del estudiante (Practicas) " << cnota[0].NP << "\n";
    std::cout << "------------------Nota Minima-------------\n";
    std::sort(std::begin(cnota), std::begin(cnota) + lectura, &sortearMinimo);
    std::cout << "Nombre del estudiante " << cnota[0].nombre << "\n";
    std::cout << "Nota para I1 " << cnota[0].I1 << "\n";
    std::cout << "Nota para I2 " << cnota[0].I2 << "\n";
    std::cout << "Nota para T1 " << cnota[0].T1 << "\n";
    std::cout << "Nota para T2 " << cnota[0].T2 << "\n";
    std::cout << "Nota para Examen " << cnota[0].nExamen << "\n";
    std::cout << "Nota final " << cnota[0].NF << "\n";
    std::cout << "Nota Promedio del estudiante (Practicas) " << cnota[0].NP << "\n";
    std::cout << "------------------Nota Promedio-------------\n";
    std::cout << promedio << "\n";
}
void desarrollo14()
{
    datosPersona ocho[7];
    for (int i = 0; i < 8; i++)
    {
        std::cout << "Introduce el nombre de la persona " << i + 1 << "\n";
        ocho[i].nombre;
        std::cout << "Introduce el año de nacimiento de la persona " << i + 1 << "\n";
        ocho[i].yearBorn;
        std::cout << "Introduce el mes de nacimiento de la persona " << i + 1 << "\n";
        ocho[i].mesNacimiento;
        std::cout << "Introduce el dia de nacimiento de la persona " << i + 1 << "\n";
        ocho[i].diaNacimiento;
    }
    int opt1 = 0;
    do
    {
        system("CLS");
        std::cout << "Introduce un número de mes para ver quien cumple en ese mes\nPresiona 0 para salir\n";
        std::cin >> opt1;
        for (int i = 0; i < 8; i++)
        {
            if (ocho[i].mesNacimiento == opt1)
            {
                std::cout << "Nombre de la persona " << ocho[i].nombre << "\n";
                std::cout << "Año de nacimiento de la persona " << ocho[i].yearBorn << "\n";
                std::cout << "Mes de nacimiento de la persona " << ocho[i].mesNacimiento << "\n";
                std::cout << "Dia de nacimiento de la persona " << ocho[i].diaNacimiento << "\n";
            }
        }
    } while (opt1 != 0);
}
void desarrollo15()
{
    int opt1 = 0;
    int edad = 0;
    char inicial = '0';
    otroDatosPersona nuevo[50];
    for (int i = 0; i < 50; i++)
    {
        std::cout << "Introduzca el nombre para la persona " << i + 1 << "\n";
        std::cin >> nuevo[i].nombre;
        if (nuevo[i].nombre.empty())
            ;
        {
            break;
        }
        std::cout << "Introduzca el telefono para la persona " << i + 1 << "\n";
        std::cin >> nuevo[i].telefono;
        std::cout << "Introduzca edad para la persona " << i + 1 << "\n";
        std::cin >> nuevo[i].edad;
        std::cout << "Introduzca la dirección para la persona " << i + 1 << "\n";
        std::cin >> nuevo[i].direccion;
    }
    do
    {
        std::cout << "0)Salir\n";
        std::cout << "1)Mostrar la lista\n";
        std::cout << "2)Mostrar la lista con personas de cierta edad\n";
        std::cout << "3)Mostrar los usuarios con una inicial\n";
        std::cin >> opt1;
        switch (opt1)
        {
        case 1:
        {
            for (int i = 0; i < 50; i++)
            {
                if (nuevo[i].nombre.empty())
                    {
                        break;
                    }
                std::cout << "Nombre de la persona " << i + 1 << " : " << nuevo[i].nombre << "\n";
                std::cout << "Telefono de la persona " << i + 1 << " : " << nuevo[i].telefono << "\n";
                std::cout << "Edad de la persona " << i + 1 << " : " << nuevo[i].edad << "\n";
                std::cout << "Dirección de la persona " << i + 1 << " : " << nuevo[i].direccion << "\n";
            }
            break;
        }
        case 2:
        {
            std::cout << "Ingrese la edad \n";
            std::cin >> edad;
            for (int i = 0; i < 50; i++)
            {
                if (nuevo[i].edad == edad)
                {
                    if (nuevo[i].nombre.empty())
                    {
                        break;
                    }
                    std::cout << "Nombre de la persona " << i + 1 << " : " << nuevo[i].nombre << "\n";
                    std::cout << "Telefono de la persona " << i + 1 << " : " << nuevo[i].telefono << "\n";
                    std::cout << "Edad de la persona " << i + 1 << " : " << nuevo[i].edad << "\n";
                    std::cout << "Dirección de la persona " << i + 1 << " : " << nuevo[i].direccion << "\n";
                }
            }
        }
        case 3:
        {
            std::cout << "Ingrese la inicial \n";
            std::cin >> inicial;
            for (int i = 0; i < 50; i++)
            {
                if (nuevo[i].nombre[0] == inicial)
                {
                    if (nuevo[i].nombre.empty())
                    {
                        break;
                    }
                    std::cout << "Nombre de la persona " << i + 1 << " : " << nuevo[i].nombre << "\n";
                    std::cout << "Telefono de la persona " << i + 1 << " : " << nuevo[i].telefono << "\n";
                    std::cout << "Edad de la persona " << i + 1 << " : " << nuevo[i].edad << "\n";
                    std::cout << "Dirección de la persona " << i + 1 << " : " << nuevo[i].direccion << "\n";
                }
            }
        }
        default:
            break;
        }
    } while (opt1 != 0);
}
void limpiar()
{
    cout << "Presione una tecla para continuar...\n";
    getch();
    system("CLS");
}
int main()
{
    do
    {
        system("CLS");
        menu();
        std::cin >> opt;
        switch (opt)
        {
        case 1:
        {
            break;
        }
        case 2:
        {
            desarrollo2();
            limpiar();
            break;
        }
        case 3:
        {
            desarrollo3();
            limpiar();
            break;
        }
        case 4:
        {
            desarrollo4();
            limpiar();
            break;
        }
        case 5:
        {
            desarrollo5();
            limpiar();
            break;
        }
        case 6:
        {
            desarrollo6();
            limpiar();
            break;
        }
        case 7:
        {
            desarrollo7();
            limpiar();
            break;
        }
        case 8:
        {
            desarrollo8();
            limpiar();
            break;
        }
        case 9:
        {
            desarrollo9();
            limpiar();
            break;
        }
        case 10:
        {
            desarrollo10();
            limpiar();
            break;
        }
        case 11:
        {
            desarrollo11();
            limpiar();
            break;
        }
        case 12:
        {
            desarrollo12();
            limpiar();
            break;
        }
        case 13:
        {
            desarrollo13();
            limpiar();
            break;
        }
        case 14:
        {
            desarrollo14();
            limpiar();
            break;
        }
        case 15:
        {
            desarrollo15();
            limpiar();
            break;
        }
        default:
            break;
        }
    } while (opt != 0);
    return 0;
}