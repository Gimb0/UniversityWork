import java.util.Scanner;

public class Addition {
    public static void main(String args[]) {
        // Scanner variable to retrieve input
        Scanner input = new Scanner(System.in);

        // Declare variables
        int num1, num2, sum;

        // Print prompt and retrieve integer inputs
        System.out.print("Enter first Integer: ");
        num1 = input.nextInt();

        System.out.print("Enter second Integer: ");
        num2 = input.nextInt();

        // Perform addition operation
        sum = num1 + num2;

        // Print resultant value
        System.out.printf("Sum is %d\n", sum);

        input.close();
    }
}