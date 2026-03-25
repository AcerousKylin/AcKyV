public class Test {
    public static void main(String[] args) throws Exception
    {
        Receiver receiver = new Receiver();
        Sender sender = new Sender(receiver);
        sender.sendMessage();
    }
}
