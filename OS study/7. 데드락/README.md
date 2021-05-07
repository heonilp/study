
## 17. 데드락의 이해: Chapter 8. Deadlocks (Part 1)

- deadlock : 집합의 다른 프로세스가 이벤트가 발생할때, 모든 프로세스가 기다릴때?

- 스레드가 wait 상태에서 계속 대기

- 리소스 타입이 some number of identical instances. - CPU 사이클, 파일들, I/O드라이버

- 4가지 필수 조건

1. Mutual Exclusion : At least one resource is held in a non-sharable mode.

2. Hold and Wait : A thread holds at least one resource and waiting to acquire additional resources held by other threads.

3. No preemption(비선점) : Resources cannot be preempted.

4. Circular Wait : A set of waiting threads exist such that the dependency graph of waiting is circular.

- 뱅크알고리즘, 예방, 회피, detect, recover