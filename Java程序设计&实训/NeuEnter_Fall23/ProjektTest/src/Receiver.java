public class Receiver {
    public void answer(Callback callback) throws Exception {
        System.out.println("Connecting...");
        callback.call();
    }
}
