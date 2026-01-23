public class StaticBindingAndHashCode {
    public static void main(String[] args) {
        A a = new A();  // 'a' is a Reference of A
        a.print();
        a.print2();

        System.out.println("------------------------------------------");

        a = new B();    // 'a' is now Point to new Object B, which is 'allowed' because of Upcasting
        a.print();  // Calls A's because of Static Binding (Use Reference's type's function)
        a.print2(); // Calls B's because of Dynamic Binding (Polymorphism / Override) (Use That Pointing Object's Function)
        a.printA(); // Is allowed due to Inheritance

        System.out.println("------------------------------------------");

        B b = (B) a;    // Downcasting
        b.print();  // Calls B's because of Static Binding (Use Reference's type's function)
        b.printB(); // Is visible by Changing the Reference type to "B"

        System.out.println("------------------------------------------");

        b.uniqueName = "ASD";
        System.out.println(b.hashCode());
    }
}

class A {

    static void print() {
        System.out.println("used A");
    }
    void print2() {
        System.out.println("used A 2");
    }
    void printA() {
        System.out.println("I am A");
    }


    // int hashCode() is a function to define how to hash this object into unique integer and return the hash code
    // Every objects that are equal should have the same hash code
    // Every objects that are not equal should have distinct hash code -> useful in hash tables etc.

    String uniqueName;



    @Override
    public int hashCode() {
        return uniqueName == null ? 0 : uniqueName.hashCode();
    }
    @Override
    public boolean equals(Object obj) {
        if (obj == this) {
            return true;
        }
        if (obj == null || obj.getClass() != this.getClass()) {
            return false;
        }
        A another = (A) obj;
        return hashCode() == another.hashCode();
    }
}


class B extends A {

    // Static Binding (Cannot Override -> is not Polymorphism)
    static void print() {
        System.out.println("used B");
    }

    // Dynamic Binding -> Polymorphism
    @Override
    void print2() {
        System.out.println("used B 2");
    }
    void printB() {
        System.out.println("I am B");
    }
}
