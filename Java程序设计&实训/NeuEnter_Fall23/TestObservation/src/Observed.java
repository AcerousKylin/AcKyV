public interface Observed {
    void addObserver(Observer ob);
    void deleteObserver(Observer ob);
    void informObserver(String action);
}
