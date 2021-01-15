# Network, C++ IOCP, Boost Asio strand공부

- IOCP, Boost Asio strand 공부(면접 질문때 대답못한 것 정리) 

- [참고 사이트](https://developstudy.tistory.com/63)

- TCP 서버/클라 함수,소켓옵션, 니글알고리즘, 용어(RTT, MSS, MTU)

##  OSI 7계층 설명하기


## TCP 특징 설명하기


## TCP 3 way handshake & 4 way handshake


## UDP 특징 설명하기


## TCP vs UDP


## TCP 서버/클라 함수


## TCP 소켓 옵션


## 니글 알고리즘


## L2~L7 스위치 특징, L4 vs L7 스위치


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


## IOCP 설명

- IOCP 개념

- IOCP 함수

- IOCP 스레드, 워커스레드 등


## C++ Boost Asio 설명


- C++ Boost Asio 개념


- C++ Boost Asio 함수


- C++ Boost Asio 스레드 , 워커스레드


## strand 설명

[strand 설명 사이트](https://blog.naver.com/njh0602/220715956896)



## HTTP 1.0/ 1.1 /2.0 /3.0


## HTTPS / SSL 특징


## HTTP 200, 300, 400, 500 응답 코드



## 브라우저에 www.xxx.com 치면 나오는 과정



## HTTP Restful API 정리



## GET 메서드와 POST 메서드


## 동기화가 뭔지, 교착상태(데드락)이뭔지 교착상태 4개 조건

- 멀티스레드의 문제점


## 크리티컬 섹션과 뮤택스의 차이가 뭘까요?



## 스케일 아웃 vs 스케일 업



## 프로세스 vs 스레드


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
