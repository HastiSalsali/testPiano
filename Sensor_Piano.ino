
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
const int NUMINPUT = 100, SENSITIVITY = 10,  NUM_OF_PINS = 6;
long ZERO [NUM_OF_PINS] = {0};
int BULB_PIN [NUM_OF_PINS] = {bulb1, bulb2, bulb3, bulb4, bulb5, bulb6}, 
REC_PIN [NUM_OF_PINS]= {rec1, rec2, rec3, rec4, rec5, rec6};


void setup() {
  pinMode (rec1, INPUT);
  pinMode(bulb1, OUTPUT);
  pinMode (BULB_PIN, OUTPUT);
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
  int noteIn;
  
  for (int i = 0;   i < NUM_OF_PINS; i++) {
    noteIn = analogRead(REC_PIN[i]);
    Serial.println (noteIn); //PRINT
    noteIn > (SENSITIVITY + ZERO[i])? digitalWrite (BULB_PIN, HIGH): digitalWrite (bulb1, LOW);
  }
  noteIn = analogRead(REC_PIN[1]);
    Serial.println (noteIn); //PRINT
    noteIn > (SENSITIVITY + ZERO[1])? digitalWrite (BULB_PIN, HIGH): digitalWrite (bulb1, LOW);
    
  digitalWrite (4, HIGH);
  //constrain (noteIn, 0, 1023);
  

  
 

  delay(100);
}
