#include <iostream>
#include <set>
#include <algorithm>
int N, M, num;
std::set<int> s;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        std::cin >> num;
        s.insert(num);
    }
    std::cin >> M;
    
    for (int i = 0; i < M; ++i)
    {
        std::cin >> num;
        std::cout << (s.find(num) == s.end() ? 0 : 1) << '\n';
    }
    return 0;
}
