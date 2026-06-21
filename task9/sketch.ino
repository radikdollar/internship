// Задание 9
// Зелёный светодиод - двери открываются
// Красный светодиод - двери закрываются
// Фоторезистор имитирует приближение/удаление человека от дверей

#define RED_PIN     9    // красный светодиод (закрытая дверь)
#define GREEN_PIN   10   // зелёный светодиод (открытая дверь)
#define LDR_PIN     A0   // фоторезистор

#define THRESHOLD   512  // порог срабатывания (человек "подошёл")
#define CHECK_DELAY 1000 // через сколько мс повторно проверяем фоторезистор

bool doorOpen = false; // по умолчанию дверь закрыта

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  Serial.begin(9600);

  // По умолчанию горит светодиод закрытой двери
  closeDoor();
}

void loop() {
  int lightValue = analogRead(LDR_PIN);

  if (lightValue > THRESHOLD) {
    // Человек рядом - открываем дверь
    openDoor();

    delay(CHECK_DELAY);

    // Проверяем ещё раз: человек всё ещё рядом?
    int recheckValue = analogRead(LDR_PIN);
    if (recheckValue > THRESHOLD) {
      // Остаётся открытой, ничего не меняем
    } else {
      closeDoor();
    }
  } else {
    // Человека рядом нет - дверь закрыта
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
