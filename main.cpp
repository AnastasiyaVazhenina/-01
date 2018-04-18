#include <iostream>

int findPath(const int startX, const int startY,
             const int targetX, const int targetY,
             const unsigned char* map, const int mapWidth, const int mapHeight,
             int* outBuffer, const int outBufferSize)
{
    int px[outBufferSize];
    int py[outBufferSize];
    int len = 0;
    auto **matrix = new unsigned char*[mapWidth];
    int k = 0;
    for (int i = 0; i < mapHeight; ++i) {
        matrix[i] = new unsigned char[mapWidth];
        for (int j = 0; j < mapWidth; ++j) {
            if (map[k] == 0) {
                matrix[i][j] = '#';
            } else {
                matrix[i][j] = '*';
            }
            ++k;
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int x = 0;
    int y = 0;
    bool stop = true;
    if ((matrix[startY][startX] == '#') || (matrix[targetY][targetX] == '#'))
        return -1;
    unsigned char d = 0;
    matrix[startY][startX] = 0;
    do {
        stop = true;
        for (y = 0; y < mapHeight; ++y) {
            for (x = 0; x < mapWidth; ++x) {
                if (matrix[y][x] == d) {
                    for (k = 0; k < 4; ++k) {
                        int iy = y + dy[k];
                        int ix = x + dx[k];
                        if ((iy >= 0) && (iy < mapHeight) && (ix >= 0) && (ix < mapWidth) &&
                                (matrix[iy][ix] == '*')) {
                            stop = false;
                            matrix[iy][ix] = d + 1;
                        }
                    }
                }
            }
        }
        d++;
    } while ((!stop) && (matrix[targetY][targetX] == '*'));
    if (matrix[targetY][targetX] == '*')
        return -1;
    len = matrix[targetY][targetX];
    x = targetX;
    y = targetY;
    d = len;
    while (d > 0) {
        px[d] = x;
        py[d] = y;
        --d;
        for (k = 0; k < 4; ++k) {
            int iy = y + dy[k];
            int ix = x + dx[k];
            if ((iy >= 0) && (iy < mapHeight) && (ix >= 0) && (ix < mapWidth) &&
                    (matrix[iy][ix] == d)) {
                x = x + dx[k];
                y = y + dy[k];
                break;
            }
        }
    }
    px[0] = startX;
    py[0] = startY;
    for (int i = 0; i < len; ++i) {
        outBuffer[i] = px[i + 1] + (mapWidth * py[i + 1]);
    }
    for (int i = 0; i < mapWidth; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return len;
}

int main() {
    unsigned char map[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1};
    int outBuffer[12];
    int num = findPath(0, 0, 1, 2, map, 4, 3, outBuffer, 12);
    std::cout << num << std::endl;
    for (int i = 0; i < num; ++i)
    {
        std::cout << outBuffer[i] << ' ';
    }
    return 0;
}
