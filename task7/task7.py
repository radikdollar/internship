# Учебная практика 2026
# Задание 7
# Вахромеев Радион Романович

def main():

    s = input().strip()
    if len(s) != 6:
        print("No")
        return
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
