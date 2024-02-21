#garibay gamero raul jared alberto
#ogazon apolinar gerardo
#practica 07

from colorama import *
from itertools import cycle
import os;
init(autoreset=True);

print(Cursor.POS(20,1)+Fore.YELLOW+Style.BRIGHT+"garibay gamero raul jared alberto");
print(Cursor.POS(24,2)+Fore.CYAN+Style.BRIGHT+"ogazon apolinar gerardo");
print(Cursor.POS(30,3)+Fore.RED+Style.BRIGHT+"practica 07");
input()

def e1(): #Funcion que dada una serie de cadenas dadas y un criterio de busqueda, devuelve las cadenas que terminen con ese criterio dado. 
    os.system("cls");
    ewe=cycle([0]);
    Fin_modulo=1;
    Fin_ingre=1;
    Fin_comando=1;
    Fin_bucle=True;
    LeBuscar='';
    nombresL=[];
    Conta_Error=0;
    Lis_entrada=" ";
    marcoEjer();
    while(Fin_modulo==1):
        for i in ewe:
            print(Cursor.POS(11,3)+Fore.YELLOW+Style.BRIGHT,end="");
            Lis_entrada=input("Dame el nombre a ingresar: ");
            if (Lis_entrada.isdigit()):
                marcoError();
                Conta_Error+=1;
                A=37
                while(A<=69):
                    print(Cursor.POS(A,3)+Back.BLACK+" ", end="");
                    A=A+1
            elif(Lis_entrada==""):
                marcoError();
                Conta_Error+=1;
            elif(Lis_entrada==" "):
                marcoError();
                Conta_Error+=1;
            else:
                nombresL.append(Lis_entrada);
                break; 
        for i in ewe:
            try:
                print(Cursor.POS(11,4)+Fore.RED+Style.BRIGHT,end="");
                Fin_comando=int(input("¿Desea ingresar otra cadena? 1=si, 2=no -> "));
                if (Fin_comando<=0):
                    marcoError();
                    Conta_Error+=1;
                    B=54
                    while(B<=69):
                        print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                        B=B+1
                elif(Fin_comando>2):
                    marcoError();
                    Conta_Error+=1;
                    B=54
                    while(B<=69):
                        print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                        B=B+1
                elif(Fin_comando==1):
                    A=37
                    B=11
                    while(A<=69):
                        print(Cursor.POS(A,3)+Back.BLACK+" ", end="");
                        A=A+1
                    while(B<=69):
                        print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                        B=B+1
                    break;
                elif(Fin_comando==2):
                    Fin_modulo=2;
                    break;
            except:
                marcoError();
                Conta_Error+=1;
                B=54
                while(B<=69):
                    print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                    B=B+1 
    for i in ewe:
        print(Cursor.POS(11,5)+Fore.GREEN+Style.BRIGHT,end="");
        LeBuscar=input("Ingrese la letra para buscar coincidencias: ");
        if (LeBuscar.isdigit()):
            marcoError();
            Conta_Error+=1;
            C=55
            while(C<=69):
                print(Cursor.POS(C,5)+Back.BLACK+" ", end="");
                C=C+1 
        elif(LeBuscar==''):
            marcoError();
            Conta_Error+=1;
        elif(LeBuscar==' '):
            marcoError();
            Conta_Error+=1;
        elif(len(LeBuscar)>1):
            marcoError();
            Conta_Error+=1;
            C=55
            while(C<=69):
                print(Cursor.POS(C,5)+Back.BLACK+" ", end="");
                C=C+1   
        else:
            break;
    C_primario=set(nombresL);
    C_final={i for i in C_primario if i[-1]==LeBuscar}
    if (len(C_final)<=0):
        print(Cursor.POS(11,6)+Fore.CYAN+Style.BRIGHT+"No se han encontrado coincidencias");
    else:
        print(Cursor.POS(11,6)+Fore.CYAN+Style.BRIGHT+"Coincidencias encontradas: ", C_final);
    input();
    os.system("cls");
    return menu(Conta_Error,0,0,0);

