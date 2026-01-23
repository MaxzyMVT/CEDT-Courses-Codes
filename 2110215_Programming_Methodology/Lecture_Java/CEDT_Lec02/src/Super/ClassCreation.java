package Super;

public class ClassCreation {

	// Creation of Subclass has to create all of its Ancestors

	public static void main(String[] args) {
		C c1 = new C(5);
	}
}

class A {
	A() {
		System.out.println("class A");
	}
}

class B extends A {
	B(int val) {
		// super(); -> Implicitly calls default constructor of A
		System.out.println("class B, value=" + val);
	}
}

class C extends B {
	C(int val) {
		super(val); // B has no default constructor, so we need to tell which constructor should be used
		System.out.println("class C, value=" + val);
		
	}
}