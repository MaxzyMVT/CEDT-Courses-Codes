import java.util.ArrayList;
import java.util.Collections;

public class Abstraction {

    public static void main(String[] args) {
        ArrayList<Animal> myAnimals = new ArrayList<>();
        myAnimals.add(new Dog());
        myAnimals.add(new Cat());
        myAnimals.add(new Bird());
        myAnimals.add(new Orca());


        // Polymorphism and Abstract Class makes code fairly shorter!
        for(Animal a : myAnimals){
            if(a.isLive) {
                a.say();
            }
        }
    }
}



abstract class Animal {
    // This is an "Abstract Class"
    /*
        Found common / similarity in multiple classes?
            -> Generalize it into Superclass
        * But the Superclass is too trivial?
            -> Use Abstract Class!

        [ Abstract Class ]
        - Cannot be "instantiate." (Cannot do "new Animal.") But can be used as a reference type variable
        - Mainly used for making subclasses to Polymorphism / Inheritance
     */

    protected boolean isLive;

    Animal() {
        this.isLive = true;
    }

    abstract void say();
    // This is an "Abstract Method"
    /*
            - It cannot have a body
            - Explicitly tells compiler that every subclass "must" have its own Polymorphism of this method
     */
}


class Dog extends Animal {

    @Override
    void say() {
        System.out.println("Woof!, woof!");
    }
}

class Cat extends Animal {

    @Override
    void say() {
        System.out.println("Meow!, meow!");
    }
}

class Bird extends Animal {

    @Override
    void say() {
        System.out.println("Jib!, jib!");
    }
}

class Orca extends Animal {

    @Override
    void say() {
        System.out.println("Baku!, baku!, bakunn~~!");
    }
}