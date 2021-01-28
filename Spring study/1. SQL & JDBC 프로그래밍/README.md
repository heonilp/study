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


- 추가적인 정리 데이터베이스 중요함


- 트랙잭션 : 데이터베이스 내에서 한꺼번에 수행되어야할 일련의 연산들
트랙잭션 의 모든 연산은 반드시 한꺼번에 완료가 되야 하며
그렇지 않은경우에는 한꺼번에 취소되어야 하는 원자성을 가지고 있습니다

- 한꺼번에 완료가 된경우에는 성공적인 종료 COMMIT 이 경우에는 작업결과는 데이터베이스에 반영이 되게 됩니다.

- 취소가 된경우에는 비정상적인 종료 ROLLBACK

* 원자성(Atomicity) - 분리 할수 없는 하나의 단위로 작업은 모두 완료되거나 모두 취소 되어야 합니다. 
* 일관성(Consistency) - 사용되는 모든 데이터는 일관되어야 합니다. 
* 격리성(Isolation) - 접근하고 있는 데이터는 다른 트랜잭션으로 부터 격리 되어야 합니다. 
트랜잭션이 진행되기전과 완료된 후에 상태를 볼수 있지만 트랜잭션이 진행되는 중간 데이터는 볼수 없습니다. 
* 영속성(Durability) - 트랙잭션이 정상 종료되면 그 결과는 시스템에 영구적으로 적용되어야 합니다. 
* 순차성(Sequentiality) - 데이터를 다시 로드하고 트랜잭션을 재생하여 원래 트랜잭션이 수행된 후의 상태로 데이터를 되돌리는 것을 말합니다.


## 생각해보기

### 1. Database와 DBMS를 개발자가 아닌 사람에게 설명해보세요.
- 엑셀처럼 특정 행과 열이 테이블이 되있는 데이터를 잘 관리하기위한 프로그램
 
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

-  데이터 조작어(Data Manipulation Language, DML)의 종류

데이터 조작어는 모두 동사로 시작합니다.

시작하는 동사에 따라서 다음과 같은 4가지 조작어가 있습니다.
```
SELECT – 검색
INSERT - 등록
UPDATE - 수정
DELETE - 삭제
```

- SELECT 구문 예제(전체 데이터 검색)

전체 데이터 검색
SELECT 뒤에 * 를 기술함으로써 나타낼 수 있다.
예제 : departments 테이블의 모든 데이터를 출력하시오.
```
SELECT * FROM  DEPARTMENT;
```

- SELECT 구문 예제(특정 컬럼 검색)

SELECT 뒤에 컬럼을 콤마(,)로 구별해서 나열
예제 : employee 테이블에서 직원의 사번(empno), 이름(name), 직업(job)을 출력하시오.

어떤 칼럼이 있는지는 desc명령으로 확인
```
select empno, name, job from employee;
```


- SELECT 구문 예제(컬럼에 Alias부여하기)

컬럼에 대한 ALIAS(별칭)을 부여해서 나타내는 칼럼의 HEADING을 변경할 수 있다.
예제 : employee 테이블에서 직원의 사번(empno), 이름(name), 직업(job)을 출력하시오.
```
select empno as 사번, name as 이름, job as 직업 from employee;
```

- SELECT 구문 예제(컬럼의 합성(Concatenation))

문자열 결합함수 concat 사용
예제 : employee 테이블에서 사번과 부서번호를 하나의 칼럼으로 출력하시오.
```
SELECT concat( empno, '-', deptno) AS '사번-부서번호' 
FROM employee;
```


- SELECT 구문 예제(중복행의 제거)

중복되는 행이 출력되는 경우, DISTINCT 키워드로 중복행을 제거
예제1 : 사원 테이블의 모든 부서번호 출력하시오. (사원 수 만큼 출력된다.)
```
select deptno from employee;
```

- select 구문 예제(중복행의 제거)
예제2 : 사원 테이블의 부서번호를 중복되지 않게 출력하시오.
```
select distinct deptno from employee;
```


