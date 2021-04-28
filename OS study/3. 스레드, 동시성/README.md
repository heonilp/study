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

