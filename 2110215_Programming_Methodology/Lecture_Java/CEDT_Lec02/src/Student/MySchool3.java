package Student;

import java.util.ArrayList;

public class MySchool3 {
    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<>();
        students.add(new Student());
        students.get(0).setName("Toe");

        students.add(new CEDTStudent());
        students.get(1).setName("Chate");

        students.add(new UndergraduateStudent(""));
        students.get(2).setName("Pop");

        for (Student s : students) {
            // "Polymorphism" | Same Code, Different Actions!!!
            System.out.println(s);
        }

        hello(new Student());
        hello(new UndergraduateStudent("Aoi"));
        hello(new CEDTStudent());
    }

    // "Generic Method" for Student -> Its Subclasses can use it!
    public static void hello(Student s) {
        if (s instanceof CEDTStudent) { // Check if s is an instance of CEDTStudent class
            System.out.println("CEDT loves Prog Meth!");
        }
            System.out.println(s);
    }
}
