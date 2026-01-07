package Test01;

public class Hello {
    public static void sayHello() {
        System.out.println("\nHello World!");

        String s = "ABCDE";
        System.out.println(s.charAt(2) + '\n');

        int[] arr = {1,2,3,4,5};
        modify(arr);
        System.out.println(arr[2]);

        Student james = new Student("6833333321", "James");
        james.setName("JamesBond007");
        System.out.println(james);
    }

    public static void modify(int[] INTS) {
        INTS[2] = 5;
    }

    public static void main(String[] args) {
        sayHello();
    }

}