def e2(): #Funcion que dada una serie de cadenas, identifica la mas grande y la imprime, y si hay mas de 1 cadena con el mismo tamaño imprime la penultima, de esas cadenas del mismo tamaño
    os.system("cls");
    uwu=cycle([0]);
    Dat_entrada="";
    Comando_salir=0;
    Bucle_Principal=True;
    Conta_error2=0;
    Cad_comparativa=[];
    Cad_casifina=[];
    marcoEjer();
    while(Bucle_Principal==True):
        for i in uwu:
            print(Cursor.POS(11,3)+Fore.YELLOW+Style.BRIGHT,end="");
            Dat_entrada=input("Ingrese la cadena: ");
            if (Dat_entrada==""):
                marcoError();
                Conta_error2+=1;
            elif(Dat_entrada==" "):
                marcoError();
                Conta_error2+=1;
            elif(Dat_entrada.isdigit()):
                marcoError();
                Conta_error2+=1;
                A=20
                while(A<=69):
                    print(Cursor.POS(A,3)+Back.BLACK+" ", end="");
                    A=A+1
            else:
                Cad_comparativa.append(Dat_entrada);
                break;
        for i in uwu:
            try:
                init(autoreset=False)
                print(Cursor.POS(11,4)+Fore.GREEN+Style.BRIGHT,end="");
                Comando_salir=int(input("¿Desea ingresar otra cadena?, 1= si, 2= no "));
                if (Comando_salir==1):
                    A=20
                    B=11
                    while(A<=69):
                        print(Cursor.POS(A,3)+Back.BLACK+" ", end="");
                        A=A+1
                    while(B<=69):
                        print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                        B=B+1
                    break;
                elif(Comando_salir==2):
                    Bucle_Principal=False;
                    break;
                elif(Comando_salir<=0):
                    marcoError();
                    Conta_error2+=1;
                    B=54
                    while(B<=69):
                        print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                        B=B+1
                elif(Comando_salir>2):
                    marcoError();
                    Conta_error2+=1;
                    B=54
                    while(B<=69):
                        print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                        B=B+1
            except:
                marcoError();
                Conta_error2+=1;
                B=54
                while(B<=69):
                    print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                    B=B+1
    cad_semifinal=set(Cad_comparativa); 
    Ordenador=sorted(cad_semifinal, key=len);
    for i in cad_semifinal:
        if (len(i)==len(Ordenador[-1])):
            Cad_casifina.append(i);
        else:
            pass;
    if (len(Cad_casifina)==1):
        print(Cursor.POS(11,5)+Fore.MAGENTA+Style.BRIGHT+"Cadena mas larga",Cad_casifina);
    elif(len(Cad_casifina)>1):
        print(Cursor.POS(11,5)+Fore.MAGENTA+Style.BRIGHT+"Penultima cadena mas larga",Cad_casifina[-2]);
    input();
    os.system("cls");
    return menu(0,Conta_error2,0,0);

