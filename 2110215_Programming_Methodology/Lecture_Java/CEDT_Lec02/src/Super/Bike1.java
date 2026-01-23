package Super;

// 1 File Must have no more than 1 Public Class, but can contain multiple classes

class Vehicle1 {
	int speed = 50;
	void display() {
		System.out.println(speed);
	}

}

class Bike1 extends Vehicle1 {
	int speed = 100;

	void display() {
		System.out.println(speed);
		System.out.println(super.speed);// will print speed of Vehicle now
		super.display();
	}

	public static void main(String args[]) {
		Vehicle1 b = new Bike1();
		b.display();
	}
}