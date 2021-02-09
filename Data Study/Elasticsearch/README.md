# 엘라스틱서치(Elasticsearch)란 무엇인가?

ElasticSearch는 오픈 소스이고 REST 기반의 실시간 검색 및 분석 엔진이다.
Java로 작성되어졌으며 아파치 Lucene 기반으로 검색 기능 및 REST-Based API (JSON Over HTTP Protocol)를 지원한다.

엘라스틱서치는 확장성이 매우 좋은 오픈소스 검색엔진입니다. 여러분이 많은 양의 데이터를 보관하고 실시간으로 분석할 수 있게 해줍니다.

엘라스틱서치는 JSON 문서 파일과 함께 동작합니다. JSON 문서 파일의 내부적 구조를 이용하여, 데이터를 파싱합니다. 파싱을 통해 여러분이 필요한 정보에 대한 거의 실시간 검색(Near real time)을 지원합니다.

## 특징
- 엘라스틱서치는 실시간, 분산형, 분석 엔진이다.
- 오픈 소스이며, 자바로 개발되었다.
- 테이블과 스키마 대신에 문서 구조로 된 데이터를 사용합니다.


## 엘라스틱서치를 설치하기

자바를 설치해야 합니다. 8버전이나 그보다 높은 버전을 설치해야합니다.
엘라스틱서치를 설치해야 합니다. [www.elastic.co/kr](https://www.elastic.co/kr/elasticsearch/) 에서 다운로드할 수 있습니다. 
그리고 여러분의 운영체제에 맞춘 몇가지 단계를 따라가면 됩니다. 
만일 여러분이 Homebrew가 설치된 맥 운영체제를 사용한다면, 
그냥 brew install elasticsearch 명령어 한 줄로 간단하게 엘라스틱서치를 설치할 수 있습니다.


## ElasticSearch 저장 구조에는 Index, Type, Document, Field, Mapping 용어들이 존재한다.

```
Index란?
RDB의 데이타베이스와 유사하다.
 
Type이란?
RDB의 테이블과 유사하다.
 
Document란?
테이블의 Row와 유사하다.
JSON 문서로 되어 있다. (key, value)
 
Field란?
엘라스틱 서치의 문서는 JSON이다. JSON의 프로퍼티를 엘라스틱 서치에서는 필드라고 부른다.
RDB 테이블의 컬럼과 유사하다.
 
Mapping이란?
RDB의 스키마와 유사하다.
Mapping은 이해하기 어려우니 아래 이미지 한장 첨부한다.
http://localhost:9200/nklee/phone/1 POST 요청과 함께 아래 JSON데이터를 전송하면 Elasticsearch에서 mapping을 자동 생성해 준다.
{
  "number": "010-1111-1111",
  "author":"nklee"
}

```

## 엘라스틱 서치
- Get = select

- Put = update

- Post = insert

- Delete = delete