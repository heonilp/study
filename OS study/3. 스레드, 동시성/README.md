# Chapter 4. Thread & Concurrency

## 07. 쓰레드의 이해: Chapter 4. Thread & Concurrency (Part 1)

1. Overview

- a process was an executing program with a single thread of control

- however, a process is able to contain multiple threads of control,

- isn't it?

- A thread is a lightweight process (LWP)

- a basic unit of CPU untilization

- 멀티스레딩 benefits

1. comprises a thread ID , a program counter, a register set, and a stack.

2. Responsiveness(continued execution), Resource Sharing (리소스 사용에 공유, Shared memory or message passing)

3. 경제적 : 프로세스 섹션보다 값이싸다. context 스위칭 보다 스레드 스위칭이 오버헤드가낮음

4. scalability : 멀티프로세스 구조의 이점을 갖는다.

- JAVA : threads are the fundamental model of program excetion,  rich set of features

- JAVA : 스레드 클래스를 상속받으면됨, public void run() 오버라이딩, 다중상속문제??

- Implementing the Runnable interface, public void run() 오버라이딩

- Lambda expresstion( 익명 스레드 사용), Runnable 디자인


- Multithreading in a Multicore system. : more effcient use of multiple cores for improved concurrency. confider an application with four threads.

1. single core : threads will be interleaved over time. : 시분할

2. multiple core : some threads can run in parallel.

- Progamming Challenges in Muticore systems.

1. Identifying tasks : find areas can be divided into separate tasks.

2. Balance : ensure the tasks to perform equal work of equal value

3. Data splitting : data also must be divided to run on separate cores.

4. Data dependency : ensure the the execution of tasks is synchronized accommodate the data dependency.

5. Testing and debugging : more difficult than sigle-thread.

- Amdahl's Law : 코어는 무조건 많을수록 좋은가? , 병렬처리안하면 무조건 좋다고할수 없다.


## 08. 멀티쓰레딩: Chapter 4. Thread & Concurrency (Part 2)

- 두개의 스레드 타입

1. 유저 스레드 : Green thread-> native thread

2. 커널 스레드 : OS 입장에서는 코어로 관리 , OS

- 유저 스레드는 OS 커널 위에서 supported

- 커널스레드는 os 직접 관리하는 것

- 유저, 커널 스레드의 연관성

1. Many to One Model

2. One to One Model

3. Many to Many Medel

- 스레드는 라이브러리로 제공, API, 스레드 매니징

- POSIX Pthreads

- Windows thread

- JAVA thread

- The Strategy Implicit Threading : concurrent and parallel applications

1. Thread Pools : 여러개의 스레드들을 풀에 저장

2. Fork & Join

- explicit threading but an excellent candidate for implicit threading

3. OpenMP

4. GCD 