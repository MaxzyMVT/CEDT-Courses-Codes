package Test01;

public class Student {
    private String ID;
    private String name;

    public Student(String ID, String name) {
        setID(ID);
        setName(name);
    }

    public Student() {
        this("0000000000","nameless");
    }

    public Student(Student another) {
        this(another.ID,another.name);
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String toString() {
        return "(" + ID + ", " + name + ")";
    }
}
