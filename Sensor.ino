const int HIT_THRESHOLD = 150;
const int TARGET_TIMEOUT = 1000;
const int TARGET_ACTIVATION_CHANCE = 100;
const int HIT_SENSOR = A0;
const int LED_PIN_0 = 3;
const int LED_PIN_1 = 5;
const int LED_PIN_2 = 6;

unsigned long startTime;
unsigned long elapsedTime;

int sensorReading;
int lastActiveTimestamp = -1;
int startflag;

void turnLedsOn() {
  digitalWrite(LED_PIN_0, HIGH);
  digitalWrite(LED_PIN_1, HIGH);
  digitalWrite(LED_PIN_2, HIGH);
}

void turnLedsOff() {
  digitalWrite(LED_PIN_0, LOW);
  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_2, LOW);
}

void setup() {
  pinMode(LED_PIN_0, OUTPUT);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //delay before start
  delay(random(5000,9000));
  turnLedsOn();
  startflag = 1;
  startTime = millis();
  // loop only when LEDs are on
  while (startflag == 1) {
    sensorReading = analogRead(HIT_SENSOR);
    elapsedTime = millis() - startTime;
    checkHit(sensorReading);
  }
}

void checkHit(int sensorReading) {
  if (sensorReading >= HIT_THRESHOLD) {
    turnLedsOff();
//    elapsedTime = millis() - startTime;
//    Serial.println("Total time:"); 
//    Serial.print(elapsedTime);
    startflag = 0;
    Serial.println("Time: ");
    Serial.println(elapsedTime);
  }
  if (elapsedTime >= 5000) {
    turnLedsOff();
    startflag = 0;
    Serial.println("MISSED");
  }
}



