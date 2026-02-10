public interface Shapable {
    // Implicit "public static final"
    String LABEL = "Shape";

    // Implicit "public abstract"
    void draw();
    double getArea();

    /*
        - Interface can't be instantiated but can be a reference type (Like abstract class)
        - Another classes can "implements" and inherits from this interface (Just like superclass)
        - Interface is just like one datatype

        *** Interface main property: One class can implements multiple interfaces, separated by comma
        - If a class implements multiple interfaces, there is no problem if those interfaces have methods with same signature
        - BUT it would be ERROR if those same signature methods have DIFFERENT RETURN TYPE

        - An interface can "extends" multiple interfaces
     */
}

class Circle implements Shapable {

    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    public Circle() {
        radius = 0;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public void draw() {
        System.out.println("Drawing Circle");
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
}
