package Student;

import java.util.Arrays;

public class CEDTStudent extends Student {
    String fridayActivities;
    public static final String FULL_DEPARTMENT_NAME = "Computer Engineering and Digital Technology";
    protected String internCompany;

    public String getInternCompany() {
        return internCompany;
    }

    public void setInternCompany(String internCompany) {
        this.internCompany = internCompany;
    }

    @Override // This is a marker to tell that this function would override parent's function with the same signature
    public String toString() {
        return "CEDTStudent{" +
                "internCompany='" + internCompany + '\'' +
                ", name='" + name + '\'' +
                ", test=" + Arrays.toString(test) +
                ", courseGrade='" + courseGrade + '\'' +
                '}';
    }
}
