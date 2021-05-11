
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


