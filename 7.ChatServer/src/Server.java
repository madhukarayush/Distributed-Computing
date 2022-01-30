import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

@SuppressWarnings("InfiniteLoopStatement")
public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket socketServer = new ServerSocket(5000);
            Socket socket = socketServer.accept();
            System.out.println("Connection from " + socket);
            PrintWriter printWriter = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader bufferedReaderSocket = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedReader bufferedReaderIO = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("System is ready...");
            String input, output;
            while (true) {
                do {
                    output = bufferedReaderIO.readLine();
                    printWriter.println(output);
                } while (!output.equals("over"));
                do {
                    input = bufferedReaderSocket.readLine();
                    System.out.println(input);
                } while (!input.equals("over"));
            }
        } catch (Exception e) {
            System.out.println("Exception: " + e);
        }

    }
}
