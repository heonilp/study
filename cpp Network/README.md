# Network, C++ IOCP, Boost Asio strand공부

- IOCP, Boost Asio strand 공부(면접 질문때 대답못한 것 정리) 

- [참고 사이트](https://developstudy.tistory.com/63)

- TCP 서버/클라 함수,소켓옵션, 니글알고리즘, 용어(RTT, MSS, MTU)

##  OSI 7계층 설명하기

* OSI(Open Systems Interconnection Reference Model)란
    * 국제표준화기구(ISO)에서 개발한 모델로, 컴퓨터 네트워크 프로토콜 디자인과 통신을 계층으로 나누어 설명한 것이다.
    * 이 모델은 프로토콜을 기능별로 나눈 것이다. 
    * 각 계층은 하위 계층의 기능만을 이용하고, 상위 계층에게 기능을 제공한다. 
    * '프로토콜 스택' 혹은 '스택'은 이러한 계층들로 구성되는 프로토콜 시스템이 구현된 시스템을 가리키는데, 프로토콜 스택은 하드웨어나 소프트웨어 혹은 둘의 혼합으로 구현될 수 있다. 
    * 일반적으로 하위 계층들은 하드웨어로, 상위 계층들은 소프트웨어로 구현된다.
1. 물리 계층(Physical layer)
    * 네트워크의 기본 네트워크 하드웨어 전송 기술을 이룬다. 
    * 네트워크의 높은 수준의 기능의 논리 데이터 구조를 기초로 하는 필수 계층이다.
    * 전송 단위는 Bit이다.
2. 데이터 링크 계층(Data link layer)
    * 포인트 투 포인트(Point to Point) 간 신뢰성있는 전송을 보장하기 위한 계층으로 CRC 기반의 오류 제어와 흐름 제어가 필요하다. 
    * 주소 값은 물리적으로 할당 받는데, 이는 네트워크 카드가 만들어질 때부터 맥 주소(MAC address)가 정해져 있다는 뜻이다. 
    * 데이터 링크 계층의 가장 잘 알려진 예는 이더넷이다.
    * 데이터 전송 단위는 Frame이다. 
3. 네트워크 계층(Network layer)
    * 여러개의 노드를 거칠때마다 경로를 찾아주는 역할을 하는 계층으로 다양한 길이의 데이터를 네트워크들을 통해 전달하고, 그 과정에서 전송 계층이 요구하는 서비스 품질(QoS)을 제공하기 위한 기능적, 절차적 수단을 제공한다. 
    * 네트워크 계층은 라우팅, 흐름 제어, 세그멘테이션(segmentation/desegmentation), 오류 제어, 인터네트워킹(Internetworking) 등을 수행한다. 
    * 논리적인 주소 구조(IP), 곧 네트워크 관리자가 직접 주소를 할당하는 구조를 가지며, 계층적(hierarchical)이다.
    * 데이터 전송 단위는 Datagram(Packet)이다.
4. 전송 계층(Transport layer)
    * 양 끝단(End to end)의 사용자들이 신뢰성있는 데이터를 주고 받을 수 있도록 해 주어, 상위 계층들이 데이터 전달의 유효성이나 효율성을 생각하지 않도록 해준다. 
    * 시퀀스 넘버 기반의 오류 제어 방식을 사용한다. 
    * 전송 계층은 특정 연결의 유효성을 제어하고, 일부 프로토콜은 상태 개념이 있고(stateful), 연결 기반(connection oriented)이다. (이는 전송 계층이 패킷들의 전송이 유효한지 확인하고 전송 실패한 패킷들을 다시 전송한다는 것을 뜻한다.) 
    * 가장 잘 알려진 전송 계층의 예는 TCP이다.
    * 데이터 전송 단위는 Segment이다.
5. 세션 계층(Session layer)
    * 양 끝단의 응용 프로세스가 통신을 관리하기 위한 방법을 제공한다. 
    * 동시 송수신 방식(duplex), 반이중 방식(half-duplex), 전이중 방식(Full Duplex)의 통신과 함께, 체크 포인팅과 유휴, 종료, 다시 시작 과정 등을 수행한다. 
    * 이 계층은 TCP/IP 세션을 만들고 없애는 책임을 진다.
6. 표현 계층(Presentation layer)
    * 코드 간의 번역을 담당하여 사용자 시스템에서 데이터의 형식상 차이를 다루는 부담을 응용 계층으로부터 덜어 준다. 
    * MIME 인코딩이나 암호화 등의 동작이 이 계층에서 이루어진다. 
7. 응용 계층(Application layer)
    * 응용 프로세스와 직접 관계하여 일반적인 응용 서비스를 수행한다. 
    * 일반적인 응용 서비스는 관련된 응용 프로세스들 사이의 전환을 제공한다. 


## TCP vs UDP

* 네트워크 계층 중 **전송 계층에서 사용하는 프로토콜**
* TCP(Transmission Control Protocol)  
    * 인터넷 상에서 데이터를 메세지의 형태(**세그먼트** 라는 블록 단위)로 보내기 위해 IP와 함께 사용하는 프로토콜이다.
    * TCP와 IP를 함께 사용하는데, IP가 데이터의 배달을 처리한다면 TCP는 패킷을 추적 및 관리한다.
    * **연결형 서비스로** 가상 회선 방식을 제공한다.
        * 3-way handshaking과정을 통해 연결을 설정하고, 4-way handshaking을 통해 연결을 해제한다.
    * 흐름제어 및 혼잡제어를 제공한다.
        * 흐름제어
            * 데이터를 송신하는 곳과 수신하는 곳의 데이터 처리 속도를 조절하여 수신자의 버퍼 오버플로우를 방지하는 것
            * 송신하는 곳에서 감당이 안되게 많은 데이터를 빠르게 보내 수신하는 곳에서 문제가 일어나는 것을 막는다.
        * 혼잡제어
            * 네트워크 내의 패킷 수가 넘치게 증가하지 않도록 방지하는 것
            * 정보의 소통량이 과다하면 패킷을 조금만 전송하여 혼잡 붕괴 현상이 일어나는 것을 막는다.
    * 높은 신뢰성을 보장한다.
    * UDP보다 속도가 느리다.
    * 전이중(Full-Duplex), 점대점(Point to Point) 방식이다.
        * 전이중
            * 전송이 양방향으로 동시에 일어날 수 있다.
        * 점대점
            * 각 연결이 정확히 2개의 종단점을 가지고 있다.
        * 멀티캐스팅이나 브로드캐스팅을 지원하지 않는다.
    * 연속성보다 신뢰성있는 전송이 중요할 때에 사용된다.

* UDP(User Datagram Protocol)  
    * 데이터를 **데이터그램** 단위로 처리하는 프로토콜이다.
    * **비연결형 서비스로** 데이터그램 방식을 제공한다.
        * 연결을 위해 할당되는 논리적인 경로가 없다.
        * 그렇기 때문에 각각의 패킷은 다른 경로로 전송되고, 각각의 패킷은 독립적인 관계를 지니게 된다.
        * 이렇게 데이터를 서로 다른 경로로 독립적으로 처리한다.
    * 정보를 주고 받을 때 정보를 보내거나 받는다는 신호절차를 거치지 않는다.
    * UDP헤더의 CheckSum 필드를 통해 최소한의 오류만 검출한다.
    * 신뢰성이 낮다.
    * TCP보다 속도가 빠르다.
    * 신뢰성보다는 연속성이 중요한 서비스, 예를 들면 실시간 서비스(streaming)에 사용된다.

* 참고
  * UDP와 TCP는 각각 별도의 포트 주소 공간을 관리하므로 같은 포트 번호를 사용해도 무방하다. 즉, 두 프로토콜에서 동일한 포트 번호를 할당해도 서로 다른 포트로 간주한다.
  * 또한 같은 모듈(UDP or TCP) 내에서도 클라이언트 프로그램에서 동시에 여러 커넥션을 확립한 경우에는 서로 다른 포트 번호를 동적으로 할당한다. (동적할당에 사용되는 포트번호는 49,152~65,535이다.)

## TCP 3 way handshake & 4 way handshake

* TCP는 장치들 사이에 논리적인 접속을 성립(establish)하기 위하여 연결을 설정하여 **신뢰성을 보장하는 연결형 서비스** 이다.
* 3-way handshake 란
  * TCP 통신을 이용하여 데이터를 전송하기 위해 네트워크 **연결을 설정(Connection Establish)** 하는 과정
  * 양쪽 모두 데이터를 전송할 준비가 되었다는 것을 보장하고, 실제로 데이터 전달이 시작하기 전에 한 쪽이 다른 쪽이 준비되었다는 것을 알 수 있도록 한다.
  * 즉, TCP/IP 프로토콜을 이용해서 통신을 하는 응용 프로그램이 데이터를 전송하기 전에 먼저 정확한 전송을 보장하기 위해 상대방 컴퓨터와 사전에 세션을 수립하는 과정을 의미한다.
      * A 프로세스(Client)가 B 프로세스(Server)에 연결을 요청
        1. A -> B: SYN
            * 접속 요청 프로세스 A가 연결 요청 메시지 전송 (SYN)
            * 송신자가 최초로 데이터를 전송할 때 Sequence Number를 임의의 랜덤 숫자로 지정하고, SYN 플래그 비트를 1로 설정한 세그먼트를 전송한다.
            * PORT 상태 - B: LISTEN, A: CLOSED
        2. B -> A: SYN + ACK
            * 접속 요청을 받은 프로세스 B가 요청을 수락했으며, 접속 요청 프로세스인 A도 포트를 열어 달라는 메시지 전송 (SYN + ACK)
            * 수신자는 Acknowledgement Number 필드를 (Sequence Number + 1)로 지정하고, SYN과 ACK 플래그 비트를 1로 설정한 세그먼트를 전송한다.
            * PORT 상태 - B: SYN_RCV, A: CLOSED
        3. A -> B: ACK
            * PORT 상태 - B: SYN_RCV, A: ESTABLISHED
            * 마지막으로 접속 요청 프로세스 A가 수락 확인을 보내 연결을 맺음 (ACK)
            * 이때, 전송할 데이터가 있으면 이 단계에서 데이터를 전송할 수 있다.
            * PORT 상태 - B: ESTABLISHED, A: ESTABLISHED
* 4-way handshake 란
  * TCP의 **연결을 해제(Connection Termination)** 하는 과정
      * A 프로세스(Client)가 B 프로세스(Server)에 연결 해제를 요청
        1. A -> B: FIN
            * 프로세스 A가 연결을 종료하겠다는 FIN 플래그를 전송
            * 프로세스 B가 FIN 플래그로 응답하기 전까지 연결을 계속 유지
        2. B -> A: ACK
            * 프로세스 B는 일단 확인 메시지를 보내고 자신의 통신이 끝날 때까지 기다린다. (이 상태가 TIME_WAIT 상태)
            * 수신자는 Acknowledgement Number 필드를 (Sequence Number + 1)로 지정하고, ACK 플래그 비트를 1로 설정한 세그먼트를 전송한다.
            * 그리고 자신이 전송할 데이터가 남아있다면 이어서 계속 전송한다.
        3. B -> A: FIN
            * 프로세스 B가 통신이 끝났으면 연결 종료 요청에 합의한다는 의미로 프로세스 A에게 FIN 플래그를 전송
        4. A -> B: ACK
            * 프로세스 A는 확인했다는 메시지를 전송

* 참고 - ***포트(PORT) 상태 정보***
  * CLOSED: 포트가 닫힌 상태
  * LISTEN: 포트가 열린 상태로 연결 요청 대기 중
  * SYN_RCV: SYNC 요청을 받고 상대방의 응답을 기다리는 중

  * ESTABLISHED: 포트 연결 상태
* 참고 - ***플래그 정보***
  * TCP Header에는 CONTROL BIT(플래그 비트, 6bit)가 존재하며, 각각의 bit는 "URG-ACK-PSH-RST-SYN-FIN"의 의미를 가진다.
    * 즉, 해당 위치의 bit가 1이면 해당 패킷이 어떠한 내용을 담고 있는 패킷인지를 나타낸다.
  * SYN(Synchronize Sequence Number) / 000010
    * 연결 설정. Sequence Number를 랜덤으로 설정하여 세션을 연결하는 데 사용하며, 초기에 Sequence Number를 전송한다.
  * ACK(Acknowledgement) / 010000
    * 응답 확인. 패킷을 받았다는 것을 의미한다.
    * Acknowledgement Number 필드가 유효한지를 나타낸다.
    * 양단 프로세스가 쉬지 않고 데이터를 전송한다고 가정하면 최초 연결 설정 과정에서 전송되는 첫 번째 세그먼트를 제외한 모든 세그먼트의 ACK 비트는 1로 지정된다고 생각할 수 있다.
  * FIN(Finish) / 000001
    * 연결 해제. 세션 연결을 종료시킬 때 사용되며, 더 이상 전송할 데이터가 없음을 의미한다.

#### :question:TCP 관련 질문 1
* Q. TCP의 연결 설정 과정(3단계)과 연결 종료 과정(4단계)이 단계가 차이나는 이유?
  * A. Client가 데이터 전송을 마쳤다고 하더라도 Server는 아직 보낼 데이터가 남아있을 수 있기 때문에 일단 FIN에 대한 ACK만 보내고, 데이터를 모두 전송한 후에 자신도 FIN 메시지를 보내기 때문이다.


#### :question:TCP 관련 질문 2
* Q. 만약 Server에서 FIN 플래그를 전송하기 전에 전송한 패킷이 Routing 지연이나 패킷 유실로 인한 재전송 등으로 인해 FIN 패킷보다 늦게 도착하는 상황이 발생하면 어떻게 될까?
  * A. 이러한 현상에 대비하여 Client는 Server로부터 FIN 플래그를 수신하더라도 일정시간(Default: 240sec)동안 세션을 남겨 놓고 잉여 패킷을 기다리는 과정을 거친다. (TIME_WAIT 과정)


#### :question:TCP 관련 질문 3
* Q. 초기 Sequence Number인 ISN을 0부터 시작하지 않고 난수를 생성해서 설정하는 이유?
  * A. Connection을 맺을 때 사용하는 포트(Port)는 유한 범위 내에서 사용하고 시간이 지남에 따라 재사용된다. 따라서 두 통신 호스트가 과거에 사용된 포트 번호 쌍을 사용하는 가능성이 존재한다. 서버 측에서는 패킷의 SYN을 보고 패킷을 구분하게 되는데 난수가 아닌 순처적인 Number가 전송된다면 이전의 Connection으로부터 오는 패킷으로 인식할 수 있다. 이런 문제가 발생할 가능성을 줄이기 위해서 난수로 ISN을 설정한다.


## TCP 서버/클라 함수

<div>
<img src="https://github.com/heonilp/study/blob/master/cpp%20Network/pc/1.PNG" width="60%"></img>
</div>

### 서버 흐름
   - 윈속 초기화
   - socket함수를 이용하여 listen_sock이라는 소켓함수 생성
   - bind함수를 이용하여 서버의 지역 IP주소와 포트번호 9000번을 설정
   - listen함수를 이용하여 클라이언트의 connect요청이 있을 때까지 대기하며 SOMAXCONN 수만큼 소켓생성
     가능(SOMAXCONN = 0x7FFFFFFF)
   - accept함수를 이용하여 클라이언트와 통신이 가능하도록 새로운 client_sock 소켓 생성
   - recv함수를 이용하여 데이터를 수신하고 출력
   - send함수를 이용하여 데이터 전송
   - closesocket함수를 이용하여 위에서 만든 client_sock와 listen_sock 소켓을 소멸
   - 윈속 종료

### 클라이언트 흐름
   - 윈속 초기화
   - socket함수를 이용하여 sock이라는 소켓함수 생성
   - connect함수를 이용하여 서버에 접속 요청하고 하나의 컴퓨터상에서 서버와 클라이언트를 실행한다는 가정
      하에 IP주소를 roll back하는 127.0.0.1을 사용하고 포트번호는 9000번으로 설정
   - send함수를 이용하여 데이터 전송
   - recv함수를 이용하여 데이터 수신
   - closesocket함수를 이용하여 위에서 만든 sock소켓 소멸
   - 윈속 종료

## TCP 소켓 옵션

- setsockopt
소켓의 송수신 동작을 setsockopt() 함수를 이용해서 다양한 옵션으로 제어할 수 있습니다.

``` C++
int setsockopt(SOCKET socket, int level, int optname, const void* optval, int optlen);

socket : 소켓의 번호
level : 옵션의 종류. 보통 SOL_SOCKET와 IPPROTO_TCP 중 하나를 사용
optname : 설정을 위한 소켓 옵션의 번호
optval : 설정 값이 저장된 주소값.
optlen : optval 버퍼의 크기
```

- SOL_SOCKET 레벨 : setsockopt() 함수의 level에 들어갈 값입니다.

1. SO_REUSEADDR	BOOL	이미 사용된 주소를 재사용하도록 함
2. SO_RCV_BUF	int	수신용 버퍼의 크기 지정
3. SO_SND_BUF	int	송신용 버퍼의 크기 지정
4. SO_RECVTIMEO	DWORD(timeval)	수신시 Blocking 제한 시간을 설정
5. SO_SNDTIMEO	DWORD(timeval)	송신시 Blocking 제한 시간을 설정
6. SO_KEEPALIVE	BOOL	TCP 통신에서만 유효. 일정 시간마다 연결 유지 상태를 체크.
7. SO_LINGER	struct LINGER	소켓을 닫을 때 남은 데이터의 처리 규칙 지정
8. SO_DONTLINGER	BOOL	소켓을 닫을때 남은 데이터를 보내기 위해서 블럭되지 않도록 함
9. SO_DONTROUTE	BOOL	라우팅(Routing)하지 않고 직접 인터페이스로 전송
10. SO_BROADCAST	BOOL	브로드캐스트 사용 가능 여부


- 중요 한것 알기

1. SO_LINGER 옵션
linger 구조체는 다음과 같은 형태로 되어 있습니다.

``` C++
struct linger {
  int l_onoff;
  int l_linger;
}

l_onoff : linger 옵션의 On/Off 여부
l_linger : 기다리는 시간
위의 두 개의 변수 값에 따라 3 가지의 close 방식이 존재합니다.

l_onoff == 0 : 소켓의 기본 설정 l_linger에 관계없이 버퍼에 있는 모든 데이터를 전송. 
close()는 바로 리턴을 하지만 백그라운드에서 이러한 작업이 이루어짐.

l_onoff > 0, l_linger == 0 : close()는 바로 리턴하며, 버퍼에 있는 데이터는 버림.
 TCP 연결 상태에서는 상대편 호스트에게 리셋을 위한 RST 패킷 전송. hard 혹은 abortive 종료라고 부름.

l_onoff > 0, l_linger > 0 : 버퍼에 남아있는 모든 데이터를 보내며, 그 동안 close()는 블럭되어 대기함.
```


2. SO_REUSEADDR 옵션
- 소켓 사용시 만약 다음과 같은 에러가 발생하는 경우가 있습니다. bind error : Address already in use

보통 소켓을 사용하는 프로그램은 강제 종료되었지만, 커널단에서 해당 소켓을 바인딩해서 사용하고 있기 때문에 발생하는 에러입니다.
이 경우 SO_REUSEADDR 옵션을 이용해서 기존에 바인딩된 주소를 다시 사용할 수 있게 할 수 있습니다.

3. TCP_NODELAY 옵션
IPPROTO_TCP 레벨의 옵션이며, TCP 소켓에서만 사용할 수 있습니다.

소켓에 네이글 알고리즘(Nagle Algorithm)을 사용할지 여부를 지정. 
TRUE인 경우 알고리즘을 사용하지 않음. 알고리즘을 사용하지 않을 경우 실제 전송까지의 지연 시간이 줄어듬.

``` C++
int opt_val = TRUE;
setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &opt_val, sizeof(opt_val));

값이 1 또는 TRUE인 경우 네이글 알고리즘을 사용하지 않습니다. 값이 2 또는 FALSE인 경우 네이글 알고리즘을 사용합니다.

```
## 니글 알고리즘

- [참고](https://ozt88.tistory.com/18)

IP 네트워크에서 데이터는 몇 곂의 헤더로 캡슐화되어 목적지로 보내진다. 이 헤더들의 용량도 제법 커서, 적은 데이터를 보내게되면 배보다 배꼽이 커지는 경우가 발생한다. 고의로 작은 단위의 데이터를 전송하는 경우도 있겠지만, 의도치 않게 네트워크 상황상 비효율적인 송신을 해야하는 경우가 있다. 

예를 들면 전송해야될 데이터가 있는데, 상대방의 윈도우 크기(전송 받을 수 있는 크기)가 매우 작은 경우. 
내가 의도한 바는 아니지만 보낼 수 있는 패킷의 크기 자체가 작기 때문에 따로 지연 설정을 하지 않으면, 작은 크기의 패킷이 만들어질 수 밖에 없다.

**보낼 수 있는 데이터를 바로 패킷으로 만들지 않고, 가능한 모아서 더 큰 패킷으로 만들어 한번에 보내면** 이런 문제는 발생하지 않을 것이다. 
네이글 알고리즘은 이 대안을 실제로 구현한 네트워크 전송 알고리즘이다. 

<div>
<img src="https://github.com/heonilp/study/blob/master/cpp%20Network/pc/2.PNG" width="60%"></img>
</div>

1. 상대방이 받을 수 있는 사이즈(window size)와 내가 보낼 데이터가 MSS보다 크다면 문제없이 바로 전송한다. 

2. 더 이상 SEND 처리할 데이터가 없다면 현재 있는것 그대로 보낸다.

3. 둘다 아니라면, 아래의 그림 (Nagle On) 처럼 동작한다.

네이글이 최대한 작은 크기의 패킷 전송을 지연시키는 기능을 할 수 있는 것은 3번 경우에 대한 처리 덕분이다.
기존의 네트워크 환경에서는 데이터가 버퍼에 조금씩 쌓이게 되면, Nagle off의 그림처럼 상대방의 ACK를 기다리지 않고 바로바로 작은 패킷을 전송한다. 
네이글은 이런 작은 패킷을 가능한 지연시키기 위하여, ACK가 올때까지 전송을 중지하고 ACK가 도착한 시점에, 지금까지 버퍼에 모인 데이터를 패킷으로 만들어서 전송한다. 

ACK를 기다리는 지연방식으로 네이글은 작은 패킷을 연속해서 보내는 네트워크의 비효율을 극복하였다.
하지만 이런 지연방식을 사용하면 위 그림처럼 데이터 전송속도가 더 늦다. 


### 네트워크 게임에서 네이글 알고리즘 왜쓰는가?

서버의 경우는 클라이언트와 다르다. 서버는 클라이언트에게 현제 유저가 처한 게임 상황의 결과를 지속적으로 보내줄 것이다. 
이 정보는 패킷 크기에 비해 헤더 크기가 비대해 보이지 않을 정도로 충분히 큰 양의 데이터일 것이며, 지속적으로 갱신해서 보내주는 데이터가 될 것이다.
이러한 데이터가 네이글 알고리즘에 의해 지연되는 경우는 클라이언트의 가용 윈도우 사이즈가 충분히 크지 않은 경우가 될 것이다. 
클라이언트의 처리 능력이 원활하지 않은 경우 계속해서 데이터를 잘라서 우겨넣는것이 유저가 체감하는 반응성에 큰 영향을 미칠 것이라 생각하지 않는다.
또한 동시에 여러 클라이언트가 사용하는 서버에서 트래픽이슈는 민감한 부분이기 때문에, 네이글 알고리즘을 사용했을때 얻는 이득이 더 크지 않을까 생각해본다.




## L2~L7 스위치 특징, L4 vs L7 스위치

- L2 스위치(Switch)

가장 원초적인 형태의 스위치는 L2 스위치이다.
본래의 스위치 정의에 가장 부합하는 것이 L2 스위치이므로 L2 스위치를 그냥 스위치라고 부르기도 한다. 

스위치는 허브에서 한 단계 진화한 것일 뿐이다.
패킷이 왔을때 그것의 목적지가 어디인가를 보고 그 목적지로 보내주는 역할만을 한다. 
말 그대로 '스위치'일 뿐이다. 

Layer 2(Data link Layer)의 프로토콜인 이더넷, 프레임릴레이, ATM 등에서 스위칭 기능을 수행한다.
Layer 2 에서 동작하므로 목적지는 Ethernet 주소로 이해한다. 즉, IP 주소가 필요한 외부로 보내줄 수 없다. 

- L2 Switch 의 한계 
OSI 7 Layer 에서 Layer 2 레벨은 Data Link Layer 이므로 L2 스위치는 Ethernet 레벨에서 동작할 뿐 그 상위 레이어인
Network Layer 에서 동작하는 IP 등을 이해하지 못한다. 다시말해 IP 어드레스를 이해하지 못하므로 라우팅이 불가능하다.
(Router 라는 것이 외부와 연결되므로 IP 어드레스를 알아야 함을 기억하면 이것은 당연한 것이다.)

- Example

A에서 보낸 패킷이 포트 1로 들어왔다고 가정하자.
L2 스위치는 포트 1 쪽에 A가 연결되어 있다는 정보를 얻게 된다.
그래서 나중에 A로 보내져야 할 패킷이 들어오면 포트 1으로 내보내게 된다.
다시 말해서, 단순한 포트에 대한 연결 정보만 있다. 

- L3 스위치(Switch) 
L3 에서는 L2 와 달리 매우 넓은 범위까지 다루게 된다.
그래서 오가는 패킷을 관찰해서는 충분한 정보를 얻을 수 없으므로 L3 스위치끼리 통신을 하면서 정보를 축적하게 된다.

L3 에서는 Layer 3(Network layer)의 프로토콜인 IP, IPX 등에서 스위칭 기능을 수행한다.
그래서 자신에게 온 패킷의 destination 이 외부에 존재하는 IP 일 경우 그 패킷을 외부에 연결된 라우터로 보내줄 수 있다. 
즉, L3 스위치는 라우터 기능도 갖고 있기 때문에 라우터와의 경계가 모호해진다.
이 경우 라우팅 기능을 스위치가 가지게 된다.

- Example

포트 1에 연결되어 있는 스위치가 여기에는 패킷이 많이 몰린다는 내용을 보낸다면
그 내용을 받은 스위치는 패킷을 포트 1 대신 다른 포트로 보내게 된다.

- 스위치 : L2, Mac Address, Hardware 동작
- 라우터 : L3, IP Address, Software 동작

- L4 스위치(Switch) 

L4 에서는 Layer 4(Transport Layer)의 프로토콜인 TCP, UDP 등을 스위칭한다.
이때 TCP와 UDP 그리고 RTP(Real Time Protocol) 등의 헤더를 사용하여(보고) FTP, HTTP, TFTP. SMTP 등의 프로토콜 중
 어느 것에 대한 요구가 우선하는지 파악한 후 스위칭하게 된다. (다시 말해, TCP와 UDP 등의 헤더를 보고 
 그것이 FTP 인가 HTTP 인가 SMTP 인가를 판단하여 어떤 것을 우선시해서 스위칭할지 판단할 수 있다.) 
즉, 로드 밸런싱이 가능해진다는 얘기인데 이는 L3 이하에서는 불가능한 것이다. 
여러대의 서버에 똑같은 컨텐츠를 탑재하는 경우는 L4에서 서버의 부하를 체크해서 가장 여유있다고 판단되는 쪽으로 보내게 된다. 
(정책이 여러개 있는데, 이 방식을 가장 많이 사용한다)
이런 이유로 서버와 연동시켜 해당 서비스를 제공하는 서버로 연결하는 스위치로 이용된다
일반 기업에서 ERP서버나 업무용서버를 운영할 때 많이 사용하는 방식이다.
서버별로 컨텐츠가 다르다면, L4에서 정책을 세워서 해당 서비스에 대한 요청이 오면 등록된 서비스로 보내주어서 
전체 부하를 분산시키는 방식을 사용한다. 대형 포탈의 경우 이런 방식을 사용하게 된다.
그리고 대부분 DB서버는 L4를 거치지 않고 웹서버와 직접 연결시켜서 사용한다. 
DB서버 분산하는게 쉽지 않기 때문에 DB를 L4에 물리는 경우는 드물다.


- L7 스위치(Switch) 

L7 스위치는 OSI 의 Layer 7. 즉, 어플리케이션 레이어에서 동작하는 것으로 이를테면 이메일의 제목이나 문자열을 보고 내용을 파악한다거나
 HTTP 의 URL, 또는 FTP의 파일명, 쿠키 정보, 특정 바이러스의 패턴 등을 분석해서 보안에 더욱 유리하고 더욱 정교한 로드 밸런싱이 가능해진다.
사실 어플리케이션 레벨의 데이터를 다 다룬다는 것은 불가능하고 L7 스위치는 단지 패킷의 내용을 조금 더 참조하여 약간 intelligent 한 결정을 내릴 수 있게 된 것 뿐이다. 쉽게말해 L7 스위치라는 것은 마케팅용어라고 볼 수 있다.


※ 상위 레벨에서 동작하는 스위치는 자신의 하위 레벨 스위치의 기능을 다 갖고 있다.
※ 예를 들어 L4 스위치는 L3, L2 스위치의 기능도 다 수행할 수 있다.



## 네트워크 및 서비스 네트워크 용어

- RTT (Round-Trip Time) :  네트워크 시작 지점에서 대상 지점으로 이동하고 시작 지점으로 다시 이동하는 데 걸리는 시간 (밀리 초 ms)입니다. 

- MTU(Maximum Transmission Unit) : TCP/IP네트워크 등과 같이 패킷 또는 프레임 기반의 네트웍에서 전송될 수 있는 최대 크기의 패킷 또는 프레임을 말합니다.

- MSS (Maximum Segment Size) : TCP상( TCP/UDP 가 아니라 그냥 TCP입니다 )에서의 전송할 수 있는 사용자 데이타의 최대크기입니다.

```
MSS 값은 기본적으로 설정된 MTU 값에 의해 결정됩니다.

MSS= MTU-(IP header크기) - (TCP header크기)

```

- CCU (Concurrent User) : 특정 시점에 접속한 동시 접속자 수

- MCU (Maxium Concurrent User) : 하루 동안 가장 높은 동시 접속자 수치.

- PCU (Peak Concurrent User) : MCU 동일어

- ACU (Average Concurrent User) : 1일 동안의 평균 동시 접속자 수

- Stickness : 고착도 (DAU/MAU)/100

- MTS (Mutigame Time Spent): 해당 기간 동안의 평균 실제 플레이 타임
 
- TS(Time Spent) : 해당기간 동안의 유저1 인당 플레이 타임

- RX  :Receive Data의 약자. 네트워크에서 데이터 수신을 의미한다.

- TX : Transmit Data의 약자. 네트워크에서 데이터 전송을 의미한다.


## 동기 vs 비동기 방식 설명

- iocp는 비동기적, select는 동기적. 

select는 선택한 이벤트를 처리 가능할 때를 기다리는. iocp는 처리할 작업을 등록하는 방식.

select는 반환이 되더라도 완료가 된 것이 아닌, 처리가 가능할 때를 의미(또는 타임아웃). 

iocp는 작업을 등록하고 완료를 통지받는 것. 때문에 select의 경우 수신을 걸더라도 버퍼를 등록할 필요가 없고, iocp는 데이터를 담을 버퍼가 필요한 것.


## IOCP 설명

- IOCP 개념

- IOCP는 Window 환경에서 작동하는 제일 흔히 쓰이는 논블로킹 프로세스이다.

- 동기화오브젝트 세마포어의 특성과 큐를 가진 커널오브젝트

- Input Output Completion Port로I/O 처리 완료를 담당하는 포트

- OS 커널 단에서 IO 처리

- Work Thread를 Leader/Follow 패턴을 따르는 Thread Pool로 사용하여최소화의 Context Switching 발생

- 유저 모드에서 Send, Receive 요청 -> OS 커널 단에서 IO 처리 -> 완료 후 Queue에 담김
 -> 작업하고 있지 않은 Work Thread를 깨움 -> 작업 진행

이전 멀티쓰레드형 서버의 문제는 컨텍스트 스위칭 비용이었다. 하지만 CPU개수만큼만 쓰레드를 사용한다면, 컨텍스트 스위칭 문제는 크게 문제가 되지 않는다. 그러니까 우리는 딱 CPU개수만큼만 쓰레드를 쓰는 서버를 만들고 싶다. 이 막연한 희망사항에 긍정적으로 대답해주는 것이 바로 윈도우의 IOCP이다.


- IOCP 함수

- 디바이스 리스트

I/O 처리를 하려면 우선 I/O 디바이스(소켓, FD) IOCP에 등록을 해야한다. CreateIoCompletionPort 함수를 통해서 디바이스와 CompletionPort(이하 CP)를 바인딩한다. 그런데 CraeteIoCompletionPort 함수의 이름을 다시 한번 생각해보면 디바이스에 바인딩하는 것과는 조금 의미가 다른것 같다. 실제로 이 함수는 두가지 기능을 한다. 첫 번째는 통지모델인 CP를 생성하고 그 핸들을 반환하는 것. 두 번째는 위에서 말한것처럼 디바이스와 CP를 바인딩하는것. 하나의 함수로 서로다른 두 가지 일을 하니, 가능하다면 다른 이름의 함수로 싸서 사용하는게 좋을 듯 하다.
``` C+++
HANDLE WINAPI CreateIoCompletionPort(
  _In_      HANDLE FileHandle,
  _In_opt_  HANDLE ExistingCompletionPort,
  _In_      ULONG_PTR CompletionKey,
  _In_      DWORD NumberOfConcurrentThreads
);
```

함수의 signature는 위와 같다. 첫번째 인자에 I/O 디바이스의 핸들을, 두 번째 인자에 CP의 핸들을 넘겨서 사용한다. 세 번째 인자인 Key에는 유저가 원하는 데이터를 넘겨서, I/O 통지때 같이 받을 수 있다. 디바이스(소켓) 정보가 담긴 객체(ex: 세션)를 넘겨서 사용하면 편리하다. 네번째 인자는 동시에 작동할 쓰레드의 최대 수를 정하는데 사용된다. 우리의 목표는 CPU개수만큼 쓰레드를 쓰는 것이므로 여기에 CPU 개수를 집어넣으면 OK다. 물론 MS도 많은 이들이 같은 목표를 공유한다는 사실을 잘 알기 때문에 0만 넣어도 CPU개수로 척척 맞춰준다. 

HANDLE hPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
CP를 처음 만들때는 위와 같이 하면 된다. CP의 핸들이 반환된다. 이 핸들은 앞으로 종종 사용되니 잘 보관한다.

``` c++
HANDLE port = CreateIoCompletionPort(socket, hPort, (ULONG_PTR)session, 0);
```
디바이스와 연결할 떄는 위와 같이 사용한다. Key는 디바이스에 고유한 정보를 넣어주면 편리하게 쓸 수 있다.


- I/O Completion Queue

완료된 I/O들의 정보가 저장되는 대기큐. I/O 완료시 말고도 유저가 직접 PostQueuedCompletionStatus 함수(이하 PQCS)를 호출하여 정보를 직접 집어 넣을 수도 있다. 이 함수를 보면 어떤 정보가 전달되는지 잘 알 수 있다. 
``` c++
BOOL WINAPI PostQueuedCompletionStatus(
  _In_      HANDLE CompletionPort,
  _In_      DWORD dwNumberOfBytesTransferred,
  _In_      ULONG_PTR dwCompletionKey,
  _In_opt_  LPOVERLAPPED lpOverlapped
);
```
통지할 CP를 인자를 결정한다. I/O의 경우 이미 I/O 디바이스와 바인딩된 CP에 전달 될 것이다. 그리고 전송된 바이트의 크기와 Key를 넘길 수 있다. I/O의 경우 디바이스 바인딩할 때 미리 넣어둔 그 Key가 전달된다. 마지막으로 버퍼가 담긴 Overlapped 구조체를 넘겨줄 수 있다. 기존 Overlapped I/O 함수에서 전달하는 Overlapped 구조체가 이에 해당한다. 위에서 언급한 정보들을 활용하면 완료된 I/O에 대해서 충분히 잘 처리할 수 있다. 이렇게 전달한 정보들은 I/O가 완료되면 Completion Queue 에 저장되어 쓰레드가 나타나 자신을 처리해주기만을 기다리게 된다.

- Waiting Thread Queue

쓰레드들이라고 노는건 아니다. 다만 바쁘거나 나설 자리가 없을 뿐 (우리가 활성화할 쓰레드 개수를 제한한 것을 잊지말자). 사용자는 쓰레드를 만들어 대기상태로 만들어야 한다. 이때 사용하는 함수가 GetQueuedCompletionStatus (이하 GQCS) 이다. 이름만 보면 바로 I/O 정보를 뽑아올 것 같지만, 우리가 앞에서 말했던것을 곰곰히 생각해보면 왜 그러면 안되는지를 알 수 있을 것이다. 정보를 받아 올 수 있는 상황이 될때까지, 즉 자신이 올라갈 빈 CPU공간이 있고(허용된 활성화 쓰레드 > 현재 활성화된 쓰레드) && 자신을 필요로 하는 완료된 I/O가 있는 경우에 비로소 이 정보를 받아 올 수 있다. 이런 조건이 맞아 떨어지지 않으면, 설정한 timeout까지 이 쓰레드는 대기상태가 된다. 

- Release Thread List

대기상태가 풀리고 쓰레드가 활성화 됬다는 것은 (timeout 제외), 드디어 I/O를 처리할 수 있다는 뜻이다. I/O장치 또는 PQCS로 보낸 정보를 GetQueuedCompletionStatus 함수를 통해서 받아온다.

``` C++
BOOL WINAPI GetQueuedCompletionStatus(
  _In_   HANDLE CompletionPort,
  _Out_  LPDWORD lpNumberOfBytes,
  _Out_  PULONG_PTR lpCompletionKey,
  _Out_  LPOVERLAPPED *lpOverlapped,
  _In_   DWORD dwMilliseconds
);

```
생긴것을 보면 딱 Post와 짝이다. 마지막 인자는 미리 언급한 timeout 설정 시간이다. 마음껏 I/O 처리를 하고난 다음 다시 GetQueuedCompletionStatus를 호출하면 다시 대기상태로 들어간다. 이 함수를 다시 호출하지 않으면 다른 쓰레드가 동작할 수 없으니 조심해야한다. 

- Paused Thread List

엄밀히 말하자면 Released Thread Queue의 마지막 문장은 잘못되었다. Released List에 있는 쓰레드, 즉 활성화된 쓰레드 중에서 Blocking 상태에 빠진녀석들을 제대로 처리하지 않는다면 비효율적이다. GQCS를 호출하지 않아도 쓰레드가 Blocking상태에 빠지면, IOCP는 똑똑하게 그것을 감지하여 이 Paused Thread List에 집어넣는다. 그러면 가용 쓰레드 공간이 늘어나서 CPU가 필요한 다른 쓰레드에게 리소스를 양도할 수 있는 것이다. 



- IOCP 다른 모델 비교, 스레드, 워커스레드 등

1. IOCP

- Input Output Completion Port로I/O 처리 완료를 담당하는 포트
- OS 커널 단에서 IO 처리
- Work Thread를 Leader/Follow 패턴을 따르는 Thread Pool로 사용하여최소화의 Context Switching 발생
- 유저 모드에서 Send, Receive 요청 -> OS 커널 단에서 IO 처리 -> 완료 후 Queue에 담김
 -> 작업하고 있지 않은 Work Thread를 깨움 -> 작업 진행

2. Select

- Select의 경우는 모든 FD( 파일 디스크립터 )를 순회 하면서 작업( Read/ Write/ Error)이 있는지 확인 하는 모델

select의 정체성

select를 사용해서 I/O의 상황을 알기 위해서는 프로세스가 커널에게 직접 상황 체크를 요청해야한다. 
프로세스가 커널의 상황을 지속적으로 확인하고 
그에 맞는 대응을 하는 형태로 구성되기 때문에 프로세스와 커널이 서로 동기화된 상태에서 
정보를 주고 받는 형태로 볼 수 있다. 따라서 select의 통지형태를 동기형 통지방식이라 부를 수 있다. 

그리고 select 그 자체는 I/O를 담당하지 않지만, 통지하는 함수의 호출방식이 timeout에 따라 
non-blocking 또는 blocking 형태가 된다. timeout을 설정하지 않으면, 관찰 대상이 변경되지 않는 이상 
반환되지 않으므로 blocking 함수가 되고, timeout이 설정되면 주어진 시간이 지나면 시간이 
다되었다는 정보를 반환하므로 non-blocking 함수가 된다. 
따라서 전체 파일디스크립터를 순회하면서 FD_ISSET을 하는 문제는 더이상 발생하지 않는다.

- epoll의 정체성
epoll은 select의 단점을 많이 개선한 형태의 통지방식이다. 
FD_SET을 운영체제가 직접 관리하는 것으로 많은 부분이 개선되었다.
 하지만 그 본질적인 동작 구조는 select와 크게 다르지 않다. 
프로세스가 커널에게 지속적으로 I/O 상황을 체크하여 동기화 하는 개념은 여전히 유효하다.
 따라서 epoll의 통지모델 역시 동기형 통지모델이다. 
그리고 timeout개념이 select와 동일한 방식으로 동작하기 때문에 timeout에 들어온 인자가 어떠냐에 따라
 blocking이기도 하고 non-blocking이기도 하다. 따라서 epoll의 전체적인 개념모델은 select와 같다고 생각한다.

3.EPoll
-Event Poll로 FD( 파일 디스크립터 )들을 OS 단에서 관리하며 유저 모드에서 처리 할 내용이 있는지 확인

<div>
<img src="https://github.com/heonilp/study/blob/master/cpp%20Network/pc/3.PNG" width="60%"></img>
</div>

1. 비동기 I/O 시작
동기 함수(Connect Close Accept Send)과 같은 역할을 하는 비동기 함수들(AccpetEX, WSASend, WSARecv...)을 실행해서 윈도우 I/O에 넘긴다. 이 동작을 거친 뒤에는 프로그램의 흐름이 다시 호출한 쓰레드로 바로 돌아온다. (비동기)

2. 비동기 입출력 완료
비동기 입출력이 윈도우 I/O에서 종료되면 IOCP라는 항구(Port)에 쌓이게 되는데 이 쌓이는 자료구조는 Queue 이다.

3. GetQueuedCompletionStatus
쓰레드 중에서 작업이 끝난, 그러니까 할 일이 없는 쓰레드에서 GetQueuedCompletionStatus를 호출하면 IOCP에서 완료된 내용을 꺼내서 받을 수 있다.


<div>
<img src="https://github.com/heonilp/study/blob/master/cpp%20Network/pc/4.PNG" width="60%"></img>
</div>

1. 작업자 쓰레드(Worker Thread)
[IOCP 흐름]  여러 개의 쓰레드가 존재하는데 IOCP에서는 이 쓰레드를 작업자 쓰레드라고 부른다.

2. Overlapped
Overlapped는 본래 IOCP가 아닌 Overlapped 모델에서 사용하는 구조체이다.
이 구조체를 이해하기 위해서는 Overlapped 모델에 대한 설명을 한번 읽어보는 것이 좋다.
[Overlapped 모델에 대한 설명](https://www.joinc.co.kr/w/Site/win_network_prog/doc/overlapped)

비동기 Recv()를 예로 들자면

1. Overlapped을 초기화(비워줌)해서 넘겨줌.
2. Window I/O에서 Overlapped의 비동기 입출력 결과(위 그림에서는 완료?)와 버퍼가 채워짐.
3. Recv()의 결과를 받는 부분에서 채워진 결과를 토대로 처리.
와 같은 방식으로 사용된다.


Overlapped는 사용자가 커스터마이징이 가능해서 Overlapped에  정보를 같이 담아서 보내고, 수신받을 때 결과를 분석하는 데 사용할수 있다.


## C++ Boost Asio 설명


- C++ Boost Asio 개념

 Boost.Asio는 주로 네트워킹과 몇몇 다른 저수준의 입력/출력 프로그래밍을 위한 크로스 플랫폼 C++ 라이브러리이다.
Boost.Asio는 네트워킹 뿐만 아니라 COM 시리얼 포트, 파일 등등을 위해 동작하는 입력과 출력의 개념을 성공적으로 추상화시켰다. 이들 위에서, 여러분은 입력 혹은 출력 프로그래밍을 동기적으로 혹은 비동기적으로 할 수 있다.
이 라이브러리는 이식 가능하고 대부분의 운영체제에 걸쳐서 동작하며, 수천의 동시 접속을 넘어 잘 확장된다. 네트워킹 부분은 BSD 소켓으로부터 영감을 받았다. 
이것은 TCP 소켓, UDP 소켓, ICMP 소켓들을 다루는 API를 제공하며, 여러분이 원한다면 여러분 자신만의 프로토콜로 확장시킬 수 있다.

- C++ Boost Asio 함수
예전에 추천 받았던 CPPCON 영상이며 설명이 잘되있습니다.
[C++ Boost ASIO CPPCON 강의영상](https://www.youtube.com/watch?v=rwOv_tw2eA4)

## - C++ Boost Asio 스레드 , 워커스레드, strand 설명 

- [strand 설명 영어 사이트](https://www.crazygaze.com/blog/2016/03/17/how-strands-work-and-why-you-should-use-them/)
- [strand 설명 해석 사이트](https://blog.naver.com/njh0602/220715956896)
- [많이 참고한 사이트](https://developstudy.tistory.com/63)
- [boost Asio 참고사이트](https://popcorntree.tistory.com/154)

- Strand는 어떤 작업을 핸들러 단위로 쪼개서 멀티 스레드로 수행하는 것이다.
예를 들어 일반적인 온라인 게임 서버에서 동기화 단위는 Room일 것이다. Room 밖에서 서로 통신하는 일이 없는 이상, Room 별로 동기화하고, 나머지는 굳이 동기화하지 않아도 되기 때문이다.

그래서 이 Room을 핸들러 단위로 하고, Strand를 사용하면 명시적인 Lock 없이 멀티스레딩 수행이 가능해진다.

그림으로 보면 이해가 더 쉬울테니 그림으로 나타내 보았다.
<div>
<img src="https://github.com/heonilp/study/blob/master/cpp%20Network/pc/6.PNG" width="60%"></img>
</div>

Lock을 사용하면 그림과 같이 같은 핸들러(mutex)를 동기화시키기 위해서 끝날 때까지 대기해야 한다. 이때, Strand를 사용하면 다음과 같이 수행이 가능하다.
<div>
<img src="https://github.com/heonilp/study/blob/master/cpp%20Network/pc/7.PNG" width="60%"></img>
</div>

Strand를 사용하면 같은 핸들러(Room)가 겹치지 않게 Strand가 알아서 함수를 실행시켜 준다. 심지어 Strand 별로 호출 순서도 보장해준다.

지금은 간단히 룸이 2개에 스레드가 2개여서 굳이? 스럽지만, 룸이 몇백몇천개고 스레드가 몇십 개가 됐을 때 Room을 동기화 하기 위해서 여기저기 Lock을 거는 것은 끔찍한 일이 아닐 수 없는데, Strand를 사용하면 명시적인 Lock 없이도 멀티 스레드 프로그래밍이 가능해진다

- Strand 사용법 (개념)

 프로그램을 실행하게 되었을 때 Socket에 IP주소와 Port 번호를 등록하고 이를 io_service(1.66 버전 이후에서는 io_context)에 이 때 handle_connect, handle_read, handle_write와 같은 handler 또한 함께 등록합니다. 이 때 등록된 handler는 server 혹은 client에서 실행되었을 때 바로 handler를 실행하는 방법으로 어느 한 쪽으로부터 데이터 전달을 기다리지 않고 있다가 요청이 들어왔을 때 실행하는 것


먼저 준비해야하는 것이 io_context이다. iocp할 때도 iocp 객체 핸들 하나를 만들었다. 마찬가지로 asio는 io_context라는 객체를 만들어서 얘를 통해 io를 한다. 클래스다.  
그리고 당연히 asio도 socket api니까 socket이 필요하다. 근데 우리가 소켓 프로그래밍에 쓰던 socket이 아니라 그냥 이름만 socket인 클래스이다. io_context 객체 하나 만들어서 사용해야하고. 여러개 만들어도 되는데 굳이 그럴 필요는 없다. 소켓은 뭐냐면, boost/asio에 있는 boost::asio::ip::tcp::socket socket(io_context); 이 소켓 객체를 이용해야 하고 이 객체를 만들 때 파라미터로 io_context를 넣어줘야한다. iocp할 때 소켓을 iocp에 등록했던 것 처럼, 이렇게 연결을 해준다. 

<div>
<img src="https://github.com/heonilp/study/blob/master/cpp%20Network/pc/5.PNG" width="60%"></img>
</div>

- IOCP vs BOOST asio 차이

- PostQueuedCompletionStatus / post (하는 일이 같다)

- post()와 dispatch()의 차이 
post()는 단순히 핸들러를 io_service 내부에 추가, 
dispatch()는 호출될 때 호출 스레드 io_service:: run(), poll() 등을 통해 실행되었다면 
dispatch한 핸들러를 io_service 내부에 추가하지 않고, 즉시 실행. 

- 밑에 로직이 같다.

``` C++
worker_thread()
{
    GQCS( g_iocp , ... );
    if (is_recv)
        ProcessBuffer();
}
```
``` C++
worker_thread()
{
    io_context->run();
}

```


## HTTP 1.1 vs 2.0

- [참조](https://ijbgo.tistory.com/26)

- TTP/1.1 동작 방식
HTTP/1.1는 기본적으로 Connection당 하나의 요청을 처리 하도록 설계
동시 전송이 불가능하고 요청과 응답이 순차적으로 이뤄짐
HTTP 문서 안에 포함된 다수의 리소스 (Images, CSS, Script)를 처리하려면 요청할 리소스 개수에 비례해서 Latency(대기 시간)는 길어짐

- HTTP/1.1 단점
1. HOL (Head Of Line) Blocking - 특정 응답의 지연
HTTP의 HOL Blocking
TCP의 HOL Blocking
- HTTP/1.1의 connection당 하나의 요청 처리를 개선할 수 있는 기법 중 pipelining이 존재 
- Connection을 통해서 다수개의 파일을 요청/응답 받을 수 있는 기법

2.  RTT( Round Trip Time ) 증가
일반적으로 하나의 connection에 하나의 요청을 처리
그렇기 때문에 매 요청별로 connection을 만들게 되고 TCP상에서 동작하는 HTTP의 특성상 3-way Handshake 가 반복적으로 일어나고
또한 불필요한 RTT증가와 네트워크 지연을 초래하여 성능을 저하 시킴

3.  무거운 Header 구조
http/1.1의 헤더에는 많은 메타정보들을 저장
매 요청 시 마다 중복된 Header 값을 전송하게 되며(별도의 domain sharding을 하지 않았을 경우) 
또한 해당 domain에 설정된 cookie 정보도 매 요청 시 마다 헤더에 포함되어 전송
전송하려는 값보다 헤더 값이 더 큰 경우도 자주 발생

- HTTP/2 등장
HTTP가 유선 상에서 표현 방법을 대치 하는 것

**성능에 초점**
최종 사용자가 대기 시간, 네트워크 및 서버 리소스 사용을 인식
하나는 브라우저에서 웹 사이트로의 단일 연결을 허용하는 것

1. Multiplexed Streams
한 커넥션으로 동시에 여러 개의 메세지를 주고 받을 있으며, 응답은 순서에 상관없이 stream으로 주고 받음
HTTP/1.1의 Connection Keep-Alive, Pipelining의 개선

2. Stream Prioritization (스트림 우선순위)
클라이언트가 요청한 HTML문서 안에 CSS파일 1개와 Image파일 2개가 존재하고 
이를 클라이언트가 각각 요청하고 난 후 Image파일보다 CSS파일의 수신이 늦어지는 경우 브라우저의 
렌더링이 늦어지는 문제가 발생하는데 HTTP/2의 경우 리소스간 의존관계(우선순위)를 설정하여 이런 문제를 해결

3. Server Push
서버는 클라이언트의 요청에 대해 요청하지도 않은 리소스를 보내줄 수 있음
클라이언트(브라우저)가 HTML문서를 요청하고 해당 HTML에 여러 개의 리소스(CSS, Image...) 가 포함되어 
있는 경우 HTTP/1.1에서 클라이언트는 요청한 HTML문서를 수신한 후  HTML문서를 해석하면서 필요한
리소스를 재 요청하는 반면 HTTP/2에서는 Server Push기법을 통해서 클라이언트가 요청하지 않은
(HTML문서에 포함된 리소스) 리소스를 Push 해주는 방법으로 클라이언트의 요청을 최소화 해서 성능 향상을 이끌어 냄
PUSH_PROMISE 라고 부르며 PUSH_PROMISE를 통해서 서버가 전송한 리소스에 대해선 클라이언트는 요청을 않음

4. Header Compression (헤더 압축)

HTTP/2는 Header 정보를 압축하기 위해 Header Table과 Huffman Encoding 기법을 사용하여 처리하는데
이를 HPACK 압축방식이라 부르며 별도의 명세서(RFC 7531)로 관리.


## HTTPS / SSL 특징

- HTTP 프로토콜
    - 개념 
        - HyperText Transfer Protocol
        - 웹 상에서 클라이언트와 서버 간에 요청/응답(request/response)으로 정보를 주고 받을 수 있는 프로토콜
    - 특징 
        - 주로 HTML 문서를 주고받는 데에 쓰인다. 
        - TCP와 UDP를 사용하며, **80번 포트**를 사용한다.
        - 1) 비연결(Connectionless)
            - 클라이언트가 요청을 서버에 보내고 서버가 적절한 응답을 클라이언트에 보내면 바로 연결이 끊긴다.
        - 2) 무상태(Stateless)
            - 연결을 끊는 순간 클라이언트와 서버의 통신은 끝나며 상태 정보를 유지하지 않는다.
- HTTPS 프로토콜 
    - 개념 
        - HyperText Transfer Protocol over Secure Socket Layer
            - 또는 HTTP over TLS, HTTP over SSL, HTTP Secure
        - 웹 통신 프로토콜인 HTTP의 보안이 강화된 버전의 프로토콜
    - 특징 
        - HTTPS의 기본 TCP/IP 포트로 **443번 포트**를 사용한다.
        - HTTPS는 소켓 통신에서 일반 텍스트를 이용하는 대신에, 웹 상에서 정보를 암호화하는 SSL이나 TLS 프로토콜을 통해 세션 데이터를 암호화한다. 
            - TLS(Transport Layer Security) 프로토콜은 SSL(Secure Socket Layer) 프로토콜에서 발전한 것이다.
            - 두 프로토콜의 주요 목표는 기밀성(사생활 보호), 데이터 무결성, ID 및 디지털 인증서를 사용한 인증을 제공하는 것이다.
        - 따라서 데이터의 적절한 보호를 보장한다. 
            - 보호의 수준은 웹 브라우저에서의 구현 정확도와 서버 소프트웨어, 지원하는 암호화 알고리즘에 달려있다.
        - 금융 정보나 메일 등 중요한 정보를 주고받는 것은 HTTPS를, 아무나 봐도 상관 없는 페이지는 HTTP를 사용한다.

- HTTPS가 필요한 이유?
    - 클라이언트인 웹브라우저가 서버에 HTTP를 통해 웹 페이지나 이미지 정보를 요청하면 서버는 이 요청에 응답하여 요구하는 정보를 제공하게 된다.
    - 웹 페이지(HTML)는 텍스트이고, HTTP를 통해 이런 텍스트 정보를 교환하는 것이다.
    - 이때 주고받는 텍스트 정보에 주민등록번호나 비밀번호와 같이 민감한 정보가 포함된 상태에서 네트워크 상에서 중간에 제3자가 정보를 가로챈다면 보안상 큰 문제가 발생한다.
    - 즉, 중간에서 정보를 볼 수 없도록 주고받는 정보를 암호화하는 방법인 HTTPS를 사용하는 것이다.

- HTTPS의 원리 
    - **[공개키 알고리즘 방식](https://github.com/WeareSoft/tech-interview/blob/master/contents/security.md#대칭키와-비대칭키-차이)**
    - **[SSL 참고하기 goodgid](https://goodgid.github.io/TLS-SSL/)**
    - 암호화, 복호화시킬 수 있는 서로 다른 키(공개키, 개인키)를 이용한 암호화 방법 
        - 공개키: 모두에게 공개. 공캐키 저장소에 등록 
        - 개인키(비공개키): 개인에게만 공개. 클라이언트-서버 구조에서는 서버가 가지고 있는 비공개키 
    - 클라이언트 -> 서버 
        - 사용자의 데이터를 **공개키로 암호화** (공개키를 얻은 인증된 사용자)
        - 서버로 전송 (데이터를 가로채도 개인키가 없으므로 **복호화할 수 없음**)
        - 서버의 **개인키를 통해 복호화**하여 요청 처리 

- HTTPS의 장단점
    - 장점 
        - 네트워크 상에서 열람, 수정이 불가능하므로 안전하다.
    - 단점 
        - 암호화를 하는 과정이 웹 서버에 부하를 준다.
        - HTTPS는 설치 및 인증서를 유지하는데 추가 비용이 발생한다.
        - HTTP에 비해 느리다. 
        - 인터넷 연결이 끊긴 경우 재인증 시간이 소요된다.
            - HTTP는 비연결형으로 웹 페이지를 보는 중 인터넷 연결이 끊겼다가 다시 연결되어도 페이지를 계속 볼 수 있다.
            - 그러나 HTTPS의 경우에는 소켓(데이터를 주고 받는 경로) 자체에서 인증을 하기 때문에 인터넷 연결이 끊기면 소켓도 끊어져서 다시 HTTPS 인증이 필요하다.


### HTTP와 HTTPS 동작 과정
#### HTTP 동작 과정
* 서버 접속 -> 클라이언트 -> 요청 -> 서버 -> 응답 -> 클라이언트 -> 연결 종료
1. **사용자가 웹 브라우저에 URL 주소 입력**
2. **DNS 서버에 웹 서버의 호스트 이름을 IP 주소로 변경 요청**
3. **웹 서버와 TCP 연결 시도**
    * 3way-handshaking
4. **클라이언트가 서버에게 요청**
    * HTTP Request Message = Request Header + 빈 줄 + Request Body
    * Request Header
      * 요청 메소드 + 요청 URI + HTTP 프로토콜 버전
        * ```GET /background.png HTTP/1.0``` ```POST / HTTP 1.1```
        * Header 정보(key-value 구조)
    * 빈 줄
      * 요청에 대한 모든 메타 정보가 전송되었음을 알리는 용도
    * Request Body
      * GET, HEAD, DELETE, OPTIONS처럼 리소스를 가져오는 요청은 바디 미포함
      * 데이터 업데이트 요청과 관련된 내용 (HTML 폼 콘텐츠 등)
5. **서버가 클라이언트에게 데이터 응답**
    * HTTP Response Message = Response Header + 빈 줄 + Response Body
    * Response Header
      * HTTP 프로토콜 버전 + 응답 코드 + 응답 메시지
        * ex. ```HTTP/1.1 404 Not Found.```
      * Header 정보(key-value 구조)
    * 빈 줄
      * 요청에 대한 모든 메타 정보가 전송되었음을 알리는 용도
    * Response Body
      * 응답 리소스 데이터
        * 201, 204 상태 코드는 바디 미포함
6. **서버 클라이언트 간 연결 종료**
    * 4way-handshaking
7. **웹 브라우저가 웹 문서 출력**

#### HTTPS(SSL) 동작 과정
* 공개키 암호화 방식과 대칭키 암호화 방식의 장점을 활용해 하이브리드 사용
  * 데이터를 대칭키 방식으로 암복호화하고, 공개키 방식으로 대칭키 전달
1. **클라이언트가 서버 접속하여 Handshaking 과정에서 서로 탐색**
    
    1.1. **Client Hello**
      * 클라이언트가 서버에게 전송할 데이터
        * 클라이언트 측에서 생성한 **랜덤 데이터**
        * 클-서 암호화 방식 통일을 위해 **클라이언트가 사용할 수 있는 암호화 방식**
        * 이전에 이미 Handshaking 기록이 있다면 자원 절약을 위해 기존 세션을 재활용하기 위한 **세션 아이디**

    1.2. **Server Hello**
      * Client Hello에 대한 응답으로 전송할 데이터
        * 서버 측에서 생성한 **랜덤 데이터**
        * **서버가 선택한 클라이언트의 암호화 방식**
        * **SSL 인증서**

    1.3. **Client 인증 확인**
      * 서버로부터 받은 인증서가 CA에 의해 발급되었는지 본인이 가지고 있는 목록에서 확인하고, 목록에 있다면 CA 공개키로 인증서 복호화
      * 클-서 각각의 랜덤 데이터를 조합하여 pre master secret 값 생성(데이터 송수신 시 대칭키 암호화에 사용할 키)
      * pre master secret 값을 공개키 방식으로 서버 전달(공개키는 서버로부터 받은 인증서에 포함)
      * 일련의 과정을 거쳐 session key 생성

    1.4. **Server 인증 확인**
      * 서버는 비공개키로 복호화하여 pre master secret 값 취득(대칭키 공유 완료)
      * 일련의 과정을 거쳐 session key 생성

    1.5. **Handshaking 종료**
2. **데이터 전송**
    * 서버와 클라이언트는 session key를 활용해 데이터를 암복호화하여 데이터 송수신
    
3. **연결 종료 및 session key 폐기**            



## HTTP 200, 300, 400, 500 응답 코드

- 100 번대  Informational (정보), 리퀘스트를 받고, 처리 중에 있음.

- 200 번대 응답(Response) : 성공(Success)

- 300 번대 응답(Response) : 리디렉션(Redirection)

- 400 번대 응답(Response) : 클라이언트 에러 (Client Error)

- 500 번대 응답(Response) : 서버 에러 (Server Error)




## 브라우저에 URL인 www.xxx.com 치면 나오는 과정

- [참조](https://owlgwang.tistory.com/1)하였습니다.

1. 주소표시줄에 URL을 입력하고 Enter를 입력한다.

2. 웹 브라우저가 URL을 해석한다.

URL의 구조
scheme:[//[user:password@]host[:port]][/]path[?query][#fragment]

URL 문법 
URL은 제일 앞에 자원에 접근할 방법을 정의해 둔 프로토콜 이름을 적는다. gopher, telnet, ftp, http, usenet 등이다.
프로토콜 이름 다음에는 프로토콜 이름을 구분하는 구분자인 ":"을 적는다.
만약 IP 혹은 Domain name 정보가 필요한 프로토콜이라면 ":" 다음에 "//"를 적는다.[3]
프로토콜명 구분자인 ":" 혹은 "//" 다음에는 프로토콜 마다 특화된 정보를 넣는다.

예1) http://www.somehost.com/a.gif- IP 혹은 Domain name 정보가 필요한 형태 ( www.somehost.com에 있는 a.gif를 가리키고 있음 )
예2) ftp://id:pass@192.168.1.234/a.gif- IP 혹은 Domain name 정보가 필요한 형태 ( 192.168.1.234에 있는 a.gif를 가리키고 있음 )
예3) mailto:somebody@mail.somehost.com - IP정보가 필요없는 프로토콜 ( mailto 프로토콜은 단지 메일을 받는 사람의 주소를 나타냄 )
 출처) 위키백과 - URL


만약, URL이 문법에 맞지 않는다면 입력을 웹 브라우저의 기본 검색엔진으로 검색을 요청한다.


3. URL이 문법에 맞으면 Punycode encoding을 url의 host부분에 적용한다.


4. HSTS (HTTP Strict Transport Security)목록을 로드해서 확인한다.


HSTS 목록에 있으면 첫 요청을 HTTPS로 보내고, 아닌경우 HTTP로 보낸다.
HTTP Strict Transport Security란? 

 - HTTP 대신 HTTPS만을 사용하여 통신해야 한다고 웹 사이트가 웹 브라우저에 알리는 보안기능
 출처) MDN - Strict Transport Security


5. DNS정보 브라우저 캐시에서 찾고 맵핑된 IP를 찾고 os에서 시스템콜로찾고 라우터가 가지고 있는지 찾고 isp같은곳에도 요청해서 찾습니다.
   그후 DNS(Domain Name Server) 조회한다.

  1) DNS에 요청을 보내기 전에 먼저 Browser에 해당 Domain이 cache돼 있는지 확인한다. (Chrome의 경우 chrome://net-internals/#dns 에서 확인 가능)
  2) 없을 경우 로컬에 저장돼 있는 hosts파일에서 참조할 수 있는 Domain이 있는지 확인한다.
  3) 1), 2)가 모두 실패 했을 경우 Network stack에 구성돼 있는 DNS로 요청을 보낸다. (DNS는 일반적으로 Local router, ISP의 캐싱 DNS)



6. ARP(Address Resolution Protocol)로 대상의 IP와 MAC address를 알아낸다.

  ARP broadcast를 보내려면 Network stack library가 조회 할 대상 IP 주소와 ARP broadcast에 사용할 인터페이스의 MAC address를 알아야 한다.
  ARP cache는 대상 IP에 대한 ARP 항목을 확인해서 cache가 있을경우 MAC주소를 반환한다.
  ARP cache가 없는 경우 : 

   1) 대상 IP address가 local subnet에 있는지 확인하기 위해 routing table 조회
   2) 있는경우 subnet과 연관된 interface 사용, 없는 경우 기본 gateway의 subnet과 연관된 interface 사용
   3) Network library는 Link Layer(OSI Model Layer 2)에 ARP 요청을 보냄



