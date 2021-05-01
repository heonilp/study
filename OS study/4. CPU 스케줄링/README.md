## 09. CPU 스케줄링: Chapter 5. CPU Scheduling (Part 1)

- CPU 스케줄링은 OS 멀티프로그래밍 기본

- 멀티 프로그래밍의 목적

1. 모든 시간의 프로세스들의 돌리는것

2. CPU 성능 최대화

- I/O bound > CPU bound

- CPU스케줄러 : 메모리 로드 된 프로세스를 선택할것인지, CPU에 ready 상태일때

1. FIFO queue : 차례차례

2. priority queue 

- 선점(preemptive)vs 비선점(Non-preemptive)

1. 비선점(Non-preemptive)

- a process keeps the CPU until it releases it,

- either by terminating or by switching to the waiting state.

2. 선점(preemptive) : 프로세스를 바꿀수 있다.

- a process can be preempted by the scheduler.

- CPU-스케줄링 

1. running to waiting

2. running to ready

3. waiting to ready

4. terminates

- NO 1&4 : no choice : 비선점

- NO 2&3 : choices : 선점 or 비선점 

- dispatcher 디스패처 (context sw 하는 역할)

- CPU core의 컨트롤을 넘겨주는것

1. switching context from one process to another

2. switching to user mode

3. jumping to the proper location to resume the user program.

- 스케줄링의 목표

1. CPU utilzation

2. Throughput : 완료되는 프로세스의 개수

3. Turnaround time : 실행부터 종료까지 최소화

4. wating time : ready queue에서 대기하는 시간 최소화

5. Response time : 응답하는 것 시간

- CPU 스케줄링 문제 해결

1. FCFS: First-Come, First-Served : CPU에게 먼저 요청한 것을 실행, CPU-burst time에 따라 달라짐 - 비선점(Non-preemptive)

- Convoy Effect : 똥차 효과

2. SJF : Shortest Job First(SRTF : Shortest Remaining Time Fisrt): next burst CPU에 따라서 배정, 같다면 FCFS를 쓰면됨.

3. RR: Round-Robin / 시분할 (T1, T2, T3... Ready queue)

4. Priority-based

5. MLQ : Multi-Level queue

6. MLFQ : Multi-Level Feedback queue






