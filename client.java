import java.io.*;
import java.net.*;

public class client {
    public static void main(String[] args)  { 
        try{
            Socket s= new Socket("localhost",6666);
            DataOutputStream dout=new DataOutputStream(s.getOutputStream());
            dout.writeUTF("hello server");
            dout.flush();
            dout.close();
        }
        catch(Exception e){

        }
    }
}