def e3(): #Función que obtiene el prefijo común más largo de una lista de cadenas
    os.system("cls");
    h=cycle([0]);
    lista=set()
    ContadorErr3=0;
    marcoEjer();
    for i in h:
        for i in h:
            print(Cursor.POS(11,3)+Fore.WHITE+Style.BRIGHT,end="");
            cadena=str(input("Ingresa una cadena: "));
            cadena.isalpha()
            if(cadena.isalpha()==False):
                ContadorErr3+=1;
                marcoError();
                A=31
                while(A<=69):
                    print(Cursor.POS(A,3)+Back.BLACK+" ", end="");
                    A=A+1
            else:
                break;
        lista.add(cadena)
        for i in h:
            try:
                print(Cursor.POS(11,4)+Fore.BLUE+Style.BRIGHT,end="");
                resp=int(input("¿Desea ingresar otro valor? 1.Si 2.No: "));
                if(resp<=0 or resp>=3):
                    ContadorErr3+=1;
                    marcoError();
                    B=40
                    while(B<=69):
                        print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                        B=B+1
                else:
                    break;
            except:
                ContadorErr3+=1;
                marcoError();
                B=40
                while(B<=69):
                    print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                    B=B+1
        if(resp==1):
            A=31
            B=11
            while(A<=69):
                print(Cursor.POS(A,3)+Back.BLACK+" ", end="");
                A=A+1
            while(B<=69):
                print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                B=B+1
            pass;
        elif(resp==2):
            break;
    prefijo=list(lista)
    prefijoComun=os.path.commonprefix(prefijo)
    if(prefijoComun==""):
        print(Cursor.POS(11,5)+Fore.YELLOW+Style.BRIGHT+"No hubo un prefijo común");
    else:
        print(Cursor.POS(11,5)+Fore.YELLOW+Style.BRIGHT+"El prefijo común más largo es",prefijoComun);
    input();
    os.system("cls");
    return menu(0,0,ContadorErr3,0);

def e4():#Función que divide una cadena por el largo que quiera el usuario
    os.system("cls");
    h=cycle([0]);
    ContadorErr4=0;
    marcoEjer();
    for i in h:
        lista=set();
        cadena=[];
        for i in h:
            print(Cursor.POS(11,3)+Fore.MAGENTA+Style.BRIGHT,end="");
            palabra=input("Escribe una palabra: ");
            if (palabra.isdigit()):
                ContadorErr4+=1;
                marcoError();
                A=32
                while(A<=69):
                    print(Cursor.POS(A,3)+Back.BLACK+" ", end="");
                    A=A+1
            elif(palabra==""):
                ContadorErr4+=1;
                marcoError();
            elif(palabra==" "):
                ContadorErr4+=1;
                marcoError();
            else:
                break;
        cadena.append(palabra);
        lista.add(palabra);
        for i in h:
            try:
                print(Cursor.POS(11,4)+Fore.CYAN+Style.BRIGHT,end="");
                length=int(input("Longitud en que quieres dividir la palabra: "));
                if(length<0 or length>50):
                    ContadorErr4+=1;
                    marcoError();
                    B=55
                    while(B<=69):
                        print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                        B=B+1
                else:
                    break;
            except:
                ContadorErr4+=1;
                marcoError();
                B=55
                while(B<=69):
                    print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                    B=B+1
        for j in range(0,len(palabra),length):
            if j+length in range(0,len(palabra)+1):
                cadena.append(palabra[j:j+length])
        conjunto=set(cadena)
        division=conjunto-lista
        final=list(division)
        print(Cursor.POS(11,5)+Fore.YELLOW+Style.BRIGHT, end="")
        print(final)
        for i in h:
            try:
                print(Cursor.POS(11,6)+Fore.RED+Style.BRIGHT,end="");
                resp=int(input("¿Desea ingresar otro valor? 1.Si 2.No: "));
                if(resp<=0 or resp>=3):
                    ContadorErr4+=1;
                    marcoError();
                    C=40
                    while(C<=69):
                        print(Cursor.POS(C,6)+Back.BLACK+" ", end="");
                        C=C+1
                else:
                    break;
            except:
                ContadorErr4+=1;
                marcoError();
                C=40
                while(C<=69):
                    print(Cursor.POS(C,6)+Back.BLACK+" ", end="");
                    C=C+1
        if(resp==1):
            A=32
            B=11
            C=11
            D=11
            while(D<=69):
                print(Cursor.POS(D,5)+Back.BLACK+" ", end="");
                D=D+1
            while(C<=69):
                print(Cursor.POS(C,6)+Back.BLACK+" ", end="");
                C=C+1
            while(B<=69):
                print(Cursor.POS(B,4)+Back.BLACK+" ", end="");
                B=B+1
            while(A<=69):
                print(Cursor.POS(A,3)+Back.BLACK+" ", end="");
                A=A+1
            pass;
        elif(resp==2):
            break;
    os.system("cls");
    return menu(0,0,0,ContadorErr4);

