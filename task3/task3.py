# Учебная практика 2026
# Задание 3.
# Вахромеев Радион Романович

def main():
    # 1. Считываем n (количество улиц) и k (количество запросов)
    n, k = map(int, input().split())

    # 2. Создаем массив улиц.
    streets = [0] * (n + 1)

    # 3. Обрабатываем k запросов в цикле
    for _ in range(k):
        query = list(map(int, input().split()))

        if query[0] == 1:
            i = query[1]  # номер улицы
            x = query[2]  # количество снега
            streets[i] += x  # прибавляем снег к нужной улице

        elif query[0] == 2:
            u = query[1]  # начальная улица
            r = query[2]  # конечная улица

            total_snow = sum(streets[u: r + 1])
            print(total_snow)


if __name__ == "__main__":
    main()