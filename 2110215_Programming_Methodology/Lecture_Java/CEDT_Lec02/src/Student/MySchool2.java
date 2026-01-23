package Student;

public class MySchool2 {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.setName("Sam");


        // Upcasting (Automatic / Implicit Casting)

        Student s2 = new CEDTStudent(); // Can cast Subclass into Superclass because Subclass got only ONE Superclass
        // s2 is a Student variable but point to CEDTStudent block

        s2.setName("Logan");
        // CANNOT s2.setInternCompany("Google");  X // Be seen as a superclass
        System.out.println(s2); // Use subclass's Function


        // Downcasting (Manual / Explicit Casting)

        CEDTStudent s3 = (CEDTStudent) s2; // Casting Superclass into Subclass must be explicit because Superclass could get more than one Subclass
        // s3 is CEDTStudent variable

        s3.setInternCompany("Google");
        System.out.println(s3);


        // Downcasting Common Mistake -> Treat [new] Block of Superclass as a Subclass

//        CEDTStudent s4 = (CEDTStudent) s1; // RUNTIME ERROR
//        s4.setInternCompany("Google");
//        System.out.println(s4);
        
    }
}
