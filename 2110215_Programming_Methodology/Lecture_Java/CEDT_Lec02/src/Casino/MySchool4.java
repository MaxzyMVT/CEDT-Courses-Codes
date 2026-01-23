package Casino;

import Student.CEDTStudent;

public class MySchool4 {

    // Access Modifier
    /*
        - private: Only it own class sees
        - default: (package-private) Also let the same Package sees
        - protected: Also let Descendants and Package sees
        - public: Everyone sees
    */

    public static void main(String[] args) {
        CEDTStudent s1 =  new CEDTStudent();

        // Different Package and NOT an Ancestor -> failed

        /*
        s1.fridayActivities = "YAYAY"; // Default (Package)
        System.out.println(s1.fridayActivities);


        s1.internCompany = "Nah"; // Protected
        System.out.println(s1.internCompany);
         */

        System.out.println(CEDTStudent.FULL_DEPARTMENT_NAME); // Public
    }

}
