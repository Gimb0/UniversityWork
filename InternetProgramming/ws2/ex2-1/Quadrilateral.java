import java.lang.Math.*;
import java.lang.String;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Quadrilateral {
    // Corners of quadrilateral
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;

    private float getArea() {
        return 0;
    }

    protected void setCoordinates() {
        try {
            Scanner s = new Scanner(System.in);
            System.out.print("Input points as:\nx1\ny1\nx2\ny2\netc...\n");
            x1 = s.nextInt();
            y1 = s.nextInt();
            x2 = s.nextInt();
            y2 = s.nextInt();
            x3 = s.nextInt();
            y3 = s.nextInt();
            x4 = s.nextInt();
            y4 = s.nextInt();
        } catch(InputMismatchException inputMismatchException) {
            System.out.println("Error receiving input!");
        }
    }

    // 
    protected float distBetweenPoints(float x1, float y1, float x2, float y2) {
        float x = Math.abs(x1 - x2);
        float y = Math.abs(y1 - y2);
        return (float)Math.sqrt(x*x + y*y);
    }
}

class Parallelogram extends Quadrilateral {
    
}

class Trapezoid extends Quadrilateral {
    float height, base;
    Trapezoid() {
        System.out.println("Test");
    }

    private void calcBase() {
        base = distBetweenPoints(x3, y3, x4, y4);
    }

    // Find midpoints of (x1,y1)(x2,y2) and (x3.y3)(x4,y4)
    // and calculate distance between them
    void calcHeight() {
        float x1MidPoint = (x1+x2)/2;
        float x2MidPoint = (x3+x4)/2;
        float y1MidPoint = (y1+y2)/2;
        float y2MidPoint = (y3+y4)/2;
        height = distBetweenPoints(x1MidPoint, y1MidPoint, x2MidPoint, y2MidPoint);
    }

    private float getArea() {
        calcBase();
        calcHeight();
        return (float)0.5*base*height;
    }

    public static void main(String[] args) {
        Trapezoid t = new Trapezoid();
        t.setCoordinates();
        System.out.printf("Area is: %f\n", t.getArea());
    }
}