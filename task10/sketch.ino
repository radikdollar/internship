#include <Servo.h>

#define SERVO_PIN 9

Servo myServo;
int currentAngle = 0; // текущий угол серво

void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(currentAngle); // начальное положение - 0 градусов
  Serial.begin(9600);
  Serial.println("Введите угол от 0 до 180:");
}

void loop() {
  // Ждём, пока в Serial появятся данные
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // читаем строку до нажатия Enter
    input.trim(); // убираем пробелы и \r\n по краям

    // Проверяем, что введено число (все символы - цифры)
    bool isNumber = true;
    if (input.length() == 0) isNumber = false;
    for (int i = 0; i < input.length(); i++) {
      if (!isDigit(input[i])) {
        isNumber = false;
        break;
      }
    }

    if (!isNumber) {
      Serial.println("Ошибка: введите число от 0 до 180");
    } else {
      int angle = input.toInt();
      if (angle < 0 || angle > 180) {
        Serial.println("Ошибка: угол должен быть от 0 до 180");
      } else if (angle == currentAngle) {
        Serial.print("Серво уже стоит в позиции ");
        Serial.print(currentAngle);
        Serial.println(" градусов");
      } else {
        // Плавно поворачиваем серво к нужному углу
        Serial.print("Поворачиваю к ");
        Serial.print(angle);
        Serial.println(" градусам...");

        int step = (angle > currentAngle) ? 1 : -1;
        while (currentAngle != angle) {
          currentAngle += step;
          myServo.write(currentAngle);
          delay(15); // задержка между шагами - чем меньше, тем быстрее
        }

        Serial.print("Готово! Текущий угол: ");
        Serial.print(currentAngle);
        Serial.println(" градусов");
      }
    }

    Serial.println("Введите угол от 0 до 180:");
  }
}
