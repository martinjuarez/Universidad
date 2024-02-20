from Lista import Lista

miLista = Lista()

while True:
    print("\tMenu de opciones")
    print("1. Insertar al inicio")
    print("2. Insertar al final")
    print("3. Imprimir lista")
    print('4. Salir')
    opc = (int)(input("\nEscriba la opcion: "))

    if opc == 1:
        miLista.insertarInicio((int)(input("Escriba lo que quiere ingresar ")))
    elif opc == 2:
        miLista.insertarFinal()
    elif opc == 3:
        miLista.imprimir()
    elif opc  == 4:
        print("Adios...")
        break
