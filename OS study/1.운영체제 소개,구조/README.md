## 1.1 운영체제가 뭐길래?

- 운영체제가 뭔가요 ? An operating system is a software that operates a computer system.(컴퓨터 시스템)

- 컴퓨터가 뭔가요 ? : A computer is a machine that processes the information.(정보를 처리)

- 도대체 정보가 뭔가요? :  An information can be defined as a quantitative representation that measures the uncertainty(불확실한 상황을 수치적으로 표현한게 정보)

- 𝐼(𝑥) = − log2 𝑃(𝑥)


- 컴퓨터가 정보를 어떻게 처리하죠?
- 정보의 최소단위 :bit

- 무어의 법칙(chip 집적도 1년에 두배로 늘어남)
- 황의 법칙 (메모리가 1년에 두배씩 늘어남)

- 그래서 컴퓨터 정보는 어떻게 처리하죠?

- 덧셈은? 반가산기, 전가산기

- 뺄셈은? 2의 보수 표현법

- 곱셈, 나눗셈? - 덧셈과 뺄셈의 반복

- 실수 연산은? 부동 수수점 표현법 (GPU)

- 컴퓨터가 만능이라는건가요? 범용성, NAND 게이트만으로 모든계산을 다할수 있다.(계산가능성: computability)

- 계산가능성: computability(Turing-computable: 튜링 머신으로 계산가능한 것.)
- 정지 문제: Halting Problem: 튜링 머신으로 풀 수 없는 문제.

- 폰 노이만이 왜 컴퓨터의 아버지인가요?(ISA, 폰노이만아키텍쳐)

- A stored-program computer is a computer that stores programs in a memory.

- 프로그램은 명령어들의 집합

-  운영체제도 프로그램인가요?

- is a program running at all times on the computer
- to provide system services to application programs
- to manage processes, resources, user interfaces, and so on. (프로세스 중요)


- 현재사회에서 거의 다 컴퓨터이고 운영제체가 될수있다.
- 지갑도 전자지갑 -chip, NFC이기 때문에 컴퓨터이고 OS일수도 있다.


## 1.2. 운영체제의 개념과 구조: Chapter 1-2. Introduction & O/S structures.

- 운영체제는 어플리케이션 , 프로그램, 유저, 하드웨어 간의 상호작용(매개)

- 4가지 컴퓨터 요소 : OS, 유저, 하드웨어, 어플리케이션 

- 하드웨어 -> OS -> system, 어플리케이션 -> 컴파일러, 어셈블러, 에디터, db ->유저

- 항상 실행하고 있는 프로그램, 커널, 시스템 프로그램, 어플리케이션를 지원

- 커널이 OS의 핵심 (공부)

- 모던 : 폰노이만 형태(전통적인) 를 따르지 않는 / 신경망, 네트워크, 양자

- 컴퓨터의 구성요소: cpu, 여러개의 디바이스 컨트롤러, 버스를 통해 연결

- 부트스트랩 프로그램 : 부팅용 프로그램 , first program to run on computer power-on.

- 운영체제를 메모리에 로드하는 역할

- 부트스트래핑 : 부팅한다.

- 인터럽트 : ex. I/O 디바이스의 입력이 있을때 cpu가 우선순위를 먼저 처리

- 인터럽트 : 언제라도 하드웨어가 트리거한다. 시스템 버스를 통해 cpu에게 시그널을 보내준다.

- 폰노이만 아키텍쳐 : instruction-execution cycle

- 메모리 ->fetch ->cpu - executed

- instruction register (명령 레지스터)

- cpu - 메모리 (RAM(휘발성))

- storage 계층 - 용량과, 접근 속도 

- 접근 순서 : 레지스터 > 캐시 > 메인메모리(RAM) >solid state disK(SSD) > 하드디스크> 옵티컬 디스크(HDD)> magnetic tapes(백업)

- I/O 구조 : thread of execution  , OS 커널 안정 

- DMA : 다이렉트 메모리 억세스 디바이스(디바이스 -메모리) 끼리 다이렉트로 억세스

- 컴퓨터 시스템 구성요소

1. CPU - The hardware that executes instructions

2. Processor - A physical chip that contains one or more CPUs

3. Core - The  back computation unit of the CPU.

4. MultiCore : Including multiple computing cores on the same CPU.

5. Mutiprocessor : Including multiple Processors.

- Symmetric Mutiprocessing (SMP) -> 멀티프로세서 프로그램 여러개의 CPU가 레지스터와 캐시를 가지고 메모리에 연결되어있다.

- 멀티코어 디자인 : cpu 안에 cpu 코어여러개 구성하고 레지스터와 캐시를 넣어서 메모리와 연결

- 멀티프로그래밍 : 옛날에 메모리에 프로그램을 하나만 로딩, 여러개의 프로세서를 동시에 메모리에 올려놓고 동시에 실행시킴(job1, job2 ...jobn)

- 멀티태스킹(=멀티 프로세싱): 멀티프로그래밍이 되면 하나의 CPU를 가지고 여러개의 job을 돌릴수 있음, 프로그램을 여러개 띄운다, 동시성, CPU 스케줄러(CPU 효율성, 다음에 프로세스를 실행시킬게 뭐냐)

- 동시성과 병렬성의 차이를 잘알고 있어야함

- mode of operations

- 유저모드와 커널모드

- 유저 프로세스에서 시스템 콜을 calls -> 커널에서 시스템콜을 실행 -> 유저프로세스로 시스템콜을 리턴 

- 커널모드아니면 직접적으로 하드웨어를 제어를 못함

- Virtualization 가상화 기술 :single computer, OS를 여러개 돌린다. VMM (버츄얼 머신 매니저)

- 컴퓨터 환경이 복잡해진다. 

1. 전통적인 컴퓨팅 -> 모바일 컴퓨팅 - aios , ios

2. 클라이언트, 서버 컴퓨팅(ex Web) -> Peer to Peer 컴퓨팅(P2P) 음악 파일 공유

3. Cloud Computing -> AWS, GCP, Azure, 엣지컴퓨팅, CDN

4. Real-Time Embedded Systems (RTOS, ex Vxworks)

- OS 프로그램의 실행을 위한 환경을 제공

1. User Interface

2. Program exection

3. I/O operation

4. File-system mainpulation

5. Communications

6. Error detection

7. Resource allocation

8. Logging

9. Protection and security

- 이번 학습 내용 :  프로세스/스레드 - 멀티프로세싱 - cpu스케줄링,  동기화 - 데드락 - 메모리 관리 -가상 메모리 관리

- OS 인터페이스 

1.  CLI, 쉘 (sh, bash, csh, tcsh, zsh ,etc)

2.  GUI, 터치 스크린 인터페이스

- 시스템 콜 : OS 제공해주는 서비스를 인터페이스를 제공, API

