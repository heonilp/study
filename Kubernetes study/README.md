# 쉽게 시작하는 쿠버네티스(Kubernetes) 인프런 강의

## 4월 10일 ~ 12일 강의 수강, 정리 예정
-실습과 전반적인 흐름을 이해할 예정

## 관련 Git 주소
- [Git 주소](https://github.com/sysnet4admin/_Lecture_k8s.starterkit)

## 추가적인 개념정립은 조대협님의 블로그를 참조
- [조대협님의 블로그](https://bcho.tistory.com/1256)

## 쿠버네티스는 어떻게 배울것인지?

- Ch1 쿠버네티스 환경 구성
실제로 사용하는 pc에 환경구성
- Ch2 배포를 통한 쿠버네티스 체험
- Ch3 쿠버네티스 인사이드
어떻게 동작하는지, 동작원리 따져보기
- Ch4 문제를 통해 배우는 쿠버네티스
- Ch5 쿠버네티스 오브젝트
철학이나 생각하는 방식도 추가
- Ch6 쿠버네티스 Tips

## 1.1 쿠버네티스 란?

## 쿠버네티스 가 하는일
- 컨테이너(도커)가 문제가 생기는 것을 관리

## 쿠버네티스의 핵심 개념
- 쿠버네티스의 핵심 개념을 한 줄로 표현하자면, 계속해서 원하는 상태를 만들기 위해 현재 상태를 바꾸는 플랫폼입니다. 예를 들어 내가 원하는 컨테이너를 쿠버네티스에 알려주면 (Desired State) 쿠버네티스는 계속해서 Current State(현재상태) 를 체크합니다. 단순히 컨테이너 뿐만 아니라 네임스페이스나 네트워크, 스토리지 같은 부분도 동일하게 동작합니다.

- 클러스터 전체를 관리하는 컨트롤러로서 마스터가 존재하고, 컨테이너가 배포되는 물리적인 머신을 노드라고 하게 됩니다.

-쿠버네티스에 의해서 배포 및 관리되는 가장 기본적인 오브젝트는 컨테이너화되어 배포되는 애플리케이션의 워크로드를 
기술하는 오브젝트로 Pod, Service, Volume, Namespace 4가지가 있다

## 도커가 뭔가요?

- 가상화 환경 : 하이퍼바이저 -> 가상머신(운영체제 커널) -> 어플리케이션 

- 하이퍼바이저(영어: hypervisor)는 호스트 컴퓨터에서 다수의 운영 체제(operating system)를 동시에 실행하기 위한 논리적 플랫폼(platform)을 말한다.

- 컨테이너 환경(도커 환경): 운영체제 커널 - 컨테이너(어플리케이션)

## 쿠버네티스를 배우기 위해 도커를 먼저 알아야 하나요?

- 초장기 O
- 지금 X 


## 쿠버네티스는 누가 만들었고 관리하나요?

- Google의 Borg 시스템 -> CLOUD NATIVE(CNCF) 
- vendor-neutral

## 쿠버네티스 배포 종류

- 관리형 쿠버네티스 : AWS, GCP, AZure
- 설치형 쿠버네티스 : PANCHER , RED HAT OPENSHIFT
- 구성형 쿠버네티스 : Kops, Kubueadm, Kubesparay, KRIB

## 1.2 코드로 구성하는 쿠버네티스 랩 환경

- 웹에서 사용가능 :  플레이 쿠버네티스(노드4, 4시간 동안사용) 
- 웹에서 사용가능 :  쿠버네티스 플레이그라운드

- 우리가 쓸 환경, 메모리를 최적화해서 쓸 예정
- VAGRANT -> 버추얼 박스 (CentOS마스터노드, 워커노드 #1 , 워커노드 #2, 워커노드 3)


- 환경 셋팅된 환경 cmd에서 vagrant up을 친다.
- kubeadm : 실제 k8s를 배포하는 과정
- 클러스터 4개의 환경으로 구성됨
- 쿠버네티스 노드 확인 : kubectl get nodes

- 환경이 달라 생기는 문제가 많다

 1. 기존 구성과 충돌

 2. 베이그런트 호스트와 게스트 통신 실패

 3. 베이그런트 실행 권한 문제


 ## 2.1 배포를 통해 확인하는 파드(Pod)

 - 노드들에 배포

 - Pod :  컨테이너들의 집합, 하나의 도커가 하나의 파드

 - kubectl run nginx --iamge=nginx

 - kubectl get pod

 - kubectl get pod -o wide

 - curi <ip>

 ## 2.2 파트를 외부에서도 접속하게 하는 서비스(Service)

 - 쿠버네티스 클러스터의 문을 통과해야함

 - SVC ??

 - kubectl expose pod nginx --type=NodePort --port=80

 - kubectl get service

 - kubectl get nodes -o wide

## 2.3 파드와 디폴로이먼트(Deployment) 차이

- kubectl run (사용 X, Pod 한개밖에...)

- kubectl create

- kubectl apply (파일)

- 배포하기

 - kubectl create deployment deploy-nginx --image=nginx

 - kubectl get pod

 - kubectl get pod -o wide

 - curi <ip>

- 여러개 배포하기 ReplicaSet replicas : 3

  - kubectl scale  deployment deploy-nginx --replicas=3

  - kubectl get service

  - kubectl get nodes -o wide

## 2.4 외부로 노출하는 더 좋은 방법인 로드 밸런서(LoadBlancer)

1. 노드 포트로 노출

- kubectl expose deployment deploy-nginx --type=NodePort --port=80-

- kubectl get services  , IP 를 치면 nginx 가씀

2. 디플로이먼트를 노출하는 가장 좋은 방법 - 로드 밸런서 타입(MetalLB)

- 노드포트보다 로드밸런서가 좋은점

- 노드포트는 ip를 알려줘야함, 하지만 로드밸런서 ip만 알려주면됨

- 로드밸런서를 사용하면 가야되는 경로를 최적화 해줄수 있음

- kubectl apply -f ~/_Lecture_k8s.starterkit/ch2/2.4/metalib.yml

- kubectl create deployment chk -hn --image=sysnet4adimin/chk-hn

- kubectl scale deployment chk-hn --replicas=3

- kubectl get pods

- kubectl expose deployment chk-hn --type=LoadBlancer --port=80- // EXTERNAL-IP를 알려줌

- kubectl get pods -o wide

## 2.5 배포한 것들을 삭제하기

- 배포 된것을 정리

- 컨테이너를 모아놓은 것? Pod, chk-hn

- 파드를 모아 놓은 것? deploy - ReplicaSet : 배포되는 걸 조절

- 쿠버네티스에서 서비스란 ? 문같은 존재, 1. NodePort, 2. LoadBlancer
- 서비스 추가 설명 : 현관문에서 다른 곳을 거쳐가는 거실 같은 곳??

- 배포 한것들 모두 삭제

1. 서비스 삭제

- kubectl delete service chk-hn

- kubectl get service

- kubectl delete service deploy-nginx

- kubectl get service

2.  deployment, pod 삭제

- kubectl delete deployment chk-hn

- kubectl delete deployment deploy-nginx

- kubectl delete pod nginx

- kubectl get pods

3.  파일 삭제

- kubectl delete f ~/_Lecture_k8s.starterkit/ch2/2.4/metalib.yml


## 3.1 쿠버네티스 구성 요소 확인

- 쿠버네티스는 어떻게 구성되어있나요?

- api, etcd, c-d, sched, CoreDNS, k-proxy, CNI, kubelet

- 구역을 나누는 네임스페이스(Namespace) -default, kub-system, metallb-system

- 네이티브 쿠버네티스 구성요소 확인

- kubectl get pods -n kube-systeam

- aws eks-node , aks(애저) , gke(GCP) 배포, aws cloudshell 등

## 3.2 쿠버네티스의 기본 철학

- 파드 배포시에 쿠버네티스 구성요소들이 하는일

- 마이크로서비스 아키텍쳐(MSA) vs 모놀리식 아키텍처

- 각자의 일을 열심히한다.

- 파드에 배포되면? (PDF 그림보기)

- 마스터모드 (API 서버 & etcd-  컨트롤러 - 스케줄러) - 워커노드 ( kubelet - 파드)

- 선언적인 시스템

- 추구하는 상태  -(X)- 현재 상태 -> 추구하는상태 -(O)- 현재상태

- 추구하는 상태와 현재 상태를 맞추려고함  ( 차이발견, 상태변경, 감시 )

- API서버와 ETCD와 다름

1. 값에 대해서 API서버가 휘발 될 수가 있으므로 DB처럼 etcd에 업데이트된 정보기록

2. API 정보에 대해서 업데이트 됬음을 API 서버에 알림


## 3.3 현재 실제 쿠버네티스의 파드 배포 흐름

- PDF 그림보고 이해

- API 서버의 모든 곳의 중심!!(알파 오메가?)

## 문제를 통해 배우는 쿠버네티스

## 4.1 쿠버네티스 파드에 문제가 생긴다면

- 파드를 실수로 지웠다면?

1. 파드만 배포된 경우 - 난감

2. 디폴로이먼트 형태로 배포된 파드

- 파드와 디폴로이먼트 비교

- 디폴로이먼트 -> pod를 감싸고있는 객체라고 생각하면됨

- 쿠버네티스가 파드를 대하는 자세는 애완동물과 가축(죽어도돼.)

- 실습

1. kubectl apply f ~/_Lecture_k8s.starterkit/ch4/4.1/dei

2. kubectl apply f ~/_Lecture_k8s.starterkit/ch4/4.1

3. kubectl get pods (보기)

4. kubectl delete pod dei-pod (삭제)

5. kubectl delete pod del-deploy-5/~~~

6. kubectl get pods

7. kubectl delete deployment dei deploy

8. kubectl get pods


