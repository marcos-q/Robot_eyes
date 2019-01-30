// By Marcos Quilez, based on a project by Steve Quinn https://www.instructables.com/id/Animated-Halloween-Evil-Eyes/
//
// 29/01/2019 
//
// https://github.com/marcos-q/Robot_eyes
// https://twitter.com/marcos_quilez  
//
// MAX7219 Control. Assumes two 8x8 LED Matrices
//
// http://playground.arduino.cc/Main/LedControl 
//
// D10 = Digital O/P CS Pin
// D11 = Digital O/P Clock Pin
// D12 = Digital O/P Data Pin
//



#include <avr/pgmspace.h>
#include <LedControl.h>

const int numDevices = 2;      // number of MAX7219s used
const int dataPin = 12;
const int clkPin = 11;
const int csPin = 10;
LedControl lc=LedControl(dataPin,clkPin,csPin,numDevices);


// Drop this code into Arduino development environment    
    
#define LeftEye1 0    
#define RightEye1 1   
#define LeftEye2 2    
#define RightEye2 3   
#define LeftEye3 4    
#define RightEye3 5   
#define LeftEye4 6    
#define RightEye4 7   
#define LeftEye5 8    
#define RightEye5 9   
#define LeftEye6 10   
#define RightEye6 11    
#define LeftEye7 12   
#define RightEye7 13    
#define LeftEye8 14   
#define RightEye8 15    
#define LeftEye9 16   
#define RightEye9 17    
#define LeftEye10 18    
#define RightEye10 19   
#define LeftEye11 20    
#define RightEye11 21   
#define LeftEye12 22    
#define RightEye12 23   
#define LeftEye13 24    
#define RightEye13 25   
#define LeftEye14 26    
#define RightEye14 27   
#define LeftEye15 28    
#define RightEye15 29   
#define LeftEye16 30    
#define RightEye16 31   
#define LeftEye17 32    
#define RightEye17 33   
#define LeftEye18 34    
#define RightEye18 35   
#define LeftEye19 36    
#define RightEye19 37   
#define LeftEye20 38    
#define RightEye20 39   
#define LeftEye21 40    
#define RightEye21 41   
#define LeftEye22 42    
#define RightEye22 43   
#define LeftEye23 44    
#define RightEye23 45   
#define LeftEye24 46    
#define RightEye24 47   
#define LeftEye25 48    
#define RightEye25 49   
#define LeftEye26 50    
#define RightEye26 51   
#define LeftEye27 52    
#define RightEye27 53   
#define LeftEye28 54    
#define RightEye28 55   
#define LeftEye29 56    
#define RightEye29 57   
#define LeftEye30 58    
#define RightEye30 59   
#define LeftEye31 60    
#define RightEye31 61   
#define LeftEye32 62    
#define RightEye32 63   
    
typedef struct {    
  prog_uchar array1[8]; 
} binaryArrayType;    
    
