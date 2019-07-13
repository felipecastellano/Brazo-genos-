#include <Servo.h>
#define motorBase 12 //Declaro pin de la base
#define motorDerecha 11 //Declaro pin del motor derecho
#define motorIzquierda 10 //Declaro pin del motor izquierdo
#define motorMano 9 //Declaro motor de la mano


Servo Base; // Declaro el servomotor de la base 
Servo Derecha; //Declaro el servomotor de la derecha
Servo Izquierda; //Declaro el servomotor de la izquierda
Servo Mano; //Declaro el servomotor de la mano

int i = 90, j = 0, anguloIngresado;

char angulo[5]; 

/*
 * Función para retornar el ángulo y dado por el usuario.
 */

int retornarNumero(char angulo[])
{
  int caracter;
  int potencia = 1, z = 4;
  
  while(z > 0)
  {
    caracter += (int(angulo[z]))*potencia;

    if(potencia != 100)
    {
      potencia = potencia *10;
    }
    z--;  
  }

  return caracter;
}

void setup() {  
  
  Serial.begin(9600);
  Base.attach(motorBase); //Inicializamos el servo de la base
  Derecha.attach(motorDerecha); //Inicializamos el servo de la derecha
  Izquierda.attach(motorIzquierda); //Inicializamos el servo de la izquierda
  Mano.attach(motorMano); //Inicializamos el servo de la mano

} 

void loop() {

    while(Serial.available() >0) //Determina si hay informacion
    {
       angulo[j] = Serial.read(); //Lee la informacion
       Serial.println(angulo[j]);
    }

    switch(angulo[0])
    {
  
      case 'B': //Movimiento del servo de la base.
       
      Serial.println("Ha pulsado el ángulo de la base.");

      anguloIngresado = retornarNumero(angulo); 
      printf(anguloIngresado);
      

      while (i != anguloIngresado)
      {
        Base.write(i);
        delay(20);
        i++;
      }
   
      break;
  
      case 'D': //Movimiento del servo derecho.
      
      Serial.println("Ha pulsado el ángulo del brazo derecho.");

       anguloIngresado = retornarNumero(angulo);
      printf(anguloIngresado);

      while (i != 110)
      {
        Derecha.write(i);
        delay(20);
        i++;
      }
       
      break;
  
      case 'I': //Movimiento del servo izquierdo.
      
      Serial.println("Ha pulsado el ángulo del brazo izquierdo.");
  
      anguloIngresado = retornarNumero(angulo);
      printf(anguloIngresado);

      while (i != 90)
      {
        Izquierda.write(i);
        delay(20);
        i++;
      }
      
      break;
  
      case 'M': //Movimiento del servo de la mano.
      
      Serial.println("Ha pulsado el ángulo de la mano");
      
      anguloIngresado = retornarNumero(angulo);
      printf(anguloIngresado);

      while (i != retornarNumero)
      {
        Mano.write(i);
        delay(20);
        i++;
      }
      
      break;  /*listo*/
      
    }

}
