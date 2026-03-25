import java.util.ArrayList;
import java.util.List;

public class Observation implements Observed {
    public String getName() {
        return name;
    }
    
    private String name;
    private List<Observer> listObserver = new ArrayList<>();
    public Observation(String name) {
        this.name = name;
    }
    @Override
    public void addObserver(Observer ob){
        listObserver.add(ob);
    }
    public void deleteObserver(Observer ob){
        listObserver.remove(ob);
    }
    public void informObserver(String action){
        for (Observer ob : listObserver)
            ob.update(action);
    }
}
