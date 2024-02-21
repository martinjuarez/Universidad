#include <Keypad.h>  // importa libreria Keypad

int LEDrojo = 13; // define LEDrojo como el pin 13
int LEDverde = 12; // define LEDverde como el pin 12
int buzzer = 11; // define buzzer como el pin 11

const byte FILAS = 4; // define numero de filas
const byte COLUMNAS = 4; // define numero de columnas
char keys[FILAS][COLUMNAS] = { // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FILAS] = {9,8,7,6}; // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {5,4,3,2}; // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto

char TECLA;       // almacena la tecla presionada
char CLAVE[7];        // almacena en un array 6 digitos ingresados
char CLAVE_MAESTRA[7] = "123456";   // almacena en un array la contraseña maestra
byte INDICE = 0;    // indice del array

  
void setup()
{
 Serial.begin(9600);      // inicializa comunicacion serie   
 pinMode(LEDrojo, OUTPUT); // pin 13 como salida
 pinMode(LEDverde, OUTPUT); // pin 12 como salida
 pinMode(buzzer, OUTPUT); // pin 11 como salida
}

void loop(){
  TECLA = teclado.getKey(); // obtiene tecla presionada y asigna a variable
  if (TECLA)       // comprueba que se haya presionado una tecla
  {
    CLAVE[INDICE] = TECLA; // almacena en array la tecla presionada
    INDICE++; // incrementa indice en uno
    Serial.print(TECLA);    // envia a monitor serial la tecla presionada
    tone(buzzer,350);     // tono de pulsacion
    delay(200); // espera de 200 milisegundos
    noTone(buzzer);   // deteiene el buzzer
  }
  if(INDICE == 6)   
  {
    if(!strcmp(CLAVE, CLAVE_MAESTRA)){
      Serial.println(" Correcta");  // imprime en monitor serial que es correcta la clave
      digitalWrite(LEDverde, HIGH); // enciende el led verde
      tone(buzzer,500); // tono de entrada correcta
      delay(5000); // espera de 5000 milisegundos(5s)
      digitalWrite(LEDverde, LOW); // apaga el led verde
      noTone(buzzer); // detiene el tono del buzzer
    }else{
      Serial.println(" Incorrecta");  // imprime en monitor serial que es incorrecta la clave
      digitalWrite(LEDrojo, HIGH); // enciende el led rojo
      tone(buzzer,70); // tono de entrada incorrecta
      delay(5000);  // espera de 5000 milisegundos(5s)
      digitalWrite(LEDrojo, LOW); //apaga el led rojo
      noTone(buzzer);    // detiene el tono del buzzer
    }
    INDICE = 0; // reinicia la posicion del indice
  }
}
