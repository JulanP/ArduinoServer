/////////////////////////////////////////////////////////////////////////////
////  Returns temperature and humidity values from DHT's connect to an Arduino
// Julan Prasad
/////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////
//Character Received//

////  form : "DHT#,X"
//     # is the number of the DHT (1,2,3,4)
//      X is the command (T,H,B)
// T- Temperature
// H- Humidity
// B- Both (temperature and humidity) 


///////////////////////////////////////////////////////////////////////////////////
#include<DHT.h>

#define DHT1PIN 2    // Pin that first DHT is connected to 
#define DHT2PIN 3    // Pin that second DHT is connected to 
#define DHT3PIN 6    // Pin that third DHT is connected to 
#define DHT4PIN 5    // Pin that fourth DHT is connected to 


#define DHT1TYPE DHT22 // DHT 22  (AM2302)
#define DHT2TYPE DHT22
#define DHT3TYPE DHT22
#define DHT4TYPE DHT22

const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;

DHT dht1(DHT1PIN, DHT1TYPE); //// Initialize DHT sensor for normal 16mhz Arduino
DHT dht2(DHT2PIN, DHT2TYPE);
DHT dht3(DHT3PIN, DHT3TYPE);
DHT dht4(DHT4PIN, DHT4TYPE);

int chk;

float hum1;     //Stores humidity value for DHT1
float temp1;    //Stores temperature value for DHT1
float hum2;     //Stores humidity value for DHT2
float temp2;    //Stores temperature value for DHT1
float hum3;     //Stores humidity value for DHT3
float temp3;    /////////////////////////////////////////
//DHT3
/////////////////////////////////////////Stores temperature value for DHT1
float hum4;     //Stores humidity value for DHT4
float temp4;    //Stores temperature value for DHT1



void setup()
{
  Serial.begin(9600);
  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();

}




void carriage_return()
{
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;
  

  if (Serial.available() > 0) {

  while (Serial.available() > 0 && newData == false)
  {
    rc = Serial.read();
    if (rc != endMarker)
    {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars)
      {
        ndx = numChars -1;
      }
    }
    else 
    {
      receivedChars[ndx] = '\0';
      ndx = 0;
      newData = true;
    }
  }
    
  }
}

void senddata() {
temp1 = dht1.readTemperature();
hum1 = dht1.readHumidity();
temp2 = dht2.readTemperature();
hum2 = dht2.readHumidity();
temp3 = dht3.readTemperature();
hum3 = dht3.readHumidity();
temp4 = dht4.readTemperature();
hum4 = dht4.readHumidity();


  
  if (newData == true)
  {
  //////////////////////////
  //DHT1//////////////////
  //////////////////////////
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '1' && receivedChars[4] == ',' && receivedChars[5] == 'T' )
   {
    Serial.println(temp1);
   }
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '1' && receivedChars[4] == ',' && receivedChars[5] == 'H' )
   {
    Serial.println(hum1);
   }
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '1' && receivedChars[4] == ',' && receivedChars[5] == 'B')
    Serial.print(temp1);
    Serial.print(",");
    Serial.println(hum1);
   }
   ////////////////////////////////////////
//DHT2
////////////////////////////////////////
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '2' && receivedChars[4] == ',' && receivedChars[5] == 'T' )
   {
    Serial.println(temp2);
   }
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '2' && receivedChars[4] == ',' && receivedChars[5] == 'H' )
   {
    Serial.println(hum2);
   }
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '2' && receivedChars[4] == ',' && receivedChars[5] == 'B')
   {
    Serial.print(temp2);
    Serial.print(",");
    Serial.println(hum2);
   }
   ////////////////////////////////////////
//DHT3
////////////////////////////////////////
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '3' && receivedChars[4] == ',' && receivedChars[5] == 'T' )
   {
    Serial.println(temp3);
   }
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '3' && receivedChars[4] == ',' && receivedChars[5] == 'H' )
   {
    Serial.println(hum3);
   }
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '3' && receivedChars[4] == ',' && receivedChars[5] == 'B')
   {
    Serial.print(temp3);
    Serial.print(",");
    Serial.println(hum3);
   }
////////////////////////////////////////
//DHT4
////////////////////////////////////////
   
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '4' && receivedChars[4] == ',' && receivedChars[5] == 'T' )
   {
    Serial.println(temp1);
   }
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '4' && receivedChars[4] == ',' && receivedChars[5] == 'H' )
   {
    Serial.println(hum1);
   }
   if(receivedChars[0] == 'D' && receivedChars[1] == 'H' && receivedChars[2] == 'T' && receivedChars[3] == '4' && receivedChars[4] == ',' && receivedChars[5] == 'B')
   {
    Serial.print(temp1);
    Serial.print(",");
    Serial.println(hum1);
   }
      newData = false;
    
  }
  
  


void loop()
{
  carriage_return();
  senddata();
}
