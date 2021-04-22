# 따라하며 배우는 도커와 CI환경 인프런 강의

- [git 주소 참고](https://github.com/jaewonhimnae/docker-codes)

## 4월 17일 ~ 23일 강의 수강, 정리 예정

- 실습과 전반적인 흐름을 이해할 예정

## 다음 책을 참고하면서 도커와 쿠버네티스를 추가적 실습할 예정

- 15단계로 배우는 도커와 쿠버네티스

## 도커 기본

## 1. 
1. 도커를 쓰는 이유

- 결론적으로 어떠한 프로그램을 다운받는 과정에서 굉장히 간단하게 만들기 위해서

- 레디스 설치 하는 것으로 시작

- 실제 리눅스에 깔기 위해서 실행환경을 갖춰야되기 때문에 에러를 먼저 만남eh

- 하지만 도커는 docker run -it redis으로 끝남

## 1. 2. 도커란 무엇인가?

- 컨테이너를 사용하여 응용프로그램을 더 쉽게만들고 배포하고 실행할수 있도록 설계한 도구이며 컨테이너 기반의 오픈소스 가상화 플랫폼이다.

## 1. 3. 도커이미지와 도커 컨테이너 정의

- 컨테이너는 코드와 모든 조옥성을 패키지화하여 응용 프로그램이 컴퓨팅 환경에서 다른 컴퓨팅환경으로 빠르고 안정적으로 실행되도록하는 소프트웨어의 표준이다.

- 컨테이너 이미지는 코드, 런타임, 시스템 도구, 시스테 라이브러리 및 설정과 같은 응용 프로그램을 실행하는데 필요한 모든것을 포함하는 가볍고 독립적이며 실행가능한 소프트웨어 패키지임

- 컨테이너 이미지는 런타임에 컨테이너가 되고 도커 컨테이너의 경우 도커 엔진에서 실행될때 이미지가 컨테이너가 된다. (이미지는 종속성, 컨테이너의 인스턴스)

1. 먼저 도커 CLI에서 커맨드를 입력한다

2. 도커 서버(도커 데몬)이 그 커멘드를 받아서 그것에 따라 이미지를 생성하든 컨테이너를 싱행하든 모든 작업을 하게 된다.

- 도커 client(CLI) - 도커 Server (Daemon)

- docker run hello-world

- 컴퓨터 도커 클라이언트 -> 도커서버 -> hello-world 이미지가 있나요?

- -> 도커허브 (이미지들을 보관) <-hello-world 

## 1. 4. 도커와 기존 가상화 기술과의 차이를 통한 컨테이너 이해

1. 가상화 기술이 나오기 전

- 한대의 서버를 하나의 용도로만이 사용 

- 남는 공간 그대로 방치

- 하나의 서버에 하나의 운영체제, 하나의 프로그램만을 운영 안정적 but 비효율적

2. 하이퍼바이저 기반의 가상화 출현

- 논리적으로 공간을 분할하여 VM이라는 독립적인 가상환경 서버 이용가능

- 하이퍼바이저는 호스트 시스템에서 다수의 OS를 구동할수 있게하는 소프트웨어

- 하드웨어를 가상화하면서 하드웨어와 각각의 VM을 모니터링하는 중간관리자임.

- 네이티브 하이퍼바이저 - 하드웨어 -> 하이퍼바이저 -> OS

- 호스트형 하이퍼바이저 - 하드웨어->OS ->하이퍼바이저 ->OS

- 도커 컨테이너와 가상기술이랑 공통점, 차이점

- 공통점 :기본 하드웨어에서 격리된 환경 내에 어플리케이션을 배치하는 방법

- 차이점 : 얼마나 격리시키는지 차이점

- 가상화기술 (VM)은 게스트 OS가 있어 무거움, 도커는 없어서 가벼움

- 컨테이너 : 카카오톡 -> 커널 ->하드디스크 CPU, 네트워크 , RAM

## 1.5. 이미지로 컨테이너 만들기

- 이미지는 응용 프로그램을 실행하는데 필요한 모든것을 포함하고 있음

- 그러면 뭐가 필요하지?

1.  컨테이너가 시작될때 실행되는 명령어 ex) run kakaotalk

