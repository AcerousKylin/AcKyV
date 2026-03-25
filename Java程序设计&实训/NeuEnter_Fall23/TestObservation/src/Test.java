public class Test {
    public static void main(String[] args) throws Exception {
        Observation observation = new Observation("The observed");
        Observer ob1 = new Observer("ob_One");
        Observer ob2 = new Observer("ob_Two");
        Observer ob3 = new Observer("ob_Three");
        
        observation.addObserver(ob1);
        observation.addObserver(ob2);
        observation.addObserver(ob3);

        observation.informObserver(observation.getName() + " is being observed.");
    }
}
