#include<VirtualWire.h>
#include<SoftwareSerial.h>
#include<SPI.h>
#include<math.h>

SoftwareSerial bt(2,3); 
unsigned char ch;
unsigned char str[100];

void setup() {
Serial.begin(9600);
bt.begin(9600); 
vw_set_ptt_inverted(true); //
vw_set_tx_pin(8);
vw_setup(2200);  // speed of data transfer Kbps

}
int f1=0,p=0,i1,j1;
void send_func(unsigned char str[],int i){
    
     for(p=0;p<i;p++){
      //if(str[p]!='.'){
     if(p%2==0){
        str[p]= str[p]+(unsigned char)1;
      }
      else{
        str[p]= str[p]-(unsigned char)1;
      }
            Serial.write(str[p]);
            //x=str[p];
           //Serial.print(x);
     }

 
vw_send((uint8_t *)str, strlen(str));
vw_wait_tx(); // Wait until the whole message is gone

delay(2000);
f1=1;
}

void loop(){

if(bt.available()){
      ch = bt.read();
      
       str[i1] = ch;
      i1++;
      f1=0;
    }
    else{
        if(f1==0 && str[i1-1]=='.')
        {
           send_func(str,i1);
           i1=0;
        }
    }
  
}