2. 파일 스냅샷 ex)컨테이너에서 카카오톡을 싱행하고 싶다면 카카오톡 스냅샷

* 파일 스냅샷은 디렉토리나 파일을 카피한것

3. 이미지에서 가지고있는 명령어를 사용해서 카카오톡을 실행시켜줌

- 이미지로 컨테이너 만드는 순서

1. 도커 클라이언트에서 docker run <이미지> 입력해줌

## 1. 6. C-group, 네임스페이스를 도커환경에서 쓸 수 있는 이유

- 컨테이너를 격리 시킬수있는 이유는 C Group과 네임스페이스를 이용해서이다.

- 하지만 생각해보면 Cgroup과 네임스페이스는 리눅스 환경에서 사용되어지는 것인데..

- docker version (내부적으로 리눅스)

- 왜? 프로그램 -> 리눅스커널 -> 리눅스VM -> 맥OS/윈도우OS->하드웨어


## 2. 기본적인 도커 클라이언트 명령어 알아보기


## 2.1 도커 이미지 내부 파일 구조보기

- 작동순서

1. 도커 클라이언트에 명령어 입력후 도커 서버로 보냄

2. 도커 서버에서 컨테이너를 위한 이미지가 이미 캐쉬가 되어 있는지 확인

3. 없으면 도커 허브에서 다운 받아옴 있다면 그 이미 가지고 있는 이미지 컨테이너 생성

- 이미로 컨테이너 생성하는 순서 복습

1. 먼저 파일 스냅샷되어있는것을 컨테이너의 하드디스크 부분에 올린다.

2. 시작 커맨드를 이용하여 어플리케이션을 실행한다.

- docker run alpine ls 

## 2.1 컨테이너들 나열하기

- docker ps //켜져있는거 보기

- docker run alpine ping localhost

- docker ps -a// 꺼져있는거 까지 모두 보기


## 2.2 도커 컨테이너의 생명주기

- 생성(craete) - 시작(start) - 실행(running) - 중지(stopping) - 삭제(remove)

- docker create <이미지 이름>

- docker start <컨테이너 아이디/이름>

- docker run <이미지이름>

- docker stop <중지할 컨테이너 아이디 /이름>

- docker rm <삭제할 컨테이너 아이디/ 이름>


## 2.3 Docker stop vs docker kill

- 공통점은 둘다 실행중인 컨테이너를 중지

- stop은 Gracefully하게 중지를 시킵니다. 자비롭게 그동안 하던 작업들 완료하고 컨테이너를 중지시킴

- kill 같은경우는 stop과 달리 어떠한것도 기다리지않고 바로 컨테이너를 중지시킴

- docker ps -a// 꺼져있는거 까지 모두 보기

- docker stop(kill) 컨테이너아이디 

## 2.4 컨테이너 삭제하기

- docker rm <아이디 /이름>

- 모든 컨테이너를 삭제하고 싶다면??  docker rm 'docker ps -a -q'

- 이미지를 삭제하고 싶다면?? docker rmi <이미지 id>

- 한번에 컨테이너, 이미지, 네트워크 모두 삭제하고 싶다면? docker system prune

- 도커를 쓰지않을떄 모두 정리하고 싶을 때 사용해주면 좋음

- 하지만, 이것도 실행중인 컨테이너에는 영향을 주지않음

## 2.5 실행중인 컨테이너에 명령어 전달

- 이미실행중인 컨테이너에 명령어를 전달하고 싶다면 ? docker exec <컨테이너 아이디>

- docker ps

- docker exec <컨테이너id> ls

## 2.6 레디스를 이용한 컨테이너 이해

- 레디스 서버가 먼저 작동하고 있어야함

- 그후 레디스 클라이언트를 실행후 명령어를 레디스 서버에 전달

- 레디스 클라이언트 redis-cli -> 명령어 set value1 hello ->레디스 서버 docker run redis


1. 먼저 레디스 서버 작동 -docker run redis

2. 그후 레디스 클라이언트를 켜야야함- 두번째 터미널을 켜서 레디스 클라이언트를 작동 - redis-cli

