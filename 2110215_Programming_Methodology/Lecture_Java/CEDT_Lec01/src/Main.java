public class Main {
    public static void main(String[] args) {

        SimpleCar testCar = new SimpleCar();
        SimpleCar myCar = new SimpleCar("Yotoya", "V45", 4);

        System.out.println(testCar);
        System.out.println(myCar);

        // Java Exception Handler
        try {
            System.out.println(8/0);
        }
        catch (ClassCastException e) {
            System.out.println(e);
            throw e;
        }
        catch (ArithmeticException e) {
            System.out.println("0/0");
        }
        finally {
            System.out.println("Yay!");
        }

        System.out.println("END!");
    }
}