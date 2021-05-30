
//---------------------- VARIBABLES -------------------//

//---------------------- VARIBABLES DEL SENSOR DE NIVEL DE AGUA -------------------//
// VARIABLE DE EL VALOR QUE DE SENSOR DE AGUA;
int SENSORWATER;
//PIN DEL SENSOR DE AGUA;
int  PINSENSORWATER = A0;
//PIN DEL LED;
int PINLED = 6;
int PINMOTOR = 2;
//----------------------------------------------------//

//---------------------- VARIBABLES DEL SENSOR DE NIVEL DE DISTANCIA(ULTRASONAR) -------------------//
// VARIABLE PIN TRIGER DELULTRASONAR; 
int PINTRIGER = 3;
// VARIABLE PIN ECO DELULTRASONAR;
int PINECO = 8;
int DURACION;
float DISTANCIA;

//----------------------------------------------------//

//----------------------------------------------------//

void setup() 
{
 pinMode(PINTRIGER, OUTPUT);
 pinMode(PINECO, INPUT);
 pinMode(PINLED, OUTPUT);
 pinMode(PINMOTOR, OUTPUT);
 Serial.begin(9600);
}
void loop() {
  
  //APAGADO DE EL ULTRASONAR
   digitalWrite(PINTRIGER, LOW);
  delayMicroseconds(2);

  //ENCENDIDO DE EL ULTRASONAR
  digitalWrite(PINTRIGER, HIGH);
   delayMicroseconds(10);
   digitalWrite(PINTRIGER, LOW);

  //SACAMOS LOS DATOS DEL PIN DE SENSOR DE AGUA
   SENSORWATER = analogRead(PINSENSORWATER); 

  //SACAMOS LOS DATOS DEL PIN DE EL ULTRASONAR
  DURACION = pulseIn(PINECO,HIGH);  

  //COMVERIMOS LOS DATOS RESIVIDOS EN DISTANCIA(CM)
  DISTANCIA = ( DURACION*0.034)/2;
   //DISTANCIA = DURACION / 58.2;

   //IMPRIMIMOS LOS DATOS EN LA CONSOLA
  Serial.print("//");
 Serial.print(SENSORWATER);
  Serial.print("//");
  Serial.print(DISTANCIA);
 Serial.print("CM");
  if(DISTANCIA >= 13.00 )
  {
                    Serial.print("A");
                  digitalWrite(PINMOTOR,LOW);
                 // digitalWrite(PINLED,HIGH);
                delay(5000);             
 } 
  else{
    Serial.print("E");
//if para encender el motor electrico cuando el agua este 35% de su capasidad
 if(SENSORWATER <= 350  )
  {
                  Serial.print("EN");
                  digitalWrite(PINMOTOR,LOW);
                delay(5000); 
                  digitalWrite(PINMOTOR,HIGH);
                delay(3000); 
               
               //Esperamos 1 segundos para mantener ensedido la bomba
             
 } 
  else{
     Serial.print("AP");
   //  Serial.print("//A");
       
        digitalWrite(PINMOTOR,LOW);
         delay(5000); 
     }    
     } 
      
}
