
//---------------------- VARIBABLES -------------------------------------------------------------//

//---------------------- VARIBABLES DEL MODULO DE RELAY ----------------------------------------//
//PIN DEL RELE;
int PINR1 = 2;
//--------------------------------------------------------------------------------------------//

//----------------------- VARIBABLES DEL SENSOR DE NIVEL DE AGUA ------------------------------//

// VARIABLE DE EL VALOR QUE DE SENSOR DE AGUA;
int SENSORWATER;
//PIN DEL SENSOR DE AGUA;
int  PINSENSORWATER = A0;
//--------------------------------------------------------------------------------------------//

//---------------------- VARIBABLES DEL SENSOR DE NIVEL DE DISTANCIA(ULTRASONAR) ------------//
// VARIABLE PIN TRIGER DELULTRASONAR; 
int PINTRIGER = 3;
// VARIABLE PIN ECO DELULTRASONAR;
int PINECO = 8;
int DURACION;
float DISTANCIA;
//--------------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------------//


void setup() {
  // put your setup code here, to run once:
 pinMode(PINR1, OUTPUT);
 pinMode(PINTRIGER, OUTPUT);
 pinMode(PINECO, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

      //APAGADO DE EL ULTRASONAR
   digitalWrite(PINTRIGER, LOW);
  delayMicroseconds(2);

  //ENCENDIDO DE EL ULTRASONAR
  digitalWrite(PINTRIGER, HIGH);
   delayMicroseconds(10);

       //APAGADO DE EL ULTRASONAR
   digitalWrite(PINTRIGER, LOW);

    //SACAMOS LOS DATOS DEL PIN DE SENSOR DE AGUA
   SENSORWATER = analogRead(PINSENSORWATER);

 //SACAMOS LOS DATOS DEL PIN DE EL ULTRASONAR
  DURACION = pulseIn(PINECO,HIGH);  

  //CALCULAMOS LA DISTANCIA EN CM
  DISTANCIA = ( DURACION*0.034)/2;
  
//------------------------------ CODIGO DE ENCENDIDO Y APAGADO DEL RELAY -------------------// 
   //DECICION DE EL ENCENDIDO DEL RELAY

  // if(DISTANCIA <= 13.00 )
  if(DISTANCIA >= 13.00 )
  {
    //Serial.print(DISTANCIA);
   // Serial.print("CM");
    // Serial.print("/A/");
     
      //APAGADO DEL RELAY
       digitalWrite(PINR1,HIGH);
       delay(5000);  

   
  }
  else{
    //  Serial.print(DISTANCIA);
   // Serial.print("CM");
   //  Serial.print("/E/");
    
        //NIVEL DE AGUA EN EL 35 PORCIRNTO DE AGUA PAR ENCENDER EL RELAY
    if(SENSORWATER <= 105){
                 // Serial.print("/EN/");
                  //Serial.print("//");
                //Serial.print(SENSORWATER);
                  //Serial.print("//");
                  
                  //ENCENDIDO DEL RELAY
                 digitalWrite(PINR1,LOW);
                  delay(5000); 
    }
    else{
                //Serial.print("//");
                  //Serial.print(SENSORWATER);
                 // Serial.print("//");
                 //Serial.print("/Ap/");

                 //APAGADO DEL RELAY
                   digitalWrite(PINR1,HIGH);
                   delay(5000);    
      }            
    }   
}
