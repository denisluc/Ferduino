// _240x320_Portrait (C)2011 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of the loadBitmap()-function.
//
// This program requires the ITDB02_Graph v4.1 or higher, 
// as well as the tinyFAT library.
//
// It is assumed that the ITDB02 module is connected to a
// ITDB02 Shield, a ITDB02 Mega Shield or that you know 
// how to change the pin numbers in the setup.
//
// This demo requires the ITDB02-2.4(D) (240x320) module.
//
// The files PIC101.RAW to PIC110.RAW must be present in
// on the root folder of a FAT16 formatted SDcard in the
// module cardslot.
//

#include <tinyFAT.h>
#include <ITDB02_Graph.h>
#include <ITDB02_tinyFAT.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];

// Uncomment the next line for the ITDB02 Shield
ITDB02tf myGLCD(19,18,17,16);   // Remember to add ITDB24D if you are using an ITDB02-2.4D!

// Uncomment the next line for the ITDB02 Mega Shield
// ITDB02tf myGLCD(38,39,40,41);   // Remember to add ITDB24D if you are using an ITDB02-2.4D!

// List of filenames for pictures to display
char* files[]={"PIC101.RAW", "PIC102.RAW", "PIC103.RAW", "PIC104.RAW", "PIC105.RAW", "PIC106.RAW", "PIC107.RAW", "PIC108.RAW", "PIC109.RAW", "PIC110.RAW"}; // 240x320

int displaysize_x=240;
int displaysize_y=320;
int pixsize_x=240;
int picsize_y=320;
boolean display_rendertime=false;  // Set this to true if you want the rendertime to be displayed after a picture is loaded
boolean display_filename=true;  // Set this to false to disable showing of filename

word res;
long sm, em;

void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
  file.initFAT();
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(SmallFont);
}

void loop()
{
  
  for (int i=0; i<(sizeof(files)/sizeof(*files)); i++)
  {
    sm=millis();
    res=myGLCD.loadBitmap((displaysize_x/2)-(pixsize_x/2), (displaysize_y/2)-(picsize_y/2), pixsize_x, picsize_y, files[i]);
    em=millis();
    if (res!=0)
    {
      if (res==0x10)
      {
        myGLCD.print("File not found...", 0, 0);
        myGLCD.print(files[i], 0, 14);
      }
      else
      {
        myGLCD.print("ERROR: ", 0, 0);
        myGLCD.printNumI(res, 56, 0);
      }
      delay(3000);
      myGLCD.clrScr();
    }
    else
    {
      if (display_rendertime==true)
      {
        myGLCD.print("Rendertime (secs):", 0, 0);
        myGLCD.printNumF(float((em-sm)/1000.0), 2, 160,0);
      }
      if (display_filename==true)
      {
        myGLCD.print(files[i], CENTER, displaysize_y-12);
      }
      delay(3000);
    }
  }
}

