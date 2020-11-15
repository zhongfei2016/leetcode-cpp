//
// Created by ZHONGFEI on 2020/10/28.
// 噪声的传播，入参是n×m坐标的矩阵和噪声源坐标及噪声值，每个噪声源的噪声值向八个方向传播，没走一个减小一个值，求整个矩阵所有噪声值（叠加的地方取最高值）

#include "NoiseCalSln.h"

#include <queue>

struct Noise {
    int x;
    int y;
    int noise;

    Noise(int x, int y, int noise) {
        this->x = x;
        this->y = y;
        this->noise = noise;
    }
};

vector<vector<int>> dirs = {{1,  0},
                            {-1, 0},
                            {0,  1},
                            {0,  -1},
                            {1,  1},
                            {-1, -1},
                            {-1,  1},
                            {1,  -1}};

int NoiseCalSln::calculateNoise(int n, int m, vector<vector<int>> noises) {
    queue<Noise> que;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> noiseMatrix(n, vector<int>(m, 0));
    int res = 0;
    for (auto noise: noises) {
        que.push(Noise(noise[0], noise[1], noise[2]));
        visited[noise[0]][noise[1]] = true;
        noiseMatrix[noise[0]][noise[1]] = noise[2];
        res += noise[2];
    }
    while (!que.empty()) {
        auto item = que.front();
        que.pop();
        int tempNoise = item.noise - 1;
        if (tempNoise <= 0) {
            continue;
        }
        for (auto dir : dirs) {
            int tempX = item.x + dir[0];
            int tempY = item.y + dir[1];
            if (tempX < 0 || tempX >= n || tempY < 0 || tempY >= m) {
                continue;
            }
            if (visited[tempX][tempY] && tempNoise <= noiseMatrix[tempX][tempY]) {
                continue;
            }
            res = res - noiseMatrix[tempX][tempY] + tempNoise;
            noiseMatrix[tempX][tempY] = tempNoise;
            visited[tempX][tempY] = true;
            que.push(Noise(tempX,tempY,tempNoise));
        }
    }
    return res;
}