3. 하지만 에러가 남, 무엇이 잘못되었을까?

4. 답 : 레디스 클라이언트도 컨테이너 안에서 실행시켜야함 - docker exec -it <컨테이너id> redis-cli


## 2.7 실행중인 컨테이너에서 터미널 생활 즐기기

- 컨테이너 쉘 환경으로 접근하기

1.  docker run alpine ping localhost

2.  docker ps (id 보기)

3.  다른 창켜서 docker exec -it 컨테이너아이디 sh

- 터미널에서 나오려면 ctrl+d로 종료해서 나와야함

## 3. 직접 도커 이미지를 만들어 보기

## 3.1 도커 이미지 생성하는 순서

- 복습

1. 도커이미지는 컨테이너를 만들기 위해서 필요한 설정이나 종속성들을 갖고 있는 소프트웨어 패키지입니다.

2. 지금까지 해왔듯이 도커이미지는 dockerhub에 이미 다른 ㅅ람들이 만들어놓은것을 이용할 수 있으며, 직접도커이미지를 만들어 사용할수 있고 직접 만든것을 Dockerhub에 업로드 할수 있습니다.

- 도커 이미지를 이용하여 도커 컨테이너를 생성

- docker create <이미지 이름>

- 그럼 도커이미지는 어떻게 생성 할까요?

- 도커 이미지 생성하는 순서

- Dockerfile 생성 -> 도커클라이언트 ->도커 서버 -> 이미지 생성


## 3.2 Dockerfile 만들기

- Dockerfile : 도커이미지를 만들기위한 설정파일, 어떠한행동해야하는지 설정을 정의해줌

- 도커파일을 만드는 순서(도커 이미가 필요한 것이 무엇인지 생각)

1. 베이스 이미지를 명시해준다(파일 스냅샷에 해당)

2. 추가적으로 필요한 파일을 다운받기 위한 몇가지 명령어를 명시해준다.

3. 컨테이너 시작시 실행될 명령어를 명시해준다(시작시 실행될 명령어에 해당)

- 베이스 이미지는 무엇인가?

 - 도커이미지는 여러개의 레이어로 되어있다. 이미지의 기반이 되는 부분

- 이미지 - 베이스이미지 (OS) - 레이어 - 레이어

- 이번강좌는 hello라는 문구

``` dockerfile
# 베이스 이미지를 명시, 태그를 붙이지 않으면 최근버전으로 받음
FROM baseIamge

# 추가적으로 필요한 파일들을 다운로드 받는다.
RUN command

# 컨테이너 시작 실행될 명령어(실행파일 및 쉘 스크립트) 를 명시해준다.
CMD [ "exccutable" ]

```


```  dockerfile
# 베이스 이미지를 명시, 태그를 붙이지 않으면 최근버전으로 받음
FROM alpine

# 추가적으로 필요한 파일들을 다운로드 받는다.
#RUN command

# 컨테이너 시작 실행될 명령어(실행파일 및 쉘 스크립트) 를 명시해준다.
CMD [ "echo", "hello" ]


```

## 3.3 도커 파일로 도커 이미지 만들기

- Dockerfile 생성 -> 도커클라이언트 ->도커 서버 -> 이미지 생성

- docker bulid ./ 또는 docker build .

- docker run -it <도커id>

## 3.4 내가 만든 이미지 기억하기 쉬운 이름 주기

- 이름 쉽게 짓기

- docker build -t smile/hello:latest ./

- -t 나의도커아이디 / 저장소 프로젝트 이름 : 버전


## 4. 도커를 이용한 간단한 Node.js 어플 만들기

## 4.1 섹션 설명

- Node.js가 중요하지않고 도커환경에 어떻게 띄우는 지 확인

## 4.2 Node.js 앱만들기

- package.json 만들기

``` json
{
  "name": "nodejs-docker-app",
  "version": "1.0.0",
  "description": "",
  "main": "server.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "dependencies": {
    "express":"4.17.1",
    "nodemon":"2.0.4"
  },
  "author": "",
  "license": "ISC"
}


```

- 간단한 node.js 만들기

