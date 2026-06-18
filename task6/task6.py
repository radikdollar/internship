def main():
    n = int(input())

    results = []

    for _ in range(n):
        a, b, x, y = map(int, input().split())
        pairs_b1 = min(b, x)
        rem_b = b - pairs_b1
        rem_x = x - pairs_b1
        pairs_a2 = min(a, y)


        rem_a = a - pairs_a2
        rem_y = y - pairs_a2

        pairs_a1 = min(rem_a, rem_x)
        total_pairs = pairs_b1 + pairs_a2 + pairs_a1
        results.append(total_pairs)
    print(*results)


if __name__ == "__main__":
    main()
