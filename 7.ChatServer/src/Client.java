import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

@SuppressWarnings("InfiniteLoopStatement")
public class Client {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket(InetAddress.getLocalHost(), 5000);
            PrintWriter printWriter =  new PrintWriter(socket.getOutputStream(), true);
            BufferedReader bufferedReaderSocket = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedReader bufferedReaderIO = new BufferedReader((new InputStreamReader(System.in)));

            String input, output;
            while (true) {
                do {
                    output = bufferedReaderSocket.readLine();
                    System.out.println(output);
                } while (!output.equals("over"));
                do {
                    input = bufferedReaderIO.readLine();
                    printWriter.println(input);
                } while (!input.equals("over"));
                return;
            }

        } catch (Exception e) {
            System.out.println("Exception: " + e);
        }
    }
}