``` js
const express = require('express');

const PORT = 8080;

//APP 
const app = express();
app.get('/', (req,res) => {
    res.send("반가워요!!!!!!!")
});

app.listen(PORT);
console.log("Server is running")
```


## 4.3 Dockerfile 작성하기

``` dockerfile
FROM node:10

RUN npm install

CMD ["nodemon", "server.js"]
```

- 에러 발생

1. npm가 실행이안되서 안됨 -> RUN 부분 추가

2. npm install에서 에러 -> COPY 부분 추가


## 4.4 Package.json 파일이 없다고 나오는 이유

- Node 베이스 이미지 ->생성 -> 임시 컨테이너

``` dockerfile
FROM node:10

COPY package.json ./

RUN npm install

COPY ./ ./

CMD ["nodemon", "server.js"]
```
- docker build -t samile/node.js ./

- 에러가 남


- 수정 실행은 되나 http://localhost:8080/에 들어가면 서버는 돌아가지않음
``` dockerfile
FROM node:10

COPY ./ ./

RUN npm install

COPY ./ ./

CMD ["node", "server.js"]

```

- 이미지 만들기

- docker build -t smile/node ./

## 4.5 생성한 이미지로 어플리케이션 실행 시 접근이 안 되는 이유

1. 현재까지 컨테이너를 실행하기 위한 사용한 명령어

- docker run 이미지 이름

2. 앞으로 컨테이너를 실행하기 위해 사용할 명령어

- docker run -p 49160:8080 이미지이름

- 우리는 이미지 만들떄 로컬에 있던 파일등을 복사해줘야했다.

- 그것과 비슷하게 네트워크도 로컬네트워크에 있던것을 컨테이너 내부에 있는 네트워크에 연결을 시켜주어야한다.

3. 다음과 같이 연결시켜주면 잘됨

- ex) 브라우저 http://localhost:49160 -> 로컬호스트 49160 -> 내부(네트워크 현재 8080)

- ex) 브라우저 http://localhost:5000 -> 로컬호스트 5000 -> 내부(네트워크 현재 8080)

- 서버 실행

- docker run -p 5000:8080 smile/node 

## 4.6 Working Directory 명시해주기

- 이미지안에서 어플리케이션 소스 코드를 갖고 있을 디렉토리를 생성하는 것이다. 그리고 이 디렉토리가 어플리케이션에 working 디렉토리가된다. 그런데 왜따로 working 디렉토리가 있어야되는가?

- docker run -it node ls (파일 시스템이 보여진다.)

- docker run -it smile/node sh

``` dockerfile
FROM node:10

WORKDIR /usr/src/app (이부분 추가)

COPY package.json ./

RUN npm install

COPY ./ ./

CMD ["nodemon", "server.js"]
```

- docker build -t smile/node ./

- docker run -p 5000:8080 smile/node 

- docker run -it smile/node sh

- cd / (root로 가서 봐야함)


## 4.7 어플리케이션 소스 변경으로 다시 빌드하는 것에 대한 문제점

- 어플리케이션을 만들다보면 소스 코드를 계속 변경해줘야하며 그에 따라서 변경된 부분을 환인하면서 개발을 해나가야합니다. 그래서 도커를 이용해서 어떻게 실시간으로 소스가 반영되게 하는지 알아보겠습니다.

1. 순서

- 도커파일 작성 -> 도커파일로 도커이미지생성 -> 도커이미지로 컨테이너 생성후 앱실행

- docker run 소스코드를 계속 변경시켜 변경된 부분을 어플리케이션에 반영시키려면 표시된 이구간 전체를 다시 실행시켜줘야함- 비효율적이다.

## 4.8 어플리케이션 소스 변경으로 재빌드 시 효율적으로 하는 법

- 완성본 Dockerfile

``` dockerfile
FROM node:10

WORKDIR /usr/src/app (이부분 추가)

COPY package.json ./

RUN npm install

COPY ./ ./

CMD ["nodemon", "server.js"]
```

- 이미 캐시됨, 종속성, 소스코드에 변화생길때 모듈을 다시받는 현상을 없애짐

##  윈도우 사용자를 위해서 다음 강의에서 참조할 부분

