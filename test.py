

with open("input.txt", 'r') as f:
    N, L, K = list(map(int, f.readline().split(' ')))
    data = [tuple(map(int, (i.split(' ')))) for i in f.readlines()]


def pos(x2: int, y2: int, type: int, positions: list) -> bool:
    for x1, y1 in positions:
        match type:
            case 1:  # Ферзь
                if not (x1 != x2 and y1 != y2 and
                        (abs(x1-x2) != abs(y1-y2))):
                    return False
            case 2:  # конь
                if [abs(x1-x2), abs(y1-y2)] in [[2, 1], [1, 2]]:
                    return False
            case 3:  # слон
                if abs(x1-x2) == abs(y1-y2):
                    return False
            case 4:  # ладья
                if x1 == x2 or y1 == y2:
                    return False
            case 5:  # король
                if abs(x1-x2) < 2 and abs(y1-y2) < 2:
                    return False
    return True

# условие для удара ферзя это равность i2=i1 or  j2=j1, а так же если abs(i2-i1) = abs(j2-j1)
# Условие для удара конём это если [abs(i2-i1), abs(j2-j1)] это [2,1] или [1,2]
# условие для удара слона это abs(j2-j1) = abs(i2-i1)
# условие для удара ладьёй это i2=i1 или j2=j1
# условие для удара короля это abs(i2-i1) < 2 and abs(j2-j1) < 2
# мы пройдемся по всем возможным полям один раз, и поэтому постановка фигур позади первой невозможна


def main(data: list, N: int, L: int, type: int):

    for start in range(N*N):
        start_x = start % N
        start_y = start // N
        positions = data.copy()
        figure = L
        flag = 1
        if not pos(start_x, start_y, type, positions):
            continue
        while flag:
            for y in range(start_y, N):
                for x in range(start_x, N):
                    if pos(x, y, type, positions):
                        figure -= 1
                        positions.append((x, y))
                    if figure == 0:
                        print(positions)
                        flag = 0
                        break
                if not flag:
                    break

            old = positions.pop()
            sums = old[0] + N * old[1] + 1
            start_x = sums % N
            start_y = sums // N
            figure += 1


main(data, N, L, 1)
