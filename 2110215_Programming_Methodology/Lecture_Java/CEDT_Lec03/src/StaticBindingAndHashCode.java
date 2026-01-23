public class StaticBinding {
    public static void main(String[] args) {
        A a = new A();


        a.print();
        a.print2();
    }
}

class A {
    // Static Binding
    static void print() {
        System.out.println("used A");
    }
    void print2() {
        System.out.println("used A 2");
    }


    // int hashCode() is a function to define how to hash this object into integer and return the hash code
    // Every objects that are equal should have the same hash code

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
}
