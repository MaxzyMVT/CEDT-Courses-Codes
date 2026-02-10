package Thread_Part1;

public class StateTest {
	public static void main(String[] args) {
		Thread t = new Thread();
		System.out.println(t.getState());
		t.start();	// Make ("New" -> "Runnable" -- (.run()) <--> "Running" -> "Dead")
		Thread.State s;
		do {
			s = t.getState();
			System.out.println(s);
		} while (s != Thread.State.TERMINATED);
	}

}
