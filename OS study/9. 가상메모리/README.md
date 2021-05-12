
## 21. 가상 메모리와 디맨드 페이징: Chapter 10. Virtual Memory (Part 1)

- 가상메모리와 디맨트 페이징

- Virtual Memory 물리적 메모리보다 커도 프로그램이 돌아간다

- 매우 효율적이다. file이나 라이브러리 공유

- Virtual Address Space : 0번지에서 논리적 주소가 시작 text -> data ->heap -><-> stack, 연속적메모리

- Virtual Memory 은 files , memory 공유하는 페이지에다가 접근한다. - 두개이상의 프로세스 메모리 공유 가능

- 메모리에 로딩하는 작업을 먼저해야함 ->페이지 단위로 올리자, 요청할 때만 올리자.(demand paging)

- valid-invalid bit : legal and in momeoy, / not valid , in secondary storage 더티비트

- Page Fault -> 1. check an internal table, 2.  page it in

- 3. free frame 4. read the desired page 5. page table in ->v 로드 6. restart

- Pure Demand Paging : 요청할때만 가져옴, 그때그때 페이징을 로딩해야되기 때문에 단점임

- Locality of Reference 컴퓨터 과학에서 로컬 리티 원칙이라고도하는 참조 로컬 리티는 프로세서가 짧은 시간 동안 동일한 메모리 위치 세트에 반복적으로 액세스하는 경향입니다. 참조 국부성, 디맨드 페이징에 참조국부성을 낼수있다.

- Page table : valid , invalid mark 한다.

- Secondary memory (=swap space)

- Instruction Restart 

- Free Frame List

- effective access time / EAT = (1-p) X ma +p (page fauit time)

- Hoe much time is needed to service a page fault?

1. three major activities.

2. Service the page-fault interrupt.

3. Read in the page

4. Restart the process

- Consider a system   8 miliseconds 200 nanosecods

- EAT = (1-p) X 200 +p 8,000,000 = 200 + 7,999,800 X p ( p =0.001) = 8.2 ms

- Copy -on Write : copy a shared page only when a process writes to a shared page.


## 22. 페이지 교체 알고리즘: Chapter 10. Virtual Memory (Part 2)

- no free frames - ex 40 frames and run 6 processes, 10 pages but, 5pages

- page Replacement , if no frame is free, find one that is not currently being used and free it.

- vicime -> page out victim page - change to invalid - page in desired page - reset page table for new page.

- Frame-allocation algorithm - how many frames allocated to each process?

- page replacement algorithm / select the frames that are to be replaced

- reference string :the number of page faults (minimize it!)

- FIFO page replacement  : the oldest page - replace

- Belady's Anomaly : The page-fault rate may increase /as the number of allocated frames increases.

- Optimal Page Replacement : lowst page falut rate  / OPT or MIN  가장쓸일이없는걸 교체하자. future knowledge - 98%자랑한다 99%자랑한다.

- Recall the Shortest-Job-First CPU scheduler 미래와 과거를 보자

- looking backeward : brought in?

- looing forward : used?

- LRU Page Replacement: Least Recently Used 사용될 가능성없는걸 victim으로 하자(합리적)

- LRU policy : 자주사용, 프레임이 언제마지막에 사용됐는지 알아야함, counter 이용방법: 레퍼런스 할때마다 counter를 복사한다. 값이 가장 된걸(가장오래된걸)로 교체해야한다. 스택이용방법 : 페이지의번호를 스택에넣음, 중간에 빠져나간다. (그래서 더블링크드리스트로 구현하라)

- reference bit 

- Second-Change Algorith : FIFO algo 0->replace / 1-> second change

- equal vs proportional 

- global vs local 

- Thrashing (스레싱) - 프로세스가 페이지 in out할때 바뻐서 지일을 못함

- 하나의 프로세스가 어느 정도의 충분한 프레임을 갖고 있지 않다면 페이지 부재가 발생하여 프레임 안에 있는 사용중인 어떤 페이지를 교체해야 하는데, 이러한 페이지 부재가 계속 발생하여 프로세스가 수행되는 시간보다 페이지에 교체되는 시간이 더 많아지는 경우

- the degree of multiprogramming

- woring-set model : working set window / 최근 page / 워킹셋만 로딩하게해줌