ARP Request:

Sender MAC: interface:mac:address:here
Sender IP: interface.ip.goes.here
Target MAC: FF:FF:FF:FF:FF:FF (Broadcast)
Target IP: target.ip.goes.here
ARP Reply:

Sender MAC: target:mac:address:here
Sender IP: target.ip.goes.here
Target MAC: interface:mac:address:here
Target IP: interface.ip.goes.here

    4) 응답에서 target의 MAC address와 IP address로 DNS 프로세스 다시 시작
    5) DNS에 53번 포트를 열어서 UDP 요청을 보낸다. (응답 데이터가 큰경우 TCP가 대신 사용)
    6) 로컬 / ISP DNS에 없는 경우 SOA(Service-oriented architecture)에 도달 할 때까지 재귀요청을 보내서 응답을 받는다.



7. 대상과 TCP 통신을 통해 Socket을 연다.

  1) 브라우저가 대상 서버의 IP 주소를 받으면 URL에서 해당 포트 번호(HTTP의 기본값은 80, HTTPS의 기본값은 443)를 가져와서, TCP Socket stream 요청
  2) TCP segment가 만들어지는 Transport Layer(OSI Model Layer 4)로 전달. 대상 포트 header에 추가되고 source port는 시스템에서 동적 포트 범위내에서 임의 지정
  3) TCP segment를 Network Layer(OSI Model Layer 3)로 전달. segment header에 대상 컴퓨터의 IP주소와 현재 컴퓨터의 IP주소가 삽입된packet 구성
  4) packet이 Link Layer(OSI Model Layer 2)로 전달. 시스템의 MAC address와 gateway(local router)의 MAC주소를 포함하는 Frame header 추가 (gateway의 MAC address를 모르는경우 ARP를 이용해 찾아야 한다.)
  5) packet이 ethernet, Wifi, Cellular data network 중 하나로 전송 
    - 광인터넷을 쓸 경우 modem을 통해 광신호로 변경된 후 network node로 직접 전송
  6) packet local subnet router 도착, AS(Autonomous System)경계 router들을 통과
      해당 라우터에선 packet의 IP header에서 target address를 추출하여 적당한 다음 hop으로 routing 
      IP header의 TTL(Time To Live)필드는 통과하는 라우터의 대해 하나씩 감소
      TTL필드가 0이 되거나 현재 router 대기열에 공간이 없으면 네트워크 정체로 packet 삭제
   7) TCP socket 통신 과정 

