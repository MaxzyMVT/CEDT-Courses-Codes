package logic;

import application.CPTSMachine;

public class Station {
    private String name;
    private int number;

    public Station(String name,int number) {
        this.setName(name);
        this.setNumber(number);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = Math.max(0, number);
    }
}