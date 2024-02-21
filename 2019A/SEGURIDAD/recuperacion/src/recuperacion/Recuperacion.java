package recuperacion;

import java.io.IOException;

public class Recuperacion {

    public static void main(String[] args) {
        // TODO code application logic here
    }
    
    public void restaurar( String servidor, String puerto, String usuario, String password, String basedatos, String path ){
        try
        {
            ProcessBuilder pbuilder;
            //Realiza la construccion del comando
            pbuilder = new ProcessBuilder( "pg_restore", "-i", "-h", servidor, "-p", puerto, "-U", usuario, "-d", basedatos, "-v", path );
            //Se ingresa el valor del password a la variable de entorno de postgres
            pbuilder.environment().put( "PGPASSWORD", password );
            pbuilder.redirectErrorStream( true );
            //Ejecuta el proceso
            pbuilder.start();
        } catch (IOException e) {}
    }
    
}