8. HTTPS인 경우 TLS(Transport Layer Security) handshake가 추가된다. 
  TLS는 SSL(Secure Sockets Layer)이 표준화 되면서 바뀐 이름이다. HTTPS로 통신을 하게 되면 TCP socket 통신과정 전에 아래와 그림과 같은 통신이 추가 된다. 여기서 시간은 큰 의미는 없다.


9. HTTP 프로토콜로 요청한다.
  그냥 HTTP라면 7번의 connection set-up 이후 부터이고, HTTPS라면 8번에 있는 그림에서 168ms 부터이다.
  client가 HTTP 프로토콜을 사용해서 서버에 다음과 같은 형식으로 요청을 보낸다.

GET / HTTP/1.1
Host: google.com
Connection: close
[other headers]
  여기서 other headers는 콜론(:) 으로 구분된 key, value 쌍을 말하며 HTTP 사양에 따라 형식이 지정되고 단일의 한 행으로 구분된다. (HTTP header 목록)
  영구 연결을 지원하지 않는 HTTP / 1.1 은 응답이 완료된 후 연결이 닫히도록 하는 close 연결 옵션을 포함해야 한다.

Connection: close
  요청과 header를 보낸 후 웹 브라우저는 요청 내용이 완료되었음을 알리는 단일 빈 줄 바꿈을 서버에 보낸다.
  서버는 상태를 나타내는 코드를 아래와 같은 형식으로 응답한다.

