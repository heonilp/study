문제 설명

특수 이진 문자열은 다음 두 가지 속성을 가진 이진 문자열입니다.
1. 0의 수는 1의 수와 같습니다.
2. 이진 문자열의 모든 접두사는 최소한 0만큼 많은 1이 있습니다.

특별한 문자열을 감안할 S하는 움직임은 두 개의 연속, 비어 있지 않은 특수 문자열을 선택 구성 S하고이를 교환.
(첫 번째 문자열의 마지막 문자가 두 번째 문자열의 첫 번째 문자 앞에 정확히 하나의 인덱스 인 경우 두 문자열이 연속적입니다.)

이동 횟수가 끝났을 때 가능한 사전식적으로 가장 큰 결과 문자열은 무엇입니까?

Time: O(nlogn)→O(n^2)
Space: O(n)

비어 있지 않은 각 특수 하위 문자열에 대해 내부를 교체하여 사전적으로 가장 큰 특수 하위 문자열을 만든 다음
특수 하위 문자열을 정렬하여 사전적으로 가장 큰 특수 하위 문자열을 형성합니다.
분명히 각 특수 하위 문자열은 1로 시작하고 0으로 끝나야합니다. 
더 작은 특수 하위 문자열을 얻을 때마다 시작에 1을 삽입하고 끝에 0을 삽입하여 더 큰 특수 하위 문자열을 만듭니다.


입력 : S = "11011000"
 출력 : "11100100"
 설명 :
문자열 "10"[S [1]에서 발생] 및 "1100"[S [3]에서 발생]이 스왑됩니다.
이것은 몇 번의 스왑 후 가능한 사전 식적으로 가장 큰 문자열입니다.

1. S를 여러 특수 문자열로 분할합니다 (가능한 한 많이).
2. 특수 문자열은 1로 시작하고 0으로 끝납니다. 중간 부분에서 재귀.
3. 모든 특수 문자열을 사전 순으로 가장 큰 순서로 정렬합니다.
4. 모든 문자열을 결합하고 출력합니다.

class Solution {
 public:
  string makeLargestSpecial(string S) {
    vector<string> specials;
    int count = 0;

    for (int i = 0, j = 0; j < S.length(); ++j) {
      count += S[j] == '1' ? 1 : -1;
      if (count == 0) {  // find a special string  // find a special string ,this is subgroup 특수 문자열 찾기, 이것은 하위 그룹입니다.
	//this subgroup starts from groupstart, ends at i, inner the group 이 하위 그룹은 start에서 시작하여 end에서 끝남, 그룹 내부
	//we need to recursively get the lexicographically largest arrangment //어휘학적으로 가장 큰 배열을 재귀 적으로 얻어야합니다
	//per problem statement.	문제 설명 당. // 2번
        const string& inner = S.substr(i + 1, j - i - 1);
        specials.push_back('1' + makeLargestSpecial(inner) + '0');
        //the next group i at j+1 //j+1에서 다음 그룹 i
        i = j + 1;
      }
    }
       //subgroup best answer in the list , we sort the descendingly
       //목록에서 하위 그룹 베스트 답변, 우리는 내림차순으로 정렬
    sort(begin(specials), end(specials), greater<>());
    return join(specials); //벡터를 string으로 변환
  }

 private:
  string join(const vector<string>& specials) {
    string joined;
    for (const string& special : specials)
      joined += special;
    return joined;
  }
};