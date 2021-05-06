
## 15. 동시성 제어의 고전적 문제들: Chapter 7. Synchronization Examples (Part 1)

1. The Bounded-Buffer problem

2. The Reader-Writers problem : 프로세스가 동시성있게 돌음, 어떤 프로세스는 읽기 만함, 어떤프로세스는 일고 쓰기 둘다함, (e.g. 데이터베이스도 read, wirte)

3. The Dining-Philosophers problem

## 16. 철학자들은 왜 굶어 죽었을까?: Chapter 7. Synchronization Examples (Part 2)

- The Dining-Philosophers problem //오른쪽, 왼쪽 젓가락을 공유하면 문제가 일어남. 임계구역에 대해서 동기화하면되지만 리소스가 적으면 문제가 남, 기아까지 x

- 모니터 솔루션 : 양쪽의 젓가락을 이용할때 가능, 상태를 세개로 나눔-> 생각, 배고픔, 먹는상태 ->하지만 밥못먹는 사람이 생기기 마련이다.

- Thread-Safe Concurrent Applications

- race conditions and liveness hazards such as dealock

- Thread-safe(Re-entrancy, Thread-local storage, Mutual exclusion,Atomic operations)

1. Transactioinal Memory : 트랙잭션 , Atomic operations

2. OpenMP (#progma omp critical)

3. Funcional Programming Langugae. / H/W로 속도로 가능해짐