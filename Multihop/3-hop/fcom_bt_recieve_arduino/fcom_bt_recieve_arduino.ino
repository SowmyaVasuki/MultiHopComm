#include<SoftwareSerial.h>
#include <SPI.h>
#include "mcp_can.h"

SoftwareSerial bt(2,3);  
const int SPI_CS_PIN = 9;
MCP_CAN CAN(SPI_CS_PIN);  
//sck=13  si=11 so=12 

void setup() {
  bt.begin(9600); 
  Serial.begin(9600); 
  while (CAN_OK != CAN.begin(CAN_500KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        delay(100);
    }
   Serial.println("CAN BUS Shield init ok!");
}
int i=0;
int j=0;

void loop() 
{

    if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
      //Serial.println("available");
      unsigned char len;
unsigned char buf[5000];

unsigned char ch;
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf        
      for(i=0;i<len;i++){
        
          Serial.write(buf[i]);
          //ch = buf[i];
         // bt.write(buf[i]);
           
        }
       //bt.write(10);
        //bt.write(13);
        for(j=0;j<len;j++)
        {
           buf[j]='\0';
        }
       
      }
      
}


