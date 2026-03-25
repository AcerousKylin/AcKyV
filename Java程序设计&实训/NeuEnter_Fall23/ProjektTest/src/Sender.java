public class Sender implements Callback{
    Receiver receiver;
    public Sender(Receiver receiver) {
        this.receiver = receiver;
    }
    public void sendMessage() throws Exception {
        System.out.println("Start to execute call-back function.");
        System.out.println("This is a message.");
        receiver.answer(this);
        System.out.println("Start to execute call-back function.");
    }
    @Override
    public void call() {
        System.out.println("Gotcha.");
    }
}
