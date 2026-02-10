package Thread_Part1;

class MyRunnable implements Runnable {
	@Override
	public void run() {
		for (int i = 0; i < 100; ++i)
			System.out.print(Thread.currentThread().getName());
	}
}

public class RunnableTest {
	public static void main(String[] args) {
		Runnable r = new MyRunnable();
		new Thread(r, "A").start(); // try .run() -> will not start thread work and getName() will return "main"
		new Thread(r, "B").start(); // try .run()
	}
}