- SELECT 구문 예제(정렬하기)

예제 : employee 테이블에서 직원의 사번(empno), 이름(name), 직업(job)을 출력하시오.
단, 이름을 기준으로 오름차순 정렬합니다.
```
select empno, name, job from employee order by name;
select empno as 사번, name as 이름, job as 직업 from employee order by 이름;
```

- SELECT 구문 예제(정렬하기)

예제 : employee 테이블에서 직원의 사번(empno), 이름(name), 직업(job)을 출력하시오.
단, 이름을 기준으로 내림차순 정렬합니다.
```
select empno, name, job from employee order by name desc;
```

- 산술비교 연산자
예제 : employee 테이블에서 고용일(hiredate)이 1981년 이전의 사원이름과 고용일을 출력하시오
```
select name, hiredate from employee where hiredate < '1981-01-01';
```


- 논리연산자
예제 : employee 테이블에서 부서번호가 30인 사원이름과 부서번호를 출력하시오.
```
select name, deptno from employee where deptno = 30;
```

- IN 키워드
예제 : employee 테이블에서 부서번호가 10또는 30인 사원이름과 부서번호를 출력하시오.
```
select name, deptno from employee where deptno in (10, 30);
```

- select 구문 예제(특정 행 검색-where절)-3
LIKE 키워드
와일드 카드를 사용하여 특정 문자를 포함한 값에 대한 조건을 처리
% 는 0에서부터 여러 개의 문자열을 나타냄
_ 는 단 하나의 문자를 나타내는 와일드 카드
예제 : employee 테이블에서 이름에 'A'가 포함된 사원의 이름(name)과 직업(job)을 출력하시오
```
select name, job from employee where name like '%A%';
```


- SELECT 구문(함수의 사용)

UCASE, UPPER
```
 SELECT UPPER('SEoul'), UCASE('seOUL');
```

LCASE, LOWER
```
SELECT LOWER('SEoul'), LCASE('seOUL');
```

substring
```
SELECT SUBSTRING('Happy Day',3,2);
```

LPAD, RPAD (? ,* 로 치환)
```
SELECT LPAD('hi',5,'?'),LPAD('joe',7,'*');
```

TRIM, LTRIM, RTRIM

ABS(x) : x의 절대값을 구합니다.
```
SELECT ABS(2), ABS(-2);
```

MOD(n,m) % : n을 m으로 나눈 나머지 값을 출력합니다.
```
SELECT MOD(234,10), 253 % 7, MOD(29,9);
```

FLOOR(x) : x보다 크지 않은 가장 큰 정수를 반환합니다. BIGINT로 자동 변환합니다.
CEILING(x) : x보다 작지 않은 가장 작은 정수를 반환합니다.
ROUND(x) : x에 가장 근접한 정수를 반환합니다.
POW(x,y) POWER(x,y) : x의 y 제곱 승을 반환합니다.
GREATEST(x,y,...) : 가장 큰 값을 반환합니다.
LEAST(x,y,...) : 가장 작은 값을 반환합니다.
CURDATE(),CURRENT_DATE : 오늘 날짜를 YYYY-MM-DD나 YYYYMMDD 형식으로 반환합니다.
CURTIME(), CURRENT_TIME : 현재 시각을 HH:MM:SS나 HHMMSS 형식으로 반환합니다.
NOW(), SYSDATE() , CURRENT_TIMESTAMP : 오늘 현시각을 YYYY-MM-DD HH:MM:SS나 YYYYMMDDHHMMSS 형식으로 반환합니다. 
DATE_FORMAT(date,format) : 입력된 date를 format 형식으로 반환합니다.
PERIOD_DIFF(p1,p2) : YYMM이나 YYYYMM으로 표기되는 p1과 p2의 차이 개월을 반환합니다.



- SELECT 구문 예제(그룹함수)
예제 : employee 테이블에서 부서번호가 30인 직원의 급여 평균과 총합계를 출력하시오.
```
SELECT AVG(salary) , SUM(salary)
FROM employee
WHERE deptno = 30;
```

