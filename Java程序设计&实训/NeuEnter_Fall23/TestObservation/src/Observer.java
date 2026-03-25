public class Observer implements Mode {
    private String name;
    public Observer(String name) {
        this.name = name;
    }
    @Override
    public void update(String action) {
        System.out.println(name + " is online! " + action);
    }
}
