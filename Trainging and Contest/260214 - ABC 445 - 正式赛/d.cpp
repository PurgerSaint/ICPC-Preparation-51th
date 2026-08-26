#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Chocolate {
    int id;    // 原始编号，方便输出
    int h, w;  // 高和宽
    int r, c;  // 最终放置的坐标
    bool used = false;
};

int H, W, N;
vector<Chocolate> chocs;
vector<vector<bool>> canvas;

// 检查在 (startR, startC) 放置一块 h*w 的巧克力是否可行
bool canPlace(int h, int w, int startR, int startC) {
    if (startR + h > H || startC + w > W) return false; // 越界
    for (int i = startR; i < startR + h; ++i) {
        for (int j = startC; j < startC + w; ++j) {
            if (canvas[i][j]) return false; // 重叠
        }
    }
    return true;
}

// 放置或移除巧克力（标记/撤销标记）
void markCanvas(int h, int w, int startR, int startC, bool val) {
    for (int i = startR; i < startR + h; ++i) {
        for (int j = startC; j < startC + w; ++j) {
            canvas[i][j] = val;
        }
    }
}

bool solve(int count) {
    if (count == N) return true; // 所有巧克力都放好了

    // 1. 寻找第一个空位 (r, c)
    int r = -1, c = -1;
    for (int i = 0; i < H && r == -1; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!canvas[i][j]) {
                r = i; c = j;
                break;
            }
        }
    }

    // 2. 尝试每一块还没用的巧克力
    for (int i = 0; i < N; ++i) {
        if (!chocs[i].used) {
            // 注意：必须能覆盖当前的 (r, c)
            if (canPlace(chocs[i].h, chocs[i].w, r, c)) {
                // 尝试放置
                chocs[i].used = true;
                chocs[i].r = r;
                chocs[i].c = c;
                markCanvas(chocs[i].h, chocs[i].w, r, c, true);

                if (solve(count + 1)) return true;

                // 回溯：撤销放置
                markCanvas(chocs[i].h, chocs[i].w, r, c, false);
                chocs[i].used = false;
            }
        }
    }
    return false;
}

int main() {
    // 输入示例：总高H, 总宽W, 巧克力数量N
    cin >> H >> W >> N;
    chocs.resize(N);
    for (int i = 0; i < N; ++i) {
        chocs[i].id = i;
        cin >> chocs[i].h >> chocs[i].w;
    }

    // 优化：按面积或高度降序排列有助于减少回溯次数
    sort(chocs.begin(), chocs.end(), [](const Chocolate& a, const Chocolate& b) {
        return a.h * a.w > b.h * b.w;
    });

    canvas.assign(H, vector<bool>(W, false));

    if (solve(0)) {
        sort(chocs.begin(), chocs.end(), [](const Chocolate& a, const Chocolate& b){
            return a.id < b.id;
        });
        for (const auto& c : chocs) {
            cout << c.r << " " << c.c << endl;
        }
    }
    return 0;
}