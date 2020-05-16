import java.lang.String;

public class Vehicle {
    private int id;
    private static int nextId;
    private String colour, type;

    Vehicle() {
        id = nextId;
        nextId++;
    }

    Vehicle(String c, String t) {
        id = nextId;
        nextId++;
        colour = c;
        type = t;
    }

    public int getID() {
        return id;
    }

    public String getColour() {
        return colour;
    }

    public String getType() {
        return type;
    }

    public int getNextID() {
        return nextId;
    }

    public void setVariables(String c, String t) {
        colour = c;
        type = t;
    }
}