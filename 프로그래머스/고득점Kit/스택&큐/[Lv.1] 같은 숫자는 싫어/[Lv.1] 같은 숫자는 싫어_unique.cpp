/* 벡터에서 연속중복값 삭제하는 문제 
<유의점>
 1. 벡터에서 중복값 제거 시, sort, unique, erase 기능을 적절히 사용
 2. unique : '연속된' '중복' 원소를, vector 가장 뒷부분 쓰레기값으로 보내는 함수. (지우는거 아님) 
             + 동시에 쓰레기값의 시작위치를 반환함. ***
            ex)    1 1 1 2 2 2 3    이 unique를 거치면, 
                   1 2 3/? ? ? ?
                        ↑ 이 쓰레기값 시작위치 반환 
    erase : arr.erase(시작위치, 끝위치) 로 사용시 지정한 시작~끝 위치사이의 원소를 삭제 
                                ↓
    즉, 다음과 같이 반환값을 바로 erase 하도록 작성하면, {연속된 중복값만 삭제}할 수 있음. 
    arr.erase(unique(arr.begin(), arr.end()), arr.end());   ******
             (unique함수로 얻은 쓰레기값 시작위치, arr의 끝위치);
                   
 3. 연속되지 않더라도 {모든 중복되는 값을 삭제}하고 싶다면,
    sort 먼저 진행 후, 2번 과정 진행*/

#include <vector>
#include <algorithm>    // unique함수, sort함수 포함 
using namespace std;

vector<int> solution(vector<int> arr) 
{
    arr.erase(unique(arr.begin(), arr.end()),arr.end());    //***

    return arr;
}
