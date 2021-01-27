# 1월 25일 ~ 1월 31일

## 1. SQL & JDBC 프로그래밍

## 1. 데이터베이스

- 핵심 개념
```
데이터베이스 (Database)
데이터베이스 메니지먼트 시스템 (DBMS)
```

- 데이터베이스와 데이터베이스 관리 시스템

Q> 데이터베이스와 데이터베이스 관리 시스템을 어린이도 알 수 있을 정도로 설명해주세요.
A> 도서관에 있는 책들이 데이터베이스라고 한다면, 도서관 사서분들이나 도서 정보를 찾아주는 컴퓨터를 DBMS라고 볼 수 있습니다.


- 데이터베이스의 기본개념 (정의)

데이터의 집합 (a Set of Data)
여러 응용 시스템(프로그램)들의 통합된 정보들을 저장하여 운영할 수 있는 공용(share) 데이터의 집합
효율적으로 저장, 검색, 갱신할 수 있도록 데이터 집합들끼리 연관시키고 조직화되어야 한다.


- 데이터베이스의 특성

실시간 접근성(Real-time Accessability)
- 사용자의 요구를 즉시 처리할 수 있다.
계속적인 변화(Continuous Evolution)
- 정확한 값을 유지하려고 삽입·삭제·수정 작업 등을 이용해 데이터를 지속적으로 갱신할 수 있다.
동시 공유성(Concurrent Sharing)
- 사용자마다 서로 다른 목적으로 사용하므로 동시에 여러 사람이 동일한 데이터에 접근하고 이용할 수 있다.
내용 참조(Content Reference)
- 저장한 데이터 레코드의 위치나 주소가 아닌 사용자가 요구하는 데이터의 내용, 즉 데이터 값에 따라 참조할 수 있어야 한다.


- 데이터베이스 관리 시스템 (Database Management System = DBMS)

데이터베이스를 관리하는 소프트웨어
여러 응용 소프트웨어(프로그램) 또는 시스템이 동시에 데이터베이스에 접근하여 사용할 수 있게 한다
필수 3기능
- 정의기능 :  데이터 베이스의 논리적, 물리적 구조를 정의
- 조작기능 : 데이터를 검색, 삭제, 갱신, 삽입, 삭제하는 기능
- 제어기능 :  데이터베이스의 내용 정확성과 안전성을 유지하도록 제어하는 기능
Oracle, SQL Server, MySQL, DB2 등의 상용 또는 공개 DBMS가 있다.
    

- 데이터베이스 관리 시스템의 장/단점

장점
- 데이터 중복이 최소화
- 데이터의 일관성 및 무결성 유지
- 데이터 보안 보장
단점
- 운영비가 비싸다
- 백업 및 복구에 대한 관리가 복잡
- 부분적 데이터베이스 손실이 전체 시스템을 정지


## 생각해보기

### 1. Database와 DBMS를 개발자가 아닌 사람에게 설명해보세요.


## 2. SQL

### 1) SQL이란?-1

- 핵심 개념
```
create database
grant
flush privileges
select
```

- SQL(Structured Query Language)

SQL은 데이터를 보다 쉽게 검색하고 추가, 삭제, 수정 같은 조작을 할 수 있도록 고안된 컴퓨터 언어입니다.
관계형 데이터베이스에서 데이터를 조작하고 쿼리하는 표준 수단입니다.
DML (Data Manipulation Language): 데이터를 조작하기 위해 사용합니다.
INSERT, UPDATE, DELETE, SELECT 등이 여기에 해당합니다.
DDL (Data Definition Language): 데이터베이스의 스키마를 정의하거나 조작하기 위해 사용합니다.
CREATE, DROP, ALTER 등이 여기에 해당합니다.
DCL (Data Control Language) : 데이터를 제어하는 언어입니다.
권한을 관리하고, 테이터의 보안, 무결성 등을 정의합니다.
GRANT, REVOKE 등이 여기에 해당합니다.


### 1) SQL이란?-2

- 핵심 개념
``` 
create database
grant
flush privileges
select
```

- 데이터를 저장하는 공간 테이블(Table)

마이크로소프트의 엑셀(Excel)을 실행하면 표가 나옵니다. 이러한 표에 각종 값을 저장할 수 있습니다.
데이터베이스도 엑셀의 표와 유사한 테이블을 가질 수 있습니다.
엑셀과 다른 점은 데이터베이스를 생성해도 테이블은 존재하지 않는다는 것입니다.
테이블을 사용하려면 테이블을 생성하는 SQL을 사용해야 합니다.
그리고, 테이블에 값을 저장하려면 저장하기 위한 SQL을 사용해야 합니다.


- 테이블(table)의 구성요소
- 테이블 : RDBMS의 기본적 저장구조 한 개 이상의 column과 0개 이상의 row로 구성합니다.
- 열(Column) : 테이블 상에서의 단일 종류의 데이터를 나타냄. 특정 데이터 타입 및 크기를 가지고 있습니다.
- 행(Row) : Column들의 값의 조합. 레코드라고 불림. 기본키(PK)에 의해 구분. 기본키는 중복을 허용하지 않으며 없어서는 안 됩니다.
- Field : Row와 Column의 교차점으로 Field는 데이터를 포함할 수 있고 없을 때는 NULL 값을 가지고 있습니다.

### 2) DML(select, insert, update, delete)-1~4

- 핵심 개념
```
select
insert
update
delete
```

### 3) DDL(create, drop)


- 핵심 개념
```
create table
alter table
drop table
```


## Maven

### 1) Maven 이란?

### 2) Maven을 이용한 웹 어플리케이션 실습


## JDBC

- [JDBC 관련 실습 코드는 이곳에 저장하였습니다.](https://github.com/heonilp/study/tree/master/jdbcexam)

### 1) JDBC란?

- 핵심 개념
```
JDBC
DriverManager
Connection
Statement
ResultSet
```

- JDBC 개요

JDBC(Java Database Connectivity)의 정의

- 자바를 이용한 데이터베이스 접속과 SQL 문장의 실행, 그리고 실행 결과로 얻어진 데이터의 핸들링을 제공하는 방법과 절차에 관한 규약
- 자바 프로그램 내에서 SQL문을 실행하기 위한 자바 API
- SQL과 프로그래밍 언어의 통합 접근 중 한 형태
JAVA는 표준 인터페이스인 JDBC API를 제공
데이터베이스 벤더, 또는 기타 써드파티에서는 JDBC 인터페이스를 구현한 드라이버(driver)를 제공한다.



### 2) JDBC 실습-1~3

- 핵심 개념
```
JDBC
PreparedStatement
ResultSet
Connection 
```
