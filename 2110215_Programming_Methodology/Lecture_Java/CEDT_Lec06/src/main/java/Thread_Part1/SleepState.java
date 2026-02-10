package Thread_Part1;

class SleepThread extends Thread {
	public void run() {
		try {
			sleep(1);
			// Make ("Running" -- (sleep() or wait() or suspend()) --> "Blocked / Waiting" -- (notify() or notifyAll() or resume() or end of sleep) --> "Runnable")
			// sleep() -> interrupted sleep will throw runtime error
		} catch (InterruptedException e) {

		}
	}
}

public class SleepState {
	public static void main(String[] args) {
		SleepThread t = new SleepThread();
		System.out.println(t.getState());
		t.start();
		Thread.State s;
		do {
			s = t.getState();
			System.out.println(s);
		} while (s != Thread.State.TERMINATED);
	}

}
