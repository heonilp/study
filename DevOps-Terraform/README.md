# DevOps : Infrastructure as Code with 테라폼(Terraform) and AWS 초급, 입문편

[강의](https://www.inflearn.com/course/%EB%8D%B0%EB%B8%8C%EC%98%B5%EC%8A%A4-%ED%85%8C%EB%9D%BC%ED%8F%BC-aws#)

Terraform 101 실습 사이트 : https://terraform101.inflearn.devopsart.dev/

## 4월 20일 ~ 4월 21일 강의 수강, 정리 예정

## 1강 DevOps의 이해

- 데브옵스에 대한 기본개념, 철학

- DevOps : 데브옵스 : 개발과 운영의 합성어, 단순한 개발과 운영의 통합을 의미하는 것은 아님 - 개발과 운영과 간극을 줄이자

- 데브옵스의 5개의 철학 : 문화, 자동화, 측정, 공유, 축적

- 문화 : 사람, 일, 서비스, 자원, 시간

- 자동화 : 인프라 및 보안, 언어 및 도구 ,지속적 통합/배포, 모니터링(장애대응)

- 측정 : 항상측정, 어플리케이션 성능, 개발속도 모니터링 지속적으로 나아지고 아닌지 측정, 의사결정 추측 배제

- 공유 : 문제는 혼자 해결하지않음,  언제든 접근 가능한 투명한 데이터, 지식의 공유, 오픈마인드, 문제발생시 함께 해결, 일의 가속도, 문제는 인턴이 해결할 수도 있음

- 측적 : 효율적으로 1만 시간의 법칙 이루는 것. ex)루이비통

- 정리 : 데브옵스는 어떠한 요구사항을 효율적으로 만족시키기 위해, 일을 자동화하며 변경사항 지표들을 측정하고 공유하고 이 모든 결과물들을 지속적으로 축적해 나가는 문화를 만들어가는 철학 방법론, 기술


## 2강 DevOps 엔지니어의 역할

- 데브옵스의 올바른 개념 기술, 방향성

- 올바른 데브옵스 문화를 위해 서비스 혹은 SW 라이프사이클에서 반복적인 일들을 자동화하고 기술적 문제 혹은 팀의 차이를 기술적으로 예방하고, 해소시키는 사람을 이야기. - 실제로하는 일이 많음

- 데브옵스의 역량의 따라서 할수 있는 역량이 넓어짐, 큰영향을 끼침

- 마케팅, 기획 이런 사람들의 자동화도 데브옵스가 할수 있음

- soft skill : 소통

1. 문제인식 : 문제가 무엇이 있는지 정확하 원인이 뭔지 파악

2. 선택과 집중 : 적합한 방법을 통해 해결, 해결 운선순위 올바르게 설정

3. 결정 : 내 기준이아닌 팀의 기준 서비스의 기준에서 결정해야함, 추측이아닌 확신을 가져야함

4. 업의 속성 : 서비스의 본질과 가치를 이해해야함

5. 사용자 : 사용자를 이해하고 요구사항에 대해서 빠르게 피드백, (실험-> 적용 ->피드백)

- technical skil : 프로그램작성능력, 데이터베이스, 서버관리 수행 등

1. 프로그래밍 능력 : go, Python, Node.js

2. 운영체제 : 리눅스 shell, OS, 파일시스템, 7 layers

3. 서버관리 : 서버를 관리하는 기술과 운영지식, IAC, CI/CD, API, 가용성, 성능 등

4. 오픈소스 : 엔진엑스, 톰켓, MySQL, Redis, Ansible, 테라톰

5. 클라우드 : 퍼블릭클라우드 AWS, 애저 , GCP, 알리바바 등

- OS, 어플리케이션 성능 모니터링, 고가용성 설계, 파이프라인 등 서버관련한 기술

- Infrastructure as Code (IaC) 코드로써의 인프라

