#define RED_PIN     9
#define GREEN_PIN   10
#define LDR_PIN     A0

#define THRESHOLD   512
#define CHECK_DELAY 1000

bool doorOpen = false;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  Serial.begin(9600);

  closeDoor();
}

void loop() {
  int lightValue = analogRead(LDR_PIN);

  if (lightValue > THRESHOLD) {
    openDoor();

    delay(CHECK_DELAY);

    int recheckValue = analogRead(LDR_PIN);
    if (recheckValue > THRESHOLD) {
    } else {
      closeDoor();
    }
  } else {
    closeDoor();
  }
}

void openDoor() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  if (!doorOpen) {
    Serial.println("Дверь открывается");
  }
  doorOpen = true;
}

void closeDoor() {
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);
  if (doorOpen) {
    Serial.println("Дверь закрывается");
  }
  doorOpen = false;
}
