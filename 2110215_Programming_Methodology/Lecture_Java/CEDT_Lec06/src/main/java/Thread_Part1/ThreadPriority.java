package Thread_Part1;

public class ThreadPriority {
	public static void main(String[] args) {
		Thread a = new MyThread2("A");
		Thread b = new MyThread2("B");
		a.setPriority(Thread.MAX_PRIORITY);
		/*
		(Priority value from 1 --> 10)
		Thread.MIN_PRIORITY -> 1
		Thread.NORM_PRIORITY -> 5
		Thread.MAX_PRIORITY -> 10
		 */
		a.start();
		b.start();
	}
}

class MyThread2 extends Thread {
	public MyThread2(String n) {
		super(n);
	}

	public void run() {
		for (int i = 0; i < 100; ++i)
			System.out.print(getName());
	}
}