- Infrastructure as Code, 즉 코드로써의 인프라는 인프라를 이루는 서버, 미들웨어, 그리고 서비스 등 인프라 구성요소들을 코드를 통해 구축하는 것, IaC는 코드써의 장점, 즉 작성용이성, 재사용성, 유지보수의 장점을 가진다.
- 심도있게 고민해서 작성해야합니다.

- Terraform by Hashicorp(IAC 도구 테라폼)

- 테라폼은 인프라를 만들고, 변경하고, 기록하는 IaC를 위해서 만들어진 도구로써, 문법이 쉬워 비교적 다루기 쉽고 사용자가 매우많아 참고 할수 있는 예제가 많다. AWS, Azure, GCP 같은 퍼블릭 클라우드 뿐만아니라 다양하 서비스에서도 지원한다.

- 우리는 AWS를 사용해서 테라폼의 실습을 진행할 것이다.

## 2강 DevOps 로드맵

- [DevOps 로드맵 사이트](https://roadmap.sh/devops)

- 선형적인 구조를 안따랐으면 좋겠음. 뭐가 중요한건없다. 다 중요하다.

- 데브옵스도 보안적으로 아는 것이 좋다.

- 킵 러닝하는게 좋다.

## 3-1강 테라폼 구성요소

- Infrastructure as Code (IaC) 코드로써의 인프라

- Infrastructure as Code, 즉 코드로써의 인프라는 인프라를 이루는 서버, 미들웨어, 그리고 서비스 등 인프라 구성요소들을 코드를 통해 구축하는 것, IaC는 코드써의 장점, 즉 작성용이성, 재사용성, 유지보수의 장점을 가진다.
- 심도있게 고민해서 작성해야합니다.

- 인지한 순간 적용해야한다.

- 테라폼은 인프라를 만들고, 변경하고, 기록하는 IaC를 위해 만들어진 도구로써 문법이 쉬워서 비교적 다루기 쉽고 사용자가 매우많아서 참고할 수 있는 예제가 많다.

- .tf 형식의 파일 형석을 가진다

- 테라폼의 구성요소

1. provider : 생성할 인프라의 종류를 의미

2. resource : 생성할 인프라 자원

3. state : 생성한 자원의 상태

4. output : 만든 자원을 변수 형태로 state에 저장하는 걸 의미

5. module : 코드를 문자 그대로 모듈형태로 정의

6. remote : 다른 경로의 state를 참조, output 변수를 불러올떄 사용

- 원격 참조 개념으로 이해하면 좋음

- 주니어는 배경, 사상보다 알단 먼저 설치 하고 작성해서 무언가를 만들면서 가까워지자.


## 3-2 테라폼 기본명령어 

- 테라폼 기본명령어부터 똑바로 알자 90%정도 쓰인다.

1. init : 테라폼 명령어 사용을 위해 각종 설정 진행

2. plan : 테라폼으로 작성한 코드가 실제로 어떻게 만들어질지에 대한 예측 결과보여줌

3. apply : 테라폼 코드로 실제 인프라를 생성하는 명령어

4. import : 이미 만들어진 자원을 테라폼 state 파일을 옮겨주는 명령어

5. state : 테라폼 state를 다루는 명령어, 하위 명령어 mv, push와 같은 명령어가 있음

6. destroy : 생성된 자원들 state 파일 모두 삭제하는 명령어(다시 만들떄 사용)


- Terraform Process

1.  init
지정한 backend에 상태 저장을 위한 .tfstate 파일을 생성합니다. 여기에는 가장 마지막에 적용한 테라폼 내역이 저장됩니다.
init 작업을 완료하면, local에는 .tfstate에 정의된 내용을 담은 .terraform 파일이 생성됩니다.
기존에 다른 개발자가 이미 .tfstate에 인프라를 정의해 놓은 것이 있다면, 다른 개발자는 init작업을 통해서 local에 sync를 맞출 수 있습니다.

2.  plan
정의한 코드가 어떤 인프라를 만들게 되는지 미리 예측 결과를 보여줍니다. 단, plan을 한 내용에 에러가 없다고 하더라도, 실제 적용되었을 때는 에러가 발생할 수 있습니다.
Plan 명령어는 어떠한 형상에도 변화를 주지 않습니다. (100% 보장해주지않음)

3.  apply
실제로 인프라를 배포하기 위한 명령어입니다. apply를 완료하면, AWS 상에 실제로 해당 인프라가 생성되고 작업 결과가 backend의 .tfstate 파일에 저장됩니다.
해당 결과는 local의 .terraform 파일에도 저장됩니다.

## 4-1강 AWS EC2 and SSH

- SSH - Secure Shell Protocol : 네트워크 프로토콜 중 하나로 보통 클라이언트와 서버가 인터넷 같은 네트워크를 통해 통신할때, 보안적으로 안전하게 통신을 하기 위해서 상요하는 프로토콜, 보통 패스워드 인증과 RSA 공개키 암호화 방식으로 연결을 함

- EC2 생성, ssh키저장

- netstat -lntp ( ssh 0.0.0.0::22 이 열려있음)

- ps -ef | grep ssh ( ssh 데몬 프로그램이 떠있음 )

- ls -al ->.ssh ->authorized_keys ( 공개키 암호화 방식 )

- 키가 쌍으로 존재, Private 키 ,퍼블릭키가 존재, 서로가 적합한지 확인


## 4-2 강 ZSH 및 Oh-my-zsh 설치

- 강사님은 리눅스환경... 저는 현재 윈도우 환경이니.. putty 사용하고, puttygen 사용해서 pem파일을 바꿈.

- sudo yum install zsh

- sudo yum install util-linux-user.x86_64

- sudo passwd ec2-user 암호 설정해줘야함

- chsh -s /bin/zsh 

- 암호침

- sudo yum install git

- curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh

- vim ~/.zshrc (테마를 바꿈, ys로 바꿈, 편하게 업무를 볼수 있음)


## 5-1 AWS CLI 및 테라폼 설치

# Linux x86 (64-bit)
- curl "https://awscli.amazonaws.com/awscli-exe-linux-x86_64.zip" -o "awscliv2.zip"

- unzip awscliv2.zip

- sudo ./aws/install

- 테라폼 설치 Terraform v0.12.24으로 설치

- $ curl -sO https://releases.hashicorp.com/terraform/0.12.24/terraform_0.12.24_linux_amd64.zip

- (Mac 유저는 darwin_amd64.zip 가 붙은 파일을 다운로드 하시면 됩니다.)

- $ unzip terraform_0.12.24_linux_amd64.zip

- $ sudo mv terraform /usr/local/bin

- $ terraform --version

- Terraform v0.12.24 (성공)


## 5-2강 AWS Configrue 설정

- 계정 이름 선택 - 내 보안 자격증명 - 액세스 키(액세스 키 ID 및 비밀 액세스 키)

1. aws configure 

2. 액세스키와 시크릿 키를 입력(절대 공개하면 안됨, 깃에 절대 올리면안됨)

3. ap-northeast-2 (서울 리전 사용)

4. json (json 이나 text)

5. aws s3 ls 하면 s3의 저장소가 나옵니다.

6. IAM 설정해서 계정만들어서 하기 (실습 , 완료)

## 6강 테라폼 작동원리와 CLI 실습

- 다음은 테라폼 활용에 필요한 개념입니다.

```
- resource : 실제로 생성할 인프라 자원을 의미합니다.
ex) aws_security_group, aws_lb, aws_instance

- provider : Terraform으로 정의할 Infrastructure Provider를 의미합니다.
https://www.terraform.io/docs/providers/index.html

- output : 인프라를 프로비저닝 한 후에 생성된 자원을 output 부분으로 뽑을 수 있습니다. Output으로 추출한 부분은 이후에 remote state에서 활용할 수 있습니다.

- backend : terraform의 상태를 저장할 공간을 지정하는 부분입니다. backend를 사용하면 현재 배포된 최신 상태를 외부에 저장하기 때문에 다른 사람과의 협업이 가능합니다. 가장 대표적으로는 AWS S3가 있습니다.

- module : 공통적으로 활용할 수 있는 인프라 코드를 한 곳으로 모아서 정의하는 부분입니다. Module을 사용하면 변수만 바꿔서 동일한 리소스를 손쉽게 생성할 수 있다는 장점이 있습니다.

- remote state : remote state를 사용하면 VPC, IAM 등과 같은 공용 서비스를 다른 서비스에서 참조할 수 있습니다. tfstate파일(최신 테라폼 상태정보)이 저장되어 있는 backend 정보를 명시하면, terraform이 해당 backend에서 output 정보들을 가져옵니다.
```

- Terraform 작동 원리

- 가장 중요한 것은 AWS 실제 인프라와 Backend에 저장된 상태가 100% 일치하도록 만드는 것입니다. 

1. Local 코드 : 현재 개발자가 작성/수정하고 있는 코드

2. AWS 실제 인프라 : 실제로 AWS에 배포되어 있는 인프라

3. Backend에 저장된 상태 : 가장 최근에 배포한 테라폼 코드 형상

4. vim provider.tf
```
provider "aws" {
    region = "ap-northeast-2"
}
```
5. terraform init

6. vim s3.tf
```
resource "aws_s3_bucket" "test" {
   bucket = "terraform101-inflearn"
}
```

7. terraform plan

8. terraform apply(배포)

9. 에러가 나옴 ,terraform101-inflearn 말고 다른 이름으로 생성
```
Error: Error creating S3 bucket: BucketAlreadyExists: The requested bucket name is not available. The bucket namespace is shared by all users of the system.

bucket 의 이름은 by all users of the system.

즉 모든 유저들이 공유하기 때문에, 그 이름이 유일해야합니다.

bucket                      = "terraform101-inflearn"

이 이름이 bucket 의 이름이 되고, 그 이름이 유일하지 않기 때문에,

제가 강의해서 만들었기 때문에 아마 만들어지지 않습니다.

이름을 유일할만한걸로 바꿔보시고 생성 - hi0223로 생성 완료
```

10.  terraform.tfstate 생성됨을 보임

11. rm -f s3.tf

12. terraform plan (삭제되었다고나옴, 코드삭제됨)

13. rm -f terraform.tfstate

14. rm -rf .terraform

15. terraform init

16. terraform plan (코드분실, 테라폼 입장에서 아무것도 안만듬)

17. terraform import aws_s3_bucket.test hi0223(실제코드가 없음- 에러)

18. vim s3.tf
```
resource "aws_s3_bucket" "test" {
   bucket = "hi0223"
}
```
19. terraform plan (force_destroy가 false 이기 때문에 apply해야함)

20. terraform apply (완료)


## 7장 VPC 소개

- AWS 시작과 기본이 되는 VPC에 대해서 알자

- 구성요소를 알아보고 AWS Console을 통해 실습

- Virtual Private Cloud(VPC) — 사용자의 AWS 계정 전용 가상 네트워크입니다.

- 서브넷 — VPC의 IP 주소 범위입니다.
- 프라이빗서브넷(NAT게이트웨이연결), 퍼블릭서브넷(인터넷게이트웨이연결)

- 라우팅 테이블 — 네트워크 트래픽을 전달할 위치를 결정하는 데 사용되는 라우팅이라는 규칙 집합입니다.

- 인터넷 게이트웨이 — VPC의 리소스와 인터넷 간의 통신을 활성화하기 위해 VPC에 연결하는 게이트웨이입니다.

- NAT 게이트웨이 — 네트워크 주소 변환을 통해 **프라이빗 서브넷**에서 인터넷 또는 기타 AWS 서비스에 연결하는 게이트웨이입니다.

- 씨큐리티 그룹 — 보안 그룹은 인스턴스에 대한 인바운드 및 아웃바운드 트래픽을 제어하는 가상 방화벽 역할을 하는 규칙 집합입니다.

- VPC 엔드포인트 — 인터넷 게이트웨이, NAT 디바이스, VPN 연결 또는 AWS Direct Connect 연결을 필요로 하지 않고 PrivateLink 구동 지원 AWS 서비스 및 VPC 엔드포인트 서비스에 VPC를 비공개로 연결할 수 있습니다. VPC의 인스턴스는 서비스의 리소스와 통신하는 데 퍼블릭 IP 주소를 필요로 하지 않습니다. VPC와 기타 서비스 간의 트래픽은 Amazon 네트워크를 벗어나지 않습니다.

## 8강 VPC와 subnet 생성하기

-왜 코드로 만드나요? - 사실 마법사로 만들거나 콘솔로 만들면 히스토리를 추척하기 힘들다. IaC를 사용하는이유는 히스토리를 추척하기 편리.

- VPC에 대해서 한번 복습하고 테라폼을 이용하여서 AWS VPC와 서브넷 생성

- VPC를 삭제하면 관련된 것을 삭제, 의존성이 있어서 하위를 먼저 삭제해야함.

- VPC 생성

- vim provider.tf

```
provider "aws" {
  region  = "ap-northeast-2"
}
```

- vim vpc.tf

```
resource "aws_vpc" "main" {
  cidr_block       = "10.0.0.0/16"

  tags = {
    Name = "terraform-101"
  }
}
```

- terraform init

- terraform plan

- terraform apply (yes, vpc 생성)

- 서브넷 구성 (서브넷은 가용영역에 속한 의존성을 가지고 있음)

- vim vpc.tf (수정)

```

resource "aws_vpc" "main" {
  cidr_block       = "10.0.0.0/16"

  tags = {
    Name = "terraform-101"
  }
}

##  추가 함

resource "aws_subnet" "public_subnet" {
  vpc_id     = aws_vpc.main.id
  cidr_block = "10.0.0.0/24"

  availability_zone = "ap-northeast-2a" // 지정을 안하면 apply 이후에 안다.

  tags = {
    Name = "terraform-101-public_subnet"
  }
}


resource "aws_subnet" "private_subnet" {
  vpc_id     = aws_vpc.main.id
  cidr_block = "10.0.10.0/24"

  availability_zone = "ap-northeast-2b"

  tags = {
    Name = "terraform-101-priavte_subnet"
  }
}
```

- terraform plan

- terraform apply (yes, 서브넷 두개 생성)

## 9강 AWS 인터넷게이트웨이 & NAT 게이트웨이 생성

- 인터넷게이트웨이 & NAT 게이트웨이 연결에 따라서 public subnet, private subnet이 결정됨, 인터넷게이트웨이 & NAT 게이트웨이를 직접 생성할것

- NAT 게이트웨이는 시간 단위로 과금이 되는 서비스이기 때문에, 오래 켜놓으시면 큰 비용이 발생합니다.

- Free Tier(프리티어) 계정을 사용한다고 하더라도, 여차하면 비용이 발생할 수도 있으므로, 반드시 삭제를 해주시기 바랍니다.

- [실습 사이트](https://terraform101.inflearn.devopsart.dev/cont/vpc-practice/vpc-practice-with-nat/)

- 인터넷게이트웨이 생성

- vim vpc.tf (수정)

```
resource "aws_internet_gateway" "igw" {
  vpc_id = aws_vpc.main.id

  tags = {
    Name = "main"
  }
}
```

- terraform plan

- terraform apply (yes, 인터넷게이트웨이 생성)

- NAT 게이트웨이 생성

```
# eip 생성
resource "aws_eip" "nat_1" {
  vpc   = true

  lifecycle {
    create_before_destroy = true
  }
}

resource "aws_nat_gateway" "nat_gateway_1" {
  allocation_id = aws_eip.nat_1.id

  # Private subnet이 아니라 public subnet을 연결하셔야 합니다.
  subnet_id = aws_subnet.public_subnet.id

  tags = {
    Name = "terraform-NAT-GW-1"
  }
}


```

- terraform plan

- terraform apply (생성, nat게이트웨이 생성)

## 10강 AWS RouteTable

- 테라폼을 이용해서 라우터 테이블 구성

- 어디로 보낼지 룰들을 선택하는 것

- Route Table은 트래픽을 규칙에 맞게 전달해주기 위해 필요한 일종의 테이블입니다. Route table은 여러 서브넷에서 동시에 사용할 수 있으며, 이렇게 연결하는 작업은 Association 이라고 합니다.


```
resource "aws_route_table" "public" {
  vpc_id = aws_vpc.main.id

  tags = {
    Name = "terraform-101-rt-public"
  }
}

resource "aws_route_table" "private" {
  vpc_id = aws_vpc.main.id

  tags = {
    Name = "terraform-101-rt-priavte"
  }
}

```

- terraform plan

- terraform apply (생성, 라우터테이블 생성)


```
# 연결 관계 생각해서 짜기

resource "aws_route_table_association" "route_table_association_public" {
  subnet_id      = aws_subnet.public_subnet.id
  route_table_id = aws_route_table.public.id
}

resource "aws_route_table_association" "route_table_association_private" {
  subnet_id      = aws_subnet.private_subnet.id
  route_table_id = aws_route_table.private.id
}

```

- terraform plan

- terraform apply (연결)


- Nat Gateway 생성
```

resource "aws_route" "private_nat" {
  route_table_id              = aws_route_table.private.id
  destination_cidr_block      = "0.0.0.0/0"
  nat_gateway_id              = aws_nat_gateway.nat_gateway_1.id
}

```

- terraform plan

- terraform apply 

- 연결되는 구간이 되게 많은 데 바깥쪽으로 코드를 뺴는 것이 더 보기 좋은 코드이다.

- VPC endpoint : 인터넷게이트웨이나 nat게이트가 아닌 ,다이렉트로 바로 만들어줌

resource "aws_vpc_endpoint" "s3" {
  vpc_id = aws_vpc.main.id
  service_name ="com.amazonaws-ap-northeast-2.s3"
}


## 11강 Amazon S3 소개

- 웹하드 서비스들이 실제로 S3를 통해 구현된 서비스들이 정말 많음

- Amazon Simple Storage Service는 인터넷용 스토리지 서비스입니다. 이 서비스는 개발자가 더 쉽게 웹 규모 컴퓨팅 작업을 수행할 수 있도록 설계되었습니다.

- 버킷

버킷은 Amazon S3에 저장된 객체에 대한 컨테이너입니다. 모든 객체는 어떤 버킷에 포함됩니다. 예를 들어 photos/puppy.jpg로 명명된 객체는 미국 서부(오레곤) 리전의 awsexamplebucket1 버킷에 저장되며 URL https://awsexamplebucket1.s3.us-west-2.amazonaws.com/photos/puppy.jpg를 사용하여 주소를 지정할 수 있습니다

## 12강 Amazon S3 실습

- 테라폼을 이용해 S3를 생성하고, 간단한 S3 설정을 실습합니다. 파일을 생성하고 aws cli를 통해 파일을 s3로 업로드합니다.

```
provider "aws" {
  region  = "ap-northeast-2"
}

resource "aws_s3_bucket" "main" {
  bucket = "devopxxxx-terraform-101-hi"

  tags = {
    Name        = "devopxxxx-terraform-101-hi"
  }
}


```

- terraform init

- terraform plan

- terraform apply

- vim index.html

- 업로드
- aws s3 cp index.html s3://devopxxxx-terraform-101-hi/hi

- 다운로드
- aws s3 cp s3://devopxxxx-terraform-101-hi/path/testfile. (현재위치)

## 13강. AWS IAM 소개

- 보안은 3가지라고 생각할 수 있다. 

- Blocking : 특정 자원에 대한 접근 혹은 사용을 제어 : IAM영역

- Encryping : 공개되는 정보에 대해서 식별 불가능한 정보로 암호화하는것

- Hiding : 정보에 대한 접근 특정 경로 혹인 명령어로 접근

- AWS Identity and Access Management(IAM)는 AWS 리소스에 대한 액세스를 안전하게 제어할 수 있는 웹 서비스입니다. IAM을 사용하여 AWS기본 접근 및 리소스를 사용하도록 권한 부여를 할 수 있습니다.

- AWS IAM User — AWS IAM User는 AWS 내에서 생성하는 사용자로 AWS와 상호작용하는 사용자 혹은 어플리케이션을 의미합니다.

- AWS IAM Group — AWS IAM Group은 IAM User의 집합이고, Group을 사용함으로써 다수 사용자에 대하여 동일한 권한을 보다 쉽게 관리할 수 있습니다.

- AWS IAM Role — AWS IAM Role은 특정 권한을 가진 IAM 자격증명입니다. 이 Role을 사용함으로써 특정 사용자 혹은 어플리케이션에 혹은 AWS 서비스에 접근 권한을 위임할 수 있습니다.

- AWS IAM Policy — AWS의 접근하는 해당 권한을 정의하는 개체로 AWS IAM 리소스들과 연결하여 사용할 수 있습니다.

## 14강 AWS IAM 실습 1

# IAM는 리전이 달라도 똑같음


- IAM user 기본 생성

provider "aws" {
  region  = "ap-northeast-2"
}


resource "aws_iam_user" "gildong_hong" {
  name = "gildong.hong"
}


- terraform init

- terraform plan

- terraform apply

- IAM group 기본 생성

- vim devops_group.tf

resource "aws_iam_group" "devops_group" {
  name = "devops"
}

- terraform paln

- terraform apply -parallelism=30


- 생성한 IAM user 를 IAM group 에 등록
IAM user를 IAM group 에 등록하는 것도 Terraform 으로 진행할 수 있습니다. 실제로 AWS IAM user 를 개발자, 데브옵스, 검증 등 조직의 실제 그룹으로 나누고 등록하고 관리해야 합니다.

Terraform을 통해서 IAM group membership을 생성해보도록 하겠습니다. IAM User를 생성할 때는 aws_iam_group_membership 리소스를 사용하면됩니다.

```
resource "aws_iam_group_membership" "devops" {
  name = aws_iam_group.devops_group.name

  users = [
    aws_iam_user.gildong_hong.name
  ]

  group = aws_iam_group.devops_group.name
}


```
- terraform paln

- terraform apply -parallelism=30 (연결 완료)

- full 이라도 deny가 하나있으면 deny된것이 우선순위임

## 15강 AWS IAM 실습 2

- IAM ROLE 기본 실습

- EC2를 위한 IAM role 기본 생성

- Terraform을 통해서 IAM role을 생성해보도록 하겠습니다. IAM role을 생성할 때는 aws_iam_role 리소스를 사용하면되고, 필수적으로 필요한 설정은 name 입니다. 여기에 aws_iam_role_policy 도 만들어 생성한 aws_iam_role 와 연결하는 작업도 진행해보겠습니다.

- vim iam_role_hello.rf

```
resource "aws_iam_role" "hello" {
  name               = "hello-iam-role"
  path               = "/"
  assume_role_policy = <<EOF
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Sid": "",
      "Effect": "Allow",
      "Principal": {
        "Service": "ec2.amazonaws.com"
      },
      "Action": "sts:AssumeRole"
    }
  ]
}
EOF

}
```
- terraform paln -parallelism=30

- terraform apply -parallelism=30

```
resource "aws_iam_role_policy" "hello_s3" {
  name   = "hello-s3-download"
  role   = aws_iam_role.hello.id
  policy = <<EOF
{
  "Statement": [
    {
      "Sid": "AllowAppArtifactsReadAccess",
      "Action": [
        "s3:GetObject"
      ],
      "Resource": [
        "*"
      ],
      "Effect": "Allow"
    }
  ]
}
EOF

}

resource "aws_iam_instance_profile" "hello" {
  name = "hello-profile"
  role = aws_iam_role.hello.name
}
```
- terraform paln -parallelism=30

- terraform apply -parallelism=30


- AWS IAM Policy 의 종류

- AWS의 접근하는 해당 권한을 정의하는 개체로 AWS IAM 리소스들과 연결하여 사용할 수 있습니다. 즉 AWS IAM policy 는 user 에 할당 할 수 도, group 에 할당 할 수 있습니다. IAM policy 는 여러 타입으로 나누어져있습니다.

- AWS Managed policy: AWS에서 먼저 생성해놓은 Policy set 입니다. 사용자가 권한(Permission)을 변경할 수 없습니다.

- Customer Managed policy: User 가 직접 생성하는 Policy 로 권한을 직접 상세하게 만들어 관리할 수 있습니다.

```
resource "aws_iam_user" "gildong_hong" {
  name = "gildong.hong"
}

resource "aws_iam_user_policy" "art_devops_black" {
  name  = "super-admin"
  user  = aws_iam_user.gildong_hong.name

  policy = <<EOF
{
    "Version": "2012-10-17",
    "Statement": [
        {
            "Effect": "Allow",
            "Action": [
                "*"
            ],
            "Resource": [
                "*"
            ]
        }
    ]
}
EOF
}
```
- terraform paln -parallelism=30

- terraform apply -parallelism=30

- resource:aws_iam_group_policy 도 할수 있음 해보기!

## Terraform 고도화 작업

## 16강 Terraform Backend

- Terraform Backend 란?
Terraform “Backend” 는 Terraform의 state file을 어디에 저장을 하고, 가져올지에 대한 설정입니다. 기본적으로는는 로컬 스토리지에 저장을 하지만, 설정에 따라서 s3, consul, etcd 등 다양한 “Backend type“을 사용할 수 있습니다.

- Locking: 보통 Terraform 코드를 혼자 작성하지 않습니다. 인프라를 변경한다는 것은 굉장히 민감한 작업이 될 수 있습니다. 원격 저장소를 사용함으로써 동시에 같은 state를 접근하는 것을 막아 의도치 않은 변경을 방지할 수 있습니다.

- Backup: 로컬 스토리지에 저장한다는건 유실할 수 있다는 가능성을 내포합니다. S3와 같은 원격저장소를 사용함으로써 state 파일의 유실을 방지합니다.

[실습 참고 코드](https://terraform101.inflearn.devopsart.dev/advanced/backend/)
- Terraform Backend 실습

S3 bucket as backend
테라폼의 상태를 저장하기 위해 S3 버킷을 생성합니다. AWS S3는 쉽게 구축할 수 있으며 versioning 을 지원하는 안전한 저장소입니다.

- DynamoDB Table for Lock

동시에 같은 파일을 수정하지 못하도록 하기 위해 DynamoDB에 작업에 대한 Lock을 생성합니다.

- state 가져오기

- terraform state list

- terraform state pull

## 17강 Variables 활용하기

- Terraform variables 사용하기

- Terraform 은 HCL Syntax를 가진 언어입니다. 언어적 특성을 가지고 있기 때문에 당연히 변수를 정의하고 주입해서 사용할 수 있습니다.

```
- Variable Types
    string
    number
    bool
    Complex variable types
    list()
    set()
    map()
    object({ = , … })
    tuple([, …])

```

## 18강 Functions 활용하기


- Terraform fuction 사용하기

Terraform 을 프로그래밍 언어라 볼 수 는 없지만, 그래도 언어적 특성과 장점을 가지고 있습니다. 그렇기 때문에 프로그래밍처럼 기본 내장된 다양한 fuction 사용할 수 있습니다.

[코드 참고](https://terraform101.inflearn.devopsart.dev/advanced/function/)
```
- Functions
    Numeric functions
    String functions
    Collection functions
    Encoding functions
    Filesystem functions
    Date and Time functions
    Hash and Crypto functions
    IP Network functions
    Type Conversion Functions
```

## 19강 Github 협업하기

- Terraform with Github

- IaC는 Infrastructure as Code 코드로써의 인프라를 이야기합니다. Terraform 은 IaC 도구이며, 즉 테라폼은 코드를 수행합니다. 그렇기 때문에 반드시 코드로써의 관리가 필요하며, 팀원간의 코드리뷰가 필요합니다. 코드리뷰란 팀원들끼리 서로의 코드를 점검하고, 서로의 코드를 배우는 것입니다.