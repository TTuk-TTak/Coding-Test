#include<string>

using namespace std;

bool solution(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
        // 0보다 작아지면 바로 out 매번마다 확인해야함 *** 
        if (n < 0)
            return false;
        // stack에 넣는 것과 비슷한 구조 n++, n--; 
        if (s[i] == '(')
            n++;
        else if (s[i] == ')')
            n--;
    }
    return n == 0;
}
