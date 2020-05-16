import java.lang.String;

public class VehicleTest {
    
    public static void main(String[] args) {
        Vehicle One = new Vehicle();
        One.setVariables("Green", "Car");

        Vehicle Two = new Vehicle();
        Two.setVariables("Red", "Motorbike");

        Vehicle Three = new Vehicle("Yellow", "Bus");

        System.out.println("Vehicles are:\n");
        System.out.printf("Vehicle:\t%x,\tColour:\t%s,\tType:\t%s\n", One.getID(), One.getColour(), One.getType());
        System.out.printf("Vehicle:\t%x,\tColour:\t%s,\tType:\t%s\n", Two.getID(), Two.getColour(), Two.getType());
        System.out.printf("Vehicle:\t%x,\tColour:\t%s,\tType:\t%s\n", Three.getID(), Three.getColour(), Three.getType());
    }
}