- SELECT 구문 예제(그룹함수와 groupby 절)
예제 : employee 테이블에서 부서별 직원의 부서번호, 급여 평균과 총합계를 출력하시오.
```
SELECT deptno, AVG(salary) , SUM(salary)
FROM employee
group by deptno;
```


- 데이터 입력 (INSERT문)
```
INSERT INTO 테이블명(필드1, 필드2, 필드3, 필드4, … ) 
        VALUES ( 필드1의 값, 필드2의 값, 필드3의 값, 필드4의 값, … )

INSERT INTO 테이블명
        VALUES ( 필드1의 값, 필드2의 값, 필드3의 값, 필드4의 값, … )
```

데이터 입력 실습 (INSERT문)

예제 : ROLE테이블에 role_id는 200, description에는 'CEO'로 한건의 데이터를 저장하시오.
```
insert into ROLE (role_id, description) values ( 200, 'CEO');
```

- 데이터 수정(UPDATE문)
```
 UPDATE  테이블명
        SET  필드1=필드1의값, 필드2=필드2의값, 필드3=필드3의값, …
   WHERE  조건식

```
- 데이터 수정 실습(UPDATE문)
예제 : ROLE테이블에 role_id가 200일 경우 description을 'CTO'로 수정하시오.
```
update ROLE
set description = 'CTO'
where role_id = 200;
```

- 데이터 삭제(DELETE문)
예제 : ROLE테이블에서 role_id는 200인 정보를 삭제하시오.
```
delete from ROLE where role_id = 200;
```


## 생각해보기

### 사원의 이름과 그 사원이 속한 부서명을 구하려면 어떻게 해야할까요?

이 경우엔 EMPLOYEE 테이블과 DEPARTMENT 테이블을 조인(Join)해야 합니다. 
select문과 join에 대해 알아보세요.
- SQL Join 이란 2개 이상의 테이블로부터 관련있는 컬럼에 기초하여 행을 결합하는데 사용된다.
- where절을 통해서 테이블끼리 번호가 같다고 놓으면 됩니다.

```
select name.이름, d.부서명
from EMPLOYEE e, DEPARTMENT d
where  e.번호 = d.번호
```

- INNER JOIN이란 FROM 테이블과 JOIN 테이블에서 ON 조건식이 만족하는 레코드를 선택한다. ON 조건식이 만족하지 않는다면 어느 두 테이블의 필드도 결과로서 나오지 않으므로 레코드의 기존 필드 값이 NULL이 아닌 이상 NULL을 볼 수 없다.

- LEFT JOIN이란 FROM 테이블의 모든 레코드와 JOIN 테이블의 ON 조건식이 만족하는 레코드를 반환한다. 일치하는 항목이 없다면 JOIN 테이블의 필드 값은 NULL이 된다.

- RIGHT JOIN이란 JOIN 테이블의 모든 레코드와 FROM 테이블의 ON 조건식이 만족하는 레코드를 반환한다. 일치하는 항목이 없다면 FROM 테이블 필드 값은 NULL이 된다.

- FULL JOIN이란 FROM과 JOIN테이블의 모든 레코드를 반환한다. ON 조건식을 만족하는 레코드가 없다면 관련 테이블의 필드 값은 NULL이 된다.

### 3) DDL(create, drop)


- 핵심 개념
```
create table
alter table
drop table
```

```
create table 테이블명( 
          필드명1 타입 [NULL | NOT NULL][DEFAULT ][AUTO_INCREMENT], 
          필드명2 타입 [NULL | NOT NULL][DEFAULT ][AUTO_INCREMENT], 
          필드명3 타입 [NULL | NOT NULL][DEFAULT ][AUTO_INCREMENT], 
          ........... 
          PRIMARY KEY(필드명) 
          );
```

- 테이블 생성 실습