binaryArrayType binaryArray[64] =   
{   
  { // LeftEye1, 0  
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye1, 1 
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye2, 2  
    B00000000,
    B00111100,
    B01000010,
    B01011010,
    B01011010,
    B01000010,
    B00111100,
    B00000000
  },  
  { // RightEye2, 3 
    B00000000,
    B00111100,
    B01000010,
    B01011010,
    B01011010,
    B01000010,
    B00111100,
    B00000000
  },  
  { // LeftEye3, 4  
    B00000000,
    B00111100,
    B00100100,
    B00110100,
    B00110100,
    B00100100,
    B00111100,
    B00000000
  },  
  { // RightEye3, 5 
    B00000000,
    B00111100,
    B00100100,
    B00110100,
    B00110100,
    B00100100,
    B00111100,
    B00000000
  },  
  { // LeftEye4, 6  
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00000000
  },  
  { // RightEye4, 7 
    B00000000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000
  },  
  { // LeftEye5, 8  
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000010,
    B01111100
  },  
  { // RightEye5, 9 
    B01111100,
    B10000010,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye6, 10 
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000010,
    B10000100,
    B01111000
  },  
  { // RightEye6, 11  
    B01111000,
    B10000100,
    B10000010,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye7, 12 
    B01111110,
    B11000001,
    B10000001,
    B10011001,
    B10011010,
    B10000100,
    B10001000,
    B01110000
  },  
  { // RightEye7, 13  
    B01110000,
    B10001000,
    B10000100,
    B10011010,
    B10011001,
    B10000001,
    B11000001,
    B01111110
  },  
  { // LeftEye8, 14 
    B00111110,
    B01000001,
    B10000001,
    B10011001,
    B10011010,
    B10000100,
    B01001000,
    B00110000
  },  
  { // RightEye8, 15  
    B00110000,
    B01001000,
    B10000100,
    B10011010,
    B10011001,
    B10000001,
    B01000001,
    B00111110
  },  
  { // LeftEye9, 16 
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye9, 17  
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye10, 18  
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B01111110
  },  
  { // RightEye10, 19 
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B01111110
  },  
  { // LeftEye11, 20  
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B01111110
  },  
  { // RightEye11, 21 
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B01111110
  },  
  { // LeftEye12, 22  
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10011001,
    B01111110
  },  
  { // RightEye12, 23 
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10011001,
    B01111110
  },  
  { // LeftEye13, 24  
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye13, 25 
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye14, 26  
    B01111110,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye14, 27 
    B01111110,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye15, 28  
    B01111110,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye15, 29 
    B01111110,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye16, 30  
    B01111110,
    B10011001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye16, 31 
    B01111110,
    B10011001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye17, 32  
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10001101,
    B01111110
  },  
  { // RightEye17, 33 
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10001101,
    B01111110
  },  
  { // LeftEye18, 34  
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000111,
    B01111110
  },  
  { // RightEye18, 35 
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000111,
    B01111110
  },  
  { // LeftEye19, 36  
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000011,
    B10000011,
    B01111110
  },  
  { // RightEye19, 37 
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000011,
    B10000011,
    B01111110
  },  
  { // LeftEye20, 38  
    B01111110,
    B10000001,
    B10000001,
    B10000011,
    B10000011,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye20, 39 
    B01111110,
    B10000001,
    B10000001,
    B10000011,
    B10000011,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye21, 40  
    B01111110,
    B10000001,
    B10000011,
    B10000011,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye21, 41 
    B01111110,
    B10000001,
    B10000011,
    B10000011,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye22, 42  
    B01111110,
    B10000011,
    B10000011,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye22, 43 
    B01111110,
    B10000011,
    B10000011,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye23, 44  
    B01111110,
    B10000111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye23, 45 
    B01111110,
    B10000111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye24, 46  
    B01111110,
    B10001101,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye24, 47 
    B01111110,
    B10001101,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye25, 48  
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye25, 49 
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // LeftEye26, 50  
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye26, 51 
    B00000000,
    B00111100,
    B01000010,
    B01011010,
    B01011010,
    B01000010,
    B00111100,
    B00000000
  },  
  { // LeftEye27, 52  
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye27, 53 
    B00000000,
    B00111100,
    B00100100,
    B00110100,
    B00110100,
    B00100100,
    B00111100,
    B00000000
  },  
  { // LeftEye28, 54  
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye28, 55 
    B00000000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000
  },  
  { // LeftEye29, 56  
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00000000
  },  
  { // RightEye29, 57 
    B00000000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000
  },  
  { // LeftEye30, 58  
    B01110000,
    B10001000,
    B10000100,
    B10110010,
    B10110010,
    B10000010,
    B10000010,
    B01111100
  },  
  { // RightEye30, 59 
    B01111100,
    B10000010,
    B10000010,
    B10110010,
    B10110010,
    B10000100,
    B10001000,
    B01110000
  },  
  { // LeftEye31, 60  
    B00111110,
    B01000001,
    B10000001,
    B10011001,
    B10010010,
    B10000100,
    B01001000,
    B00110000
  },  
  { // RightEye31, 61 
    B00110000,
    B01001000,
    B10000100,
    B10010010,
    B10011001,
    B10000001,
    B01000001,
    B00111110
  },  
  { // LeftEye32, 62  
    B01111110,
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10000001,
    B10000001,
    B01111110
  },  
  { // RightEye32, 63 
    B00000000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000
  } 
};    
   
	

typedef struct {			
	int frameCount;		// index pointer into binaryArray signifying animation frame
	int frameDelay;	        // Approx delay in MilliSeconds to hold display this animated frame
  int frameLuminance;	// 0 ... 15, The intensity of the led matrix for a given frame
} frameType;			
			

void delayMillis(int milliseconds)
{
   for(int i=0; i < milliseconds; i++)
     delayMicroseconds(1000);
}

void setup(){
   for (int x=0; x<numDevices; x++){
        lc.shutdown(x,false);       //The MAX72XX is in power-saving mode on startup
        lc.setIntensity(x,1);       // Set the brightness to default value
        lc.clearDisplay(x);         // and clear the display
    }

    lc.setIntensity(0,3);       
    lc.setIntensity(1,3);    
}

/////////////////////////////////////////////
////////////       Main loop
////////////
/////////////////////////////////////////////

