int yellowButton = 8 ;
int blueButton = 9 ;
int greenButton = 11 ;
int redButton = 10 ;

int yellowRead ;
int yellowState ;
int yellowLast = HIGH ;
int yellowValue = 1 ;
int blueRead ;
int blueState ;
int blueLast = HIGH ;
int blueValue = 1 ;
int greenRead ;
int greenState ;
int greenLast = HIGH ;
int greenValue = 1 ;
int redRead ;
int redState ;
int redLast = HIGH ;
int redValue = 1 ;

long lastYellowTime = 0 ;
long lastBlueTime = 0 ;
long lastGreenTime = 0 ;
long lastRedTime = 0 ;
long debounceDelay = 50 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600) ;
  pinMode(yellowButton, INPUT_PULLUP) ;
  pinMode(blueButton, INPUT_PULLUP) ;
  pinMode(greenButton, INPUT_PULLUP) ;
  pinMode(redButton, INPUT_PULLUP) ;
}

void loop() {
  // reading in digital values for stroke sensors
  yellowRead = digitalRead(yellowButton) ;
  blueRead = digitalRead(blueButton) ;
  greenRead = digitalRead(greenButton) ;
  redRead = digitalRead(redButton) ;

  //Debouncing stroke sensors
  //Changing values to be sent
  if (yellowRead != yellowLast) {
    if ((millis() - lastYellowTime) > debounceDelay) {
      if (yellowRead != yellowState) {
        yellowState = yellowRead ;
      }
      yellowValue = 0 ;
      lastYellowTime = millis() ;
    }
  } else {
    yellowValue = 1 ;
  }

  if (blueRead != blueLast) {
    if ((millis() - lastBlueTime) > debounceDelay) {
      if (blueRead != blueState) {
        blueState = blueRead ;
      }
      blueValue = 0 ;
      lastBlueTime = millis() ;
    }
  } else {
    blueValue = 1 ;
  }

  if (greenRead != greenLast) {
    if ((millis() - lastGreenTime) > debounceDelay) {
      if (greenRead != greenState) {
        greenState = greenRead ;
      }
      greenValue = 0 ;
      lastGreenTime = millis() ;
    }
  } else {
    greenValue = 1 ;
  }

  if (redRead != redLast) {
    if ((millis() - lastRedTime) > debounceDelay) {
      if (redRead != redState) {
        redState = redRead ;
      }
      redValue = 0 ;
      lastRedTime = millis() ;
    }
  } else {
    redValue = 1 ;
  }

  //Sending values through serial
  Serial.print(yellowValue) ;
  Serial.print(",") ;
  Serial.print(blueValue) ;
  Serial.print(",") ;
  Serial.print(greenValue) ;
  Serial.print(",") ;
  Serial.println(redValue) ;

  //Changing last read to the previous read for debouncing
  yellowLast = yellowRead ;
  blueLast = blueRead ;
  greenLast = greenRead ;
  redLast = redRead ;
}
