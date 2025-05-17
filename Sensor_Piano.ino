
#define NOTE_A4 880
#define NOTE_B4 988
#define NOTE_C5 1046
#define NOTE_D5 1174
#define NOTE_E5 1244
#define NOTE_F5 1318
#define NOTE_G5 1397
#define NOTE_H5 1568
#define NOTE_A5 1760

#define bulb1 3
#define bulb2 4
#define bulb3 5
#define bulb4 6
#define bulb5 7
#define bulb6 8
#define rec1 A7
#define rec2 A6
#define rec3 A5
#define rec4 A4
#define rec5 A3
#define rec6 A2
const int NUMINPUT = 100, SENSITIVITY = 50,  NUM_OF_PINS = 3;
long ZERO [NUM_OF_PINS] = {0};
int BULB_PIN [6] = {bulb1, bulb2, bulb3, bulb4, bulb5, bulb6}, 
REC_PIN [6]= {rec1, rec2, rec3, rec4, rec5, rec6};


void setup() {
  for (int i = 0; i < NUM_OF_PINS; i++){
    pinMode (REC_PIN [i], INPUT);
    pinMode(BULB_PIN [i], OUTPUT);
  }
  
  Serial.begin(9600);
  delay (500);
  for (int i = 0;   i < NUM_OF_PINS; i++) {
    long inputVal = 0;
    for (int j = 0; j < NUMINPUT; j++){
        inputVal = analogRead(REC_PIN[i]);
        ZERO[i] += inputVal;
        Serial.println (inputVal); //PRINT
        //delay(10);
      }
      ZERO[i] = (ZERO[i] / NUMINPUT);
      Serial.println (ZERO[i]); //PRINT
  }
}

void loop() {
  int noteIn[NUM_OF_PINS] = {0}, max = 0, maxBulb = 0;
  String sss = "";
  bool bulbOn [NUM_OF_PINS] = {0};
 
  for (int i = 0;   i < NUM_OF_PINS; i++) {
    noteIn[i] = analogRead(REC_PIN[i]);  
    //constrain(noteIn, ZERO[i] , 1023);
    noteIn[i] -= ZERO[i];
    noteIn[i] > SENSITIVITY? digitalWrite (BULB_PIN[i], HIGH): digitalWrite (BULB_PIN[i], LOW);
    //digitalWrite (BULB_PIN[i], LOW);
    if (max < noteIn[i]) {
      max = noteIn;
      bulbOn [maxBulb] = 0;
      bulbOn [i] = 0;
      maxBulb = i;
      
      };
    
    sss = sss + String(noteIn[i]) + " ";
  }

  //noteIn[maxBulb] > SENSITIVITY? digitalWrite (BULB_PIN[maxBulb], HIGH): digitalWrite (BULB_PIN[maxBulb], LOW);
 
  Serial.println (sss);

  delay(100);
}
