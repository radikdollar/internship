# Учебная практика 2026
# Задание 7
# Вахромеев Радион Романович

def main():
    # Считываем строку и убираем пробелы по краям
    s = input().strip()

    if len(s) != 6:
        print("No")
        return

    # Проверяем каждый символ по правилу:
    # 1 буква, 3 цифры, 2 буквы
    # Индексы в строке идут от 0 до 5

    # isalpha() проверяет, что это буква
    # isdigit() проверяет, что это цифра

    if (s[0].isalpha() and
            s[1].isdigit() and
            s[2].isdigit() and
            s[3].isdigit() and
            s[4].isalpha() and
            s[5].isalpha()):

        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