200 OK

[response headers]

   이 응답에 빈 줄이 한줄 들어가고 google.com의 HTML 내용의 Payload를 보낸다. 이 후에 서버는 연결을 close 할 수도 있고, 클라이언트가 보낸 헤더가 요청한 경우 추가 요청을 위해 연결을 유지 할 수도 있다.

   만약 웹 브라우저가 보낸 HTTP header에 웹 브라우저가 캐시한 파일의 버전이 마지막 검색이후 수정되지 않았으면(HTTP header의 ETag 값으로 확인) 서버에선 다음과 같이 응답한다. 

304 Not Modified
[response headers]
  이 응답에선 Payload가 없고 웹 브라우저는 캐시에서 HTML을 검색한다. HTML을 파싱한 후 웹 브라우저와 서버는 GET / HTTP/1.1요청이 아닌 HTML페이지에서 참조하는 모든 자원(Image, CSS, favicon.ico 등)에 대해 이 프로세스를 반복한다. 만약 HTML이 다른 Domain의 resource를 참조하는 경우 웹 브라우저는 다른 도메인을 확인하는 단계(5번 단계)로 돌아가고 해당 도메인에 대해 모든 단계를 수행한다. Host 요청의 header는 해당 서버의 이름으로 설정된다.


10. HTTP 서버가 응답한다.
  HTTPD(HTTP daemon) 서버는 요청 / 응답을 처리하는 서버이다. 가장 일반적인 HTTPD 서버는 Linux의 경우 Apache 또는 Nginx이고 Windows의 경우 IIS이다.
  1) HTTPD 서버가 요청을 수신
  2) 서버는 요청을 다음 매개변수로 구분

    - HTTP method (GET, POST, PUT, DELETE, CONNECT, OPTIONS, TRACE, HEAD). 주소 표시줄에 직접 입력한 url의 경우는 GET
    - 도메인 (여기서는 google.com)
    - 요청 된 경로 ( /path 형태, 여기서는 /, 기본경로)

  3) 서버는 google.com에 해당하는 서버에 구성된 가상 호스트가 있는지 확인 (하나에 서버에서 여러 도메인을 서비스 할 수 있음)
  4) 서버는 google.com이 GET 요청을 수락할 수 있는지 확인
  5) 서버는 클라이언트가 IP, 인증 등을 통해 이 method를 사용할 수 있는지 확인
  6) 서버에 rewrite module이 설치 돼 있으면 (예 : Apache의 경우 mod_rewrite, IIS의 경우 URL Rewrite) 요청 된 rule 중 하나와 일치하도록 시도, 일치하는 rule 이 있는 경우 서버는 해당 rule을 사용하여 요청을 다시 작성
  7) 서버는 요청에 해당하는 콘텐츠를 가져오고, 여기서는 "/"가 기본 경로이므로 이 경우 index파일을 해석
  8) 서버는 핸들러에 따라 파일을 구문 분석한다. php인 경우는 php를 사용하여 index파일 해석 후 출력을 클라이언트로 스트리밍


