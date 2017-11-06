import processing.serial.*;
import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.KeyEvent;

Serial myPort;
Robot robot;
int[] sensor = {0, 0, 0, 0};


void setup() {
  
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[1], 9600);
  myPort.bufferUntil ('\n');
  try {
    robot = new Robot(); 
  }
  catch (AWTException e) {
    e.printStackTrace();
    exit();
  }
}

void draw() {
  if (sensor[0] == 0) {  
    robot.keyPress(KeyEvent.VK_A);
    robot.delay(100);
    robot.keyRelease(KeyEvent.VK_A);
  }
  if (sensor[1] == 0 ){
     robot.keyPress(KeyEvent.VK_B);
     robot.delay(100);
     robot.keyRelease(KeyEvent.VK_B);
  }
  if (sensor[2] == 0) {  
    robot.keyPress(KeyEvent.VK_C);
    robot.delay(100);
    robot.keyRelease(KeyEvent.VK_C);
  }
  if (sensor[3] == 0 ){
     robot.keyPress(KeyEvent.VK_D);
     robot.delay(100);
     robot.keyRelease(KeyEvent.VK_D);
  }
}

void serialEvent(Serial myPort) {
  String inString = myPort.readStringUntil('\n');
  inString = trim(inString);
  if (inString != null) {
    String[] parsedSerial = split(inString, ',');
    for (int x = 0; x < 4; x=x+1) {
      sensor[x] = parseInt(parsedSerial[x]);
    }
  }
}