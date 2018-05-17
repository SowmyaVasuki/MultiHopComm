#include<VirtualWire.h>
#include <mcp_can.h>
#include<SPI.h>

const int SPI_CS_PIN = 9;
MCP_CAN CAN(SPI_CS_PIN);
unsigned char str[1000];
unsigned char ch;
int i=0,j;
int f1=0;
int p;
int x1=0;
unsigned int x;
int num2=0;

void setup()
{
Serial.begin(9600);
vw_set_ptt_inverted(true); // Required for DR3100
vw_set_rx_pin(8);
vw_setup(2200); // Bits per sec

vw_rx_start(); // Start the receiver PLL running

while (CAN_OK != CAN.begin(CAN_500KBPS))
    { 
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");

}


void loop()
{
  
 // vw_rx_start();
unsigned char buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    for(i=0;i<buflen;i++){
      Serial.write(buf[i]);
      if(buf[i]=='/' || buf[i]=='-'){
        break;
      }
      else{
        x1++;
      }
    }
    //Serial.print('heyy');
    buflen = x1;
    CAN.sendMsgBuf(0x30,0,buflen ,buf);
    
    delay(2000);
     x1=0;
  }
  //vw_rx_stop();
}
