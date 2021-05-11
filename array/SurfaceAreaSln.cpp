//
// 求三维形体表面积 https://leetcode-cn.com/problems/surface-area-of-3d-shapes/
//

#include "SurfaceAreaSln.h"

// 方式一，计算每个柱体的表面积（柱体内立方体的接触面自然被省略掉），再减去柱体间接触的面积
int SurfaceAreaSln::surfaceArea(vector<vector<int>> &grid) {
    int n = grid.size();
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int everyNum = grid[i][j];
            if (everyNum <= 0) {
                continue;
            }
            area += 2 + 4 * everyNum;
            area -= i > 0 ? min(grid[i - 1][j], grid[i][j]) * 2 : 0;
            area -= j > 0 ? min(grid[i][j - 1], grid[i][j]) * 2 : 0;
        }
    }
    return area;
}

// 方式二，计算每个立方体的表面积，再减去柱体内立方体的接触面，再减去柱体间接触的面积
int SurfaceAreaSln::surfaceArea2(vector<vector<int>> &grid) {
    int n = grid.size();
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = grid[i][j];
            if (num <= 0) {
                continue;
            }
            // num个立方体摞在一起，有num-1个接触面，每个面有两个方块各自的面积，所以✖2
            area += num * 6 - (num - 1) * 2;
            area -= i > 0 ? min(grid[i - 1][j], grid[i][j]) * 2 : 0;
            area -= j > 0 ? min(grid[i][j - 1], grid[i][j]) * 2 : 0;
        }
    }
    return area;
}
