"""
El archivo no se puede llamar colorama
"""
def e1():
    from colorama import init;
    init();
    
def e2():
    from colorama import init,Back, Fore;
    init();
    print(Back.GREEN + Fore.LIGHTYELLOW_EX + "Martin CS");
    input();
    
def e3():
    from colorama import init,Back, Fore;
    init();
    print(Back.GREEN + Fore.LIGHTYELLOW_EX + "Martin CS");
    print("ESTE ES OTRO INPUT")
    input();

def e4():
    from colorama import init,Back, Fore, Style;
    init();
    print(Style.DIM + "Martin CS");
    print(Style.NORMAL + "CS");
    print(Style.BRIGHT + "Usando colorama");
    print(Style.BRIGHT + "Mezcla", Style.RESET_ALL + Fore.GREEN + "En python");
    input();

def e5():
    from colorama import init,Back, Fore;
    init(autoreset=True);
    print(Fore.WHITE + Back.BLUE + "Ya me ve--S--");
    print("Sin colorama");
    input();

def e6():
    from time import sleep;
    from colorama import Cursor, init, Fore;
    init(autoreset=True);
    print("moviendo figura a una posicion ...");
    for progress in ["*-----", "-*----", "--*---", "---*--", "----*-", "-----*"]:
        sleep(1)
        print(Cursor.POS(37,3) + Fore.LIGHTYELLOW_EX + str(progress));
    print(Cursor.POS(37,3) + Fore.LIGHTYELLOW_EX + "Ya termino ...");
    input();     
    
e6();
    
