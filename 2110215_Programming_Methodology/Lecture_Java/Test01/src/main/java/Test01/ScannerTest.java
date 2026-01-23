package Test01;

import java.util.Scanner;

public class ScannerTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Input your floating point: ");
        double input = scanner.nextDouble();

        System.out.println("Your value is " + input);
        System.out.println("Your number times 4.5 is " + input * 4.5);

        scanner.close();
    }
}