def marcoError(): #Funcion que dibuja la ventana de errores 
    A=18
    B=18
    C=30
    D=30
    while(A<=21):
        print(Cursor.POS(30,A)+Fore.WHITE+Style.BRIGHT+"║");
        A=A+1
    while(B<=21):
        print(Cursor.POS(50,B)+Fore.WHITE+Style.BRIGHT+"║");
        B=B+1
    while(C<=50):
        print(Cursor.POS(C,17)+Fore.WHITE+Style.BRIGHT+"═", end="");
        C=C+1
    while(D<=50):
        print(Cursor.POS(D,22)+Fore.WHITE+Style.BRIGHT+"═", end="");
        D=D+1
    print(Cursor.POS(30,17)+Fore.WHITE+Style.BRIGHT+"╔");
    print(Cursor.POS(30,22)+Fore.WHITE+Style.BRIGHT+"╚");
    print(Cursor.POS(50,17)+Fore.WHITE+Style.BRIGHT+"╗");
    print(Cursor.POS(50,22)+Fore.WHITE+Style.BRIGHT+"╝");
    print(Cursor.POS(36,19)+Fore.YELLOW+Back.RED+Style.BRIGHT+"No valido");
    input()
    E=18
    F=18
    G=30
    H=30
    while(E<=22):
        print(Cursor.POS(30,E)+Back.BLACK+" ");
        E=E+1
    while(F<=22):
        print(Cursor.POS(50,F)+Back.BLACK+" ");
        F=F+1
    while(G<=51):
        print(Cursor.POS(G,17)+Back.BLACK+" ", end="");
        G=G+1
    while(H<=51):
        print(Cursor.POS(H,22)+Back.BLACK+" ", end="");
        H=H+1
    print(Cursor.POS(36,19)+Back.BLACK+"         ");

def marcoEjer():#Funcion que dibuja la ventana de los ejercicios
    A=2
    B=2
    C=10
    D=10
    while(A<=27):
        print(Cursor.POS(10,A)+Fore.RED+Style.BRIGHT+"║");
        A=A+1
    while(B<=27):
        print(Cursor.POS(70,B)+Fore.RED+Style.BRIGHT+"║");
        B=B+1
    while(C<=70):
        print(Cursor.POS(C,1)+Fore.BLUE+Style.BRIGHT+"═", end="");
        C=C+1
    while(D<=70):
        print(Cursor.POS(D,28)+Fore.BLUE+Style.BRIGHT+"═", end="");
        D=D+1
    print(Cursor.POS(10,1)+Fore.RED+Style.BRIGHT+"╔");
    print(Cursor.POS(10,28)+Fore.RED+Style.BRIGHT+"╚");
    print(Cursor.POS(70,1)+Fore.RED+Style.BRIGHT+"╗");
    print(Cursor.POS(70,28)+Fore.RED+Style.BRIGHT+"╝");

def marcoMenu():#Sirve para mandar llamar otras funciones
    A=2
    B=2
    C=20
    D=20
    E=20
    while(A<=22):
        print(Cursor.POS(20,A)+Fore.CYAN+Style.BRIGHT+"║");
        A=A+1
    while(B<=22):
        print(Cursor.POS(60,B)+Fore.CYAN+Style.BRIGHT+"║");
        B=B+1
    while(C<=60):
        print(Cursor.POS(C,1)+Fore.YELLOW+Style.BRIGHT+"═", end="");
        C=C+1
    while(D<=60):
        print(Cursor.POS(D,23)+Fore.YELLOW+Style.BRIGHT+"═", end="");
        D=D+1
    while(E<=60):
        print(Cursor.POS(E,3)+Fore.YELLOW+Style.BRIGHT+"═", end="");
        E=E+1
    print(Cursor.POS(20,1)+Fore.CYAN+Style.BRIGHT+"╔");
    print(Cursor.POS(20,23)+Fore.CYAN+Style.BRIGHT+"╚");
    print(Cursor.POS(60,1)+Fore.CYAN+Style.BRIGHT+"╗");
    print(Cursor.POS(60,23)+Fore.CYAN+Style.BRIGHT+"╝");
    print(Cursor.POS(20,3)+Fore.CYAN+Style.BRIGHT+"╠");
    print(Cursor.POS(60,3)+Fore.CYAN+Style.BRIGHT+"╣");
    return;

