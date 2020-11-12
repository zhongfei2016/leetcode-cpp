// 杨辉三角


class YangHuiTriangleSln {
public:
    vector<vector<int>> generate(int numRows);
};
/**
 * 杨辉三角
 * 1
 * 11
 * 121
 * 1331
 * 14641
 * @param numRows
 * @return
 */
vector<vector<int>> YangHuiTriangleSln::generate(int numRows) {
    vector<vector<int>> results;
    if (numRows <= 0) {
        return results;
    }
    // 先塞[1]进去
    vector<int> result(1, 1);
    results.push_back(result);

    for (int i = 1; i < numRows; i++) {
        auto &lastItem = results[i - 1];
        //每一行的第一个元素都是1
        vector<int> item(1, 1);
        // 后面每一个元素都是上一行当前索引和前一个索引对应的数的和
        for (int j = 1; j < lastItem.size(); j++) {
            item.push_back(lastItem[j - 1] + lastItem[j]);
        }
        // 最后一个也是1
        item.push_back(1);
        results.push_back(item);
    }
    return results;
}