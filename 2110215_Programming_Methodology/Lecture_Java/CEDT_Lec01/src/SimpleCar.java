public class SimpleCar {

    // ------ Fields
    // All fields should be private (Encapsulation)

    private static final int MAX_SPEED = 120;
    private final String brand;
    private final String model;
    private int wheelNumber;

    // ------ Methods

    // Constructors

    public SimpleCar(String brand, String model, int wheelNumber) {
        this.brand = brand;
        this.model = model;
        this.wheelNumber = wheelNumber;
    }

    public SimpleCar() {
        this("TestBrand", "TestModel", 4);
    }


    // Getter & Setter for Encapsulation

    public String getBrand() {
        return brand;
    }

    public String getModel() {
        return model;
    }

    public int getWheelNumber() {
        return wheelNumber;
    }

    public void setWheelNumber(int wheelNumber) {
        this.wheelNumber = Math.max(wheelNumber, 1);
    }

    // toString() for printing
    @Override
    public String toString() {
        return "SimpleCar{" +
                "brand='" + brand + '\'' +
                ", model='" + model + '\'' +
                ", wheelNumber=" + wheelNumber +
                '}';
    }
}
