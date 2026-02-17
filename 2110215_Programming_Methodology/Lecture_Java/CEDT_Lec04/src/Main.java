import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {

        /**
         * Short-form notation for "functional interface"
         * Lambda Expression [  (parameters...) -> <function>  ]
         */
        Circle circle1 = new Circle(10, () -> {
            System.out.println("WHAT???");
        });

        // Normal Interface
        Circle circle2 = new Circle(77);

        circle1.draw();
        System.out.println(circle1.getArea());
        circle1.speaker.talk();

        circle2.draw();
        System.out.println(circle2.getArea());
    }
}