EMPLOYEE와 같은 구조를 가진 EMPLOYEE2 테이블을 생성하시오.
```
CREATE TABLE EMPLOYEE2(   
            empno      INTEGER NOT NULL PRIMARY KEY,  
           name       VARCHAR(10),   
           job        VARCHAR(9),   
           boss       INTEGER,   
           hiredate   VARCHAR(12),   
           salary     DECIMAL(7, 2),   
           comm       DECIMAL(7, 2),   
          deptno     INTEGER);
```

- 테이블 수정 (컬럼 추가 / 삭제)
```
alter table 테이블명
          add  필드명 타입 [NULL | NOT NULL][DEFAULT ][AUTO_INCREMENT];

alter table 테이블명
         drop  필드명;
         
```
- 테이블 수정 실습 (컬럼 추가)
```
실습 – EMPLOYEE2 테이블에 생일(birthdate)칼럼을 varchar(12)형식으로 추가하시오.
alter table EMPLOYEE2
add birthdate varchar(12);
```

- 테이블 수정 실습 (컬럼 삭제)
```
실습 – EMPLOYEE2 테이블의 생일(birthdate)칼럼을 삭제하시오.
alter table EMPLOYEE2
drop birthdate;​

```


- 테이블 수정 (컬럼 수정)
```
alter table  테이블명
     change  필드명  새필드명 타입 [NULL | NOT NULL][DEFAULT ][AUTO_INCREMENT];

```
- 테이블 수정 실습 (컬럼 수정)
```
실습 – EMPLOYEE2 테이블의 부서번호(deptno)를 dept_no로 수정하시오
alter table EMPLOYEE2
change deptno dept_no int(11);
```

- 테이블 이름 변경
```
alter table  테이블명 rename 변경이름
```

- 테이블 이름 변경 실습
실습 – EMPLOYEE2 테이블의 이름을 EMPLOYEE3로 변경하시오.
```
alter table EMPLOYEE2
rename EMPLOYEE3;
```

- 테이블 삭제하기
```
drop table 테이블이름;
```


- 테이블 삭제 실습

* 테이블 삭제 후 desc 명령을 수행하면, 존재하지 않는 테이블이라고 표시됩니다.
실습 – EMPLOYEE2 테이블을 삭제하시오.

```
drop table EMPLOYEE2;
```


## 생각해보기

### 칼럼의 길이가 10인데, 해당 칼럼에 값이 저장되어 있습니다.  이 때 칼럼의 길이를 5로 바꾼다면 어떤 일이 벌어질까요?
- 문자열을 저장하는 데이터 타입인 CHAR와 VARCHAR 차이점에 대해 알아보고 어떤 상황에서 CHAR 또는 VARCHAR 를 선택하는 것이 효율적인지 생각해봅시다.

### 문자열 데이터 타입에는 문자셋을 지정할 수 있습니다. 문자셋에 따라 해당 필드가 차지하는 공간 크기를 한번 계산해보자. (예: VARCHAR(10) CHARACTER SET UTF8; 은 몇 Byte 크기를 차지할까요? ASCII 일때는 또 몇 Byte 크기를 가질까요?

1. 데이터가 잘리기 때문에 "ERROR 1265 (01000): Data truncated for column 'name' at row 1"와 같은 에러가 발생하고 해당 명령은 실행되지 않습니다.


2. CHAR 데이터 타입은 길이가 고정되기 때문에 저장 및 검색이 빠르지만 저장공간을 낭비할 수 있고, VARCHAR 데이터 타입은 길이가 가변적이기 때문에 저장 및 검색이 느리지만 저장공간을 낭비하지 않습니다.
CHAR 데이터 타입은 고정된 데이터인 성별, 주민번호 등을 저장 및 연산할 때 쓰이면 좋고, VARCHAR은 가변적인 데이터인 Content, Address 등을 저장 및 연산할 때 쓰이면 좋습니다.


3. https://dev.mysql.com/doc/refman/8.0/en/charset-charsets.html 를 통해서 MySQL이 지원하는 character sets를 볼 수 있으며 VARCHAR(10) CHARACTER SET UTF8;은 30바이트의 크기를 가지며 ASCII 일 때는 10바이트의 크기를 가집니다.

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
