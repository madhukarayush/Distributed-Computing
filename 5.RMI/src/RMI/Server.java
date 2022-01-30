package RMI;

import java.rmi.Naming;

public class Server {
    public static void main(String[] args) {
        System.out.println("Starting the Remote Server at rmi://localhost:5000/");
        try {
            Adder stub = new AdderRemote();
            Naming.bind("rmi://localhost:5000/Adder", stub);
        } catch (Exception e) {
            System.out.println("Exception: " + e);
        }
    }
}
