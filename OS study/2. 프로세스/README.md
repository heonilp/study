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

## 04. 프로세스의 생성: Chapter 3. Processes (Part 2) 

- 실습

## 05. 프로세스간 통신: Chapter 3. Processes (Part 3)

- 프로세스 간의 통신 (RPC)

- Processes executing concurrently may be : 독립적, 협력적

- IPC (Inter -Process Communication)

- 데이터를 주고 받는 과정, send data, receive data

- 두가지 모델이 있음

1. 공유 메모리

2. Message Passing (메세지 큐)

- 생산자 소비자 문제

1.  ex) 컴파일러-> 어셈블러 코드-> 어셈블러 

2.  ex) web server ->  HTML file -> brower 

- shared-memory 이용할때 솔루션 - 버퍼를 공유 메모리로 만들면 됩니다.

- To allow producer and comsumer to run concurrently

- Let a buffer of items be available,

 1. a producer and fill the buffer and

 2. a consumer can empty the buffer

 - A shared memory is a region of memory : that is shared by the producer and comsumer processes.

 ``` C++
 #define BUFFER_SIZE 10

    typedef struct {
        
    }item

    item buffer[BUFFER_SIZE];
    int in =0;
    int out =0;

 ```

- OS에서 책임안지고 개발자보고 짜라고하면 그 OS를 안쓰겠죠?

- Message-Passing :OS가 cooperating processes를 제공, 공유메모리 제공해줘!

-Communication Links

- 두개의 프로세스 P와 Q가 통신을 원할때, send와 recevice메시지를 주고 받을수 있다.

- direct(상대방을 아는 것), indirect 통신

1. direct : exactly trwo processes , exactly one link

2. indirect : 메세지는 port로 전송하고 수신할수 있다., port를 공유해야지 pair가 맺어진다. 두개 이상의 프로세스도 상관없다!

- port와 4가지만 os에서 제공해주면됨 : create , send, recv, delete

- synchronous and asynchronous communication.

- blocking or non-blocking :  synchronous and asynchronous.

- blocking send : the sender is blocked until the message is received.

- non-blocking end : the sender is sends the message and conninue.

- blocking receive : the receiver blocks until a message is available.

- Non-blocking receive : the receiver receives either a valid message or a null message.

- automatic(자동) or explicit buffering(명시적으로 버퍼링)

- 결론 : IPC : 프로세스간 통신을 어떻게하는지 / 1. 공유메모리 2.메시지 passing P->Q


## 06. 프로세스간 통신의 실제: Chapter 3. Processes (Part 4)

- 종합요약: IPC, RPC에 대한 것을 알기

- IPC 시스템의 예

1. Shared Memory : POSIX Shared Memory

- POSIX: Portable Operating System Interface (for unix) / OS 표준화? X

2. Message Passing : Pipes

- One of the earliest IPC mechanisms on UNIX systems

- POSIX Shared Memory - memory-mapped files, which associate the region of shared memory with a file.

1. create a shared-momory object

- fd = shm_open(name ,O_CREAT | ORDWR, 0666);

2. Configure the size of the object in bytes:

- ftruncate(fd, 4096);

3. Finally, establish a memory-mapped file

- mmap(0, SIZE, PORT_READ | PORT_WRITE, MAP_SHARED, fd 0);

- Pipes were

- one of the first IPC mechanisms in early UNIX systems.

- A pipe acts as a conduit allowing two processes 

- Four issues of pipe implementation :

- Does the pope allow unidirectional or bidirectional communication?

- In the case of two-way comm.,is it half-duplex or full-duplex?

- Two common types of pipes 

1. Ordinary pipes 
- cannot be accessed from outside the process the created it.

- Typically, a parent process creates a pipe and uses 

2. Named pipes

- can be accessed without a parent-child relationship.

- Ordinary Pipes

- allow two processes to communicate in prodeucer-consumer fashion.

- the producer writes to one end of the pipe (write end)

- the consumer reads from the other end (read end)

- ex) pipe (int fd[])

1. fd[0] : the read end of the pipe

2. fd[1] : the write end

- sockets : are defined as endpoints for communication.

- RPCs(Remote Procedure Calls) : abstracts procedure calls between processes on networked systems. (추상화 프로시저), one of the most forms of remote serivce.

- The PRC system : hides the details that allow communication to take place -by providing a stub on the client side. (Little엔디안인지 Bigd엔디안인지 문제생김, 객체직렬화)

- 마샬링은 객체의 메모리 표현을 저장공간 또는 전송에 적합한 데이터 포맷으로 변환하는 과정이다

- The stub of client -side locates the server and - marchals (마샬링) the prameter.