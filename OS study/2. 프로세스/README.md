# Chapter 3. Processes

## 03. 프로세스의 이해: Chapter 3. Processes (Part 1)

- 프로세스는 실행중인 프로그램

- 운영체제 입장은 작업의 단위가 프로세스이다.

- 프로세스는 다음을 이용

1. cpu time

2. memory

3. files

4. and I/O devices(resoure)

- 프로세스 메모리 구조

1. TEXT 영역  : 코드

2. DATA 영역 : 전역, static

3. HEAP 영역 : 동적할당

4. 스택 영역 : 지역, 함수 , 매개변수

- 프로세스의 라이프 사이클

1. New : 프로세스가 만들어 졌을때 (fork)

2. Running : CPU 점유해서 프로세스를 로드

3. Waiting : 이벤트가 발생해서 프로세스가 기다리는거 , 대기상태 (I/O, 시그널)

4. Ready : I/O이 오면 바로 실행되는게 아니라 기다렸다가 실행 (ready queue)

- Ready -> running : 스캐줄러가 디스패처해주면 감

4. Terminated : 프로세스가 종료 될때 상태

- PCB (Process Contorl Block) or TCB(Task Contorl Block) : 각 프로세스가 가져야할 정보 , 구조체타입으로 제공

1. Process state : 라이프 사이클 상태

2. Program counter : PC (프로그램을 몇번 호출했는지) 

3. CPU registers ->context

4. CPU-sheduling information

5. Memory-managemnet information

6. Accounting information

7. I/O status information  어디서 락을 걸었는지

- 프로세스는 싱글 스레드 실행, 시분할에 의해서 실행

- 싱글 스레드 컨트롤, 한번에 한 테스크밖에못함 ->여러개의 동시에 하는것이 멀티스레드

- 멀티태스킹, 멀티 프로세싱 제공 -> 하지만 프로세스 안에서 멀티스레드를 돌릴수 있음

- A thread is a lightweight process 

- 프로세스 스케줄링

- 멀티프로그래밍의 목적

1.  동시에 실행 시켜보자.  동시성 <-> 병렬성

2.  CPU 사용률을 최대화시키자.

- time sharing

1. CPU core를 프로세스 간의 자주 스위칭하자

2. 각각 프로그램이 동시에 돌고 있는 것 처럼 보이자

- CPU 스케줄링 큐 : 큐는 FIFO, 레디큐, 구현은 링크드리스트로함

1. I/O request ->I/O queue ->I/O -> 레디큐 ->CPU

2. time slice expired -> 레디큐 ->CPU

3. for a child ->child execcutes -> 레디큐 -> CPU

4. wait for an interrupt -> interrupt occurs -> 레디큐 -> CPU

- Context Switch (문맥교환) : the conext of process is represnted in the PCB, 인터럽트가 일어날때 상태를 저장해놓고 다시 cpu 획득했을때 다시 불러온다. 

- OS에서 기기에 제공되어야될것

1. 프로세스 생성

2. 프로세스 종료

- 프로세스가 새로운 프로세스를 실행시킬수 있다.(부모, 자식 프로세스)

- exit() 시스템 콜 : asks OS to delete it

- Zombie and Orphan(좀비 && 기아), 백그라운드를 만들때 사용

- 좀비 프로세스 : 부모 없는 프로세스

- 기아 프로세스 : wait를 실행하지 않음, 부모가 죽지는않았는데 신경을 안씀 