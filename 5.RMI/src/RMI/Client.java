package RMI;

import java.rmi.Naming;
import java.util.Scanner;

public class Client {
    private static final String URL = "rmi://localhost:5000/Adder";
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the integer operands: ");
        System.out.print("x = ");
        int x = input.nextInt();
        System.out.print("y = ");
        int y = input.nextInt();
        try {
            System.out.println("Calling the Remote Adder function at " + URL);
            Adder stub = (Adder) Naming.lookup(URL);
            System.out.println("Server Response: " + stub.add(x, y));

        } catch (Exception e) {
            System.out.println("Exception: " + e);
        }
    }
}
