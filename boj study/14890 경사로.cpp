#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_SIZE 101

int n, l;
int map[MAX_SIZE][MAX_SIZE];
int runway_row[MAX_SIZE];
int runway_col[MAX_SIZE];
int ans;

// prev_h : 이전 칸의 높이
// x, y : 현재 칸의 x, y 좌표
// cnt : 현재까지 동일한 칸의 개수
void RecurRow(int prev_h, int x, int y, int cnt)
{
    // 행 검사가 끝나면
    if (y == n)
    {
        bool isway = true;
        for (int i = 0; i < n; i++)
        {
            // 경사로의 개수가 두 개 이상이면 길로 만들지 못한다
            if (runway_row[i] > 1)
                isway = false;
        }

        if (isway)
            ans++;

        memset(runway_row, 0, sizeof(runway_row));
        return;
    }

    int abs_sub = abs(map[x][y] - prev_h);

    if (abs_sub == 0)
    {
        RecurRow(map[x][y], x, y + 1, cnt + 1);
    }
    // 차가 1이면
    else if (abs_sub == 1)
    {
        // 현재 칸의 높이가 이전 칸보다 높은 칸이면
        if (prev_h < map[x][y])
        {
            if (cnt >= l)
            {
                for (int i = y - 1, l_cnt = 0; l_cnt < l; i--, l_cnt++)
                {
                    if (i < 0)
                    {
                        memset(runway_row, 0, sizeof(runway_row));
                        return;
                    }
                    // 경사로 개수 추가
                    runway_row[i] += 1;
                }
                RecurRow(map[x][y], x, y + 1, 1);
            }
            else
            {
                memset(runway_row, 0, sizeof(runway_row));
                return;
            }

        }
        // 현재 칸이 더 낮은 칸이면
        else
        {
            // 현재부터 l개의 칸을 경사로로 만들어준다
            for (int i = y, l_cnt = 0; l_cnt < l; i++, l_cnt++)
            {
                if (i >= n)
                {
                    memset(runway_row, 0, sizeof(runway_row));
                    return;
                }
                if (map[x][i] == map[x][y])
                    runway_row[i] += 1;
                // 앞의 l개의 칸 중에서 높이가 다른 칸이 존재하면 경사로를 못만든다
                else
                {
                    memset(runway_row, 0, sizeof(runway_row));
                    return;
                }
            }
            RecurRow(map[x][y], x, y + 1, 1);
        }
    }
    // 차가 1도 아니고 0도 아니면 길이 될 수 없으므로 호출 종료
    else
    {
        memset(runway_row, 0, sizeof(runway_row));
        return;
    }
}

void RecurCol(int prev_h, int x, int y, int cnt)
{
    // 열 검사가 끝나면
    if (x == n)
    {
        bool isway = true;
        for (int i = 0; i < n; i++)
        {
            // 경사로의 개수가 두 개 이상이면 길로 만들지 못한다
            if (runway_col[i] > 1)
                isway = false;
        }
        if (isway)
            ans++;

        memset(runway_col, 0, sizeof(runway_col));
        return;
    }

    int abs_sub = abs(map[x][y] - prev_h);

    if (abs_sub == 0)
    {
        RecurCol(map[x][y], x+1, y, cnt + 1);
    }
    // 차가 1이면
    else if (abs_sub == 1)
    {
        // 현재 칸의 높이가 이전 칸보다 높은 칸이면
        if (prev_h < map[x][y])
        {
            if (cnt >= l)
            {
                for (int i = x - 1, l_cnt = 0; l_cnt < l; i--, l_cnt++)
                {
                    if (i < 0)
                    {
                        memset(runway_col, 0, sizeof(runway_col));
                        return;
                    }
                    // 경사로 개수 추가
                    runway_col[i] += 1;
                }
                RecurCol(map[x][y], x+1, y, 1);
            }
            else
            {
                memset(runway_col, 0, sizeof(runway_col));
                return;
            }
        }
        // 현재 칸이 더 낮은 칸이면
        else
        {
            // 현재부터 l개의 칸을 경사로로 만들어준다
            for (int i = x, l_cnt = 0; l_cnt < l; i++, l_cnt++)
            {
                if (i >= n)
                {
                    memset(runway_col, 0, sizeof(runway_col));
                    return;
                }
                if (map[i][y] == map[x][y])
                    runway_col[i] += 1;
                // 앞의 l개의 칸 중에서 높이가 다른 칸이 존재하면 경사로를 못만든다
                else
                {
                    memset(runway_col, 0, sizeof(runway_col));
                    return;
                }
            }
            RecurCol(map[x][y], x+1, y, 1);
        }
    }
    // 차가 1도 아니고 0도 아니면 길이 될 수 없으므로 호출 종료
    else
    {
        memset(runway_col, 0, sizeof(runway_col));
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l;

    // #1. 지도 입력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    // #2. 행, 열 검사
    for (int i = 0; i < n; i++)
    {
        RecurRow(map[i][0], i, 0, 0);
        RecurCol(map[0][i], 0, i, 0);
    }

    cout << ans << "\n";

    return 0;
}