```
맥에서

-v $(pwd):/usr/src/app

윈도우에서

-v %cd%:/usr/src/app

이런 식으로 다르게      $(pwd) => %cd% 이렇게 다르게 사용해주시면 됩니다 
```

## 4.9 Docker Volume에 대하여

- 소스를 변경할때마다 변경된 소스 부분을 COPY 한후 이미지를 다시 빌드해주고 컨테이너를 다시 실행시켜줘야지 변경된 소스가 화면에 반영
- 이러한 작업을 너무나 시간 소요가 크며 이미지도 너무나 많이 빌드함

- 이러한 문제점을 해결하기 위해 Volume을 사용하게됨

```
docker run -p 5000:8080 
-v /usr/src/app/node_modules 
호스트 디렉토리 node_module은 없기에 컨테이너에 맵핑을 하지말라고하는것
-v %cd%:/usr/src/app
pwd 경로에 있는 디렉토리 혹은 파일을 /usr/src/app 경로에서 참조
<이미지 아이디>

```

- docker run -p 5000:8080 -v /usr/src/app/node_modules -v %cd%:/usr/src/app smile/node

- PWD : print working directory

- 현재 작업중인 디렉토리를 가리킨다.

## 5. Docker Compose

## 5.1 Docker Compose 무엇인지?

- Docker Compose 다중 컨테이너 도커 어플리케이션을 정의하고 실행하기 위한 도구이다.

- 페이지를 리프레시했을때 숫자 0부터 1씩 올라는 앱

- 또한, redis를 쓸 예정

- docker compose up

## 5.2 어플리케이션 소스 작성하기

- npm init

``` json
{
  "name": "nodejs-docker-app",
  "version": "1.0.0",
  "description": "",
  "main": "server.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "dependencies": {
    "express":"4.17.1",
    "nodemon":"2.0.4"
  },
  "author": "",
  "license": "ISC"
}

```


``` js
const express = require("express");
const redis = require("redis");
//레디스 클라이언트 생성 
const client = redis.createClient({
    host: "redis-server",
    port: 6379
})

const app = express();

//숫자는 0 부터 시작합니다.
client.set("number", 0);

app.get('/', (req, res) => {
    client.get("number", (err, number) => {
        //현재 숫자를 가져온 후에 1씩 올려줍니다.
        res.send("숫자가 1씩 올라갑니다. 숫자: " + number)
        client.set("number", parseInt(number) + 1)
    })
})


app.listen(8080);
console.log('Server is running');
```

- 레디스 ?
레디스(REmote Dictionary Server)는 메모리 기반 키-값 구조 데이터 관리 시스템이며, 모든 데이터를 메모리에 저장하고 빠르게 조회할수 있는 비관계형 데이터베이스 이다.

- 레디스를 쓰는 이유 : 메모리에 저장하기 때문에 mysql 같은 데이터베이스에 데이터를 저장하는 것과 데이터를 불러올떄 훨씬 빠르게 처리할수 있으며, 비록 메모리에 저장핮만 영속적으로도 보관 가능하다. 그래서 서버를 재부팅해도 데이터를 유지할수 있는 장점이 있다.



## 5.3 Dockerfile 작성하기

``` dockerfile
FROM node:10

WORKDIR /usr/src/app

COPY ./ ./

RUN npm install

COPY ./ ./

CMD ["node", "server.js"]
```

## 5.4 Docker Containers간 통신 할 때 나타나는 에러

- 1. 컨테이너 (레디스 서버) + 2. 컨테이너 (노드 JS앱, 레디스 클라이언트 )

- 서로 다른컨테이너에 있는데 이렇게 컨테이너 사이에는 아무런 설정없이는 접근을 할수 없기에 노드 JS 앱에서 레디스 서버에 접근을 할 수 없습니다.

- 그러면 어떻게 컨테이너 사이에 통신을 할수 있게 해줄까요?

- 멀티컨테이너 상황에서 쉽게 네트워크를 연결시켜주기위해 Docker Compose를 이용하면 됩니다.

## 5.5 Docker Compose 파일 작성하기

