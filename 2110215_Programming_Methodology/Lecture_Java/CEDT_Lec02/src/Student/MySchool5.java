package Student;

public class MySchool5 {
    public static void main(String[] args) {

        // static and final

        Student s1 = new Student("Toe");
        Student s2 = new Student("Chate");

        s1.studentNum = 5;
        s2.studentNum = 10;
//        s2.SEVENEIGHTNINE = 10; Cannot Change Value
        System.out.println(CEDTStudent.studentNum);
        System.out.println(Student.studentNum);
        System.out.println(s1.SEVEN_EIGHT_NINE);
    }
}