def menu(error1, error2, error3, error4):#Funcion que permite llamar a la funcion ingresada por el usuario
    os.system("cls")
    init(autoreset=False)
    infinity=cycle([0]);
    marcoMenu()
    ErrorTotal1=0;
    ErrorTotal2=0;
    ErrorTotal3=0;
    ErrorTotal4=0;
    ErrorTotal1+=error1;
    ErrorTotal2+=error2;
    ErrorTotal3+=error3;
    ErrorTotal4+=error4;
    ErrorMenu=0;
    print(Cursor.POS(31,2)+Fore.BLUE+Style.BRIGHT+"Bienvenido al Menú");
    print(Cursor.POS(30,4)+Back.WHITE+Fore.BLACK+"Selecciona una opcion");
    print(Cursor.POS(21,6)+Fore.RED+Style.BRIGHT+"1.Para ejecutar e1()");
    print(Cursor.POS(42,6)+Fore.RED+Style.BRIGHT, end="");
    print(ErrorTotal1);
    print(Cursor.POS(21,7)+Fore.GREEN+Style.BRIGHT+"2.Para ejecutar e2()");
    print(Cursor.POS(42,7)+Fore.GREEN+Style.BRIGHT, end="");
    print(ErrorTotal2);
    print(Cursor.POS(21,8)+Fore.YELLOW+Style.BRIGHT+"3.Para ejecutar e3()");
    print(Cursor.POS(42,8)+Fore.YELLOW+Style.BRIGHT, end="");
    print(ErrorTotal3);
    print(Cursor.POS(21,9)+Fore.MAGENTA+Style.BRIGHT+"4.Para ejecutar e4()");
    print(Cursor.POS(42,9)+Fore.MAGENTA+Style.BRIGHT, end="");
    print(ErrorTotal4);
    print(Cursor.POS(21,10)+Fore.WHITE+Style.BRIGHT+"5.Para salir");
    for i in infinity:
        try:
            print(Cursor.POS(21,12)+Fore.CYAN+Style.BRIGHT, end="");
            opcion=int(input("Respuesta: "));
            if(opcion<=0 or opcion>=6):
                ErrorMenu=ErrorMenu+1;
                print(Cursor.POS(44,6)+Fore.WHITE+Style.BRIGHT+"Errores Menu", ErrorMenu);
                marcoError()
                A=32
                while(A<=59):
                    print(Cursor.POS(A,12)+Back.BLACK+" ", end="");
                    A=A+1
            else:
                break;
        except:
            ErrorMenu=ErrorMenu+1;
            print(Cursor.POS(44,6)+Fore.WHITE+Style.BRIGHT+"Errores Menu", ErrorMenu);
            marcoError()
            A=32
            while(A<=59):
                print(Cursor.POS(A,12)+Back.BLACK+" ", end="");
                A=A+1
    if(opcion==1):
        return e1();
    elif(opcion==2):
        return e2();
    elif(opcion==3):
        return e3();
    elif(opcion==4):
        return e4();
    elif(opcion==5):
        print(Cursor.POS(21,13)+Fore.YELLOW+Style.BRIGHT+"Fin del programa");
    return;
menu(0,0,0,0)
input()
