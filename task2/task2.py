# Учебная практика 2026
# Задание 2.
# Вахромеев Радион Романович

def main():
    # 1. Считываем N (количество узлов) и M (количество линий связи)
    n, m = map(int, input().split())

    # 2. Создаем граф в виде списка смежности.
    graph = [[] for _ in range(n + 1)]

    # Считываем существующие связи
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u) # Граф ненаправленный, поэтому связь двусторонняя

    # Массив для отслеживания посещенных узлов
    visited = [False] * (n + 1)
    components_count = 0

    # 3. Функция обхода графа в глубину (DFS) без рекурсии (с помощью стека)
    def dfs(start_node):
        stack = [start_node]
        while stack:
            current = stack.pop()
            if not visited[current]:
                visited[current] = True
                # Добавляем всех непосещенных соседей в стек
                for neighbor in graph[current]:
                    if not visited[neighbor]:
                        stack.append(neighbor)

    # 4. Считаем количество независимых кусков сети (компонент связности)
    for i in range(1, n + 1):
        if not visited[i]:
            # Нашли узел, в котором еще не были
            components_count += 1
            # Запускаем обход, чтобы пометить все узлы как посещенные
            dfs(i)

    # 5. Минимальное число новых линий
    print(components_count - 1)

if __name__ == "__main__":
    main()