- Compose 파일이 yaml 파일인데 yml이 무엇이지?
```
YAML ain't makeup language의 약자이며 일반적으로 구성 파일 및 데이터가 저장되거나 전송되는 응용프로그램에서 사용되고 원래는 XML이나 json 포맷으로 많이쓰였지만, 좀 더 사람이 읽기 쉬운 포맷으로 나타난게 yaml입니다.
```


- 어플을 위한 docker-compose.xml

- docker-compose.xml

- 1. 컨테이너 (레디스 서버) + 2. 컨테이너 (노드 JS앱, 레디스 클라이언트 )

- services

- yml 파일 작성, 띄어 쓰기 중요함
``` yml
version: "3" # 도커 컴포즈의 버전
services: # 이곳을 싱핼허려는 컨테이너들
  redis-server: # 컨테이너이름
    image: "redis" # 컨테이너에서 사용되는이미지
  node-app: #컨테이너이름
    build: . #현 디렉토리에 있는 도커파일
    ports: #포트맵핑 로컬포트 : 컨테이너 포트
     - "5000:8080"
```     

- 명령어 docker compose up

## 5.6 Docker Compose로 컨테이너를 멈추기

- docker compose down 멈추기

- docker compose -d up 백그라운드에서 실행

- docker compse up 이미지가 없으면 이미지지를 빌드하고 컨테이너 시작

- docker compose up --build 이미지가 있든 없든 이미지를 빌드하고 컨테이너 시작


## 6. 간단한 어플을 실제로 배포해보기(개발 환경 부분)

## 6.1 섹션 설명 

- 단일컨테이너 어플리케이션 : 6, 7

- 개발환경에서 리액트앱 개발

- 멀티 컨테이너 어플리케이션 8, 9


## 6.2 리액트 앱설명

- node -v 체크해서 가능 (없으면 js홈페이지가서 받아요.)

- npx create-react-app react-app(리엑트를 설치하고자하는 디렉토리 이름)
 
- npx create-react-app react-app ./

- npm run build 

- npm run start


## 6.3 도커를 이용하여 리액트 앱 실행하기

``` dockerfile
FROM node:alpine

WORKDIR /usr/src/app

COPY package.json ./

RUN npm install

COPY ./ ./

CMD ["npm", "run", "start"]
```

- unable to evaluate symilink 오류가 나는 이유
원래는 이밎를 빌드할때랑 해당 디렉토리만 정해주면 dockerfile을 자동으로 찾아서 빌드하는데 현재는 dockerfile이 없고 dockerfile.dev 밖에없습니다. 그러기에 자동으로 올바른 도커파일을 찾지 못하여 에러가 발생합니다. 해결책은 임의로 build 할때 어떠한파일을 참조할지 알려줍니다.

- docker run -f Dockerfile.dev .


## 6.4 생성된 도커 이미지로 리액트 앱 실행해보기

- docker build -f Dockerfile.dev -t hi/docker-react-app ./

- docker run hi/docker-react-app 

- it옵션을 줘야지 리엑트 실행

- docker run -it -p 3000:3000 hi/docker-react-app 



## 6.5 도커 볼륨을 이용한 소스 코드 변경

- docker run -p 3000:3000 -v /usr/src/app/node_modules -v %cd%:/usr/src/app hi/docker-react-app 


## 6.6 도커 컴포즈로 좀 더 간단하게 앱 실행해보기

- docker-compose.yml 작성
- 도커 파일, 포트 맵핑

``` yml
version: "3"
services:
  react:
    build: 
      context: .
      dockerfile: Dockerfile.dev
    ports:
     - "3000:3000"
    volumes:
     - /usr/src/app/node_modules
     - ./:/usr/src/app
    stdin_open: true # 리액트 앱을 끌때 필요(버그수정)
  tests:
    build:
      context: .
      dockerfile: Dockerfile.dev
    volumes:
      - /usr/src/app/node_modules
      - ./:/usr/src/app
    command: ["npm", "run", "test"]
```
- docker compose up

## 6.6 리액트 앱 테스트 하기

- docker compose up --build

## 6.7 운영환경을 위한 Nginx

- 브라우저 <-> (개발서버?가없으면 ) <-정적파일

