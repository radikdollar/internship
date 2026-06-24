# Учебная практика 2026
# Задание 11, Вариант 7
# Вахромеев Радион Романович

import cv2
import numpy as np

# Загружаем изображение
image = cv2.imread("image.jpg")

# Показываем исходное изображение
cv2.imshow("original", image)
cv2.waitKey(0)

# Размываем изображение, чтобы убрать шум
blurred_image = cv2.GaussianBlur(image, (11, 11), 0)

cv2.imshow("blurred", blurred_image)
cv2.waitKey(0)

# Переводим из BGR в HSV — в HSV проще выбирать цвета по оттенку
hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)

cv2.imshow("hsv", hsv_image)
cv2.waitKey(0)