#include <NewPing.h>

#define trigger1 12 
#define trigger2 5
#define echo1 11
#define echo2 4   
#define max_distance1 200
#define max_distance2 200


const byte numChars = 32;
char receivedChars[numChars];   
#include<SoftwareSerial.h>
SoftwareSerial HC05(0,1); 
boolean newData = false;


float temp;
NewPing sonar1(trigger1,echo1,max_distance1);
NewPing sonar2(trigger2,echo2,max_distance2);

void calculate_distances(void);
  int distance1,distance2;
  void recvWithEndMarker(void);
  void showNewData(void);
  
void calculate_distances(void){
                
  unsigned int d1=sonar1.ping();
  distance1=sonar1.convert_cm(d1);
  unsigned int d2=sonar2.ping();
  distance2=sonar2.convert_cm(d2);
 
}


void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '`';
    char rc;
    
    while (HC05.available() > 0 && newData == false) {
        rc = HC05.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; 
            ndx = 0;
            newData = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.println(receivedChars);
        newData = false;
    }
}


void setup() {
  Serial.begin(38400);
  HC05.begin(38400); 
}

void loop() {

 /*
  calculate_distances();

  Serial.print(distance1);
  Serial.print("--");
  Serial.println(distance2);
  delay(100);

 
  */
 
 if (HC05.available()){
  recvWithEndMarker();
    showNewData();
 }
else{
   calculate_distances();
   if(distance1 >=3 && distance1 <= 26){
      delay(300);
      calculate_distances();
      if(distance1>=3 && distance1 <= 26){
        delay(700);
         calculate_distances();
        if(distance1 >= 3 && distance1 <= 26){
          Serial.println("j");
          }else if (distance1 >=30 && distance1 <=45){
                     Serial.println("c");
      }
      }else{
        delay(300);
            temp=millis();
    while(millis()<=(temp+300)){
       calculate_distances();
       if(distance2 >=3 && distance2 <=22){
        Serial.println("3");
        break;
       }
    }
    }
    
   
   } else if (distance2 >=3 && distance2 <= 26){
      delay(300);
      calculate_distances();
      if(distance2 >=3 && distance2 <= 26){
        delay(700);
        calculate_distances();
            if(distance2 >= 3 && distance2 <= 26){
        Serial.println("p");
      }else if (distance2 >=30 && distance2 <= 45){
        Serial.println("l");
      }
 
   }else {
    delay(300);
        temp=millis();
    while(millis() <= (temp+300)){
      calculate_distances();
      if(distance1 >=3 && distance1 <=22){
        Serial.println("4");
        break;
      }
    }
   }
    
   }else if(distance1 >= 30 && distance1 <=40){
    delay(400);
    calculate_distances();
    if(distance1 >= 4 && distance1 <= 13   ){
      Serial.println("5");
    }
   }else if(distance2 >= 30 && distance2 <=40){
    delay(400);
    calculate_distances();
    if(distance2 >= 3 && distance2 <= 26 ){
      Serial.println("k");
    }
   }
   }
}
