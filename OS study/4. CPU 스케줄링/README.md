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

## 10. 스케줄링 알고리즘: Chapter 5. CPU Scheduling (Part 2)

- SJF 스케줄링 알고리즘 is provably optimal, it gives the minimum average waiting time for a given set of processes.

- 짧은 process의 waiting time을 감소

- SJF 스케줄링 : next CPU burst의 길이를 알수 없음(예측할수 없음)

- predict 예측, next CPU, 과거를 보면 미래를 알수 있음, optimal하다.

- SJF -> 비선점(Non-preemptive),  선점(preemptive)

- SRTF : Shortest Remaining Time Fisrt , 선점(preemptive) 스케줄링

- RR 스케줄링 : 라운드 로빈 : 선점(preemptive) FCFS with time quantum(시분할, or time clice) ,10~100 ms, 레디큐는 순환큐로 구현한다.

- the process may have a cpu burst of less than one time quantum.

- if the CPU burst is longer than one time quantum.

- the timer will go off and will cause an interrupt to the OS.

- a context switch will be executed.

- the process will beput at the tail of the ready queue

- time quantum의 사이즈에 따라서 성능 차이가 남

- 우선순위가 큰 걸 CPU에 acllocated함. 같으면 FCFC 방식으로함

- SJF -> 우선순위 기반 스케줄링, low number , high 우선순위

- priority 스케줄링은 비선점(Non-preemptive),  선점(preemptive)

- 기아 문제가 발생 -> indefinite blocking : a blockd process : ready to run, but waiting for the CPU, some low-priority processes may wait indefinitely. 낮은 우선순위일때 계속 큐에 존재함. 계속 대기만함. 기아 발생

- 기아 문제는 aging(에이징 방법)으로 풀어야함

- Multi-Level Queue(MLQ) Scheduling : hignest priority 

1. real-time processes

2. system processes

3. interactive processes

4. batch processes

- Multi-Level Feedback Queue(MLFQ) 스케줄링 : 실전 O/S + 멀티코어

-  time quantum =8 -> time quantum =16 -> FCFS

- 현대적 OS : it is kernel threads - not processes - that are being scheduled,

- 커널스레드에 유저스레드 맵핑만하면됨. OS 커널은 CPU스케줄링 -> 커널 스레드로 대상으로 한다.

- Real-Time OS(실시간 운영체제)에서 스케줄링

- Soft Realtime (critical process 먼저)vs Hard Realtime(데드라인안에 실행되어야함, 우선순위)

