#ifndef EMPLEADOS_H
#define EMPLEADOS_H


class Empleados
{
    public:
    Empleados();
    virtual ~Empleados();

    char activo[2]= {'a','\0'};
    char inAct [2]= {'d','\0'};
    char auxAc [2]= {'a','\0'};

    void Activacion         ();
    void Altas              ();
    void Bajas              ();
    void Generador          ();
    void Modificaciones     ();
    void Consultas          ();
    void ConsultaIndividual ();
    void ConsultaGeneral    ();
    void Eliminacion        ();
    void EliminacionLogica  ();
    void ClearScreen        ();
    void MostrarLugaresDisp ();
};

struct Empleado{
    int     cont=1;
    char    codigo     [5];
    char    nombre     [20];
    char    apellido   [40];
    char    sexo       [2];
    char    direccion  [45];
    char    ciudad     [32];
    char    telefono   [12];
    char    pais_origen[15];
    char    cod_final  [5];
};

//static struct{
//short cont_reg;
  // short apt_ini;
   //char  relleno[1];
//}encabezado;



#endif // EMPLEADOS_H