void loop(){ 

     // secuencia fija para mostrar los movimientos oculares programados
     stare();
     blinkEyes();
     dobleBlink();
     stare();
     right(); rightToCenter();
     left(); leftToCenter();
     stare();
     
     left();
     circle(); rightToCenter();delay(700);
     
     sad();
     stare();
     frown();
     wink();
     stare();
     mmm();delay(1000);
     mmmToCenter();

     while(true){             
                        // este bucle se repite indefinidamente y realiza movimientos oculares al azar. 
                        //Cada movimiento tiene definida una probabilidad de aparición
      int number=random(100);
      if (number<40){
        stare();
      }else if(number<55){
        blinkEyes();
      }else if (number<60){
        frown();
      }else if (number<70){
        dobleBlink();
      }else if(number<75){
        right();
        rightToCenter();
      }else if (number< 80){
        left();
        leftToCenter();
      }else if (number <85){
        right(); rightToCenter();
        left(); leftToCenter();
        stare();
        left();
        circle(); rightToCenter();delay(700);
      }else if (number<90){
        sad();
        delay(1000);
        stare();
      }else if (number<95){
        wink();
      }else if(number<100){
        mmm();
        mmmToCenter();
        delay(1000);
      }
     }
     delay(1000);
}



///////////////////////////////////////////////////
//////////
//////////    Functions
//////////
///////////////////////////////////////////////////

void stare(){
   frameType movie[] = 
    {
      {LeftEye1,1000,1}
    };

    for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
}

void sad(){
  frameType movie[] = 
    {
      {LeftEye30,1000,1}
    };    
  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
}


void blinkEyes(){
  frameType movie[] = 
    {
      {LeftEye1,1000,1}, {LeftEye2,5,1}, {LeftEye3,10,1}, {LeftEye4,10,1},   {LeftEye29,100,1}, {LeftEye4,10,1}, {LeftEye3,10,1}, {LeftEye2,5,1}, {LeftEye1,1000,1}
    };
  
  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
}


void dobleBlink(){
   frameType movie[] = 
    {
      {LeftEye1,1000,1}, {LeftEye2,5,1}, {LeftEye3,10,1}, {LeftEye4,10,1},   {LeftEye29,100,1}, {LeftEye4,10,1}, {LeftEye3,10,1}, {LeftEye2,5,1},
      {LeftEye1,200,1}, {LeftEye2,5,1}, {LeftEye3,10,1}, {LeftEye4,10,1},   {LeftEye29,100,1}, {LeftEye4,10,1}, {LeftEye3,10,1}, {LeftEye2,5,1},
    };
  
  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
}


void wink(){
  frameType movie[] = 
    {
      {LeftEye25,1000,1}, {LeftEye26,5,1}, {LeftEye27,10,1}, {LeftEye28,10,1},   {LeftEye32,250,1}, {LeftEye28,10,1}, {LeftEye27,10,1}, {LeftEye26,5,1}, {LeftEye25,1000,1}
    };
  
  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
}


void left(){
  frameType movie[] = 
    {
      {LeftEye9,5,1}, {LeftEye10,15,1}, {LeftEye11,15,1}, {LeftEye12,3000,1}
    };

  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
 }


void leftToCenter(){
  frameType movie[] = 
    {
      {LeftEye12,5,1}, {LeftEye11,15,1}, {LeftEye10,15,1}, {LeftEye9,5,1}
    };
  
  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
 } 


void right(){
  frameType movie[] = 
    {
      {LeftEye13,5,1}, {LeftEye14,15,1}, {LeftEye15,15,1}, {LeftEye16,3000,1},
    };
  
  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
 } 


void rightToCenter(){
  frameType movie[] = 
    {
      {LeftEye16,5,1}, {LeftEye15,15,1}, {LeftEye14,15,1}, {LeftEye13,5,1},
    };
  
  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
 } 


void circle(){
  frameType movie[] = 
    {
     {LeftEye17,30,1}, {LeftEye18,30,1}, {LeftEye19,50,1}, {LeftEye20,70,1}, {LeftEye21,50,1}, {LeftEye22,50,1}, {LeftEye23,20,1}, {LeftEye24,20,1}, 
    };
  
  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
}


void frown(){
  frameType movie[] = 
    {
        {LeftEye5,5,1},    {LeftEye6,5,5}, {LeftEye7,5,5},  {LeftEye8,1000,5}, {LeftEye31,2000,12},{LeftEye8,5,5}, {LeftEye7,5,5},    {LeftEye6,5,5},   {LeftEye5,5,1}
    };
  
  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
}


void mmm(){
  frameType movie[] = 
    {
      {LeftEye9,5,1}, {LeftEye10,15,1}, {LeftEye11,15,1}, {LeftEye12,15,1},{LeftEye17,2000,1}
    };
  
  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
 }


void mmmToCenter(){
  frameType movie[] = 
    {
      {LeftEye12,15,1}, {LeftEye11,15,1}, {LeftEye10,15,1}, {LeftEye9,5,1}
    };

  for (int a = 0; a < (sizeof(movie)/sizeof(frameType)); a++)
     {
       for (int i = 0; i < 8; i++)
       {
         lc.setRow(0,i, binaryArray[movie[a].frameCount].array1[i]); 
         lc.setRow(1,i, binaryArray[movie[a].frameCount+1].array1[i]); 
         lc.setIntensity(0,movie[a].frameLuminance);       
         lc.setIntensity(1,movie[a].frameLuminance);       
       }          
       delayMillis(movie[a].frameDelay);
     } 
 }
