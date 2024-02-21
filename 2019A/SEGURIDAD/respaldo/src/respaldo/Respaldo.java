package respaldo;

import java.io.IOException;

public class Respaldo {

    public static void main(String[] args) {
        try {
            String path = "C:\\Users\\marti\\Desktop\\datos.backup";
            Runtime r = Runtime.getRuntime();

            String user = "postgres";
            String dbase = "reciclaje";
            String password = "212575181";

            Process p;
            ProcessBuilder pb;

            r = Runtime.getRuntime();
            pb = new ProcessBuilder("pg_dump", "-v", "-D", "-f", path, "-U", user, dbase);
            pb.environment().put("PGPASSWORD", password);
            pb.redirectErrorStream(true);
            p = pb.start();

        } catch (IOException e) {
        }
    }
}
