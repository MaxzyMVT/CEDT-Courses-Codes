package Student;

public class MySchool {
    public static void main(String[] args) {

        // Basic Inheritance

        Student s1 = new Student();
        s1.setName("Charles");
        System.out.println(s1);

        CEDTStudent s2 = new CEDTStudent();
        s2.setName("Zim");
        s2.setInternCompany("Google");
        System.out.println(s2);
    }
}