11. 웹 브라우저가 그린다. 

  서버가 리소스(HTML, CSS, JS, Image 등)를 브라우저에 제공하면 브라우저는 아래 프로세스를 수행한다.
   - 구문 분석 - HTML, CSS, JS
   - 렌더링 - DOM Tree 구성 -> 렌더 트리 구성 -> 렌더트리 레이아웃 배치 -> 렌더트리 그리기

  웹 브라우저의 기능은 서버에서 요청하고 브라우저 창에 표시하여 선택한 웹 리소스를 표시하는 것이다. 리소스는 일반적으로 HTML문서이지만 PDF, 이미지 또는 다른 유형의 콘텐츠일 수도 있다. 자원의 위치는 URI(Uniform Resource Identifier)를 사용하여 사용자가 지정한다.

  브라우저가 HTML파일을 해석하고 표시하는 방법은 HTML 및 CSS 사양에 지정되어 있다. 이 사양은 웹 표준 단체인 W3C(World Wide Web Consortium)에서 관리한다.
  브라우저의 일반적인 User Interface 요소

  - URI를 입력하기 위한 주소표시줄
  - 뒤로 및 앞으로 버튼
  - 북마크 버튼
  - 새로고침 및 중지 버튼
  - 홈페이지 이동 버튼


  브라우저 자세한 구조

  - User InterFace : 사용자 인터페이스는 주소 표시줄, 뒤로 / 앞으로 버튼, 북마크 메뉴 등 포함. 요청한 페이지가 표시된 창을 제외하고 브라우저의 모든 부분
  - Browser Engine : Browser Engine은 UI와 Rendering Engine 사이의 작업을 통제
  - Rendering Engine : Rendering Engine은 요청된 콘텐츠를 표시한다. HTML의 경우 Rendering Engine은 HTML과 CSS를 구문 분석하고 파싱된 컨텐츠를 화면에 표시
  - Networking : Networking은 인터페이스와 독립적으로 구현되어 HTTP 요청과 같은 Network호출을 처리
  - UI backend : UI backend는 콤보 상자 및 창과 같은 기본 위젯을 그리는 데 사용. 특정 플랫폼이 아닌 일반 인터페이스 제공. 운영체제 사용자 인터페이스 method 사용
  - Javascript Engine : Javascript 코드를 구문 분석하고 실행하는 데 사용.
  - Data Storage : 브라우저는 쿠키와 같이 모든 종류의 데이터를 로컬로 저장해야 할 수도 있음. localStorage, IndexedDB, WebSQL, File System과 같은 저장 수단을 지원


  HTML parsing
  - 렌더링 엔진은 요청 된 문서의 내용을 네트워킹 계층에서 가져옴. 보통 8Kb단위로 이루어짐
  - HTML의 마크업을 parse tree로 만드는 HTML parser의 기본 작업
  - 생성된 트리(parse tree)는 DOM(Document Object Model)노드와 속성 노드의 트리이다. Javascript와 같이 HTML문서의 객체 표현과 HTML 요소의 인터페이스 이고, 트리의 root는 "Documnet"객체이다. 스크립팅을 통한 조작 전에는 마크업과 DOM은 거의 일대일 관계를 유지

  Parsing 알고리즘
  - HTML은 regular top-down 방식이나 bottom-up parsers를 사용할 수 없음
  - 이유 

    1) 관대한 언어이다.

    2) 브라우저는 잘못된 HTML을 지원하기 위해 일반적인 오류 허용 범위를 갖고 있다.

    3) HTML이 파싱되는 동안 변경될 가능성이 있다.(document.write()를 사용해서 동적 코드로 토큰을 추가할 수 있다.)

  - 일반적인 parsing 기술을 사용할 수 없이 때문에 HTML을 구문 분석하기 위한 사용자 정의 parser를 사용. 구문분석 알고리즘은 HTML5 사양에 자세히 명세돼 있음.

  - 이 알고리즘은 토큰화와 트리구조화의 두 단계로 구성



  구문분석이 끝나면 브라우저는 페이지에 연결된 외부 리소스(CSS, Image, Javascript file)를 가져 온다. 이 단계에서 브라우저는 분서를 대화형으로 표시하고 문서가 구문 분석 된 후에 실행되어야 하는 "deferred"모드의 스크립트를 구문 분석한다. 문서 상태가 "complete"로 설정 되고 "load"이벤트가 발생한다.

  HTML 페이지에는 "Invalid Syntax"오류가 없다. 브라우저가 잘못된 콘텐츠를 고쳐서 계속한다.

  CSS parsing

  - "CSS lexical and syntax grammar"를 사용하여 CSS파일, <style>태그 내용 및 style 속성 값을 parsing한다.

  - 각 CSS file은 StyleSheet object로 parsing된다. 각 object에는 CSS문법에 해당하는 선택자와 객체가 일치하는 CSS 문법이 있다.

  - CSS parser는 regular top-down 방식이거나 bottom-up parsers일 수 있다.

  Page Rendering

  1) DOM 노드를 탐색하고 각 노드에 대한 CSS 값을 계산하여 "Frame tree" 또는 "Render tree"를 만듦.

  2) 자식 노드의 width와 수평 margin, border, padding 을 합해서 Frame tree의 아래쪽에 있는 각 노드의 기본 너비를 계산.

  3) 각 노드의 사용 가능한 너비를 자식 노드에 할당하여 각 노드의 실제 width 값 계산.

  4) 텍스트 배치를 적용하고 하위 노드의 height와 margin, border, padding을 합해 각 노드의 높이를 상향식으로 계산.

  5) 위에서 계산 된 정보를 사용해서 각 노드의 좌표를 계산.

  6) float, absolutely, relatively 와 같은 속성이 사용되었을 경우 더 복잡한 단계가 수행 된다. 

  7) 페이지의 어느 부분을 그룹으로 애니메이션화 할 수 있는지 설명하는 레이어를 만듦. frame/render object는 layer에 할당

  8) 텍스처는 페이지의 각 레이어에 할당

  9) 각 frame/render object를 통해서 각 레이어 별로 그리기 명령을 실행.

  10) 위의 모든 단계를 웹페이지가 렌더링 된 마지막 시간에 계산 된 값을 재사용 할 수 있으므로 점진적 변경은 작업이 덜 필요하다.

  11) 페이지 레이어는 합성 프로세스로 보내져 browser chrome, iframe, addon panels과 같은 시각적인 레이어와 결합된다.

  12) 최종 레이어 위치가 계산되고 Direct3D / OpenGL을 통해 합성 명령이 실행된다. GPU 명령 버퍼는 비동기 렌더링을 위해 GPU로 출력되고 frame은 window server로 전송된다.

  

  GPU rendering

  - 렌더링 프로세스 동안 graphical computing layers는 CPU 또는 GPU를 사용할 수 있다.
  - graphical rendering 계산에 GPU를 사용하는 경우 그래픽 소프트웨어 레이어에서 작업을 여러조각으로 분할하여 렌더링 프로세스에 필요한 부동 소수점 계산을 위해 GPU 대용량 병렬 처리를 사용 할 수 있다.

  렌더링이 완료된 후 브라우저는 Javascript 실행을 통해 DOM과 CSSOM이 변경 될 수 있는데 레이아웃이 수정 되는 경우 페이지 렌더링 및 페인팅을 다시 수행한다.

