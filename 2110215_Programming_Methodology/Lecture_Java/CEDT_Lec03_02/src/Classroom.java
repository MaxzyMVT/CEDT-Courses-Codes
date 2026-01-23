import java.util.ArrayList;

public class Classroom {
    private ArrayList<String> students;

    public Classroom() {
        this.students = new ArrayList<>();
    }

    public ArrayList<String> getStudents() {
        return this.students;
    }

    public void addStudent(String student) {
        getStudents().add(student);
    }

    public int sizeOfStudents() {
        return getStudents().size();
    }
}
