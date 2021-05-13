

## 23. 스토리지와 입출력: Chapter 11-15. Storage Management

- Mass storage , non- vlatile, HDD, NVM, magnetic taps, op disk ,cloud storage

- hard disk drives

- HDD 스케줄링 : minimize the adcess  time (or seek time), maximize data transfer bandwidth

- seek time : 데이터를 읽었을때 많이 읽은 latency, disk bandwidth

- FIFO 스케줄링 : fair, faster seek

- SCAN Scheduling :   < - >

- C-SCAN

- Boot Block : powered up

- RAID : Redundant Arrays of Independent Disks -> parallel, reliability

- Redundancy : Improvement of Reliability. , mirroring (쉬운방법)

- Parallelisim : Improvement in Performance. <- bit/block level striping

- RAID Levels : mirroring : 비쌈, striping : Reliability와 관계없음 // 레벨은 찾아서보기

- parity bit -> 1 even, 0 odd , 어느 비트가 깨졌는지 확인

- RAID Levels : 분류 schemes ,  cost-performance trade- offs 

- Two main jobs of a computer : I/O and computing.

- 대부분 커널보다 I/O 디바이스를 만드는 일이 많다.

- data-in ,data-out, status,  control register.

- Memory-mapped I/O

- Three type of I/O : Polling : or busy-waiting, interrupt. DMA

- DMA : direct Memory Access.

- Blocking I/O vs Non Blocking I/O  : wait.

- Asynchronous system call. : 요청만하고 자기 할일함.

- File System :스토지에 data를 쓰고 읽고 접근 , programs - file ,디렉토리

- Access methods sequential access, direct access

- 정리 : second stroage : HDD SSD NVM ->RAID, file system