## HTTP 3.0 (QUIC)

- [참고 1](https://evan-moon.github.io/2019/10/08/what-is-http3/)
- [참고 2](https://ykarma1996.tistory.com/86)

- HTTP/3의 장점을 설명하기 위해서는 기존의 TCP를 포기하고 QUIC를 채택하면서 얻게 된 장점을 설명해야한다.
   즉, UDP 기반의 프로토콜인 QUIC을 사용하여 통신하는 프로토콜이다. HTTP/3와 기존 HTTP 들과 가장 큰 차이점이라면 TCP가 아닌 UDP 기반의 통신을 한다는 것이다.
```
암호화가 프로토콜의 일부기능으로 포함되어 있다
스트림 연결과 암호화 스펙등을 포함한 모든 핸드쉐이크가 단일 요청/응답으로 끝난다
패킷이 개별적으로 암호화 되며, 다른 데이터 부분의 패킷을 기다릴 필요가 없다
통신이 멀티플렉싱 되며 이를 통해 HOLB를 극복할 수 있다
QUIC는 운영체제 커널과 독립적으로 응용 프로그램 공간내에서 구현할 수 있으며, 덕분에 데이터의 이동에 따른 컨텍스트 전환에 의한 오버헤드가 없어진다
Source Address와 무관하게 서버에 대한 연결을 고유하게 식별하는 연결 식별자가 포함되어 있어, IP주소가 변경되더라도 커넥션을 유지할 수 있다
```

- 이러한 QUIC를 이용하는 HTTP/3는 새로운 연결에 대해서 핸드세이크로 인한 지연, 패킷 손실이 다른 스트림에 미치는 영향, 패킷 손실로 인한 지연으로부터 자유로울 수 있다.

- 그런데, 결국 QUIC가 다한거면 QUIC위에 단순히 기존의 HTTP/2를 올리기만 해서 사용하면 되는게 아닌가? HTTP/2도 스트림 멀티플렉싱을 지원한다면서? 다른 수정이 필요해?

결론적으로보면 니 생각보다 복잡하다이다. HTTP/2의 일부 기능들은 QUIC 위에서도 별도의 변환 없이 그대로 적용할 수 있지만, 몇몇 기능들은 그렇지 않다. 대표적으로 예를 들자면, HPACK 이라는 HTTP/2에서 사용하던 헤더 압축 체계는 응답의 전달순서에 따라 크게 좌우되는데, QUIC는 스트림간의 순서를 보장하지 않기 때문에 사용할 수 없다.(이러한 경우 QPACK이라는 새로운 HTTP 헤더 압축체계를 작성했다고 한다.)

- 지금 사용중인가?
빠른 콘텐츠 전달이 생명인 CDN들은앞 다투어 서비스들을 적용하고 있고, 당연히 해당 CDN을 이용하는 서비스 제공자들은 HTTP/3를 지원한다.

구글에서 제공하는 상당수의 컨텐츠들(유튜브 포함), 페이스북 등이 지원하도록 구성되었고, 클라이언트는 크롬, 엣지 브라우저, curl 등이 이미 지원하고 있다.

## GET 메서드와 POST 메서드

- [참조](https://hongsii.github.io/2017/08/02/what-is-the-difference-get-and-post/) 하였습니다.

1. GET
HTTP/1.1 스펙인 RFC2616의 Section9.3에 따르면 GET은 서버로부터 정보를 조회하기 위해 설계된 메소드입니다.
GET은 요청을 전송할 때 필요한 데이터를 Body에 담지 않고, 쿼리스트링을 통해 전송합니다. URL의 끝에 ?와 함께 이름과 값으로 쌍을 이루는 요청 파라미터를 쿼리스트링이라고 부릅니다. 만약, 요청 파라미터가 여러 개이면 &로 연결합니다. 쿼리스트링을 사용하게 되면 URL에 조회 조건을 표시하기 때문에 특정 페이지를 링크하거나 북마크할 수 있습니다.

쿼리스트링을 포함한 URL의 샘플은 아래와 같습니다. 여기서 요청 파라미터명은 name1, name2이고, 각각의 파라미터는 value1, value2라는 값으로 서버에 요청을 보내게 됩니다.

``` 
www.example-url.com/resources?name1=value1&name2=value2
```
그리고 GET은 불필요한 요청을 제한하기 위해 요청이 캐시될 수 있습니다. js, css, 이미지 같은 정적 컨텐츠는 데이터양이 크고, 변경될 일이 적어서 반복해서 동일한 요청을 보낼 필요가 없습니다. 정적 컨텐츠를 요청하고 나면 브라우저에서는 요청을 캐시해두고, 동일한 요청이 발생할 때 서버로 요청을 보내지 않고 캐시된 데이터를 사용합니다. 그래서 프론트엔드 개발을 하다보면 정적 컨텐츠가 캐시돼 컨텐츠를 변경해도 내용이 바뀌지 않는 경우가 종종 발생합니다. 이 때는 브라우저의 캐시를 지워주면 다시 컨텐츠를 조회하기 위해 서버로 요청을 보내게 됩니다.

2. POST
POST는 리소스를 생성/변경하기 위해 설계되었기 때문에 GET과 달리 전송해야될 데이터를 HTTP 메세지의 Body에 담아서 전송합니다. HTTP 메세지의 Body는 길이의 제한없이 데이터를 전송할 수 있습니다. 그래서 POST 요청은 GET과 달리 대용량 데이터를 전송할 수 있습니다. 이처럼 POST는 데이터가 Body로 전송되고 내용이 눈에 보이지 않아 GET보다 보안적인 면에서 안전하다고 생각할 수 있지만, POST 요청도 크롬 개발자 도구, Fiddler와 같은 툴로 요청 내용을 확인할 수 있기 때문에 민감한 데이터의 경우에는 반드시 암호화해 전송해야 합니다.

그리고 POST로 요청을 보낼 때는 요청 헤더의 Content-Type에 요청 데이터의 타입을 표시해야 합니다. 데이터 타입을 표시하지 않으면 서버는 내용이나 URL에 포함된 리소스의 확장자명 등으로 데이터 타입을 유추합니다. 만약, 알 수 없는 경우에는 application/octet-stream로 요청을 처리합니다.

- GET과 POST의 차이

GET은 Idempotent, POST는 Non-idempotent하게 설계되었습니다.
Idempotent(멱등)은 수학적 개념으로 다음과 같이 나타낼 수 있습니다.

수학이나 전산학에서 연산의 한 성질을 나타내는 것으로, 연산을 여러 번 적용하더라도 결과가 달라지지 않는 성질

즉, 멱등이라는 것은 동일한 연산을 여러 번 수행하더라도 동일한 결과가 나타나야 합니다.
여기서 GET이 Idempotent하도록 설계되었다는 것은 GET으로 서버에게 동일한 요청을 여러 번 전송하더라도 동일한 응답이 돌아와야 한다는 것을 의미합니다. 이에 따라 GET은 설계원칙에 따라 서버의 데이터나 상태를 변경시키지 않아야 Idempotent하기 때문에 주로 조회를 할 때에 사용해야합니다. 예를 들어, 브라우저에서 웹페이지를 열어보거나 게시글을 읽는 등 조회를 하는 행위는 GET으로 요청하게 됩니다.

반대로 POST는 Non-idempotent하기 때문에 서버에게 동일한 요청을 여러 번 전송해도 응답은 항상 다를 수 있습니다. 이에 따라 POST는 서버의 상태나 데이터를 변경시킬 때 사용됩니다. 게시글을 쓰면 서버에 게시글이 저장이 되고, 게시글을 삭제하면 해당 데이터가 없어지는 등 POST로 요청을 하게 되면 서버의 무언가는 변경되도록 사용됩니다. 이처럼 POST는 생성, 수정, 삭제에 사용할 수 있지만, 생성에는 POST, 수정은 PUT 또는 PATCH, 삭제는 DELETE가 더 용도에 맞는 메소드라고 할 수 있습니다.

## 교착상태(데드락)이뭔지 교착상태 4개 조건

데드락 (Dead lock) 이란?

- ‘교착 상태’라고도 하며 한정된 자원을 여러 곳에서 사용하려고 할 때 발생할 수 있다.

발생 원인

- 멀티 프로그래밍 환경에서 한정된 자원을 사용하려고 서로 경쟁하는 상황이 발생 할 수 있다.

- 어떤 프로세스가 자원을 요청 했을 때 그 시각에 그 자원을 사용할 수 없는 상황이 발생할 수 있고 그 때는 프로세스가 대기 상태로 들어 간다.

- 대기 상태로 들어간 프로세스들이 실행 상태로 변경 될 수 없을 때 이러한 상황을 교착 상태라 한다.


- 교착 상태의 조건
1971년에 E. G. 코프만 교수는 교착상태가 일어나려면 다음과 같은 네 가지 필요 조건을 충족시켜야 함을 보였다.

- 상호배제(Mutual exclusion) : 프로세스들이 필요로 하는 자원에 대해 배타적인 통제권을 요구한다.
- 점유대기(Hold and wait) : 프로세스가 할당된 자원을 가진 상태에서 다른 자원을 기다린다.
- 비선점(No preemption) : 프로세스가 어떤 자원의 사용을 끝낼 때까지 그 자원을 뺏을 수 없다.
- 순환대기(Circular wait) : 각 프로세스는 순환적으로 다음 프로세스가 요구하는 자원을 가지고 있다.

이 조건 중에서 한 가지라도 만족하지 않으면 교착 상태는 발생하지 않는다. 이 중 순환대기 조건은 점유대기 조건과 비선점 조건을 만족해야 성립하는 조건이므로, 위 4가지 조건은 서로 완전히 독립적인 것은 아니다.

 
 - 데드락 (Dead lock) 처리

- 교착 상태 예방 및 회피 : 교착 상태가 되지 않도록 보장하기 위하여 교착 상태를 예방하거나 회피하는 프로토콜을 이용하는 방법

- 교착 상태 탐지 및 회복 : 교착 상태가 되도록 허용한 다음에 회복시키는 방법

- 교착 상태 무시 : 대부분의 시스템은 교착 상태가 잘 발생하지 않으며, 교착 상태 예방, 회피, 탐지, 복구하는 것은 비용이 많이 든다.

## 크리티컬 섹션과 뮤택스, 세마포어 의 차이가 뭘까요?

1. 크리티컬섹션 (Critical section)

유저모드 동기화 객체
커널모드 객체가 아니기 때문에 가볍고 같은 프로세스내에 스레드 동기화에 사용할 수 있다.
EnterCriticalSection을 호출하면 객체는 비신호 상태가 되고,
LeaveCriticalSection을 호출하면 신호상태로 바뀌어서 다른 스레드들이 접근가능하다.


2. 뮤텍스 (Mutex)

커널모드 동기화 객체
커널모드라서 크리티컬 섹션보다는 느리지만 프로세스를 넘어서 모든 스레드에 사용 될 수 있는 동기화 객체이다.
뮤텍스를 신호상태로 생성한 후 스레드에서 Wait 함수를 호출하면 뮤텍스는 비신호 상태가 되어서 다른 스레드에서는 접근하지 못한다.
ReleaseMutex를 호출하면 뮤텍스는 신호상태가 되어 다른 스레드들이 접근가능하다.


3. 세마포어 (Semaphore)

커널모드 동기화 객체
뮤텍스와 비슷하지만 접근할 수 있는 스레드 갯수를 정할 수 있다.
세마포어를 생성할 때 3개의 스레드들이 접근가능하도록 지정하면 내부카운트값은 3이다.
객체 내부적으로 카운트를 관리하여 세마포어 객체를 Wait하는 스레드가 있으면 카운트가 하나씩 감소한다. 그래서 내부카운트가 0이되면 비신호상태로 바뀐다.  세마포어를 사용하고 있는 스레드들중 ReleaseSemaphore 하면 세마포어 내부카운트는 다시 1 증가하여 신호상태로 바뀌어서 다른 스레드들이 사용가능하게 된다.



Mutex : 프로세스간 공유되는 크리티컬 섹션을 보호하기 위한 구현이다. 애초에 커널 오브젝트이기 때문에 프로세스간 공유가 가능하며, 호출하면 커널모드로 빠진다. 동작속도가 느리기 때문에 프로세스간 공유할 일이 없다면 크리티컬 섹션을 사용해야 한다.

## 스케일 아웃 vs 스케일 업

1. 스케일 업(Scale-up)

Scale-up이란, 서버의 자체 성능을 증가시키는 것이라고 생각하시면 됩니다. 즉, 기존의 서버에서 더욱 고성능의 서버로 변경하는 것을 의미하며, 스케일 업을 "수직 스케일"이라고 부르기도 합니다. 

스케일 업의 문제점으로는 스토리지 컨트롤러의 확장성 한계의 문제, 성능 그리고 용량 확장 제한에 다다른 경우에 새 시스템을 추가해야되는데 이때 발생하는 마이그레이션 비용 등이 있습니다.

2. 스케일 아웃(Scale-out)

Scale-out이란, 기존의 서버와 같은 사양 또는 비슷한 사양의 서버 대수를 증가시키는 방법으로 처리 능력을 향샹시키는 것입니다. 스케일 아웃 방식을 "수평 스케일"이라고 부르기도 하고, 확장이 스케일 업보다는 다소 유연하다고 합니다.

스케일 업의 문제점으로는, 병렬 컴퓨팅의 어려움(설계 및 구현), 기본적으로 직렬화(단일 처리)되어야 할 부분이 존재하며, 기술적으로 문제점(대역폭, 동기화 문제), 코어가 늘어남에 따라 마냥 성능이 증가하지는 않고, 코어 증가에 따라 대역폭은 증가해 지연이 발행할 가능성이 있습니다.

3. 결론

주어진 환경에서 어떤 방식을 채택해서 더욱 실용적으로 구축해서 사용하는 것을 권장해드립니다. 예를 들면, 웹사이트의 접속자가 증가해서 트래픽이 많이 발생할 경우에는 scale-out이 scale-up 보다는 효과적이며, 비용도 저렴합니다. 그 반면, 데이터베이스의 빈번한 갱신이 필요한 OLTP(온라인 트랜잭션)에서는 scale-out보다는 scale-up이 효과적이라고 합니다.

## 프로세스 vs 스레드

- 프로그램이란, 파일이 저장 장치에 저장되어 있지만 메모리에는 올라가 있지 않은 정적인 상태를 말한다.
- 프로세스: 운영체제로부터 자원을 할당받은 작업의 단위.
- 스레드: 프로세스가 할당받은 자원을 이용하는 실행 흐름의 단위.

- 왜 면접에서 물어볼까? **프로세스와 스레드의 작동 방식**에 대한 더 자세한 설명
위에서 프로세스가 메모리에 올라갈 때 운영체제로부터 시스템 자원을 할당받는다고 언급했었다. 
이 때 운영체제는 프로세스마다 각각 독립된 메모리 영역을, Code/Data/Stack/Heap의 형식으로 할당해 준다. 
각각 독립된 메모리 영역을 할당해 주기 때문에 프로세스는 다른 프로세스의 변수나 자료에 접근할 수 없다.
이와 다르게 스레드는 메모리를 서로 공유할 수 있다고 언급했었다. 이에 대해 더 자세히 설명하자면,
 프로세스가 할당받은 메모리 영역 내에서 Stack 형식으로 할당된 메모리 영역은 따로 할당받고,
  나머지 Code/Data/Heap 형식으로 할당된 메모리 영역을 공유한다. 따라서 각각의 스레드는 별도의 스택을 가지고 있지만 힙 메모리는 서로 읽고 쓸 수 있게 된다.

스레드는 본문 맨 위에서 "흐름의 단위"라고 말했는데, 정확히는 CPU 입장에서의 최소 작업 단위가 된다. 
CPU는 작업을 처리할 때 스레드를 최소 단위로 삼고 작업을 한다. 
반면 운영체제는 이렇게 작은 단위까지 직접 작업하지 않기 때문에 운영체제 관점에서는 프로세스가 최소 작업 단위가 된다.

## 셰션 vs 쿠키

```
세션 정보는 세션은 서버에 저장되는거고 브라우저에서 확인할수 있느건 쿠키값입니다.
JSESSIONID는  name 과 value 는 쿠키의 key-value 를 말하는 것입니다. 
구현하기에 따라 다른데 보통 사용자 정보를 서버에 저장하고그 저장된 키값을 쿠키에 담아서 브라우저로 보내줍니다
그럼 나중에 브라우저에서 요청을 할 때 쿠키값을 같이 받아서 그걸 기반으로 서버에서 다시 사용자 정보를 찾습니다.
그래서 로그인 정보가 있다면 세션 정보는 개발자 도구가 아니라 서버에서 확인하실 수 있을겁니다
세션 스토리지는 일반적으로 생각하는 로그인 세션이 아니라 브라우저에서 제공하는 웹스토리지라서 이거는 따로 공부해보시는게 좋을것 같다고합니다.
```

## JSESSIONID란?

- 톰캣 컨테이너에서 세션을 유지하기 위해 발급하는 키

- HTTP 프로토콜은 stateless하다. 요청시마다 새로운 연결이 생성되고 응답후 연결은 끊기게 되므로 상태를 유지할 수 없다.

- 따라서, 상태를 저장하기 위해서 톰캣은 JSESSIONID 쿠키를 클라이언트에게 발급해주고 이 값을 통해 세션을 유지할 수 있도록 한다.

#### 동작방식에 대해서

1. 브라우저에 최초 접근시 톰캣은 Response 헤더에 다음과 같이 JSESSIONID값이 발급된다.

- Set-Cookie: JSESSIONID=3CB361E~~~~~~~~~~~~~~~~~
 
2. 브라우저 재요청시 Response를 통해 받은 JSESSIONID를 Request 헤더의 쿠키에 값을 넣어 서버에 요청한다. 쿠키를 통해 JSESSIONID값을 전달받게 되면 서버는 새로운 JSESSIONID 값을 Response 헤더에 발급하지 않는다.

3. 클라이언트로부터 전달받은 JSESSIONID값을 기준으로 서버에서는 세션 메모리 영역에 상태를 유지할 값들을 저장할 수 있게 된다. (HttpSession 등)



## HTTP Restful API 정리
-[여기 꼭보기, 참고](https://gmlwjd9405.github.io/2018/09/21/rest-and-restful.html)

- REST의 정의
```
Representational State Transfer” 의 약자
자원을 이름(자원의 표현)으로 구분하여 해당 자원의 상태(정보)를 주고 받는 모든 것을 의미한다.
즉, 자원(resource)의 표현(representation) 에 의한 상태 전달
자원(resource)의 표현(representation)
자원: 해당 소프트웨어가 관리하는 모든 것
-> Ex) 문서, 그림, 데이터, 해당 소프트웨어 자체 등
자원의 표현: 그 자원을 표현하기 위한 이름
-> Ex) DB의 학생 정보가 자원일 때, ‘students’를 자원의 표현으로 정한다.
```
- 상태(정보) 전달
데이터가 요청되어지는 시점에서 자원의 상태(정보)를 전달한다.
JSON 혹은 XML를 통해 데이터를 주고 받는 것이 일반적이다.
월드 와이드 웹(www)과 같은 분산 하이퍼미디어 시스템을 위한 소프트웨어 개발 아키텍처의 한 형식
REST는 기본적으로 웹의 기존 기술과 HTTP 프로토콜을 그대로 활용하기 때문에 웹의 장점을 최대한 활용할 수 있는 아키텍처 스타일이다.
REST는 네트워크 상에서 Client와 Server 사이의 통신 방식 중 하나이다.

- REST의 구체적인 개념
HTTP URI(Uniform Resource Identifier)를 통해 자원(Resource)을 명시하고, HTTP Method(POST, GET, PUT, DELETE)를 통해 해당 자원에 대한 CRUD Operation을 적용하는 것을 의미한다.
즉, REST는 자원 기반의 구조(ROA, Resource Oriented Architecture) 설계의 중심에 Resource가 있고 HTTP Method를 통해 Resource를 처리하도록 설계된 아키텍쳐를 의미한다.
웹 사이트의 이미지, 텍스트, DB 내용 등의 모든 자원에 고유한 ID인 HTTP URI를 부여한다.

- CRUD Operation
```
Create : 생성(POST)
Read : 조회(GET)
Update : 수정(PUT)
Delete : 삭제(DELETE)
HEAD: header 정보 조회(HEAD)
```

- RESTful 하지 못한 경우
1.  CRUD 기능을 모두 POST로만 처리하는 API
2.  route에 resource, id 외의 정보가 들어가는 경우(/students/updateName)



## select 모델, epoll 모델 (리눅스)

- select함수

select 함수는 한곳에 여러 개의 파일 디스크립터(소켓)를 모아놓고 동시에 이들을 관찰할 수 있다.
파일디스크립터를 동시에 관찰하려면 파일디스크립터들을 모아야한다. 이 모을 때 사용되는 것이 fd_set형 변수이다.

 
 ``` C
int select(int maxfd, fd_set *readset, fd_set *writeset, fd_set *exceptset, const struct timeval * timeout);
```


maxfd : 검사 대상이 되는 파일 디스크립터의 수

readset : fd_set형 변수에 ‘수신된 데이터의 존재여부’에 관심 있는 파일 디스크립터 정보를 모두 등록해서 그 변수의 주소 값을 전달한다.

writeset :　fd_set형 변수에 ‘블로킹 없는 데이터 전송의 가능여부’에 관심 있는 파일 디스크립터 정보를 모두 등록해서 그 변소의 주소 값을 전달한다.

exceptset : fd_set형 변수에 ‘예외상황의 발생여부’에 관심이 있는 파일 디스크립터 정보를 모두 등록해서 그 변수의 주소 값을 전달한다.

timeout : select함수호출 이후에 무한정 블로킹 상태에 빠지지 않도록 타임아웃을 설정하기 위한 인자를 전달한다.

->성공 시 0 이상, 오류발생시에는 -1이 반환되고, 타임 아웃에 의한 반환 시에는 0이 반환된다.

select함수를 실행할 때 파일디스크립터에 변화가 생기지 않으면 무한정 브로킹 상태에 머물게 된다. 이러한 상황을 막기 위해 타임아웃을 지정하고 일정한 시간이 지나면 함수가 0을 반환한다.

 

select의 문제점

- select는 오래 전에 개발된 멀티플렉싱 기법으로 허용할 수 있는 동시접속자의 수가 백을 넘기 힘들다.

  그래서 오늘날의 개발환경에서는 epoll을 많이 사용한다.

- select 함수호출 이후에 항상 등장하는, 모든 파일 디스크립터를 대상으로 하는 반복문

- select 함수를 호출할 때마다 인자로 매번 전달해야 하는 관찰대상에 대한 정보들

  select 함수 호출시 관찰대상에 대한 정보를 매번 운영체제에 전달해야 한다는 것을 말한다. 운영체제에게

  데이터를 전달하는 것은 프로그램에 많은 부담이 따르는 일이다. 그러므로 성능에 치명적인 약점이 될 수 있다.

  그래서 운영체제에게 관찰대상에 대한 정보를 딱 한번만 알려주고서, 관찰대상의 범위, 또는 내용에 변경이 있을

  때 변경 사항만 알려주도록 하는 함수가 리눅스의 epoll이다.

 

- epoll

epoll의 장점


- 상태변화의 확인을 위한, 전체 파일 디스크립터를 대상으로 하는 반복문이 필요 없다.

- select 함수에 대응하는 epoll_wait 함수호출 시, 관찰대상의 정보를 매번 전달할 필요가 없다.

 

epoll의 함수

epoll_create : epoll 파일 디스크립터 저장소 생성

epoll_ctl : 저장소에 파일 디스크립터 등록 및 삭제

epoll_wait : select 함수와 마찬가지로 파일 디스크립터의 변화를 대기한다.

 
``` C
int epoll_create(int size);
```

size: epoll 인스턴스의 크기정보

->성공 시 epoll 파일 디스크립터, 실패 시 -1반환//함수 호출 시 생성되는 파일 디스크립터 저장소

 
``` C
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
```

epfd : 관찰대상을 등록할 epoll 인스턴스의 파일 디스크립터

op : 관찰대상의 추가, 삭제 또는 변경여부 지정

      EPOLL_CTL_ADD 파일 디스크립터를 epoll 인스턴스에 등록한다.

      EPOLL_CTL_DEL 파일 디스크립터를 epoll 인스턴스에서 삭제한다.

      EPOLL_CTL_MOD 등록된 파일 디스크립터의 이벤트 발생상황을 변경한다.

fd :등록할 관찰대상의 파일 디스크립터

event : 관찰대상의 관찰 이벤트 유형 (epoll_event의 포인터,event의 유형을 등록하는 용도)

 
``` C
int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);
```

epfd : 이벤트 발생의 관찰영역인 epoll 인스턴스의 파일 디스크립터

events : 이벤트가 발생한 파일 디스크립터가 채워질 버퍼의 주소 값.

maxevents : 두 번째 인자로 전달된 주소 값의 버퍼에 등록 가능한 최대 이벤트 수(버퍼최대크기)

timeout : 1/1000초 단위의 대기시간, -1전달 시 , 이벤트가 발생할 때까지 무한 대기

->성공 시 이벤트가 발생한 파일 디스크립터의 수 , 실패 시 -1 반환

- 요약

- IO Multiplexing의 두 가지 기법

select를 이용한 기법의 장점 : 이식성이 좋다. (여러 운영체제에서 호환이 용이)
select를 이용한 기법의 단점 : 비교적 성능이 떨어지기 때문에, 아주 많은 클라이언트들을 관리하기에는 적합하지 않다.

epoll을 이용한 기법의 장점 : 성능이 뛰어나서 많은 클라이언트를 관리하기에 좋다. 구현도 편리하다.
epoll을 이용한 기법의 단점 : Linux에서만 사용하는 기법이기 때문에 이식성이 좋지 않다.

- epoll?
 select나 poll과 비슷하게 관심 있는 파일 디스크립터를 모두 등록하고 이벤트 발생을 감지하는 것에는 차이는 없지만
epoll은 사건이 발생한 fd들만의 구조체 배열을 셋팅하여 관리한다.

=>  상태 변화에 대해서 일일이 확인이 필요한 전체 파일 디스크립터를 대상으로 반복문을 돌려 일일이 확인할 필요가 없다


- epoll 프로그래밍 흐름 

* epoll fd 생성 : epoll_create() * 연결 받기 (listen, accept)

listen 용 fd 생성 및 준비 : socket(), bind(), setsockopt()
epoll에 등록 : epoll_ctl(..., EPOLL_CTL_ADD, ... )
listen()
epoll_wait를 통해, fd_listen 에 사건발생(즉, 누군가 접속시도함)을 감지하여 접속받음 : accept()
accept로부터 넘어온 fd에 통신준비 : fcntl()
epoll에 새로운 fd 등록 : epoll_ctl(..., EPOLL_CTL_ADD, ... )

* 연결 하기 (connect)
사전준비(상대방 ip주소, port번호등) 그리고 연결 : connect()
연결성공하면 connect로부터 넘어온 fd에 통신준비 : fcntl()
epoll에 새로운 fd 등록 : epoll_ctl(..., EPOLL_CTL_ADD, ... )

* 연결 끊기 (connect)
연결을 끊고 싶거나, 연결이 끊김 사건 발생 또는 에러발생 : read(), epoll_wait() 에서 감지
epoll에서 해당 fd 삭제 : epoll_ctrl(..., EPOLL_CTL_DEL, ...)
연결 닫음 : close()

* epoll 종료 : close(), epoll 도 FILE이기 때문에 그냥 닫으면 된다 ;)

* 읽기 (read)
읽을 데이타 도착했음을 감지 : epoll_wait()
데이타 읽기 : read()
읽는 도중 발생하는 에러처리, 필요시 연결끊기

* 쓰기 (write)
보낼 데이터가 발생한 경우 Send Buffer에 일단 저장
보내도 된다는 신호를 감지 : epoll_wait()
데이터 전송 : write()
전송 도중 발생하는 에러처리, 필요시 연결끊기 혹은 WOULDBLOCK 처리
참고 1, WOULDBLOCK 인 경우는 에러지만 에러처리하지 않고, 단순히 리턴하고 기다리다가, EPOLLOUT 신호가 다시 발생했을 경우에 데이터를 전송하도록 한다.
참고 2, Send Buffering (]?SendBuffer])




- Edge Trigger & Level Trigger

- Edge Trigger(ET)

특정 상태가 변화하는 시점에서만 감지.

특정 디지털 신호 000 111 000 111 000 111 일 경우 신호가 0에서 1로 변하는 시점에서만 이벤트가 발생한다.

소켓 버퍼에 대응하면, 한번에 읽을 수 있는 데이터 버퍼가 600인데, 데이터가 1000바이트가 도착했다면, 600바이트만 읽고 나머지 400바이트는 읽지 않은 상태에서 더 이상의 이벤트는 발생하지 않는다.

읽은 시점을 기준으로 보면 더이상의 상태 변화가 없기 때문이다.

따라서 한번에 읽을 수 있는 바이트 이상의 데이터가 오게 된다면 추가적인 작업을 따로 해주어야 한다.

ET로 작동하게 하려면 Non-blocking 소켓으로 생성해 줘야 하며 epoll에 관심 FD로 등록 할 때 EPOLLET로 설정해 주어야 한다.

서버의 트리거 모드가 엣지 트리거인 경우, 한번에 전송 가능한 패킷 버퍼 사이즈보다 보내야 하는 데이터의 사이즈가 더 클 경우, 여러번에 걸쳐 write를 하게 되면 엣지 트리거의 특성상 정상적으로 데이터를 전부 읽어드릴 수 없는 경우가 생긴다.


- Level Trigger(LT)

특정 상태가 유지되는 동안 감지.

특정 디지털 신호 000 111 000 111 000 111 에서 1에 대한 Trigger 라면 1이 유지되는 시간동안 횟수에 상관없이 이벤트가 발생한다.

소켓 버퍼에 대응하면, 한번에 읽을 수 있는 데이터 버퍼가 600인데, 데이터가 1000바이트 도착했다면, 600바이트를 읽고 소켓 버퍼에 아직 데이터가 유지되고 있는 1인 상태이기 때문에 한번 더 이벤트가 발생하여 나머지 400바이트를 읽게 된다. 즉, 소켓 버퍼가 비어지는(0이 되는) 순간까지 계속해서 이벤트가 발생이 된다.

LT는 기본으로 설정되어 있으며 select나 poll은 LT만 지원이 된다.

서버의 트리거 모드가 레벨 트리거인 경우, 입력 버퍼에 데이터가 수신된 상황에서 이를 빠르게 읽어들이지 않으면 epoll_wait() 함수를 호출할 때 마다 이벤트가 발생하게 된다. 이로인해 발생하는 이벤트의 수가 계속 누적되는데, 이를 현실적으로 감당하는건 불가능하다. 따라서, 정상적인 접속-접속종료 테스트에 대한 처리가 불가능해질 수 있다.

* 입출력 모델
- 블락 : 데이터가 준비될때까지 블락
- 논블락 : 바로 반환
- fcntl 함수로 소켓을 보오새 혹은 논블록로 지정

* 동기 - 데이터 입출력을 시점을 알고있다.
        - 기다리거나 , 감시해야함
* 비동기 - 데이터의 입출력 시점을 모른다. 신호기반
        -자기의 일을 한다. 유저프로세스에게 신호를 받아서 일을 함


동기, 블락 모델
- 데이터 입력을 대기/  read --대기--read
- 단순하고 직관적
- 하나의 입력만 처리할 수 있다.

``` c++
while(1)
{
	select(...);	
	read(...);
}
```

동기, 논블락모델
-소켓을 비동기/  read- read-read-read
- 즉시반환 , errno -> EAGAIN으로 설정
- busy wait 문제
- 입출력 다중화로 해결할수 있음

``` c++
while(1)
{
	select(...);	
	fcntl(nonblocking)
	while(read(...))
	{
		if(errno == EAGAIN) return;
	}
}
```

비동기 , 블락 모델 
- 입출력 다중화      select - read -read
- 하나의 프로세스에서 여러 입출력 처리 가능

- level -triggered : 특정 조건이 유지되는 동안 감지
- edge-triggered : 특정 조건이 변화하는 시점에만 감지


- select : level triggered 
- epoll : edge triggered & level triggered 

비동기 , 논블락 모델
-데이터 입출력과 유저모드 프로세스가 분리
-데이터가 준비되면 이벤트로 통지
-read - 다른작업 (이벤트) - read


- 단일 프로세스/단일 스레드 기반
- epoll
- 입출력 다중화 기술 기반
- 빠른 이벤트 처리
- real-time signal
- 시그널 기반
- 시그널 유지
- 정보 전달

- 입출력 다중화와 완전한 동일 - 비동기 & 블락모델
- 입출력 파일의 목록을 반환

``` C++
while(1)
{
	readn =read(...);
	if(readn ==-1)
		if(errno == EAGAIN) break;
}
```
입출력 다중화와 동일한 프로그램 흐름
이벤트 목록을 반환
입출력 다중화 보다 높은 효율
입출력 다중화보다 명확한 코드


- real-time signal
유닉스 시그널 확장기술
시그널 대기열을 가진다.
정보를 전달할수 있다.

소켓에서 이벤트를 발생
-이벤트를 대기하다가 이벤트 정보를 읽어서 처리
``` C++
fcntl(sockfd, F_SETEL, O_RDWR|O_NONBLOCK|O_ASYNC)

fcntl(sockfd, F_SETSIG, SIGRTMIN)
```
- real-time signal 장단점
신호 기반으로 매우빠르다.
제대로 다루기가 까다롭다.