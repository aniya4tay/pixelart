#include <Wire.h>
#include <ArdusatSDK.h>
#include <SPI.h>

ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);
Display display;
int demodelay=2000;


Acceleration accel;
float gforce;

void setup(void)
{
  serialConnection.begin(9600);
  accel.begin();
  serialConnection.println("timestamp, gforce");
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void loop(void)
{
  accel.read();
  gforce = (sqrt(sq(accel.x)+sq(accel.y)+sq(accel.z))/9.8); 
  
  serialConnection.println(valueToJSON("G-Force", DATA_UNIT_METER_PER_SECONDSQUARED, gforce));
   
  if (gforce>6) { 
      display.clearDisplay();
      
      display.drawLine(15,2 , 16, 2, BLACK);
      display.drawLine(19, 2, 20, 2, BLACK);
      display.drawLine(14, 3, 14, 5, BLACK);
      display.drawLine(15,3 , 16, 3, RED);
      display.drawLine(16 ,3 , 17, 3, BLACK);
      display.drawLine(19 ,3 , 20, 3, RED);
      display.drawLine(21 ,5 , 21, 5, BLACK);
      display.drawLine(15, 4, 20, 4, RED);
      display.drawLine(15, 5, 20, 5, RED);
      display.drawLine(15,6,BLACK);
      display.drawLine(20,6,BLACK);
      display.drawLine(16, 6, 19, 6, BLACK);
      display.drawLine(16, 7, BLACK);
      display.drawLine(19, 7, BLACK);
      display.drawLine( 17, 7, 18, 7, RED);
      display.drawLine( 17, 8, 18, 8, BLACK);
      
      display.display();
        }
    else { 
     display.drawLine(15,2 , 16, 2, BLACK);
      display.drawLine(19, 2, 20, 2, BLACK);
      display.drawLine(14, 3, 14, 5, BLACK);
      display.drawLine(15,3 , 16, 3, WHITE);
      display.drawLine(16 ,3 , 17, 3, BLACK);
      display.drawLine(19 ,3 , 20, 3, WHITE);
      display.drawLine(21 ,5 , 21, 5, BLACK);
      display.drawLine(15, 4, 20, 4, WHITE);
      display.drawLine(15, 5, 20, 5, WHITE);
      display.drawLine(15,6,BLACK);
      display.drawLine(20,6,BLACK);
      display.drawLine(16, 6, 19, 6, BLACK);
      display.drawLine(16, 7, BLACK);
      display.drawLine(19, 7, BLACK);
      display.drawLine( 17, 7, 18, 7, WHITE);
      display.drawLine( 17, 8, 18, 8, BLACK);
    }
    }