- 개발 서버가없으면 nginx으로 대신 수행 - 정적파일을 제공하는 웹서버

- 개발환경, 운영환경 서버를 다른거 써야되나요?

- 개발에는 사용하는 서버는 소스를 변경하면 자동으로 전체앱을 다시빌드해서 변경소스를 반영해주는 것과 같이 개발환경에 특화된 기능들이 있기 때문에 그러한 기능이없는 Nginx 서버가 적합, 다시반영해줄 필요가없으며 개발에 필요한 기능들이 필요하지 않기 떄문에 빠른 Nginx를 웹 서버로 사용


## 6.8 운영환경 도커 이미지를 위한 Dockerfile 작성하기

- Nginx 포함해서 도커파일 생성

- 엔진엑스 도커 이미지를 이용한 엔진엑스 시작

``` dockerfile
FROM node:alpine

WORKDIR /usr/src/app

COPY package.json ./

RUN npm install

COPY ./ ./

CMD ["npm", "run", "build"]

```

- FROM nginx (nginx를 위한 베이스 이미지)

- COPY --from=builder /usr/src/app/build /usr/share/nginx/html

- docker run -p 8080:80 <이미지이름>

- Nginx의 기본포트는 80입니다.

## 7. 간단한 어플을 실제로 배포해보기(테스트 & 배포 부분)

## 7.1 섹션 설명 & Github에 소스 코드 올리기
## 7.2 Travis CI 설명

- Travis CI : Github에서 진행하는 오픈소스 프로젝트를 위한 지속적인 통합 서비스

- Travis CI 흐름 로컬 git -> github -> Travis CI ->AWS 

1. 로컬 Git에 있는 소스를 Github 저장소에 push를합니다.

2. Github master 저장소에 소스가 push 되면 Travis CI에게 소스가 Push 되었다고 이야기 해줌

3. Travis CI는 업데이트 된소스를 Github에서 가지고 옵니다.

4. 깃허브에서 가져온 소스의 테스트 코드를 실행해봅니다.

5. 테스트 코드 실행후 테스트가 성공하면 AWS같은 호스팅 사이트로 보내서 배포를 합니다.

- Travis CI와 github id로 가입해서 프로젝트를 동기화

- 설정을 위해서 -> Travis CI-> .travis.yml작성을 함


## 7.3 .travis.yml 파일 작성하기 (테스트까지)

 ``` yml

 sudo: required

language: generic

services:
  - docker

before_install:
  - echo "start creating an image with dockerfile"
  - docker build -t smileajw1004/docker-react-app -f Dockerfile.dev .

script: #스크립트에서 테스트
  - docker run -e CI=true smileajw1004/docker-react-app npm run test -- --coverage
  ```

## 7.4 AWS알아보기

- EC2(서버), EB (Benatalk)

- EB : 도커와 함께 응용 프로그램 및 서비스를 배포하고 확장하기 쉬운 서비스
- 역할 : EC2인스턴스 데이터베이스, 시큐리티 그룹, 오토스케일링 그룹, 로드밸런서

## 7.5 Elastic Beanstalk 환경 구성하기
## 7.6 .travis.yml 파일 작성하기 (배포 부분)

- EB를 만들면 S3를 만든다. 배포 버킷장소

``` yml
deploy:
  edge: true
  provider: elasticbeanstalk
  region: ap-northeast-2
  app: docker-react-app
  env: DockerReactApp-env
  bucket_name: elasticbeanstalk-ap-northeast-2-801492874160
  bucket_path: docker-react-app
  on:
    branch: master
  access_key_id: $AWS_ACCESS_KEY
  secret_access_key: $AWS_SECRET_ACCESS_KEY

```

## 7.7 Travis CI의 AWS접근을 위한 API 생성
- API key (AWS_SECRET_ACCESS_KEY,AWS_ACCESS_KEY 필요 )

## 8. 복잡한 어플을 실제로 배포해보기(테스트 & 배포 부분)

- Dockerrun.aws.json : 백엔드 프론트앤드 등등 도커파일 배포

- EB 안에 ECS(TASK, 컨테이너)가 들어있음 

- 실습 