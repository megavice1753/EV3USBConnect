package EV3USBConnect;

public class Connector {
    public static native byte[] readWrite(byte[] mas);
    
    public static native void write(byte[] mas);
}