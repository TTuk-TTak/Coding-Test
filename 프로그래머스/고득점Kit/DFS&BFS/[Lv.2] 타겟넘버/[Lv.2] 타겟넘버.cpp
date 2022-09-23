/* DFS 문제 
+, - 두경우이므로 branch 두가지 */
#include <string>
#include <vector>

using namespace std;

vector<int> nums;
int targ;
int cnt =0;

// 재귀함수 
void recur(int level, int limit, int sum){
    // level
    if(level > limit){                  // numbers.size()초과하면, 
        if(targ == sum)
            cnt++;
        return;
    }
    // branch       => +, - 종류 2개 
    recur(level+1, limit, sum + nums[level]);   // ***
    recur(level+1, limit, sum - nums[level]);
        
    return;
}

int solution(vector<int> numbers, int target) {
    // 전역변수로 빼기 
    nums = numbers;
    targ = target;
    // 재귀 
    recur(0, numbers.size() -1, 0);     // -1 꼭 해주고 넣기! 
    return cnt;
}
