# Учебная практика 2026
# Задание 11, Вариант 7
# Вахромеев Радион Романович

import cv2
import numpy as np

# Загружаем изображение (файл должен лежать в той же папке)
image = cv2.imread("image.jpg")

# Показываем исходное изображение
cv2.imshow("original", image)
cv2.waitKey(0)

# Размываем изображение, чтобы убрать шум (как в примере)
blurred_image = cv2.GaussianBlur(image, (11, 11), 0)

cv2.imshow("blurred", blurred_image)
cv2.waitKey(0)

# Переводим из BGR в HSV — в HSV проще выбирать цвета по оттенку
hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)

cv2.imshow("hsv", hsv_image)
cv2.waitKey(0)

# Задаём границы синего цвета в HSV
# Синий в HSV: оттенок (Hue) примерно от 100 до 130
hsv_min = np.array((100, 50, 50), np.uint8)   # нижняя граница синего
hsv_max = np.array((130, 255, 255), np.uint8)  # верхняя граница синего

# Создаём маску — белое там, где цвет попадает в наш диапазон
blue_mask = cv2.inRange(hsv_image, hsv_min, hsv_max)

cv2.imshow("mask", blue_mask)
cv2.waitKey(0)

# Находим все контуры на маске
contours, hierarchy = cv2.findContours(blue_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

# Проверяем, нашлось ли хоть что-то
if len(contours) == 0:
    print("Синих объектов не найдено!")
else:
    # Сортируем контуры по площади — самый большой будет первым
    sorted_contours = sorted(contours, key=cv2.contourArea, reverse=True)

    # Берём самый большой контур
    largest_contour = sorted_contours[0]

    # Находим описывающий прямоугольник — он даёт x, y (верхний левый угол), ширину и высоту
    x, y, w, h = cv2.boundingRect(largest_contour)

    print(f"Самый большой синий объект: x={x}, y={y}, ширина={w}, высота={h}")

    # Вычисляем центр объекта
    center_x = int(x + w / 2)
    center_y = int(y + h / 2)

    print(f"Центр объекта: ({center_x}, {center_y})")

    # Рисуем красную точку в центре объекта
    # (image, координаты центра, радиус, цвет BGR, -1 = закрашенный круг)
    cv2.circle(image, (center_x, center_y), 10, (0, 0, 255), -1)

    # Показываем результат
    cv2.imshow("result", image)
    cv2.waitKey(0)

cv2.destroyAllWindows()
