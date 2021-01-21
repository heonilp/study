
//커맨드패턴 : 명령하다.
//커맨드패턴을 통해서 명령을 객체화할 수 있다.

public class Main {

	public static void main(String[] args) {

		//큐에 넣고 명령을 실행하는 것

		//작업 1 -> 작업 2 -> 작업 3 실행
		List<Command> list = new LinkedList<>();

		list.add(new Commend()) {
			@Override
			public void execute () {
				System.out.println("작업 1");
			}
		});

		list.add(new Commend()) {
			@Override
			public void execute () {
				System.out.println("작업 2");
			}
		});

		list.add(new Commend()) {
			@Override
			public void execute () {
				System.out.println("작업 3");
			}
		});


		for(Commend commend : list) {
			commend.execute();
		}

		//또는 우선순위 큐에 넣어서 작업 하루 있다.
		PriorityQueue<Commend> queue = new PriorityQueue<>();

		queue.add(new(StringPrintCommend("ABDC")));
		queue.add(new(StringPrintCommend("ABC")));
		queue.add(new(StringPrintCommend("AB")));
		queue.add(new(StringPrintCommend("A")));

		//A->AB->ABC ->ABDC 실행
		for((Commend commend :queue) {
			commend.execute();
		}
	}
}
